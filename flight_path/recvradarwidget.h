#ifndef RECVRADARWIDGET_H
#define RECVRADARWIDGET_H
#include<radarwidget.h>


class RecvRadarWidget : public RadarWidget
{
public:
    RecvRadarWidget(RadarWidget *parent=nullptr);

    QPixmap paintWidget();
};

#endif // RECVRADARWIDGET_H
