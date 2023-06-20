#include "mythread.h"
#include<QMessageBox>
#include<QThread>
#include<QDebug>



StartMotion::StartMotion(QObject *parent):QObject (parent)
{
    flightpathdataSave={0};
    PathBefore={0};
    Tcounter=0;

}

StartMotion::~StartMotion()
{
    fTimer->stop();
    fTimer->deleteLater();
}

void StartMotion::working()
{

    fTimer=new QTimer();
    fTimer->setInterval(50);
    connect(fTimer,SIGNAL(timeout()),this,SLOT(UpdateData()));
    fTimer->start();
   T=fTimer->interval()/10.0;//倍速
}

void StartMotion::UpdateData()
{
    flightpathdataSave=Motion(flightpathdataSave);
    flightpathdata a=flightpathdataSave;
    //qDebug()<<a.x<<" "<<a.TargetID<<"  "<<QTime::currentTime();
    emit sendFlightPathData(a);
    //qDebug()<<a.Angle;
}

void StartMotion::recvAFlightData(flightpathdata a)
{

    flightpathdataSave=a;

}

qreal StartMotion::UniformLinerMotion(qreal x,qreal v)//匀速直线运动函数
{
    x=x+v*T;
    return  x;
}

FlightPathDataXYVxVyW StartMotion::UniformCircularMotion(qreal x, qreal y, qreal vx, qreal vy, qreal w)
{

       T=fTimer->interval()/1000.0;//倍速
    FlightPathDataXYVxVyW temp;

    x=x+(qSin(w*T)/w)*vx-((1-qCos(w*T))/w)*vy;
    y=((1-qCos(w*T))/w)*vx+y+(qSin(w*T)/w)*vy;
    vx=qCos(w*T)*vx-qSin(w*T)*vy;
    vy=qSin(w*T)*vx+qCos(w*T)*vy;
    //    qDebug()<<"x:"<<x;
    //    qDebug()<<"y:"<<y;
    temp.x=x;
    temp.y=y;
    temp.vx=vx;
    temp.vy=vy;
    temp.w=w;
    return temp;
}


FlightPathDataSVAW StartMotion::UniformlyAcceleratedLinearMotion(qreal x, qreal v, qreal a)
{
    int w=0;
    FlightPathDataSVAW temp;
    x=x+v*T+(0.5)*a*T*T;
    v=v+a*T;
    temp.a=a;
    temp.v=v;
    temp.s=x;
    temp.w=w;
    return temp;
}





flightpathdata StartMotion::RandomMotion1(flightpathdata aFlightPath)//航路1
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter >=0&&T*Tcounter<=100 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+ aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ax=-0.1;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ax=0;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=600 )
    {
        aFlightPath.ax=-0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>600 &&T*Tcounter<=1100 )
    {
        aFlightPath.ax=-0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1200 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1200 &&T*Tcounter<=1500 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;

        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ay=0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=1000 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1000 &&T*Tcounter<=1100 )
    {
        aFlightPath.ay=-0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1300 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1300 &&T*Tcounter<=1400 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;

        }
    }

    //z方向
    if(T*Tcounter>=0&&T*Tcounter<=160 )
    {

        aFlightPath.az=0;
        temp.az=0;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>160 &&T*Tcounter<=360 )
    {
        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>330 &&T*Tcounter<=460 )
    {

        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>460 &&T*Tcounter<=560 )
    {
        aFlightPath.az=0.05;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>560 &&T*Tcounter<=1060 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1060 &&T*Tcounter<=1160 )
    {
        aFlightPath.az=-0.15;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1160 &&T*Tcounter<=1360 )
    {
        aFlightPath.az=-0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1360 &&T*Tcounter<=1460 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vz;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.z;
        }
    }
    if(T*Tcounter>=1500)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
    return temp;
}

flightpathdata StartMotion::RandomMotion2(flightpathdata aFlightPath)//航路2
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+ aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ax=-0.1;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ax=0;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=600 )
    {
        aFlightPath.ax=-0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>600 &&T*Tcounter<=1100 )
    {
        aFlightPath.ax=-0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1200 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1200 &&T*Tcounter<=1500 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=150 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>150 &&T*Tcounter<=350 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>350 &&T*Tcounter<=450 )
    {

        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>450 &&T*Tcounter<=550 )
    {
        aFlightPath.ay=-0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>550 &&T*Tcounter<=1050 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1050 &&T*Tcounter<=1150 )
    {
        aFlightPath.ay=0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1150 &&T*Tcounter<=1350 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1350 &&T*Tcounter<=1450 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }
    //z方向
    if(T*Tcounter>=0&&T*Tcounter<=160 )
    {

        aFlightPath.az=0;
        temp.az=0;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>160 &&T*Tcounter<=360 )
    {
        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>330 &&T*Tcounter<=460 )
    {

        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>460 &&T*Tcounter<=560 )
    {
        aFlightPath.az=0.05;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>560 &&T*Tcounter<=1060 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1060 &&T*Tcounter<=1160 )
    {
        aFlightPath.az=-0.15;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1160 &&T*Tcounter<=1360 )
    {
        aFlightPath.az=-0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1360 &&T*Tcounter<=1460 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vz;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.z;
        }
    }
    if(T*Tcounter>=1500)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
