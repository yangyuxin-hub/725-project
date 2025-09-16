#include "taskthread.h"

// 确保两个h文件中定义的类可以互相引用
#include "menu.h"
#include "ui_menu.h"

void TaskThread::run()
{
//    if (taskType == CollectWeldMap) // 采集熔池图像
//    {
//        // 保存数据
//        qint64 nowTime_ms = QDateTime::currentMSecsSinceEpoch();
//        while (!stopCollection)
//        {
//            QMetaObject::invokeMethod(MainWindow, [this]() {
//                QPixmap* weldPoolMap = new QPixmap(MainWindow->w->ui->gvMain->size()); // 新建一与gvMain同尺寸的QPixmap
//                QPainter* weldPoolMapPainter = new QPainter(weldPoolMap); // 将QPainter与要绘图的对象关联起来
//                MainWindow->w->m_scene->render(weldPoolMapPainter); // 使用render()方法将视图内容绘制到QPixmap上

//                weldPoolMap->save("./data/" + timeStamp + "/WeldPoolImage_" +
//                    QDateTime::fromMSecsSinceEpoch(QDateTime::currentMSecsSinceEpoch()).toString("yyyyMMdd_HHmmss_zzz") + ".png"); // 保存截图到文件

//                weldPoolMapPainter->end();
//                delete weldPoolMapPainter;
//                delete weldPoolMap;
//            }, Qt::QueuedConnection);


////            MainWindow->weldPoolMap = new QPixmap(MainWindow->w->ui->gvMain->size()); // 新建一与gvMain同尺寸的QPixmap
////            MainWindow->weldPoolMapPainter = new QPainter(MainWindow->weldPoolMap); // 将QPainter与要绘图的对象关联起来
////            MainWindow->w->m_scene->render(MainWindow->weldPoolMapPainter); // 使用render()方法将视图内容绘制到QPixmap上

////            nowTime_ms = QDateTime::currentMSecsSinceEpoch();
////            MainWindow->weldPoolMap->save("./data/"+timeStamp+"/WeldPoolImage_"+
////                              QDateTime::fromMSecsSinceEpoch(nowTime_ms).toString("yyyyMMdd_HHmmss_zzz")+".png"); // 保存截图到文件
////            //Sleep(50); // 不Sleep的情况下，两次拍照间的间隔大致为110ms

////            MainWindow->weldPoolMapPainter->end(); // 确保结束绘图
////            delete MainWindow->weldPoolMap;
////            delete MainWindow->weldPoolMapPainter;
//        }
//    }
//    else if (taskType == UpdateAcquiCardPlot) // 更新数据采集卡图表
//    {
////        while(MainWindow->ifDrawAcquiCard)
////        {
////            QMetaObject::invokeMethod(MainWindow, "updateAcquiCardPlot", Qt::QueuedConnection);
////            Sleep(1000);
////        }
//    }
}
