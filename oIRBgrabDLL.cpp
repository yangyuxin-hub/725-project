
#include "oIRBgrabDLL.h"
#include <QDebug>
#include <QString>


/*void __CALLCONV IRBGonNewFrame(QWidget *aContext, TITSDK_Handle aDevHandle, int aStreamIndex)
{
    if (aContext == NULL) return;
    MainWindow *m = reinterpret_cast<MainWindow *>(aContext);
    m->on_NewFrame(aDevHandle, aStreamIndex);
}*/

namespace IRBGRAB_Lib {

}

TIRBgrabLib::TIRBgrabLib()
{
    FLibHandle = nullptr;
    FLibCounter = 0;

    NilProcs();
    for (int ii = 0; ii < int(arraylength(FDeviceTypes)); ii++)
    {
        FDeviceTypes[ii] = nullptr;
    }
}

TIRBgrabLib::~TIRBgrabLib()
{
    while (LibLoaded()) UnloadLib();
    for (int ii = 0; ii < int(arraylength(FDeviceTypes)); ii++)
    {
        if (FDeviceTypes[ii] != NULL)
        {
            free(FDeviceTypes[ii]);
        }
    }
}

bool GetFunc(TITSDK_LibHandle aLibHandle, TLibProcAddr *aFunc, const char *aName)
{
#ifdef ITSDK_OS_LINUX
    TLibProcAddr Func = dlsym(aLibHandle, aName);
#endif

#ifdef ITSDK_OS_WINDOWS
    TLibProcAddr Func = GetProcAddress(aLibHandle,aName);
#endif

    if (!Func) return false;
    *aFunc = Func;
    return true;
}

