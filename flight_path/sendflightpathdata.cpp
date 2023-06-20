#include "sendflightpathdata.h"
#include "ui_sendflightpathdata.h"
#include<QMessageBox>
#pragma execution_character_set("utf-8")

SendFlightPathData::SendFlightPathData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendFlightPathData)
{
    ui->setupUi(this);
}

SendFlightPathData::~SendFlightPathData()
{
    delete ui;
}

void SendFlightPathData::on_btnCancel_clicked()
{
    this->reject();
}

void SendFlightPathData::on_btnOk_clicked()
{
    QString dlgTitle="提示";
    QString strInfo="连接成功";
    QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);
    this->accept();
}