PathBefore=temp;
    return temp;
}



flightpathdata StartMotion::RandomMotion3(flightpathdata aFlightPath)//航路3
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+ aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ax=0.1;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ax=0;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=600 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>600 &&T*Tcounter<=1100 )
    {
        aFlightPath.ax=-0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1200 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1200 &&T*Tcounter<=1500 )
    {
        aFlightPath.ax=-0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=150 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>150 &&T*Tcounter<=350 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>350 &&T*Tcounter<=450 )
    {

        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>450 &&T*Tcounter<=550 )
    {
        aFlightPath.ay=-0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>550 &&T*Tcounter<=1050 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1050 &&T*Tcounter<=1150 )
    {
        aFlightPath.ay=0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1150 &&T*Tcounter<=1350 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1350 &&T*Tcounter<=1450 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }
    //z方向
    if(T*Tcounter>=0&&T*Tcounter<=160 )
    {

        aFlightPath.az=0;
        temp.az=0;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>160 &&T*Tcounter<=360 )
    {
        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>330 &&T*Tcounter<=460 )
    {

        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>460 &&T*Tcounter<=560 )
    {
        aFlightPath.az=0.05;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>560 &&T*Tcounter<=1060 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1060 &&T*Tcounter<=1160 )
    {
        aFlightPath.az=-0.15;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1160 &&T*Tcounter<=1360 )
    {
        aFlightPath.az=-0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1360 &&T*Tcounter<=1460 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vz;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.z;
        }
    }
    if(T*Tcounter>=1500)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
PathBefore=temp;
    return temp;
}

flightpathdata StartMotion::RandomMotion4(flightpathdata aFlightPath)//航路4
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+ aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ax=-0.1;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ax=0;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=600 )
    {
        aFlightPath.ax=-0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>600 &&T*Tcounter<=1100 )
    {
        aFlightPath.ax=-0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1200 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1200 &&T*Tcounter<=1500 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ay=0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=1000 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1000 &&T*Tcounter<=1100 )
    {
        aFlightPath.ay=-0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1300 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1300 &&T*Tcounter<=1400 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }
    if(T*Tcounter>=1550)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
    return temp;
}

flightpathdata StartMotion::RandomMotion5(flightpathdata aFlightPath)//航路5
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=1000 )
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1000 &&T*Tcounter<=1100 )
    {
        aFlightPath.ax=-0.3;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1300 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1300 &&T*Tcounter<=1400 )
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ay=0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=1000 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1000 &&T*Tcounter<=1100 )
    {
        aFlightPath.ay=-0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1300 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1300 &&T*Tcounter<=1400 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }
    //z方向
    if(T*Tcounter>=0&&T*Tcounter<=160 )
    {

        aFlightPath.az=0;
        temp.az=0;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>160 &&T*Tcounter<=360 )
    {
        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>330 &&T*Tcounter<=460 )
    {

        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>460 &&T*Tcounter<=560 )
    {
        aFlightPath.az=0.05;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>560 &&T*Tcounter<=1060 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1060 &&T*Tcounter<=1160 )
    {
        aFlightPath.az=-0.15;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1160 &&T*Tcounter<=1360 )
    {
        aFlightPath.az=-0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1360 &&T*Tcounter<=1460 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vz;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.z;
        }
    }
    if(T*Tcounter>=1500)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
    return temp;
}


