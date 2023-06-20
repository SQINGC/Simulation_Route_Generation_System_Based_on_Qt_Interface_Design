#ifndef SENDFLIGHTPATHDATA_H
#define SENDFLIGHTPATHDATA_H

#include <QDialog>

namespace Ui {
class SendFlightPathData;
}

class SendFlightPathData : public QDialog
{
    Q_OBJECT

public:
    explicit SendFlightPathData(QWidget *parent = nullptr);
    ~SendFlightPathData();

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::SendFlightPathData *ui;
};

#endif // SENDFLIGHTPATHDATA_H
