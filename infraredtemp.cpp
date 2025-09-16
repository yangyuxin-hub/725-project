#include "infraredtemp.h"

const char* InfraredTemp::filePath_irdx = "Temp_infTemp_IRDX.irdx"; // 保存文件的路径(irdx)
const QString InfraredTemp::filePath_txt = "Temp_infTemp_txt.txt"; // 保存文件的路径(txt)

InfraredTemp::InfraredTemp()
{

}

bool InfraredTemp::cameraCheck() // 自动检测相机
{
    DDAQ_U32 NrDevices = DDAQ_DEVICE_DO_DETECTION();
    if (NrDevices==0) return false;
    qDebug() << "[红外]检测到的设备数量：" << NrDevices;

    //DDAQ_DEVICE_DO_LIST

    //if (DDAQ_DEVICE_DO_OPEN(DeviceNo, nullptr)!=DDAQ_NO_ERROR) return false;
    //DDAQ_U32 eCode = DDAQ_DEVICE_DO_OPEN(DeviceNo, filePath_irdx);
    DDAQ_U32 eCode = DDAQ_DEVICE_DO_OPEN(DeviceNo, nullptr);
    //qDebug() << "[红外]打开设备错误代码：" << eCode;
    if (eCode!=DDAQ_NO_ERROR) return false;
    return true;
}

bool InfraredTemp::startCollection() // 开始采集
{
    //if (DDAQ_DEVICE_DO_OPEN(DeviceNo, filePath_irdx) == DDAQ_NO_ERROR) return true;
    //else return false;
    DDAQ_U32 eCode = DDAQ_DEVICE_DO_START(DeviceNo);
    //qDebug() << eCode;

    if (eCode == DDAQ_NO_ERROR) return true;
    else return false;
}

// 暂无，暂时用于测试
bool InfraredTemp::pauseCollection() // 暂停采集
{
//    // 读取文件大小
//    DDAQ_P_F64 pf64FileSizeMB = new DDAQ_F64;
//    DDAQ_U32 eCode1 = DDAQ_IRDX_FILE_GETSIZE(filePath_irdx, pf64FileSizeMB);
//    qDebug() << "eCode1:" << eCode1;
//    qDebug() << "size:" << pf64FileSizeMB;
//    if (eCode1!=DDAQ_NO_ERROR) return false;

    // 获取IRDX句柄
    DDAQ_HANDLE hIRDX = INVALID_HANDLE_VALUE;
    DDAQ_P_HANDLE phIRDX = &hIRDX; // 初始化指向IRDX句柄的指针
    DDAQ_U32 eCode1 = DDAQ_DEVICE_GET_IRDX(DeviceNo, phIRDX);
    qDebug() << "eCode1:" << eCode1;
    if (eCode1!=DDAQ_NO_ERROR) return false;

//    DDAQ_U32 eCode2 = DDAQ_IRDX_FILE_OPEN_READWRITE(filePath_irdx, true, phIRDX);
//    qDebug() << "eCode2:" << eCode2;
//    if (eCode2!=DDAQ_NO_ERROR) return false;

//    DDAQ_PC_CHAR8 sz8FileNameOld = "IRDX1.irdx";
//    DDAQ_PC_CHAR8 sz8FileNameNew = "IRDX2.irdx";
//    DDAQ_U32 eCode3 = DDAQ_IRDX_FILE_RENAME(sz8FileNameOld, sz8FileNameNew);
//    qDebug() << "eCode3:" << eCode3;
//    if (eCode3!=DDAQ_NO_ERROR) return false;

    DDAQ_U32 eCode4 = DDAQ_IRDX_FILE_SAVE(*phIRDX, filePath_irdx);
    qDebug() << "eCode4:" << eCode4;
    if (eCode4!=DDAQ_NO_ERROR) return false;

    return true;
}

bool InfraredTemp::stopCollection() // 停止采集
{
    DDAQ_U32 eCode = DDAQ_DEVICE_DO_STOP(DeviceNo);
    //qDebug() << eCode;

    if (eCode == DDAQ_NO_ERROR) return true;
    else return false;
}

