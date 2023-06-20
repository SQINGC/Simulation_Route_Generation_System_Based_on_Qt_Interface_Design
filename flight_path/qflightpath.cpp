#include "qflightpath.h"
#include "ui_qflightpath.h"
#include<QPalette>
#include<QDebug>
#include<QChar>
#include<QGraphicsOpacityEffect>
#include<QtMath>
#include<QtCharts/QtCharts>


#pragma execution_character_set("utf-8")





QFlightPath::QFlightPath(QWidget *parent) ://构造函数
    QMainWindow(parent),
    ui(new Ui::QFlightPath)
{
    ui->setupUi(this);

    iniPathSystem();
    iniFlightPathTable();
    ThisStartTime();//设置定时器以及关联槽函数

}

QFlightPath::~QFlightPath()
{
    for(int i=0;i<targetMaximumCount;i++)
    {
        m_thread[i].quit();
        m_thread[i].wait();
    }
    delete ui;
}

void QFlightPath::iniPathSystem()//初始化系统
{
    newTargetID=3001;
    addaNewFlight=new setAFlightPath;//创建一个新窗口
    connect(addaNewFlight,&setAFlightPath::setSuccessfully,this,&QFlightPath::on_ReceptAFlightPath);//关联新数据
    aItemLocation.resize(targetMaximumCount);//表格
    aItemVelocity.resize(targetMaximumCount);
    aItemAcceleration.resize(targetMaximumCount);
    FlightPathDataSave.resize(targetMaximumCount);//航迹数据保存
    currentFlightPathCount=0;
    Tcounter=0;
    for(int i=0;i<targetMaximumCount;i++)
    {
        startmotion[i]=new StartMotion;//有targetMaximumCount个“子程序”（忘了那个叫什么了）
        startmotion[i]->moveToThread(&m_thread[i]);//创建子线程
    }
    showFlag=false;

    newSend =new SendFlightPathData();

    connect(this,&QFlightPath::SendShowFlag,ui->Radar,&RadarWidget::recvShowFlag);
    emit SendShowFlag(showFlag);
    NewRecvDlg=new RecvDataDlg;

}





void QFlightPath::paintAxis()
{

}

bool QFlightPath::saveTextByStream(const QString &aFileName)
{
    //用QTextStream保存文本文件
    QFile aFile(aFileName);
    if(!aFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        return false;
    }
    QTextStream aStream(&aFile);//用文本流读取文件
    aStream.setAutoDetectUnicode(true);//自动检测Unicode
    QString str=ui->editlog->toPlainText();
    aStream<<str;//写入文本流
    aFile.close();//关闭文件
    return true;

}

void QFlightPath::on_actionAddFlightPath_triggered()//打开添加一条新航迹的对话框
{
    //添加航迹
    addaNewFlight->TargetID=newTargetID;

    if(currentFlightPathCount==8)
    {
        QString dlgTitle="提示";
        QString strInfo=QString::asprintf("最大航迹数为%d条，无法添加",targetMaximumCount);
        QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);
        return;
    }
    int ret =addaNewFlight->exec();
    if(ret==QDialog::Accepted)
    {
        newTargetID++;
    }
}

void QFlightPath::resizeEvent(QResizeEvent *event)
{


}

void QFlightPath::paintEvent(QPaintEvent *event)
{
    QPalette pal(this->palette());

    pal.setColor(QPalette::Background, QColor(225,255,255)); //设置背景黑色
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
//    QPixmap pixmap = QPixmap(":/backgroud.png").scaled(this->size());
//       QPainter painter(this);
//       painter.drawPixmap(this->rect(), pixmap);


}

void QFlightPath::on_btnDisplayFlightPath_clicked()
{
    showFlag=1;
      emit SendShowFlag(showFlag);

}

