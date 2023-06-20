#include "radarwidget.h"
#include<QTimer>
#include<QPainter>
#include<QDebug>
#include<QTime>
#include<QGridLayout>
#include<QPushButton>
#include<QElapsedTimer>
#pragma execution_character_set("utf-8")

RadarWidget::RadarWidget(QWidget *parent):QWidget(parent)
{
    this->setStyleSheet("background-color:black");//设置窗口背景色为黑色
    timer = new QTimer();
    timer->start();//毫米单位
    timer->setInterval(10);
    PathPaint.resize(MAX);
    IniPlanePoint();
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));
    //        connect(timer,&QTimer::timeout,this,[=](){
    //            timerTimeOut();
    //        });

}

void RadarWidget::IniPlanePoint()
{
    double bili;
    bili=1.2;
    PlanePoint0[planeA]=QPointF(8,0.0)*2.5*bili;
    PlanePoint0[planeB]=QPointF(-(0.5 - 8),0.5)*2.5*bili;
    PlanePoint0[planeC]=QPointF(-(2.5-8),0.5)*2.5*bili;
    PlanePoint0[planeD]=QPointF(-(4.5-8),4.5)*2.5*bili;
    PlanePoint0[planeE]=QPointF(-(5-8),4.5)*2.5*bili;
    PlanePoint0[planeF]=QPointF(-(4.5-8),0.5)*2.5*bili;
    PlanePoint0[planeG]=QPointF(-(7-8),0.5)*2.5*bili;
    PlanePoint0[planeH]=QPointF(-(8-8),3)*2.5*bili;
    PlanePoint0[planeAN]=QPointF(8,0.0)*2.5*bili;
    PlanePoint0[planeBN]=QPointF(-(0.5-8),-0.5)*2.5*bili;
    PlanePoint0[planeCN]=QPointF(-(2.5-8),-0.5)*2.5*bili;
    PlanePoint0[planeDN]=QPointF(-(4.5-8),-4.5)*2.5*bili;
    PlanePoint0[planeEN]=QPointF(-(5-8),-4.5)*2.5*bili;
    PlanePoint0[planeFN]=QPointF(-(4.5-8),-0.5)*2.5*bili;
    PlanePoint0[planeGN]=QPointF(-(7-8),-0.5)*2.5*bili;
    PlanePoint0[planeHN]=QPointF(-(8-8),-3)*2.5*bili;

    //    PlanePoint0[planeA]=QPointF(0.08,0.0);
    //    PlanePoint0[planeB]=QPointF(-(0.005 - 0.08),0.005);
    //    PlanePoint0[planeC]=QPointF(-(0.025-0.08),0.005);
    //    PlanePoint0[planeD]=QPointF(-(0.045-0.08),0.045);
    //    PlanePoint0[planeE]=QPointF(-(0.05-0.08),0.045);
    //    PlanePoint0[planeF]=QPointF(-(0.045-0.08),0.005);
    //    PlanePoint0[planeG]=QPointF(-(0.07-0.08),0.005);
    //    PlanePoint0[planeH]=QPointF(-(0.08-0.08),0.03);
    //    PlanePoint0[planeAN]=QPointF(0.08,0.0);
    //    PlanePoint0[planeBN]=QPointF(-(0.005-0.08),-0.005);
    //    PlanePoint0[planeCN]=QPointF(-(0.025-0.03),-0.005);
    //    PlanePoint0[planeDN]=QPointF(-(0.045-0.08),-0.045);
    //    PlanePoint0[planeEN]=QPointF(-(0.05-0.08),-0.045);
    //    PlanePoint0[planeFN]=QPointF(-(0.045-0.08),-0.005);
    //    PlanePoint0[planeGN]=QPointF(-(0.07-0.08),-0.005);
    //    PlanePoint0[planeHN]=QPointF(-(0.08-0.08),-0.03);
}

void RadarWidget::resizeEvent(QResizeEvent *event)
{
    if(this->width() > this->height()){
        i_diameter = this->height()-15;
        point = QPoint((this->width()-this->height())/2+(i_diameter)/2,this->height()/2);//中心点
    }else{
        i_diameter = this->width()-15;
        point = QPoint(this->width()/2,(this->height()-this->width())/2+(i_diameter)/2);//12表示和上边界的距离

    }
}

