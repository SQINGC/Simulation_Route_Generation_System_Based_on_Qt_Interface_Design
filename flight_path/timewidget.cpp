#include "timewidget.h"
#include<QPalette>

TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent)
{

}


void TimeWidget::paintEvent(QPaintEvent *event)
{
    QPalette pal(this->palette());

    pal.setColor(QPalette::Background, Qt::white); //设置背景黑色
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
}
