#include "setaflightpath.h"
#include "ui_setaflightpath.h"
#include<QMessageBox>
#include<QDebug>
#pragma execution_character_set("utf-8")

setAFlightPath::setAFlightPath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setAFlightPath)
{
    ui->setupUi(this);
    ui->editID->setText(QString::asprintf(" "));
//    ui->radioHelicopter->setVisible(false);
    setMovementTypecmb();//界面初始化
}


setAFlightPath::~setAFlightPath()
{
    delete ui;
}


void setAFlightPath::on_btnOK_clicked()
{
    ui->editID->setText(QString::asprintf("%d",TargetID+1));
    bool flag,flag1,flag2;//判断有无漏选
    flag1=(ui->radioPlane->isChecked()||ui->radioHelicopter->isChecked());
    flag2=ui->radioenemy->isChecked()||ui->radiooos->isChecked();
    flag=flag1&&flag2&&(ui->editID->text()!="");
    if(flag)//没有漏选，进行下一步判断
    {
        if(ui->cmbType->currentIndex()==zxyd&&(ui->cmbtypex->currentText()=="  "||ui->cmbtypey->currentText()=="  "||ui->cmbtypez->currentText()=="  "))
        {
            QString dlgTitle="提示";
            QString strInfo="各方向运动类型参数有误!";
            QMessageBox::warning(this,dlgTitle,strInfo,QMessageBox::Ok);

        }
        else
        {
            newflightpathdata.TargetID=TargetID;
            newflightpathdata.FlightPathSelect=ui->cmbFlightPath->currentIndex();
            /********************************飞机类型********************************/
            if(ui->radioPlane->isChecked())
            {
                newflightpathdata.TargetType=Plane;
            }
            else
            {
                newflightpathdata.TargetType=Helicopter;
            }

            /*********************************************************************/

            /********************************是否敌人******************************/
            if(ui->radiooos->isChecked())
            {
                newflightpathdata.IsEnemy=oos;
            }
            else
            {
                newflightpathdata.IsEnemy=enemy;
            }
            /*********************************************************************/


            newflightpathdata.x=ui->spinlocx->value();//初始位置
            newflightpathdata.y=ui->spinlocy->value();
            newflightpathdata.z=ui->spinlocz->value();


            newflightpathdata.MotionType=ui->cmbType->currentIndex();
            newflightpathdata.MotionTypex=ui->cmbtypex->currentIndex();
            newflightpathdata.MotionTypey=ui->cmbtypey->currentIndex();
            newflightpathdata.MotionTypez=ui->cmbtypez->currentIndex();
            // qDebug()<<ui->cmbtypez->currentIndex();

            newflightpathdata.vx=ui->spinvx->value();//初始速度
            newflightpathdata.vy=ui->spinvy->value();
            newflightpathdata.vz=ui->spinvz->value();

            newflightpathdata.ax=ui->spinax->value();//加速度
            newflightpathdata.ay=ui->spinay->value();
            newflightpathdata.az=ui->spinaz->value();

            newflightpathdata.wx=ui->spinwx->value();//角速度
            newflightpathdata.wy=ui->spinwy->value();
            newflightpathdata.wz=ui->spinwz->value();

            //        QVariant v;
            //        v.setValue(newflightpathdata);
            emit setSuccessfully(newflightpathdata);//发送信号

            QString dlgTitle="提示";
            QString strInfo="新建航迹成功";
            QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);

            this-> accept();
        }

    }
    else
    {
        QString dlgTitle="提示";
        QString strInfo="信息输入不全，请补充完整";
        QMessageBox::warning(this,dlgTitle,strInfo,QMessageBox::Ok);
    }

}



void setAFlightPath::on_btnCancel_clicked()
{
    this->reject();
}



void setAFlightPath::setMovementTypecmb()
{
    QStringList MovementTypexyz,MovementType,FlightPathSelect;
    MovementType<<"单方向自定义"<<"协同转弯运动"<<"机动运动";
    MovementTypexyz<<"静止"<<"匀速直线"<<"匀加速直线"<<"  ";
    FlightPathSelect<<"航路1"<<"航路2"<<"航路3"<<"航路4"<<"航路5"<<"航路6"<<"航路7"<<"航路8";
    ui->cmbFlightPath->addItems(FlightPathSelect);
    ui->cmbtypex->addItems(MovementTypexyz);   //运动类型
    ui->cmbtypey->addItems(MovementTypexyz);   //运动类型
    ui->cmbtypez->addItems(MovementTypexyz);   //运动类型
    ui->cmbType->addItems(MovementType);   //运动类型
    ui->spinwy->setVisible(false);
    ui->spinwz->setVisible(false);
    ui->label_16->setVisible(false);
    ui->label_17->setVisible(false);
    ui->label_15->setText("ꞷ");
    if(ui->cmbType->currentIndex()==zxyd)
    {
        ui->spinwx->setEnabled(false);
    }
    if(ui->cmbtypex->currentIndex()==jz)
    {
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(false);
        ui->spinvx->setEnabled(false);
        ui->spinvx->setValue(0);
    }
    if(ui->cmbtypey->currentIndex()==jz)
    {
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(false);
        ui->spinvy->setEnabled(false);
        ui->spinvy->setValue(0);
    }
    if(ui->cmbtypez->currentIndex()==jz)
    {
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(false);
        ui->spinvz->setEnabled(false);
        ui->spinvz->setValue(0);
    }

}