void QFlightPath::on_ReceptAFlightPath(flightpathdata aFlightpath)//接收到一个新目标槽函数
{
    QString str;
    str="************************";
    ui->editlog->appendPlainText(str);
    ui->editlog->appendPlainText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    ui->editlog->appendPlainText(QString::asprintf("创建航迹成功,当前航迹数为：%d",currentFlightPathCount+1));
    str=QString::asprintf("%d",aFlightpath.TargetID);
    ui->editlog->appendPlainText("目标ID："+str+"\n");
    str=QString::asprintf("初始位置 \nx:%.2fm, \ny:%.2fm,  \nz:%.2fm;\n",aFlightpath.x,aFlightpath.y,aFlightpath.z);
    ui->editlog->appendPlainText(str);
    QString TargetType;
    switch(aFlightpath.TargetType)
    {
    case setAFlightPath::Plane:
        TargetType="飞机";
        break;
    case setAFlightPath::Helicopter:
        TargetType="直升机";
        break;

    }
    str=QString("目标类型:"+TargetType);
    ui->editlog->appendPlainText(str);
    if(aFlightpath.IsEnemy)
    {
        str=QString("目标是否为敌方：是\n");
    }
    else {
        str=QString("是否为敌方：否\n");
    }
    ui->editlog->appendPlainText(str);
    str=QString("运动类型：\n")+strMotionType(aFlightpath);
    ui->editlog->appendPlainText(str);
    str=QString::asprintf("初始速度 \nx:%.2fm/s, \ny:%.2fm/s,  \nz:%.2fm/s;\n",aFlightpath.vx,aFlightpath.vy,aFlightpath.vz);
    ui->editlog->appendPlainText(str);
//    str=QString::asprintf("加速度 \nx:%.2fm/s^2, \ny:%.2fm/s^2,  \nz:%.2fm/s^2\n;",aFlightpath.ax,aFlightpath.ay,aFlightpath.az);
//    ui->editlog->appendPlainText(str);
//    str=QString::asprintf("角速度 \nx:%.2frad/s, \ny:%.2frad/s,  \nz:%.2frad/s\n;",aFlightpath.wx,aFlightpath.wy,aFlightpath.wz);
//    ui->editlog->appendPlainText(str);
    str="************************\n";
    ui->editlog->appendPlainText(str);
    int row=ui->FlightPathTable->rowCount();//行数
    WriteNewToFlightPathTable(row,aFlightpath);
    FlightPathDataSave[currentFlightPathCount].push_back(aFlightpath);

    connect(this,&QFlightPath::SendAPath,startmotion[currentFlightPathCount],&StartMotion::recvAFlightData);//将产生的航迹数据发送到对应的子线程
    connect(&m_thread[currentFlightPathCount],SIGNAL(started()),startmotion[currentFlightPathCount],SLOT(working()));//在启动子线程的时候创建定时器
    connect(&m_thread[currentFlightPathCount],&QThread::finished,startmotion[currentFlightPathCount],&QObject::deleteLater);//不知道这句是干嘛的
    m_thread[currentFlightPathCount].start();//启动子线程
    emit SendAPath(FlightPathDataSave[currentFlightPathCount][0]);
    disconnect(this,&QFlightPath::SendAPath,startmotion[currentFlightPathCount],&StartMotion::recvAFlightData);//断开链接，避免每个子线程重复接收数据

    connect(startmotion[currentFlightPathCount],&StartMotion::sendFlightPathData,this,&QFlightPath::recvFlightPathData);//接收子线程发送的数据
    connect(startmotion[currentFlightPathCount],&StartMotion::sendFlightPathData,ui->Radar,&RadarWidget::recvAPath);

    connect(startmotion[currentFlightPathCount],&StartMotion::sendFlightPathData,NewRecvDlg,&RecvDataDlg::recvaData);

    currentFlightPathCount++;
}

void QFlightPath::recvFlightPathData(flightpathdata aPathData)
{
    switch(aPathData.TargetID)
    {
    case 3001:
        FlightPathDataSave[0].push_back(aPathData);
        //qDebug()<<FlightPathDataSave[0][FlightPathDataSave[0].size()-1].x;
        break;
    case 3002:
        FlightPathDataSave[1].push_back(aPathData);
        break;
    case 3003:
        FlightPathDataSave[2].push_back(aPathData);
        break;
    case 3004:
        FlightPathDataSave[3].push_back(aPathData);
        break;
    case 3005:
        FlightPathDataSave[4].push_back(aPathData);
        break;
    case 3006:
        FlightPathDataSave[5].push_back(aPathData);
        break;
    case 3007:
        FlightPathDataSave[6].push_back(aPathData);
        break;
    case 3008:
        FlightPathDataSave[7].push_back(aPathData);
    }
}