flightpathdata StartMotion::RandomMotion6(flightpathdata aFlightPath)//航路6
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter>=0&&T*Tcounter<=90 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+ aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>90 &&T*Tcounter<=290 )
    {
        aFlightPath.ax=-0.1;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>290 &&T*Tcounter<=390 )
    {

        aFlightPath.ax=0;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>390 &&T*Tcounter<=490 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>490 &&T*Tcounter<=590 )
    {
        aFlightPath.ax=-0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>590 &&T*Tcounter<=1090 )
    {
        aFlightPath.ax=-0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1090 &&T*Tcounter<=1190 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1190 &&T*Tcounter<=1490 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=150 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>150 &&T*Tcounter<=350 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>350 &&T*Tcounter<=450 )
    {

        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>450 &&T*Tcounter<=550 )
    {
        aFlightPath.ay=0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>550 &&T*Tcounter<=1050 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1050 &&T*Tcounter<=1150 )
    {
        aFlightPath.ay=-0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1150 &&T*Tcounter<=1350 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1350 &&T*Tcounter<=1450 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //z方向
    if(T*Tcounter>=0&&T*Tcounter<=160 )
    {

        aFlightPath.az=0;
        temp.az=0;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>160 &&T*Tcounter<=360 )
    {
        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>330 &&T*Tcounter<=460 )
    {

        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>460 &&T*Tcounter<=560 )
    {
        aFlightPath.az=0.05;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>560 &&T*Tcounter<=1060 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1060 &&T*Tcounter<=1160 )
    {
        aFlightPath.az=-0.15;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1160 &&T*Tcounter<=1360 )
    {
        aFlightPath.az=-0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1360 &&T*Tcounter<=1460 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vz;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.z;
        }
    }
    if(T*Tcounter>=1500)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
PathBefore=temp;
    return temp;
}