bool TIRBgrabLib::LoadLib(const char *aLibFileName)
{
    bool res = false;

    qDebug().noquote() << QString::fromUtf8("开始加载IRBGrab库...");

    if (FLibHandle == LibHandleInvalid)
    {
        qDebug().noquote() << QString::fromUtf8("步骤1: 检查库句柄状态 - 未加载，开始加载流程");
        char FileName[MAX_PATH];

        if (aLibFileName == NULL)
        {
            qDebug().noquote() << QString::fromUtf8("步骤2: 使用默认DLL文件名...");
#ifdef ITSDK_OS_WINDOWS
            strcpy_s(FileName, arraylength(FileName), "irbgrab_win64.dll");
            qDebug().noquote() << QString::fromUtf8("   指定DLL文件: ") << QString::fromLocal8Bit(FileName);
#endif

#ifdef ITSDK_OS_LINUX
            strcpy(FileName, "/usr/lib/infratec/libirbgrab_linux.so");
#endif
        }
        else
        {
            qDebug().noquote() << QString::fromUtf8("步骤2: 使用指定的DLL文件名: ") << QString::fromLocal8Bit(aLibFileName);
#ifdef ITSDK_OS_WINDOWS
            strcpy_s(FileName, arraylength(FileName), aLibFileName);
#endif
#ifdef ITSDK_OS_LINUX
            strcpy(FileName, aLibFileName);
#endif
        }

        qDebug().noquote() << QString::fromUtf8("步骤3: 加载动态库文件...");
#ifdef ITSDK_OS_WINDOWS
        FLibHandle = LoadLibraryA(FileName);
#endif

#ifdef ITSDK_OS_LINUX
        FLibHandle = dlopen(FileName, RTLD_LAZY | RTLD_GLOBAL);
#endif

        if (FLibHandle == 0)
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法加载动态库文件 ") << QString::fromLocal8Bit(FileName);
            return res;
        }
        qDebug().noquote() << QString::fromUtf8("   动态库加载成功");

        qDebug().noquote() << QString::fromUtf8("步骤4: 获取函数指针...");
        if (!GetFunc(FLibHandle, (TLibProcAddr*)(&FProc_dll_version), "irbgrab_dll_version"))
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法获取函数 irbgrab_dll_version");
            return res;
        }
        if (!GetFunc(FLibHandle, (TLibProcAddr*)(&FProc_dll_init), "irbgrab_dll_init"))
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法获取函数 irbgrab_dll_init");
            return res;
        }
        if (!GetFunc(FLibHandle, (TLibProcAddr*)(&FProc_dll_uninit), "irbgrab_dll_uninit"))
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法获取函数 irbgrab_dll_uninit");
            return res;
        }
        if (!GetFunc(FLibHandle, (TLibProcAddr*)(&FProc_dll_isinit), "irbgrab_dll_isinit"))
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法获取函数 irbgrab_dll_isinit");
            return res;
        }
        if (!GetFunc(FLibHandle, (TLibProcAddr*)(&FProc_dll_devicetypenames), "irbgrab_dll_devicetypenames"))
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法获取函数 irbgrab_dll_devicetypenames");
            return res;
        }
        qDebug().noquote() << QString::fromUtf8("   所有函数指针获取成功");

        qDebug().noquote() << QString::fromUtf8("步骤5: 初始化对象处理器...");
        FObjectHandler_Dev.Init(&FLibHandle);
        FObjectHandler_Mem.Init(&FLibHandle);
        qDebug().noquote() << QString::fromUtf8("   对象处理器初始化完成");

        qDebug().noquote() << QString::fromUtf8("步骤6: 调用DLL初始化函数...");
        if (FProc_dll_init() != ITSDK_RET_OK)
        {
            qDebug().noquote() << QString::fromUtf8("错误: DLL初始化失败");
            return res;
        }
        qDebug().noquote() << QString::fromUtf8("   DLL初始化成功");

        qDebug().noquote() << QString::fromUtf8("步骤7: 获取设备类型信息...");

        for (int ii = 0; ii < int(arraylength(FDeviceTypes)); ii++)
        {
            if (FDeviceTypes[ii] != NULL) free(FDeviceTypes[ii]);
        }

        char buf[1024];
        if (FProc_dll_devicetypenames(buf, arraylength(buf)) != ITSDK_RET_OK)
        {
            qDebug().noquote() << QString::fromUtf8("错误: 无法获取设备类型名称");
            return res;
        }

        char *oldpos;
        char *sspos = buf;
        int idx = 0;
        while (true)
        {
            oldpos = sspos;
            sspos = strstr(sspos, ";");
            if (sspos == NULL)break;
            int len = (int)(sspos - oldpos);
            FDeviceTypes[idx] = (char*)malloc(len + 1);

#ifdef ITSDK_OS_WINDOWS
            strncpy_s(FDeviceTypes[idx], len + 1, oldpos, len);
#endif
#ifdef ITSDK_OS_LINUX
            strncpy(FDeviceTypes[idx], oldpos, len);
#endif

            sspos++;
            idx++;
        }
        qDebug().noquote() << QString::fromUtf8("   解析到 ") << idx << QString::fromUtf8(" 个设备类型");

    }
    else
    {
        qDebug().noquote() << QString::fromUtf8("库已经加载，增加引用计数");
    }
    res = true;

    if (res)
    {
        FLibCounter++;
        qDebug().noquote() << QString::fromUtf8("IRBGrab库加载完成！");
    }
    else
    {
        qDebug().noquote() << QString::fromUtf8("IRBGrab库加载失败，正在清理...");
        UnloadLib();
    }

    return res;
}

bool TIRBgrabLib::UnloadLib()
{
    if (FLibCounter > 0) FLibCounter--;
    if (FLibCounter == 0)
    {
        //try
        {
            if (FProc_dll_uninit != NULL) FProc_dll_uninit();

#ifdef ITSDK_OS_WINDOWS
            FreeLibrary(FLibHandle);
#endif

#ifdef ITSDK_OS_LINUX
            dlclose(FLibHandle);
#endif

        }
        //__finally
        {
            FLibHandle = 0;
            NilProcs();
        }
    }
    return true;
}


void TIRBgrabLib::NilProcs()
{
    FProc_dll_version = NULL;
    FProc_dll_init = NULL;
    FProc_dll_uninit = NULL;
    FProc_dll_devicetypenames = NULL;
    FProc_dll_isinit = NULL;
}

int TIRBgrabLib::DeviceCount()
{
    int res = 0;
    for (int ii = 0; ii < int(arraylength(FDeviceTypes)); ii++)
    {
        if (FDeviceTypes[ii] != NULL) res++;
    }
    return res;
}

char* TIRBgrabLib::DeviceName(int aIndex)
{
    if ((aIndex < 0) || (aIndex >= int(arraylength(FDeviceTypes))))
    {
        return  NULL;
    }
    else
    {
        return FDeviceTypes[aIndex];
    }
}


bool TIRBgrabLib::LibLoaded()
{
    return FLibHandle != 0;
}