bool InfraredTemp::saveIRDX() // 保存为IRDX文件
{
    // 获取IRDX句柄
    DDAQ_HANDLE hIRDX = INVALID_HANDLE_VALUE;
    DDAQ_P_HANDLE phIRDX = &hIRDX; // 初始化指向IRDX句柄的指针
    DDAQ_U32 eCode1 = DDAQ_DEVICE_GET_IRDX(DeviceNo, phIRDX);
    qDebug() << "eCode1:" << eCode1;
    if (eCode1!=DDAQ_NO_ERROR) return false;

//    DDAQ_U32 eCode2 = DDAQ_IRDX_FILE_OPEN_READWRITE(filePath_irdx, true, phIRDX);
//    qDebug() << "eCode2:" << eCode2;
//    if (eCode2!=DDAQ_NO_ERROR) return false;

//    DDAQ_PC_CHAR8 sz8FileNameOld = "IRDX1.irdx";
//    DDAQ_PC_CHAR8 sz8FileNameNew = "IRDX2.irdx";
//    DDAQ_U32 eCode3 = DDAQ_IRDX_FILE_RENAME(sz8FileNameOld, sz8FileNameNew);
//    qDebug() << "eCode3:" << eCode3;
//    if (eCode3!=DDAQ_NO_ERROR) return false;

    DDAQ_U32 eCode4 = DDAQ_IRDX_FILE_SAVE(*phIRDX, filePath_irdx);
    qDebug() << "eCode4:" << eCode4;
    if (eCode4!=DDAQ_NO_ERROR) return false;

    return true;

//    // 获取IRDX句柄
//    DDAQ_HANDLE hIRDX = INVALID_HANDLE_VALUE;
//    DDAQ_P_HANDLE phIRDX = &hIRDX; // 初始化指向IRDX句柄的指针
//    DDAQ_U32 eCode1 = DDAQ_DEVICE_GET_IRDX(DeviceNo, phIRDX);
//    qDebug() << "eCode1:" << eCode1;
//    if (eCode1!=DDAQ_NO_ERROR) return false;

//    // 获取NewDataReady的信号
//    //bool NewDataReady = false;
//    //DDAQ_DEVICE_GET_NEWDATAREADY(DeviceNo,&NewDataReady);

//    //DDAQ_IRDX_FILE_ADD_IRDX(nullptr, );

}

bool InfraredTemp::savePixelData() // 保存每个像素的温度值
{
    //if (DDAQ_DEVICE_GET_IRDX(DeviceNo, phIRDX)!=DDAQ_NO_ERROR) return false;
    //if (DDAQ_IRDX_PIXEL_GET_DATA(*phIRDX, pf32Data, BufSize)!=DDAQ_NO_ERROR) return false;
    // 获取IRDX句柄
    DDAQ_HANDLE hIRDX = INVALID_HANDLE_VALUE;
    DDAQ_P_HANDLE phIRDX = &hIRDX; // 初始化指向IRDX句柄的指针
    DDAQ_U32 eCode1 = DDAQ_DEVICE_GET_IRDX(DeviceNo, phIRDX);
    qDebug() << "savetxt-eCode1:" << eCode1;
    if (eCode1!=DDAQ_NO_ERROR) return false;

    // 获取像素温度数据
    DDAQ_P_F32 pf32Data = new DDAQ_F32[BufSize]; // 初始化指向数据的指针
    DDAQ_U32 eCode2 = DDAQ_IRDX_PIXEL_GET_DATA(*phIRDX, pf32Data, BufSize);
    qDebug() << "savetxt-eCode2:" << eCode2;
    if (eCode2!=DDAQ_NO_ERROR) return false;

    if (pf32Data) // 保存数据
    {
       QFile file(filePath_txt); // 相对路径
       if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
           qWarning("Cannot open file for writing");
       }

       QTextStream textStream(&file);
       for (int i = 0; i < num_line*num_pixel; ++i) {
           textStream << QString::number(*(pf32Data+i)) << " ";
           if ((i+1)%512==0) textStream << "\n";
       }

       file.close();
    }

    delete [] pf32Data;

    return true;
}
