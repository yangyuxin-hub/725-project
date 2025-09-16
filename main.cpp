#include <Python.h>
#include "pybind11/embed.h"
#include <pybind11/stl.h>
#ifdef _WIN64
#define MS_WIN64
#include <windows.h>
#endif

#include "menu.h"
#include "MecaVision.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "qcustomplot.h"
#include "streamingbufferedai.h"
#include "configuredialog.h"
#include "frm_irbgrab_v4.h"

#include <QCoreApplication>
#include <iostream>
#include <qDebug>

namespace py = pybind11;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef _WIN64
    SetEnvironmentVariableA("PYTHONHOME", "C:/Users/Admin/miniconda3/envs/py38");
#endif
    py::scoped_interpreter guard{};

    // 设置 sys.path，把当前目录加入搜索路径
    py::module_ sys = py::module_::import("sys");
    sys.attr("path").attr("append")("D:/20250826_win64");
    sys.attr("path").attr("append")("C:/Users/Admin/miniconda3/envs/py38/lib/site-packages");

    // 主菜单
    Menu mainMenu;
    mainMenu.setWindowTitle("主控界面"); // 设置窗口名称

    // 光谱需要的内容
    application app(argc, argv);
    mainMenu.app = &app;
    spectrum spec(&app);
    mainMenu.spec = &spec;

    mainMenu.show();
    return a.exec();
}
