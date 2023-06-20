#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<flightpathdata.h>
#include<setaflightpath.h>
#include<QRunnable>
#include <QObject>
#include<QWidget>
#include<QVector>
#include<QTimer>
#include<QThread>
#include<QTime>
#include<QtMath>


class StartMotion:public QObject
{
    Q_OBJECT
public:
    explicit StartMotion(QObject *parent=nullptr);
    ~StartMotion();

    void recvFlightPathData(FlightPathData);



    QTimer *fTimer;

    int Tcounter;

    qreal T;   //单位时间间隔


    setAFlightPath Yinyong;//引用

    void recvAFlightData(flightpathdata);

    enum FlightPathSelect{hl1,hl2,hl3,hl4,hl5,hl6,hl7,hl8,hl9};//航路选择

protected:
    FlightPathData Motion(FlightPathData);//所有的运动都在这个函数里执行

    FlightPathData PathBefore;//上一个航迹点

    qreal UniformLinerMotion(qreal x,qreal vx );//匀速直线运动函数

    flightpathdata RandomMotion1(flightpathdata );//航路1
    flightpathdata RandomMotion2(flightpathdata );//航路2
    flightpathdata RandomMotion3(flightpathdata );//航路3
    flightpathdata RandomMotion4(flightpathdata );//航路4
    flightpathdata RandomMotion5(flightpathdata );//航路5
    flightpathdata RandomMotion6(flightpathdata );//航路6
    flightpathdata RandomMotion7(flightpathdata );//航路7
    flightpathdata RandomMotion8(flightpathdata );//航路8
    flightpathdata RandomMotion9(flightpathdata );//航路9

    FlightPathDataXYVxVyW UniformCircularMotion(qreal x,qreal y,qreal vx,qreal vy,qreal w);//匀速圆周运动

    FlightPathDataSVAW UniformlyAcceleratedLinearMotion(qreal x,qreal v,qreal a);//匀加速直线运动

private slots:
    void UpdateData();

    void working();

signals:
    void sendFlightPathData(FlightPathData);

private:
    FlightPathData flightpathdataSave;

    QString strMotionType(FlightPathData aFlightPath);//返回目标的运动类型



};



#endif // MYTHREAD_H
