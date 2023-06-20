#ifndef FLIGHTPATHDATA_H
#define FLIGHTPATHDATA_H

#/*include <QMetaType>
#include<QVariant>*/
#include<QtMath>

typedef struct flightpathdata
{
    int TargetID;
   int TargetType;//目标类型，1为飞机，2直升机，3导弹
   int IsEnemy;//是否为敌方，0否，1是
   qreal  x ,y,z;//目标初始位置
   qreal vx,vy,vz;//初始速度
   int MotionType;//总的运动
   int MotionTypex,MotionTypey,MotionTypez;//运动类型
   qreal ax,ay,az;//目标加速度
   qreal wx,wy,wz;//目标角速度
   int FlightPathSelect;//航路选择
   qreal Angle;//物体飞行时的转角
}FlightPathData;

typedef  struct flightpathdatasvaw//匀加速运动专用结构体
{
    qreal s;//位置
    qreal a;//加速度
    qreal v;//速度
    qreal w;//角速度
}FlightPathDataSVAW;

typedef  struct flightpathdataxyvxvyw//匀速圆周运动专用结构体
{
    qreal x;//位置
    qreal y;//另一个方向的坐标
    qreal vx;//加速度
    qreal vy;//速度
    qreal w;//角速度
}FlightPathDataXYVxVyW;


//Q_DECLARE_METATYPE(flightpathdata);


#endif // FLIGHTPATHDATA_H
