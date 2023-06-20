/********************************************************************************
** Form generated from reading UI file 'recvdatadlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECVDATADLG_H
#define UI_RECVDATADLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <recvradarwidget.h>

QT_BEGIN_NAMESPACE

class Ui_RecvDataDlg
{
public:
    QHBoxLayout *horizontalLayout;
    RecvRadarWidget *widget;

    void setupUi(QDialog *RecvDataDlg)
    {
        if (RecvDataDlg->objectName().isEmpty())
            RecvDataDlg->setObjectName(QStringLiteral("RecvDataDlg"));
        RecvDataDlg->resize(588, 455);
        horizontalLayout = new QHBoxLayout(RecvDataDlg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new RecvRadarWidget();
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);


        retranslateUi(RecvDataDlg);

        QMetaObject::connectSlotsByName(RecvDataDlg);
    } // setupUi

    void retranslateUi(QDialog *RecvDataDlg)
    {
        RecvDataDlg->setWindowTitle(QApplication::translate("RecvDataDlg", "\346\225\260\346\215\256\346\216\245\346\224\266\346\250\241\346\213\237\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecvDataDlg: public Ui_RecvDataDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECVDATADLG_H
