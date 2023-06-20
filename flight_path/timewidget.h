#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QObject>
#include <QWidget>

class TimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TimeWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // TIMEWIDGET_H
