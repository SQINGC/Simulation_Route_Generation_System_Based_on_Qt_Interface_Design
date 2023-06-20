#include "recvdatadlg.h"
#include "ui_recvdatadlg.h"

RecvDataDlg::RecvDataDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecvDataDlg)
{
    ui->setupUi(this);
    connect(this,&RecvDataDlg::SuggestedData,ui->widget,&RecvRadarWidget::recvAPath);
}

RecvDataDlg::~RecvDataDlg()
{
    delete ui;
}

void RecvDataDlg::recvaData(flightpathdata a)
{
    flightpathdataSave=a;
    emit SuggestedData(flightpathdataSave);
}