QPixmap RadarWidget::paintWidget()
{
    QPixmap pixmap(this->width(),this->height());
    QPainter p_painter(&pixmap);
    QPen pen;
    QTime timedebug;
    timedebug.start();
    //反锯齿
    p_painter.setRenderHint(QPainter::Antialiasing);
    pixmap.fill(QColor(55,55,55));

    pen.setColor(Qt::gray);
    p_painter.setPen(pen);
    p_painter.drawLine(point.x(),point.y()-i_diameter/2-10,point.x(),point.y()+i_diameter/2+10);//画坐标
    p_painter.drawLine(point.x()-i_diameter/2-10,point.y(),point.x()+i_diameter/2+10,point.y());
    pen.setColor(QColor(0,238,0));
    pen.setWidth(0);
    p_painter.setPen(pen);
    double i2=0.7;
    for(int i=1; i<6; i=i+2){//画圈圈

        pen.setColor(QColor(0,238,0));
        pen.setWidthF(i2);
        p_painter.setPen(pen);
        i2=i2+0.3;

        p_painter.drawEllipse(point.x()-i_diameter*0.2*i/2,point.y()-i_diameter*0.2*i/2,i_diameter*0.2*i,i_diameter*0.2*i);
    }

    pen.setWidthF(0.5);
    QVector<qreal> dashes;
    qreal space=8;
    dashes<<15<<space<<15<<space<<15<<space;
    pen.setDashPattern(dashes);
    pen.setStyle(Qt::CustomDashLine);
    p_painter.setPen(pen);
    for(int i=0; i<12; i++)
    {//辐射线（i=0时的左端点可能是原点位置）
        p_painter.drawLine(point.x(),point.y(),point.x()+i_diameter*0.5*cos(30.0*3.14159/180.0*i),point.y()+i_diameter*0.5*sin(30.0*3.14159/180.0*i));
    }
    bili=i_diameter*0.1/3000;//比例尺
    pen.setColor(QColor(255,255,255));
    p_painter.setPen(pen);
    QFont font=this->font();
    font.setFamily("SongTi");
    font.setBold(true);
    font.setPixelSize(20);
    p_painter.setFont(font);
    p_painter.drawText(this->width()/10-40,this->height()/10-20,"航路显示");
    font=this->font();
    p_painter.setFont(font);
    //    //标注角度
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(0.0*3.14/180),point.y()-i_diameter*0.5*sin(0.0*3.14/180), "90°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(30.0*3.14/180),point.y()-i_diameter*0.5*sin(30.0*3.14/180), " 60°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(60.0*3.14/180),point.y()-i_diameter*0.5*sin(60.0*3.14/180), " 30°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(90.0*3.14/180),point.y()-i_diameter*0.5*sin(90.0*3.14/180), " 0°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(120.0*3.14/180),point.y()-i_diameter*0.5*sin(120.0*3.14/180), " 330°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(150.0*3.14/180),point.y()-i_diameter*0.5*sin(150.0*3.14/180), " 300°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(180.0*3.14/180),point.y()-i_diameter*0.5*sin(180.0*3.14/180), " 270°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(210.0*3.14/180),point.y()-i_diameter*0.5*sin(210.0*3.14/180), " 240°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(240.0*3.14/180),point.y()-i_diameter*0.5*sin(240.0*3.14/180), " 210°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(270.0*3.14/180),point.y()-i_diameter*0.5*sin(270.0*3.14/180), " 180°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(300.0*3.14/180),point.y()-i_diameter*0.5*sin(300.0*3.14/180), " 150°");
    //    p_painter.drawText(point.x()+i_diameter*0.5*cos(330.0*3.14/180),point.y()-i_diameter*0.5*sin(330.0*3.14/180), " 120°");

    //    //标注距离
    //    pen.setColor(Qt::yellow);
    //    p_painter.setPen(pen);
    //    p_painter.drawText(point.x()+2, point.y(), "0");
        p_painter.drawText(point.x()+2, point.y()-i_diameter*0.2*1/2+12, "3km");
    //    p_painter.drawText(point.x()+2, point.y()-i_diameter*0.2*2/2+12, "6km");
        p_painter.drawText(point.x()+2, point.y()-i_diameter*0.2*3/2+12, "9km");
    //    p_painter.drawText(point.x()+2, point.y()-i_diameter*0.2*4/2+12, "12km");
        p_painter.drawText(point.x()+2, point.y()-i_diameter*0.2*5/2+12, "15km");


    //定义圆心和渐变的角度
    //    QConicalGradient conical_gradient(point,(6.28-d_angle)/6.28*720);
    //    conical_gradient.setColorAt(0,Qt::green);
    //    conical_gradient.setColorAt(0.2,QColor(255,255,255,0));
    //    p_painter.setBrush(conical_gradient);
    //    p_painter.drawEllipse(point.x()-i_diameter/2,point.y()-i_diameter/2,i_diameter,i_diameter);

    //计算飞机极坐标


    pen.setColor(Qt::yellow);
    pen.setWidth(1);
    pen.setCapStyle(Qt::RoundCap);
    p_painter.setPen(pen);
    for(int i=0;i<MAX;i++)//画航迹
    {

        if(PathPaint[i].isEmpty()==false)
        {
            if(PathPaint[i][0].IsEnemy==true)
            {
                  pen.setColor(QColor(0x7c,0xfc,0x00));
                pen.setWidth(1);
                p_painter.setPen(pen);
            }
            else
            {
                pen.setColor(QColor(0,191,255));
                pen.setWidth(1);
                p_painter.setPen(pen);
            }
            if(showFlag==true)
            {
                for(int j=0;j<PathPaint[i].size();j++)
                {
                    p_painter.drawPoint(point.x()+PathPaint[i][j].x*bili,point.y()-PathPaint[i][j].y*bili);

                }
            }
            else
            {
                p_painter.drawPoint(point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili,point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili);//单个航迹点
            }

            if(PathPaint[i].size()>=2)
            {
                pointshang[i].setX(PathPaint[i][PathPaint[i].size()-2].x);
                pointshang[i].setY(PathPaint[i][PathPaint[i].size()-2].y);
                pointcurrent[i].setX(PathPaint[i][PathPaint[i].size()-1].x);
                pointcurrent[i].setY(PathPaint[i][PathPaint[i].size()-1].y);
                hjj[i]=PathPaint[i][PathPaint[i].size()-1].Angle;

            }

        }

    }

    // qDebug()<<hjj[0];

    //qDebug()<<hjj[0];
    //将飞旋转
    for(int i=0;i<MAX;i++)
    {
        if(PathPaint[i][0].IsEnemy==true)
        {
            pen.setColor(Qt::yellow);
            p_painter.setPen(pen);
        }
        else
        {
            pen.setColor(QColor(0,191,255));
            p_painter.setPen(pen);
        }
        for(int i1=0;i1<planeAN;i1++)
        {

            TransCoordinate(PlanePoint0[i1],planeR[i1],planetheta[i1]);

        }
        if(PathPaint[i].size()>=2)
        {
            for(int j=0;j<planeAN;j++)
            {
                if((pointcurrent[i].x()-pointshang[i].x()<0)&&(pointcurrent[i].y()-pointshang[i].y()>0))//向左上方运动
                {
                    planetheta[j]=planetheta[j]+hjj[i]+PI;

                    //                    qDebug()<<planetheta[j];
                    //                    qDebug()<<PathPaint[i][PathPaint[i].size()-1].Angle;
                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili+25, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));
                }
                else if((pointcurrent[i].x()-pointshang[i].x()<0)&&(pointcurrent[i].y()-pointshang[i].y()<0))//向左下方运动
                {
                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili+10, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));
                    planetheta[j]=planetheta[j]+hjj[i]-PI;


                }
                else if((pointcurrent[i].x()-pointshang[i].x()<0)&&(abs(pointcurrent[i].y()-pointshang[i].y())==0))//向x轴负方向运动
                {
                    planetheta[j]=planetheta[j]+hjj[i]+PI;
                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili+7, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili-22,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));

                }
                else if((pointcurrent[i].x()-pointshang[i].x()>0)&&(pointcurrent[i].y()-pointshang[i].y())>0)//向右上方运动
                {
                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili+25, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili+12,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));
                    planetheta[j]=planetheta[j]+hjj[i];

                }
                else  if((pointcurrent[i].x()-pointshang[i].x()>0)&&(pointcurrent[i].y()-pointshang[i].y()<0))//向右下方运动
                {
                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili-22, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili-10,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));
                    planetheta[j]=planetheta[j]+hjj[i];
                }
                else  if((pointcurrent[i].x()-pointshang[i].x()==0.0)&&(pointcurrent[i].y()-pointshang[i].y()<0))//向y负方向运动
                {

                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili+4, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili+12,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));
                    planetheta[j]=planetheta[j]-hjj[i];
                }

                else  if((pointcurrent[i].x()-pointshang[i].x()==0.0)&&(pointcurrent[i].y()-pointshang[i].y()>0))//向y负方向运动
                {

                    p_painter.drawText( PlanePoint[i][planeE].x()+point.x()+PathPaint[i][PathPaint[i].size()-1].x*bili+27, PlanePoint[i][planeE].y()+point.y()-PathPaint[i][PathPaint[i].size()-1].y*bili+12,QString::number(PathPaint[i][PathPaint[i].size()-1].TargetID));
                    planetheta[j]=planetheta[j]-hjj[i];
                }

            }
        }
        if(1)
            for(int j=0;j<planeAN;j++)
            {
                //               qDebug()<<j<<"  "<<PlanePoint[i][j];
                //              qDebug()<<j<<"  "<<PlanePoint0[j];
                FeiJiZhuanWanHDZB(PlanePoint[i][j],planeR[j],planetheta[j]);

            }
    }

    for(int i=0;i<MAX;i++)//正式画飞机
    {
        if(PathPaint[i].size()>=2)
        {
            pen.setWidth(1);
            pen.setCapStyle(Qt::RoundCap);
            pen.setStyle(Qt::SolidLine);
            QPointF PlanePoints[]={PlanePoint[i][planeA]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeB]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   PlanePoint[i][planeC]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   PlanePoint[i][planeD]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   PlanePoint[i][planeE]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   PlanePoint[i][planeF]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   PlanePoint[i][planeG]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   PlanePoint[i][planeH]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
                                   //PlanePoi[i]t0[planeAN]+point ,
                                   PlanePoint[i][planeHN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeGN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeFN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeEN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeDN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeCN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                   PlanePoint[i][planeBN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
                                  };
            //               QPointF PlanePoints[]={PlanePoint0[planeA]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili),
            //                                      PlanePoint0[planeB]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      PlanePoint0[planeC]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      PlanePoint0[planeD]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      PlanePoint0[planeE]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      PlanePoint0[planeF]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      PlanePoint0[planeG]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      PlanePoint0[planeH]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)   ,
            //                                      //PlanePoint0[planeAN]+point ,
            //                                      PlanePoint0[planeHN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
            //                                      PlanePoint0[planeGN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
            //                                      PlanePoint0[planeFN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
            //                                      PlanePoint0[planeEN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
            //                                      PlanePoint0[planeDN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
            //                                      PlanePoint0[planeCN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili) ,
            //                                      PlanePoint0[planeBN]+point+QPointF(PathPaint[i][PathPaint[i].size()-1].x*bili,-PathPaint[i][PathPaint[i].size()-1].y*bili)
            //                                     };
                p_painter.setRenderHint(QPainter::Antialiasing);
            if(PathPaint[i][0].IsEnemy==true)
            {
                pen.setColor(Qt::yellow);
                p_painter.setBrush(Qt::SolidPattern);
                p_painter.setBrush(Qt::yellow);
                p_painter.setPen(pen);
            }
            else
            {
//                pen.setColor(QColor(0x87,0xc3,0xfa));
                 pen.setColor(QColor(0,191,255));
                p_painter.setBrush(Qt::SolidPattern);
                p_painter.setBrush(QColor(0,191,255));
                p_painter.setPen(pen);
            }
            p_painter.drawPolygon(PlanePoints,15,Qt::OddEvenFill);
        }
    }
    /************************************************************************************************************/
    //    pen.setWidth(1);                                                                                                            //
    //    pen.setCapStyle(Qt::RoundCap);                                                                                 //
    //    pen.setStyle(Qt::SolidLine);                                                                                         //
    //    p_painter.setPen(pen);                                                                                                 //
    //    QPointF PlanePoints[]={PlanePoint0[planeA]+point,                                               //
    //                           PlanePoint0[planeB]+point  ,                                                              //
    //                           PlanePoint0[planeC]+point  ,                                                              //
    //                           PlanePoint0[planeD]+point  ,                                                              //
    //                           PlanePoint0[planeE]+point  ,                                                                  //
    //                           PlanePoint0[planeF]+point  ,                                                                   //
    //                           PlanePoint0[planeG]+point  ,                                                                  //
    //                           PlanePoint0[planeH]+point  ,                                                                 //
    //                           //PlanePoint0[planeAN]+point ,                                                            //
    //                           PlanePoint0[planeHN]+point,                                                               //
    //                           PlanePoint0[planeGN]+point ,                                                              //
    //                           PlanePoint0[planeFN]+point,                                                               //
    //                           PlanePoint0[planeEN]+point ,                                                              //
    //                           PlanePoint0[planeDN]+point ,                                                              //
    //                           PlanePoint0[planeCN]+point ,                                                              //
    //                           PlanePoint0[planeBN]+point ,                                                              //
    //                          };                                                                                                                  //
    //                                                                                                                                              //
    //                                                                                                                                              //
    //    p_painter.setBrush(Qt::SolidPattern);                                                                       //
    //    p_painter.setBrush(Qt::yellow);                                                                                 //
    //    p_painter.drawPolygon(PlanePoints,15,Qt::OddEvenFill);                                   //
    //                                                                                                                                             //
    //qDebug()<<"time_end="<<timedebug.elapsed()<<"ms";                                           //
    /************************************************************************************************************/
    return pixmap;

}

