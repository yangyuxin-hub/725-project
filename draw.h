#ifndef DRAW_H
#define DRAW_H

#include <QMainWindow>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Draw; }
QT_END_NAMESPACE

// TODO：draw.h文件是杨雨欣测试用的，可以删掉
// 暂时不能删，有依赖关联
class Draw : public QMainWindow
{
    Q_OBJECT

public:
    Draw(QWidget *parent = nullptr);
    ~Draw();
    void cursor(QCustomPlot *widget);
    void setupGraph(QCustomPlot *widget, const QColor &color);
    void dynamicPlot(int number, int channel);

public slots:
    void myMove(QCustomPlot *widget, QMouseEvent *e);
    void handleMouseMove(QMouseEvent *event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Draw *ui;
    QMap<QCustomPlot*, QCPItemTracer*> tracerMap;     // 游标
    QMap<QCustomPlot*, QCPItemText*> tracerLabelMap;// 游标说明

};
#endif // DRAW_H
