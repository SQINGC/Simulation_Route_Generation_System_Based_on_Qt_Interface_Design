#ifndef QFLIGHTPATH_H
#define QFLIGHTPATH_H

#include <QMainWindow>
#include<setaflightpath.h>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<flightpathdata.h>
#include<QDateTime>
#include<QTimer>
#include<vector>
#include<QTableWidgetItem>
#include<QMessageBox>
#include<mythread.h>
#include<QThread>
#include<sendflightpathdata.h>
#include<QFile>
#include<recvdatadlg.h>

#define targetMaximumCount  8//航迹最大数量

namespace Ui {
class QFlightPath;
}

class QFlightPath : public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsScene *scene;//绘图场景
    QTimer *fTimer;//定时器
    QTime fTimeCounterFlightPath[15];//航迹计时器
    QGraphicsLineItem *axisX,*axisY;//坐标轴
    QGraphicsEllipseItem *Circle1,*Circle2;//两个圆
    std::vector<std::vector<FlightPathData>> FlightPathDataSave;//用于每条航迹的数据存储
    std::vector<QTableWidgetItem*>aItemLocation;//表格中关于当前位置的项
    std::vector<QTableWidgetItem*>aItemVelocity;//表格中关于运动速度的项
     std::vector<QTableWidgetItem*>aItemAcceleration;//表格中关于运动距离的项
    std::vector<QGraphicsPathItem*>aItemPath;//路径元素
    //    std::vector<QPainterPath>aFlightPainterPath;//路径，如果卡的话就改这个为数组试试
    int Tcounter;//机动运动的时间计数器

    RecvDataDlg *NewRecvDlg;

    StartMotion *startmotion[targetMaximumCount];

    SendFlightPathData *newSend;

    void recvFlightPathData(flightpathdata);

    QRectF ViewRect;
    qreal ViewRectWidth,ViewRectHight;//View宽度和长度
    int currentFlightPathCount;//当前航迹数

    bool showFlag;

    int paintPathFlag;//开始绘制航迹图标志

    QPen pathPen[targetMaximumCount];

    int paintCircleFlag;//是否要添加圆
    int lineToPathFlag;//是否要添加路线
    int paintAxisFlag;//是否要添加坐标轴
    int iniPointFlag;//是否要移到起始点
    int setPenFlag;//是否要SetPen
    int resizeFlag;//是否进行了resize
    int aItemPathRefreshFlag;//是否重新创立aItemPath

    int newTargetID;
    setAFlightPath *addaNewFlight;

    //自定义单元格Type的类型，在创建单元格的item时使用
    enum CellType{ctTargetID=1000,ctTargetType,ctIsEnemy,ctLocation,ctVelocity,ctMotionType,ctAcceleration,ctAngleVelocity};
    //各字段在表格中的列号
    enum FlightcolNum{colTargetID,colTargetType,colIsEnemy,colLocation,colMotionType,colVelocity,colAcceleration,colAngleVelocity};

public:
    explicit QFlightPath(QWidget *parent = nullptr);
    ~QFlightPath();


    QRectF rectFlightPathView;//获取FlightPathView的矩形

    std::vector<QTableWidgetItem*> item;//用于更新表格中的距离项

    void iniPathSystem();


    void paintAxis();//绘制坐标轴

    //void recvA

    bool saveTextByStream(const QString &aFileName);

    //void ReceiveAFlightPath(FlightPathData *a);

protected:
    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *event);

    void ThisStartTime();//显示时间开始计时

    void iniFlightPathTable();//初始化航迹数据表格

    void WriteNewToFlightPathTable(int rowNum,FlightPathData aFlightPath);//把航迹数据写入表格中

    void UpdateFlightPathTable(int, flightpathdata);//在表格中更新航迹数据(测试）

    void UpdateFligthPathTable(int rowNo,flightpathdata);//更新表格数据




    //    void paintEvent(QPaintEvent *event);

    int btnflagTest;//绘图标志

private:
    QString strMotionType(FlightPathData aFlightPath);//返回目标的运动类型

private slots:
    void on_actionAddFlightPath_triggered();

    void on_ReceptAFlightPath(FlightPathData apath);//收到一条航迹

    void on_btnDisplayFlightPath_clicked();

    void UpdateFlightPathData();//更新每条航迹数据

    void DisplayDateTime();//显示时间



signals:

    void SendAPath(flightpathdata);

    void Startup();

    void SendShowFlag(bool);

private:
    Ui::QFlightPath *ui;

    QThread m_thread[8];

    /******************test专用代码块*****************/
public:

private:



private slots:


    void on_btnHideFlightPath_clicked();

    void on_btnSend_clicked();

    void on_btnDisconnect_clicked();

    void on_actionCalification_triggered();

    void on_btnSavelog_clicked();

    void on_pushButton_clicked();

protected:

};

#endif // QFLIGHTPATH_H