void setAFlightPath::mousePressEvent(QMouseEvent *event)
{
  //  ui->editID->setText(QString::asprintf("%d",TargetID));
    //    ui->editID->setEnabled(false);
}



void setAFlightPath::on_cmbType_activated(int index)
{
    if(index==zxyd)
    {

    }

}

void setAFlightPath::on_cmbType_currentIndexChanged(int index)//总的运动类型
{
    if(index==zxyd)//直线运动
    {
        ui->cmbtypex->setCurrentText("静止");
        ui->cmbtypey->setCurrentText("静止");
        ui->cmbtypez->setCurrentText("静止");
        ui->cmbFlightPath->setEnabled(false);
        ui->spinwx->setEnabled(false);
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(true);
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(true);
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(true);
        ui->spinvx->setValue(0);
        ui->spinvx->setEnabled(true);
        ui->spinvy->setValue(0);
        ui->spinvy->setEnabled(true);
        ui->spinvz->setValue(0);
        ui->spinvz->setEnabled(true);

        ui->groupBox_3->setVisible(true);
        ui->groupBox_4->setVisible(true);
        ui->groupBox_5->setVisible(true);
        ui->groupBox_7->setVisible(false);
         ui->groupBox_9->setVisible(false);

        if(ui->cmbtypex->currentIndex()==jz)
        {
            ui->spinax->setValue(0);
            ui->spinax->setEnabled(false);
            ui->spinvx->setEnabled(false);
            ui->spinvx->setValue(0);
        }
        if(ui->cmbtypey->currentIndex()==jz)
        {
            ui->spinay->setValue(0);
            ui->spinay->setEnabled(false);
            ui->spinvy->setEnabled(false);
            ui->spinvy->setValue(0);
        }
        if(ui->cmbtypez->currentIndex()==jz)
        {
            ui->spinaz->setValue(0);
            ui->spinaz->setEnabled(false);
            ui->spinvz->setEnabled(false);
            ui->spinvz->setValue(0);
        }
        ui->cmbtypex->setEnabled(true);
        ui->cmbtypey->setEnabled(true);
        ui->cmbtypez->setEnabled(true);
    }
    else if(index==yszx)//匀速圆周运动
    {
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(false);
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(false);
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(false);
        ui->spinwx->setEnabled(true);
        ui->spinvx->setEnabled(true);
        ui->spinvy->setEnabled(true);
        ui->spinvz->setEnabled(false);
        ui->cmbtypex->setEnabled(false);
        ui->cmbtypey->setEnabled(false);
        ui->cmbtypez->setEnabled(true);
        ui->cmbFlightPath->setEnabled(false);
        ui->cmbtypex->setCurrentText("  ");
        ui->cmbtypey->setCurrentText("  ");
        ui->cmbtypez->setCurrentText("  ");
        ui->groupBox_3->setVisible(true);
        ui->groupBox_4->setVisible(false);
        ui->groupBox_5->setVisible(false);
        ui->groupBox_7->setVisible(true);
         ui->groupBox_9->setVisible(false);

    }
    else if(index==jd)//机动运动
    {
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(false);
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(false);
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(false);
        ui->spinwx->setValue(0);
        ui->spinwx->setEnabled(false);
        ui->spinvx->setValue(30.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(-40.0);
        ui->spinvy->setEnabled(false);
        ui->spinvz->setValue(0);
        ui->spinvz->setEnabled(false);
        ui->cmbtypex->setEnabled(false);
        ui->cmbtypey->setEnabled(false);
        ui->cmbtypez->setEnabled(false);
        ui->cmbFlightPath->setEnabled(true);
        ui->cmbtypex->setCurrentText("  ");
        ui->cmbtypey->setCurrentText("  ");
        ui->cmbtypez->setCurrentText("  ");
        ui->groupBox_3->setVisible(true);
        ui->groupBox_4->setVisible(false);
        ui->groupBox_5->setVisible(true);
        ui->groupBox_7->setVisible(false);
         ui->groupBox_9->setVisible(true);
         ui->spinvz->setValue(-20.0);
         ui->spinvz->setEnabled(false);
         ui->spinlocz->setValue(6320);
    }
}



void setAFlightPath::on_cmbtypex_activated(int index)
{
    if(ui->cmbtypex->currentIndex()==jz)
    {
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(false);
        ui->spinvx->setEnabled(false);
        ui->spinvx->setValue(0);
    }
    else  if(ui->cmbtypex->currentIndex()==yszx)
    {
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(false);
        ui->spinvx->setValue(0);
        ui->spinvx->setEnabled(true);
    }
    else if(ui->cmbtypex->currentIndex()==yjszx)
    {
        ui->spinax->setValue(0);
        ui->spinax->setEnabled(true);
        ui->spinvx->setValue(0);
        ui->spinvx->setEnabled(true);
    }

}

void setAFlightPath::on_cmbtypey_activated(int index)
{
    if(ui->cmbtypey->currentIndex()==jz)
    {
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(false);
        ui->spinvy->setEnabled(false);
        ui->spinvy->setValue(0);
    }
    else  if(ui->cmbtypey->currentIndex()==yszx)
    {
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(false);
        ui->spinvy->setValue(0);
        ui->spinvy->setEnabled(true);
    }
    else if(ui->cmbtypey->currentIndex()==yjszx)
    {
        ui->spinay->setValue(0);
        ui->spinay->setEnabled(true);
        ui->spinvy->setValue(0);
        ui->spinvy->setEnabled(true);
    }
}

void setAFlightPath::on_cmbtypez_activated(int index)
{
    if(ui->cmbtypez->currentIndex()==jz)
    {
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(false);
        ui->spinvz->setEnabled(false);
        ui->spinvz->setValue(0);
    }
    else  if(ui->cmbtypez->currentIndex()==yszx)
    {
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(false);
        ui->spinvz->setValue(0);
        ui->spinvz->setEnabled(true);
    }
    else if(ui->cmbtypez->currentIndex()==yjszx)
    {
        ui->spinaz->setValue(0);
        ui->spinaz->setEnabled(true);
        ui->spinvz->setValue(0);
        ui->spinvz->setEnabled(true);
    }
}

void setAFlightPath::on_editID_returnPressed()
{
    ui->editID->setText(QString::asprintf("%d",TargetID));
}

void setAFlightPath::on_pushButton_clicked()
{
        ui->editID->setText(QString::asprintf("%d",TargetID));
}

void setAFlightPath::on_cmbFlightPath_currentIndexChanged(int index)
{
    ui->spinvz->setValue(-20.0);
    ui->spinvz->setEnabled(false);
    ui->spinlocz->setValue(6320);
    if(ui->cmbFlightPath->currentIndex()==hl1)
    {

        ui->spinlocx->setValue(1000);
        ui->spinlocy->setValue(1000);
        ui->spinvx->setValue(30.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(-40.0);
        ui->spinvy->setEnabled(false);
    }
  else  if(ui->cmbFlightPath->currentIndex()==hl2)
    {
        ui->spinlocx->setValue(1000);
        ui->spinlocy->setValue(-1000);
        ui->spinvx->setValue(30.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(40.0);
        ui->spinvy->setEnabled(false);
    }
else if(ui->cmbFlightPath->currentIndex()==hl3)
    {
        ui->spinvx->setValue(-30.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(40.0);
        ui->spinvy->setEnabled(false);
    }
    else if(ui->cmbFlightPath->currentIndex()==hl4)
    {
        ui->spinvx->setValue(30.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(-40.0);
        ui->spinvy->setEnabled(false);
    }
    else if(ui->cmbFlightPath->currentIndex()==hl5)
    {
        ui->spinlocx->setValue(-2000);
        ui->spinlocy->setValue(1000);
        ui->spinvx->setValue(-40.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(-40.0);
        ui->spinvy->setEnabled(false);
    }
    else if(ui->cmbFlightPath->currentIndex()==hl6)
    {
        ui->spinvx->setValue(30.0);
        ui->spinvx->setEnabled(false);
        ui->spinvy->setValue(-40.0);
        ui->spinvy->setEnabled(false);
    }
    else  if(ui->cmbFlightPath->currentIndex()==hl7)
      {
          ui->spinlocx->setValue(-1000);
          ui->spinlocy->setValue(-1000);
          ui->spinvx->setValue(-30.0);
          ui->spinvx->setEnabled(false);
          ui->spinvy->setValue(-40.0);
          ui->spinvy->setEnabled(false);
      }
}
