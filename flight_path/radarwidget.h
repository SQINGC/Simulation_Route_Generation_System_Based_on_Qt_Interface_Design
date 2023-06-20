#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <QWidget>
#include"flightpathdata.h"
#include<QColor>
#include<QVector>
#include"planevertex.h"
#define MAX 8
#define PI 3.14159

class RadarWidget : public QWidget
{
    //public:
    //    RadarWidget();

    //    std::vector<std::vector<FlightPathData>> FlightPaths;//接收到的路径数据

    //private slots:
    //    void ReceivePaths(FlightPathData[]);//接收瞬时的数据，怎么存储应该由这边来操作

    Q_OBJECT

public:
    explicit RadarWidget(QWidget *parent = nullptr);
    ~RadarWidget();
    virtual    QPixmap  paintWidget();

    void recvAPath(flightpathdata);

    void recvShowFlag(bool);

    bool showFlag;

        QPoint point;

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

        int i_diameter=0;
        qreal bili;//比例

protected slots:
    void timerTimeOut();

protected:
    QPointF PlanePoint[MAX][15];
    QPointF PlanePoint0[15];
    qreal planeR[15],planetheta[15];//飞机的极坐标
    qreal hjj[MAX];//航迹角

    void TransCoordinate(QPointF,qreal& ,qreal& );//计算飞机极坐标
    void FeiJiZhuanWanHDZB(QPointF&,qreal,qreal);//飞机转弯后的坐标


    QPointF pointshang[MAX];//上一个航迹点
    QPointF pointcurrent[MAX];//当前航迹点



    void IniPlanePoint();

protected:
    QTimer *timer;


    double d_angle=0;
    QList<QPixmap> list_pixmap;
    QVector<QVector<flightpathdata>> PathPaint;


};

#endif // RADARWIDGET_H
