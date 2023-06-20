#include "qflightpath.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<flightpathdata>("flightpathdata");
     qRegisterMetaType<FlightPathData>("FlightPathData");
    QFlightPath w;
    w.show();

    return a.exec();
}