void RadarWidget::timerTimeOut()
{

    timer->start(5);//刷新率
    d_angle += 3.14/720;
    if(d_angle >= 6.28){
        d_angle = 0;
    }
    update();


}

void RadarWidget::TransCoordinate(QPointF ZuoBiao, qreal &Radius, qreal &JiaoDu)
{
    Radius=sqrt(ZuoBiao.x()*ZuoBiao.x()+ZuoBiao.y()*ZuoBiao.y());
    JiaoDu=qAtan(ZuoBiao.y()/ZuoBiao.x());


}

void RadarWidget::FeiJiZhuanWanHDZB(QPointF &ZuoBiao, qreal Radius, qreal JiaoDu)
{
    ZuoBiao.setX(Radius*qCos(JiaoDu));
    ZuoBiao.setY(-Radius*qSin(JiaoDu));
}



void RadarWidget::recvAPath(flightpathdata aPathData)
{
    switch(aPathData.TargetID)
    {
    case 3001:
        PathPaint[0].push_back(aPathData);
        //qDebug()<<FlightPathDataSave[0][FlightPathDataSave[0].size()-1].x;
        break;
    case 3002:
        PathPaint[1].push_back(aPathData);
        break;
    case 3003:
        PathPaint[2].push_back(aPathData);
        break;
    case 3004:
        PathPaint[3].push_back(aPathData);
        break;
    case 3005:
        PathPaint[4].push_back(aPathData);
        break;
    case 3006:
        PathPaint[5].push_back(aPathData);
        break;
    case 3007:
        PathPaint[6].push_back(aPathData);
        break;
    case 3008:
        PathPaint[7].push_back(aPathData);
    }

}

void RadarWidget::recvShowFlag(bool a)
{
    showFlag=a;
}

void RadarWidget::paintEvent(QPaintEvent *event)
{
    QElapsedTimer time;
    time.start();
    QPainter p_painter(this);
    //反锯齿
    p_painter.setRenderHint(QPainter::Antialiasing);

    p_painter.drawPixmap(0,0,this->width(),this->height(),paintWidget());

    QWidget::paintEvent(event);
    //    qDebug()<<"转一下用了"<<time.elapsed()<<"毫秒";
}

RadarWidget::~RadarWidget()
{

}
