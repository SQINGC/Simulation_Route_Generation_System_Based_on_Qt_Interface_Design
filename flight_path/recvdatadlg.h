#ifndef RECVDATADLG_H
#define RECVDATADLG_H

#include <QDialog>
#include<flightpathdata.h>

namespace Ui {
class RecvDataDlg;
}

class RecvDataDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RecvDataDlg(QWidget *parent = nullptr);
    ~RecvDataDlg();

public:
    void recvaData(flightpathdata);
    flightpathdata flightpathdataSave;

signals:
   void  SuggestedData(flightpathdata);

public:
    Ui::RecvDataDlg *ui;
};

#endif // RECVDATADLG_H
