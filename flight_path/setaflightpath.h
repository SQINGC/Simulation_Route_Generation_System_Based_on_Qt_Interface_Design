#ifndef SETAFLIGHTPATH_H
#define SETAFLIGHTPATH_H
//设置一条航迹
#include <QDialog>
#include<QPushButton>
#include<QComboBox>
#include"flightpathdata.h"

namespace Ui {
class setAFlightPath;
}

class setAFlightPath : public QDialog
{
    Q_OBJECT

public:
    explicit setAFlightPath(QWidget *parent = nullptr);
    ~setAFlightPath();

    enum TargetType{zeroTarget,Plane,Helicopter};//目标类型
    enum IsEnemy{oos,enemy};//目标是否为敌方
    enum MovemenType{zxyd,ysyz,jd};
    enum MovementTypexyz{jz,yszx,yjszx};//匀速直线，匀加速直线
    enum FlightPathSelect{hl1,hl2,hl3,hl4,hl5,hl6,hl7,hl8,hl9};//航路选择

    int TargetID;


private:
    FlightPathData newflightpathdata;//用来存储新的航迹数据

    void setMovementTypecmb();//添加选项函数

    void mousePressEvent(QMouseEvent *event);

//QObject *obj=new QComboBox;
//QComboBox* cmbbox=qobject_cast<QComboBox *>(obj);



private slots:
    void on_btnOK_clicked();

    void on_btnCancel_clicked();

    void on_cmbType_activated(int index);

    void on_cmbType_currentIndexChanged(int index);



    void on_cmbtypex_activated(int index);

    void on_cmbtypey_activated(int index);

    void on_cmbtypez_activated(int index);

    void on_editID_returnPressed();

    void on_pushButton_clicked();

    void on_cmbFlightPath_currentIndexChanged(int index);

signals:
   void setSuccessfully(FlightPathData data);//设置成功

private:
    Ui::setAFlightPath *ui;
};

#endif // SETAFLIGHTPATH_H
