#ifndef INFRAREDTEMP_H
#define INFRAREDTEMP_H

#include "DIASDAQDLL.h"

#include <QDateTime> // 获取日期时间
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <handleapi.h>

class InfraredTemp
{
public:
    InfraredTemp();

public:
    const DDAQ_U32 DeviceNo = 1; // 设备编号
    const int num_line = 512;
    const int num_pixel = 512;
    const int num_byte = 4;
    const DDAQ_U32 BufSize = 512*512*4; // 缓冲区大小=num_line*num_pixel*num_byte
    //const char* filePath_irdx = ("./infTempData/infTemp_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".irdx").toLatin1();
    //const char* filePath_irdx = "./infTempData/IRDX1.irdx";
    //const char* filePath_irdx = "D:\\20240927_1_lyh_725\\715\\infTempData\\IRDX1.irdx";
    //const char* filePath_irdx = "IRDX1.irdx";
    //const char* filePath_irdx = ("infTempData/infTemp_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".irdx").toLatin1();
    //const char* filePath_irdx = ("infTempData\\infTemp_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".irdx").toLatin1();
    //const QString filePath_txt = "infTempData/infTemp_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".txt";
    static const char* filePath_irdx; // 保存文件的路径(irdx)
    static const QString filePath_txt; // 保存文件的路径(txt)

    //bool initialize(); // 初始化

    bool cameraCheck(); // 自动检测相机

    bool startCollection(); // 开始采集
    bool pauseCollection(); // 暂停采集
    bool stopCollection(); // 停止采集

    bool saveIRDX(); // 保存为IRDX文件
    bool savePixelData(); // 保存每个像素的温度值
};

#endif // INFRAREDTEMP_H
