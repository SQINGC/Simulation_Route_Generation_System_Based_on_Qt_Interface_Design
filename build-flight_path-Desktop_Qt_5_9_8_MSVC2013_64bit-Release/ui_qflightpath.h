/********************************************************************************
** Form generated from reading UI file 'qflightpath.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFLIGHTPATH_H
#define UI_QFLIGHTPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <radarwidget.h>
#include <timewidget.h>

QT_BEGIN_NAMESPACE

class Ui_QFlightPath
{
public:
    QAction *actionAddFlightPath;
    QAction *actionCalification;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QPushButton *btnDisplayFlightPath;
    QPushButton *btnHideFlightPath;
    QPushButton *btnSend;
    QPushButton *btnDisconnect;
    QPushButton *btnSavelog;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *editlog;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *FlightPathTable;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    TimeWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *LCDYear;
    QLabel *label_3;
    QLCDNumber *LCDMonth;
    QLabel *label_4;
    QLCDNumber *LCDDay;
    QLabel *label_5;
    QLCDNumber *LCDHour;
    QLabel *label;
    QLCDNumber *LCDMin;
    QLabel *label_2;
    QLCDNumber *LCDSec;
    QSpacerItem *horizontalSpacer;
    RadarWidget *Radar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QFlightPath)
    {
        if (QFlightPath->objectName().isEmpty())
            QFlightPath->setObjectName(QStringLiteral("QFlightPath"));
        QFlightPath->resize(958, 593);
        actionAddFlightPath = new QAction(QFlightPath);
        actionAddFlightPath->setObjectName(QStringLiteral("actionAddFlightPath"));
        actionCalification = new QAction(QFlightPath);
        actionCalification->setObjectName(QStringLiteral("actionCalification"));
        actionQuit = new QAction(QFlightPath);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(QFlightPath);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout_2->addLayout(verticalLayout_3, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        btnDisplayFlightPath = new QPushButton(centralWidget);
        btnDisplayFlightPath->setObjectName(QStringLiteral("btnDisplayFlightPath"));

        verticalLayout_2->addWidget(btnDisplayFlightPath);

        btnHideFlightPath = new QPushButton(centralWidget);
        btnHideFlightPath->setObjectName(QStringLiteral("btnHideFlightPath"));

        verticalLayout_2->addWidget(btnHideFlightPath);

        btnSend = new QPushButton(centralWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        verticalLayout_2->addWidget(btnSend);

        btnDisconnect = new QPushButton(centralWidget);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));

        verticalLayout_2->addWidget(btnDisconnect);

        btnSavelog = new QPushButton(centralWidget);
        btnSavelog->setObjectName(QStringLiteral("btnSavelog"));

        verticalLayout_2->addWidget(btnSavelog);

        verticalSpacer_2 = new QSpacerItem(20, 134, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        editlog = new QPlainTextEdit(groupBox_4);
        editlog->setObjectName(QStringLiteral("editlog"));
        editlog->setEnabled(true);

        verticalLayout_4->addWidget(editlog);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        FlightPathTable = new QTableWidget(groupBox_2);
        FlightPathTable->setObjectName(QStringLiteral("FlightPathTable"));
        FlightPathTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FlightPathTable->sizePolicy().hasHeightForWidth());
        FlightPathTable->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        FlightPathTable->setFont(font);
        FlightPathTable->setSortingEnabled(false);

        horizontalLayout_4->addWidget(FlightPathTable);


        verticalLayout_5->addWidget(groupBox_2);


        gridLayout_2->addWidget(groupBox_3, 0, 3, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new TimeWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        LCDYear = new QLCDNumber(widget);
        LCDYear->setObjectName(QStringLiteral("LCDYear"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LCDYear->sizePolicy().hasHeightForWidth());
        LCDYear->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(7);
        LCDYear->setFont(font1);
        LCDYear->setFrameShape(QFrame::NoFrame);
        LCDYear->setSmallDecimalPoint(false);
        LCDYear->setDigitCount(4);
        LCDYear->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCDYear);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        LCDMonth = new QLCDNumber(widget);
        LCDMonth->setObjectName(QStringLiteral("LCDMonth"));
        sizePolicy2.setHeightForWidth(LCDMonth->sizePolicy().hasHeightForWidth());
        LCDMonth->setSizePolicy(sizePolicy2);
        LCDMonth->setFont(font1);
        LCDMonth->setFrameShape(QFrame::NoFrame);
        LCDMonth->setSmallDecimalPoint(false);
        LCDMonth->setDigitCount(2);
        LCDMonth->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCDMonth);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout->addWidget(label_4);

        LCDDay = new QLCDNumber(widget);
        LCDDay->setObjectName(QStringLiteral("LCDDay"));
        LCDDay->setFrameShape(QFrame::NoFrame);
        LCDDay->setSmallDecimalPoint(false);
        LCDDay->setDigitCount(2);
        LCDDay->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCDDay);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        LCDHour = new QLCDNumber(widget);
        LCDHour->setObjectName(QStringLiteral("LCDHour"));
        LCDHour->setFrameShape(QFrame::NoFrame);
        LCDHour->setFrameShadow(QFrame::Raised);
        LCDHour->setSmallDecimalPoint(false);
        LCDHour->setDigitCount(2);
        LCDHour->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCDHour);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        LCDMin = new QLCDNumber(widget);
        LCDMin->setObjectName(QStringLiteral("LCDMin"));
        LCDMin->setFrameShape(QFrame::NoFrame);
        LCDMin->setSmallDecimalPoint(false);
        LCDMin->setDigitCount(2);
        LCDMin->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCDMin);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(7);
        font2.setKerning(true);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        LCDSec = new QLCDNumber(widget);
        LCDSec->setObjectName(QStringLiteral("LCDSec"));
        LCDSec->setFrameShape(QFrame::NoFrame);
        LCDSec->setSmallDecimalPoint(false);
        LCDSec->setDigitCount(2);
        LCDSec->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(LCDSec);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        Radar = new RadarWidget(groupBox);
        Radar->setObjectName(QStringLiteral("Radar"));

        verticalLayout->addWidget(Radar);


        gridLayout_2->addWidget(groupBox, 0, 4, 1, 1);

        QFlightPath->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QFlightPath);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QFlightPath->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QFlightPath);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFlightPath->setStatusBar(statusBar);

        mainToolBar->addAction(actionAddFlightPath);
        mainToolBar->addAction(actionCalification);
        mainToolBar->addAction(actionQuit);

        retranslateUi(QFlightPath);

        QMetaObject::connectSlotsByName(QFlightPath);
    } // setupUi

    void retranslateUi(QMainWindow *QFlightPath)
    {
        QFlightPath->setWindowTitle(QApplication::translate("QFlightPath", "\346\250\241\346\213\237\350\210\252\350\267\257\347\224\237\346\210\220\347\263\273\347\273\237V1.0", Q_NULLPTR));
        actionAddFlightPath->setText(QApplication::translate("QFlightPath", "\346\267\273\345\212\240\350\210\252\350\267\257", Q_NULLPTR));
        actionCalification->setText(QApplication::translate("QFlightPath", "\346\240\241\345\207\206\346\227\266\351\227\264", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("QFlightPath", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QFlightPath", "\346\267\273\345\212\240\350\210\252\350\267\257", Q_NULLPTR));
        btnDisplayFlightPath->setText(QApplication::translate("QFlightPath", "\346\230\276\347\244\272\350\210\252\350\277\271", Q_NULLPTR));
        btnHideFlightPath->setText(QApplication::translate("QFlightPath", "\351\232\220\350\227\217\350\210\252\350\277\271", Q_NULLPTR));
        btnSend->setText(QApplication::translate("QFlightPath", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
        btnDisconnect->setText(QApplication::translate("QFlightPath", "\345\201\234\346\255\242\345\217\221\351\200\201", Q_NULLPTR));
        btnSavelog->setText(QApplication::translate("QFlightPath", "\345\255\230\345\202\250\346\227\245\345\277\227", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QApplication::translate("QFlightPath", "\346\227\245\345\277\227", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QFlightPath", "\347\233\256\346\240\207\344\277\241\346\201\257", Q_NULLPTR));
        label_3->setText(QApplication::translate("QFlightPath", "\345\271\264", Q_NULLPTR));
        label_4->setText(QApplication::translate("QFlightPath", "\346\234\210", Q_NULLPTR));
        label_5->setText(QApplication::translate("QFlightPath", "\346\227\245", Q_NULLPTR));
        label->setText(QApplication::translate("QFlightPath", "\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("QFlightPath", "\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QFlightPath: public Ui_QFlightPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFLIGHTPATH_H