flightpathdata StartMotion::RandomMotion7(flightpathdata aFlightPath)//航路2
{
    //把z改成x
    Tcounter++;
    flightpathdata temp=aFlightPath;

    //qDebug()<<T*Tcounter;
    //x方向
    if(T*Tcounter>=0&&T*Tcounter<=100 )
    {

        aFlightPath.ax=0;
        temp.ax=0;
        temp.x=aFlightPath.x+ aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>100 &&T*Tcounter<=300 )
    {
        aFlightPath.ax=0.1;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>300 &&T*Tcounter<=400 )
    {

        aFlightPath.ax=0;//加速度不能超过5，不能低于2
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>400 &&T*Tcounter<=500 )
    {
        aFlightPath.ax=0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>500 &&T*Tcounter<=600 )
    {
        aFlightPath.ax=0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>600 &&T*Tcounter<=1100 )
    {
        aFlightPath.ax=-0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1100 &&T*Tcounter<=1200 )
    {
        aFlightPath.ax=-0.2;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else if(T*Tcounter>1200 &&T*Tcounter<=1500 )
    {
        aFlightPath.ax=-0.1;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
    }
    else
    {
        aFlightPath.ax=0;
        temp.ax=aFlightPath.ax;
        temp.x=aFlightPath.x+aFlightPath.vx*T+(0.5)*aFlightPath.ax*T*T;
        temp.vx=aFlightPath.vx+aFlightPath.ax*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //y方向
    if(T*Tcounter>=0&&T*Tcounter<=150 )
    {

        aFlightPath.ay=0;
        temp.ay=0;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>150 &&T*Tcounter<=350 )
    {
        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>350 &&T*Tcounter<=450 )
    {

        aFlightPath.ay=0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>450 &&T*Tcounter<=550 )
    {
        aFlightPath.ay=0.1;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>550 &&T*Tcounter<=1050 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1050 &&T*Tcounter<=1150 )
    {
        aFlightPath.ay=-0.3;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1150 &&T*Tcounter<=1350 )
    {
        aFlightPath.ay=-0.2;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else if(T*Tcounter>1350 &&T*Tcounter<=1450 )
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
    }
    else
    {
        aFlightPath.ay=0;
        temp.ay=aFlightPath.ay;
        temp.y=aFlightPath.y+aFlightPath.vy*T+(0.5)*aFlightPath.ay*T*T;
        temp.vy=aFlightPath.vy+aFlightPath.ay*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vy;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.y;
        }
    }

    //z方向
    if(T*Tcounter>=0&&T*Tcounter<=160 )
    {

        aFlightPath.az=0;
        temp.az=0;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>160 &&T*Tcounter<=360 )
    {
        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>330 &&T*Tcounter<=460 )
    {

        aFlightPath.az=0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>460 &&T*Tcounter<=560 )
    {
        aFlightPath.az=0.05;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>560 &&T*Tcounter<=1060 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1060 &&T*Tcounter<=1160 )
    {
        aFlightPath.az=-0.15;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1160 &&T*Tcounter<=1360 )
    {
        aFlightPath.az=-0.1;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else if(T*Tcounter>1360 &&T*Tcounter<=1460 )
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
    }
    else
    {
        aFlightPath.az=0;
        temp.az=aFlightPath.az;
        temp.z=aFlightPath.z+aFlightPath.vz*T+(0.5)*aFlightPath.az*T*T;
        temp.vz=aFlightPath.vz+aFlightPath.az*T;
        if(T*Tcounter==1500 )
        {
            qDebug()<<aFlightPath.vx;
            qDebug()<<aFlightPath.vz;
            qDebug()<<aFlightPath.x;
            qDebug()<<aFlightPath.z;
        }
    }
    if(T*Tcounter>=1500)
    {
        Tcounter=0;
    }
    temp.Angle=qAtan((temp.y-PathBefore.y)/(temp.x-PathBefore.x));
    PathBefore=temp;
PathBefore=temp;
    return temp;
}

flightpathdata StartMotion::Motion(FlightPathData aFlightPathData)//目标进行运动
{
    PathBefore= aFlightPathData;
    /********************************************************************************************自定义**************************************************************************************************************************/
    if(aFlightPathData.MotionType==Yinyong.zxyd)
    {
        //x方向
        if(aFlightPathData.MotionTypex==Yinyong.jz)
        {

        }
        else  if(aFlightPathData.MotionTypex==Yinyong.yszx)
        {
            aFlightPathData.x=  UniformLinerMotion(aFlightPathData.x,aFlightPathData.vx);
        }

        else
        {
            FlightPathDataSVAW temp=UniformlyAcceleratedLinearMotion(aFlightPathData.x,aFlightPathData.vx,aFlightPathData.ax);
            aFlightPathData.x=temp.s;
            aFlightPathData.vx=temp.v;
        }

        //y方向
        if(aFlightPathData.MotionTypey==Yinyong.jz)
        {

        }
        else if(aFlightPathData.MotionTypey==Yinyong.yszx)
            aFlightPathData.y= UniformLinerMotion(aFlightPathData.y,aFlightPathData.vy);
        else
        {
            FlightPathDataSVAW temp=UniformlyAcceleratedLinearMotion(aFlightPathData.y,aFlightPathData.vy,aFlightPathData.ay);
            aFlightPathData.y=temp.s;
            aFlightPathData.vy=temp.v;
        }


        //z方向
        if(aFlightPathData.MotionTypez==Yinyong.jz)
        {

        }
        else  if(aFlightPathData.MotionTypez==Yinyong.yszx)
            aFlightPathData.z= UniformLinerMotion(aFlightPathData.z,aFlightPathData.vz);
        else
        {
            FlightPathDataSVAW temp=UniformlyAcceleratedLinearMotion(aFlightPathData.z,aFlightPathData.vz,aFlightPathData.az);
            aFlightPathData.z=temp.s;
            aFlightPathData.vz=temp.v;
        }
        aFlightPathData.Angle=qAtan((PathBefore.y-aFlightPathData.y)/(PathBefore.x-aFlightPathData.x));
    }
    /**********************************************************************************************************************************************************************************************************************************/
    //   另外两个运动的代码

    else if(aFlightPathData.MotionType==Yinyong.ysyz)//协同转弯运动
    {
        FlightPathDataXYVxVyW temp=UniformCircularMotion(aFlightPathData.x,aFlightPathData.y,aFlightPathData.vx,aFlightPathData.vy,aFlightPathData.wx);
        aFlightPathData.x=temp.x;
        aFlightPathData.y=temp.y;
        aFlightPathData.vy=temp.vy;
        aFlightPathData.vx=temp.vx;
        aFlightPathData.Angle=qAtan((PathBefore.y-aFlightPathData.y)/(PathBefore.x-aFlightPathData.x));
        aFlightPathData.ax=-(PathBefore.x-aFlightPathData.x)/fTimer->interval()/100.0;
        aFlightPathData.ay=-(PathBefore.y-aFlightPathData.y)/fTimer->interval()/100.0;
    }

    else //机动运动
    {
        FlightPathData temp;
        if(aFlightPathData.FlightPathSelect==hl1)//航路1
        {
            temp=RandomMotion1(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl2)//航路2
        {
            temp=RandomMotion2(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl3)//航路3
        {
            temp=RandomMotion3(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl4)//航路4
        {
            temp=RandomMotion4(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl5)//航路5
        {
            temp=RandomMotion5(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl6)//航路6
        {
            temp=RandomMotion6(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl7)//航路7
        {
            temp=RandomMotion7(aFlightPathData);
        }
        if(aFlightPathData.FlightPathSelect==hl8)//航路8
        {
            temp=RandomMotion1(aFlightPathData);
        }
        aFlightPathData=temp;
    }


    return aFlightPathData;

}