QString QFlightPath::strMotionType(FlightPathData aFlightPath)//返回目标运动类型
{
    QString str,strx,stry,strz;
    switch(aFlightPath.MotionType)
    {
    case setAFlightPath::zxyd:
        switch(aFlightPath.MotionTypex)
        {
        case setAFlightPath::jz:
            strx=QString("x方向：静止");
            break;
        case setAFlightPath::yszx:
            strx=QString("x方向：匀速直线运动");
            break;
        case setAFlightPath::yjszx:
            strx=QString("x方向：匀速加速运动");
            break;
        }
        switch(aFlightPath.MotionTypey)
        {
        case setAFlightPath::jz:
            stry=QString("y方向：静止");
            break;
        case setAFlightPath::yszx:
            stry=QString("y方向：匀速直线运动");
            break;
        case setAFlightPath::yjszx:
            stry=QString("y方向：匀速加速运动");
            break;
        }
        switch(aFlightPath.MotionTypez)
        {
        case setAFlightPath::jz:
            strz=QString("z方向：静止");
            break;
        case setAFlightPath::yszx:
            strz=QString("z方向：匀速直线运动");
            break;
        case setAFlightPath::yjszx:
            strz=QString("z方向：匀速加速运动");
            break;
        }
        break;
    case setAFlightPath::ysyz:
        strx=QString("协同转弯运动");
        break;
    case setAFlightPath::jd:
        strx=QString("机动运动");
        break;

    }

    str=strx+"\n"+stry+"\n"+strz+"\n";
    return str;
}



void QFlightPath::ThisStartTime()//设置定时器以及关联槽函数
{
    fTimer=new QTimer(this);

    fTimer->stop();
    fTimer->setInterval(100);//定时周期
    connect(fTimer,SIGNAL(timeout()),this,SLOT(DisplayDateTime()));
    connect(fTimer,SIGNAL(timeout()),this,SLOT(UpdateFlightPathData()));
    fTimer->start();
}


void QFlightPath::DisplayDateTime()//更新时间显示的槽函数
{
    //显示系统日期和时间
    QTime curTime=QTime::currentTime();//获取当前时间

    /********************************显示时******************************/
    if(curTime.hour()>=10)
    {
        ui->LCDHour->display(curTime.hour());
    }
    else
    {
        QString str=QString("%1").arg(curTime.hour(),2,10,QChar('0'));
        ui->LCDHour->display(str);
    }

    /********************************显示分******************************/
    if(curTime.minute()>=10)
    {
        ui->LCDMin->display(curTime.minute());
    }
    else
    {
        QString str=QString("%1").arg(curTime.minute(),2,10,QChar('0'));
        ui->LCDMin->display(str);
    }

    /********************************显示秒******************************/
    if(curTime.second()>=10)
    {
        ui->LCDSec->display(curTime.second());
    }
    else
    {
        QString str=QString("%1").arg(curTime.second(),2,10,QChar('0'));
        ui->LCDSec->display(str);
    }

    QDate curDate=QDate::currentDate();

    /********************************显示年******************************/
    ui->LCDYear->display(curDate.year());

    /********************************显示月******************************/
    if(curDate.month()>=10)
    {
        ui->LCDMonth->display(curDate.month());
    }
    else
    {
        QString str=QString("%1").arg(curDate.month(),2,10,QChar('0'));
        ui->LCDMonth->display(str);
    }

    /********************************显示日******************************/
    if(curDate.day()>=10)
    {
        ui->LCDDay->display(curDate.day());
    }
    else
    {
        QString str=QString("%1").arg(curDate.day(),2,10,QChar('0'));
        ui->LCDDay->display(str);
    }
}


