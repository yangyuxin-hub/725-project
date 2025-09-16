#include "wirespeed.h"
#include "ui_wirespeed.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <iomanip>
#include <QThread>
#include <Windows.h>
#include <QDebug>

//WireSpeed* WireSpeed::instance = nullptr; // 单例模式

//WireSpeed* WireSpeed::getInstance() // 单例模式
//{
//    if (!instance) instance = new WireSpeed();
//    return instance;
//}

QString WireSpeed::speedValue = QString("无数据");

const QString WireSpeed::filePath = "Temp_WireSpeed.txt"; // 保存文件的路径(txt)

WireSpeed::WireSpeed(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WireSpeed)
{
    ui->setupUi(this);
//    initialPort();
    connect(ui->btn_open, &QPushButton::clicked, this, &WireSpeed::on_btn_open_clicked);
    connect(ui->btn_close, &QPushButton::clicked, this, &WireSpeed::on_btn_close_clicked);
    connect(ui->btn_clear, &QPushButton::clicked, this, &WireSpeed::on_btn_clear_clicked);

}

WireSpeed::~WireSpeed()
{
    // 析构函数，关闭串口和释放界面对象
    if (this->hSerial != INVALID_HANDLE_VALUE) // 确保句柄有效再关闭
    {
        CloseHandle(this->hSerial); // 关闭串口句柄
    }
    delete ui; // 释放界面对象内存
}

void WireSpeed::initialPort()
{
    // 初始化串口函数
    // 如果句柄有效，先关闭它
        if (this->hSerial != INVALID_HANDLE_VALUE)
        {
            CloseHandle(this->hSerial);
            this->hSerial = INVALID_HANDLE_VALUE; // 重置句柄
        }
        this->dcbSerialParams = {0};
        this->timeouts = {0};

        // 打开串口
        this->hSerial = CreateFileW(L"COM8", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (this->hSerial == INVALID_HANDLE_VALUE)
        {
            qDebug() << "无法打开串口";
            return;
        }

        // 获取并配置串口状态
        this->dcbSerialParams.DCBlength = sizeof(this->dcbSerialParams);

        if (!GetCommState(this->hSerial, &this->dcbSerialParams))
        {
            qDebug() << "获取串口状态失败";
//            CloseHandle(this->hSerial);
            return;
        }

        // 设置串口参数：波特率、数据位、停止位、校验位
        this->dcbSerialParams.BaudRate = CBR_9600;
        this->dcbSerialParams.ByteSize = 8;
        this->dcbSerialParams.StopBits = ONESTOPBIT;
        this->dcbSerialParams.Parity = NOPARITY;

        if (!SetCommState(this->hSerial, &this->dcbSerialParams))
        {
            qDebug() << "设置串口参数失败";
//            CloseHandle(this->hSerial);
            return;
        }

        // 设置串口超时时间
        this->timeouts.ReadIntervalTimeout = 50;
        this->timeouts.ReadTotalTimeoutConstant = 50;
        this->timeouts.ReadTotalTimeoutMultiplier = 10;
        this->timeouts.WriteTotalTimeoutConstant = 50;
        this->timeouts.WriteTotalTimeoutMultiplier = 10;

        if (!SetCommTimeouts(this->hSerial, &this->timeouts))
        {
            qDebug() << "设置超时时间失败";
            CloseHandle(this->hSerial);
            return;
        }
}


void WireSpeed::on_btn_open_clicked()
{
    initialPort(); // 重新初始化串口
    if (this->hSerial == INVALID_HANDLE_VALUE) // 检查串口是否成功打开
    {
        qDebug() << "串口未打开，无法开始采集";
        return;
    }
    this->readornot = true;

    //获取当前时间戳
    startTime = static_cast<double>(QDateTime::currentDateTime().toMSecsSinceEpoch()); // 获取开始时间戳
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    dataTimer->start(100); // 更新频率，单位毫秒（更新频率可以调整）
}



void WireSpeed::on_btn_close_clicked()
{
    this->readornot = false;
    dataTimer->stop(); // 停止定时器

    // 关闭串口句柄
    if (this->hSerial != INVALID_HANDLE_VALUE)
    {
        CloseHandle(this->hSerial);
        this->hSerial = INVALID_HANDLE_VALUE; // 将句柄设置为无效，避免重复关闭
        qDebug() << "串口已关闭";
     }

}



void WireSpeed::on_btn_clear_clicked()
{
    ui->plainTextEdit->clear();
}

void WireSpeed::updatePlot()
{
//    // 设置读取标志为true，开始串口数据读取循环
//    this->readornot = true;

    int n = 0;
    const int buf_size = 32;
    unsigned char read_buf[buf_size];
    DWORD bytes_written;
    DWORD bytes_read;
    QString hexString;
    QTextStream stream(&hexString);
    stream.setIntegerBase(16);
    stream.setFieldWidth(2);
    stream.setPadChar('0');

    unsigned char msg[] = {0x01, 0x03, 0x00, 0x40, 0x00, 0x05, 0x84, 0x1D};  // 发送的十六进制数据
//    unsigned char msg[] = {0x01, 0x03, 0x00, 0x44, 0x00, 0x01, 0xc4, 0x1f};
    //while (this->readornot) // 循环读取串口数据，根据需要注释掉或启用该循环
    if (this->readornot)
    {
        bytes_written = 0;
        if (!WriteFile(this->hSerial, msg, sizeof(msg), &bytes_written, NULL))
        {
            qDebug() << "向串口写入数据失败";
//            CloseHandle(this->hSerial);
            return;
        }

        // qDebug() <<  n++;

        //qDebug() << "发送数据：" << QByteArray(reinterpret_cast<char*>(msg), sizeof(msg)).toHex();

        // 实时地从串口读取数据
        memset(read_buf, 0, buf_size * sizeof(unsigned char));
        bytes_read = 0;
        if (!ReadFile(this->hSerial, read_buf, buf_size, &bytes_read, NULL))
        {
            qDebug() << "从串口读取数据失败";
//            CloseHandle(this->hSerial);
            return;
        }

        hexString.clear();//清空 hexString，为新的数据做准备。

        if (bytes_read > 0)
        {
            double timeStamp = static_cast<double>((QDateTime::currentDateTime().toMSecsSinceEpoch())-startTime)/1000.0;

            // 打印接收到的数据（十六进制格式）
            // qDebug() << "接收到的数据（十六进制格式）:";
            for (DWORD i = 3; i < bytes_read - 2; ++i)
            {
                stream << static_cast<int>(read_buf[i]) << " ";
            }
            double flow = (read_buf[7] << 24) | (read_buf[8] << 16) | (read_buf[9] << 8) | read_buf[10];
            flow = - flow; // 焊接时反转
            qDebug() << "电机转速: " << flow*3.14159*0.04/100;
            speedValue = QString::number(flow*3.14159*0.04/100, 'f', 3) + "m/min";
            //ui->plainTextEdit->appendPlainText(QString::number(flow*3.14159*0.04/100, 'f', 3) + "m/min\n");
            ui->plainTextEdit->appendPlainText(speedValue + "\n");

            // txt中保存数据
            QFile file(filePath); // 相对路径
            if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) { // txt中不清除，继续添加数据
                qWarning("Cannot open file for writing");
            }
            QTextStream textStream(&file);
            textStream << timeStamp << " " << flow*3.14159*0.04/100 << "\n";
            //textStream << " " << flow*3.14159*0.04/100 << "\n";
            file.close();
        }

        //Sleep(100); // 可以添加适当的延迟以降低 CPU 负载
    }
}