void QFlightPath::iniFlightPathTable()//初始化航迹数据表格
{
    //设置表头
    QTableWidgetItem *headerItem;//
    QStringList headerText;
    headerText<<"目标ID"<<"目标类型"<<"目标属性"<<"当前位置(/m)"<<"运动类型"<<"当前速度/(m/s)"<<"当前加速度(/m^2)"<<"当前角速度(rad/s)";
    ui->FlightPathTable->setColumnCount(headerText.count());
    for(int i=0;i<ui->FlightPathTable->columnCount();i++)
    {
        headerItem=new QTableWidgetItem(headerText.at(i));
        QFont font=headerItem->font();
        font.setBold(false);//设置为粗体
        font.setPointSize(10);//字体大小
        headerItem->setTextColor(Qt::black);//字体颜色
        headerItem->setFont(font);//设置字体
        ui->FlightPathTable->setHorizontalHeaderItem(i,headerItem);
    }
    ui->FlightPathTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->FlightPathTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //    ui->FlightPathTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}


void QFlightPath::WriteNewToFlightPathTable(int row,flightpathdata aFlightPath)//在表格中写入一条新航迹数据
{
    ui->FlightPathTable->insertRow(row);//在最后面的行中加入一行
    //为一行的单元格创建itemNewNews
    QTableWidgetItem *itemNew;
    QString str;
    //    uint a=100;

    /********************************TargetID******************************/
    itemNew=new QTableWidgetItem(str.setNum(aFlightPath.TargetID),ctTargetID);
    itemNew->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //    itemNew->setData(Qt::UserRole,QVariant(a));
    ui->FlightPathTable->setItem(row,colTargetID,itemNew);

    /********************************目标类型******************************/
    if(aFlightPath.TargetType==addaNewFlight->Plane)
    {
        itemNew=new QTableWidgetItem(str.sprintf("%s","飞机"),ctTargetType);
    }
    if(aFlightPath.TargetType==addaNewFlight->Helicopter)
    {
        itemNew=new QTableWidgetItem(str.sprintf("%s","直升机"),ctTargetType);
    }

    itemNew->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //    itemNew->setData(Qt::UserRole,QVariant(a));
    ui->FlightPathTable->setItem(row,colTargetType,itemNew);

    /********************************是否敌方******************************/
    if(aFlightPath.IsEnemy==addaNewFlight->enemy)
    {
        itemNew=new QTableWidgetItem(str.sprintf("%s","敌方"),ctIsEnemy);
    }
    if(aFlightPath.IsEnemy==addaNewFlight->oos)
    {
        itemNew=new QTableWidgetItem(str.sprintf("%s","己方"),ctIsEnemy);
    }

    itemNew->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //    itemNew->setData(Qt::UserRole,QVariant(a));
    ui->FlightPathTable->setItem(row,colIsEnemy,itemNew);

    /********************************初始位置******************************/
    //   str.clear();
    itemNew=new QTableWidgetItem(str.sprintf("x:%.2f\ny:%.2f\nz:%.2f",aFlightPath.x,aFlightPath.y,aFlightPath.z),ctLocation);

    itemNew->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    //    itemNew->setData(Qt::UserRole,QVariant(a));
    ui->FlightPathTable->setItem(row,colLocation,itemNew);

    /********************************运动类型******************************/

    QString strx,stry,strz;
    if(aFlightPath.MotionType==addaNewFlight->zxyd)
    {
    /*********************************x方向*******************************/
    if(aFlightPath.MotionTypex==addaNewFlight->jz)
    {
        itemNew=new QTableWidgetItem(strx.sprintf("x:%s\n","静止"),ctMotionType);
    }
    if(aFlightPath.MotionTypex==addaNewFlight->yszx)
    {
        itemNew=new QTableWidgetItem(strx.sprintf("x:%s\n","匀速直线运动"),ctMotionType);
    }
    if(aFlightPath.MotionTypex==addaNewFlight->yjszx)
    {
        itemNew=new QTableWidgetItem(strx.sprintf("x:%s\n","匀加速直线运动"),ctMotionType);
    }


    /*********************************y方向*******************************/
    if(aFlightPath.MotionTypey==addaNewFlight->jz)
    {
        itemNew=new QTableWidgetItem(stry.sprintf("y:%s\n","静止"),ctMotionType);
    }
    if(aFlightPath.MotionTypey==addaNewFlight->yszx)
    {
        itemNew=new QTableWidgetItem(stry.sprintf("y:%s\n","匀速直线运动"),ctMotionType);
    }
    if(aFlightPath.MotionTypey==addaNewFlight->yjszx)
    {
        itemNew=new QTableWidgetItem(stry.sprintf("y:%s\n","匀加速直线运动"),ctMotionType);
    }

    /*********************************z方向*******************************/
    if(aFlightPath.MotionTypez==addaNewFlight->jz)
    {
        itemNew=new QTableWidgetItem(strz.sprintf("z:%s","静止"),ctMotionType);
    }
    if(aFlightPath.MotionTypez==addaNewFlight->yszx)
    {
        itemNew=new QTableWidgetItem(strz.sprintf("z:%s","匀速直线运动"),ctMotionType);
    }
    if(aFlightPath.MotionTypez==addaNewFlight->yjszx)
    {
        itemNew=new QTableWidgetItem(strz.sprintf("z:%s","匀加速直线运动"),ctMotionType);
    }
    str=strx+stry+strz;
    itemNew=new QTableWidgetItem(str,ctMotionType);
    itemNew->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    //    itemNew->setData(Qt::UserRole,QVariant(a));
    ui->FlightPathTable->setItem(row,colMotionType,itemNew);
}
    else if(aFlightPath.MotionType==addaNewFlight->ysyz)
    {
          itemNew=new QTableWidgetItem(strx.sprintf("协同转弯运动"),ctMotionType);
           ui->FlightPathTable->setItem(row,colMotionType,itemNew);
    }
    else
    {
        itemNew=new QTableWidgetItem(strx.sprintf("机动运动"),ctMotionType);
         ui->FlightPathTable->setItem(row,colMotionType,itemNew);
    }
    /*********************************当前速度*******************************/
    itemNew=new QTableWidgetItem(str.sprintf("x:%.2f\ny:%.2f\nz:%.2f",aFlightPath.vx,aFlightPath.vy,aFlightPath.vz),ctVelocity);
    itemNew->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    ui->FlightPathTable->setItem(row,colVelocity,itemNew);

    /*********************************加速度*******************************/
    itemNew=new QTableWidgetItem(str.sprintf("x:%.2f\ny:%.2f\nz:%.2f",aFlightPath.ax,aFlightPath.ay,aFlightPath.az),ctAcceleration);
    itemNew->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    ui->FlightPathTable->setItem(row,colAcceleration,itemNew);

    /*********************************角速度*******************************/
    itemNew=new QTableWidgetItem(str.sprintf("%.2f\n",aFlightPath.wx),ctAngleVelocity);
    itemNew->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    ui->FlightPathTable->setItem(row,colAngleVelocity,itemNew);
}



void QFlightPath::UpdateFlightPathTable(int rowNo, flightpathdata aFlightPathData)//更新航迹数据表
{
    QString str;
    str=QString::asprintf("x:%.2f\ny:%.2f\nz:%.2f",aFlightPathData.x,aFlightPathData.y,aFlightPathData.z);

    aItemLocation[rowNo]=new QTableWidgetItem(str,ctLocation);
    ui->FlightPathTable->setItem(rowNo,colLocation,aItemLocation[rowNo]);

    str=QString::asprintf("x:%.2f\ny:%.2f\nz:%.2f",aFlightPathData.vx,aFlightPathData.vy,aFlightPathData.vz);
    aItemVelocity[rowNo]=new QTableWidgetItem(str,ctVelocity);
    ui->FlightPathTable->setItem(rowNo,colVelocity,aItemVelocity[rowNo]);

    str=QString::asprintf("x:%.2f\ny:%.2f\nz:%.2f",aFlightPathData.ax*10,aFlightPathData.ay*10,aFlightPathData.az*10);
    aItemAcceleration[rowNo]=new QTableWidgetItem(str,ctAcceleration);
    ui->FlightPathTable->setItem(rowNo,colAcceleration,aItemAcceleration[rowNo]);
    //    itemTest->setText(str);
    //    itemTest=new QTableWidgetItem(str,ctLocation);
    //    ui->FlightPathTable->setItem(rowNo,colLocation,itemTest);

}


/******************************test*********************************************/


void QFlightPath::UpdateFlightPathData()
{
    for(int i=0;i<currentFlightPathCount;i++)
    {

        int FlightPathDataSaveCount=FlightPathDataSave[i].size();
        //  FlightPathDataSave[i].push_back(Motion(FlightPathDataSave[i][FlightPathDataSaveCount-1]));
        //emit SendPaths(FlightPathDataSave[i][FlightPathDataSave[i].size()]);
        UpdateFlightPathTable(i,FlightPathDataSave[i][(FlightPathDataSaveCount-1)]);


    }
}



void QFlightPath::on_btnHideFlightPath_clicked()
{
    showFlag=0;
    emit SendShowFlag(showFlag);
}

void QFlightPath::on_btnSend_clicked()
{
newSend->exec();


NewRecvDlg->show();
}

void QFlightPath::on_btnDisconnect_clicked()
{
    QString dlgTitle="提示";
    QString strInfo="连接断开";
    QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);
    NewRecvDlg->close();
}

void QFlightPath::on_actionCalification_triggered()
{
    QString dlgTitle="提示";
    QDateTime currentTime;
    QString strInfo="校准时间成功，当前时间为"+currentTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);
}

void QFlightPath::on_btnSavelog_clicked()
{
    QString curPath=QDir::currentPath();
    QString dlgTitle="保存日志";
    QString filter="txt文件(*.txt)";
    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if(aFileName.isEmpty())
    {
        return;
    }
    saveTextByStream(aFileName);

   dlgTitle="提示";
    QDateTime currentTime;
    QString strInfo="日志存储成功！";
    QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);
}

void QFlightPath::on_pushButton_clicked()
{
    //添加航迹
    addaNewFlight->TargetID=newTargetID;

    if(currentFlightPathCount==8)
    {
        QString dlgTitle="提示";
        QString strInfo=QString::asprintf("最大航迹数为%d条，无法添加",targetMaximumCount);
        QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);
        return;
    }
    int ret =addaNewFlight->exec();
    if(ret==QDialog::Accepted)
    {
        newTargetID++;
    }
}
