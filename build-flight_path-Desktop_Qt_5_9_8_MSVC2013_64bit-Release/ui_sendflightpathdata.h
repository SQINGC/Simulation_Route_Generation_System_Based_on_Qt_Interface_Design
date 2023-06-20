/********************************************************************************
** Form generated from reading UI file 'sendflightpathdata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDFLIGHTPATHDATA_H
#define UI_SENDFLIGHTPATHDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SendFlightPathData
{
public:
    QLabel *label;
    QLineEdit *editRecvAddress;
    QLabel *label_2;
    QLineEdit *editRecvPort;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *SendFlightPathData)
    {
        if (SendFlightPathData->objectName().isEmpty())
            SendFlightPathData->setObjectName(QStringLiteral("SendFlightPathData"));
        SendFlightPathData->resize(380, 130);
        label = new QLabel(SendFlightPathData);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 81, 16));
        editRecvAddress = new QLineEdit(SendFlightPathData);
        editRecvAddress->setObjectName(QStringLiteral("editRecvAddress"));
        editRecvAddress->setGeometry(QRect(110, 20, 141, 31));
        label_2 = new QLabel(SendFlightPathData);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 30, 61, 16));
        editRecvPort = new QLineEdit(SendFlightPathData);
        editRecvPort->setObjectName(QStringLiteral("editRecvPort"));
        editRecvPort->setGeometry(QRect(310, 20, 61, 31));
        btnOk = new QPushButton(SendFlightPathData);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(220, 90, 93, 28));
        btnCancel = new QPushButton(SendFlightPathData);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(70, 90, 93, 28));

        retranslateUi(SendFlightPathData);

        QMetaObject::connectSlotsByName(SendFlightPathData);
    } // setupUi

    void retranslateUi(QDialog *SendFlightPathData)
    {
        SendFlightPathData->setWindowTitle(QApplication::translate("SendFlightPathData", "\350\276\223\345\205\245\346\216\245\346\224\266\346\226\271\345\234\260\345\235\200", Q_NULLPTR));
        label->setText(QApplication::translate("SendFlightPathData", "\346\216\245\346\224\266\347\253\257\345\234\260\345\235\200", Q_NULLPTR));
        editRecvAddress->setText(QApplication::translate("SendFlightPathData", "192.168.1.104", Q_NULLPTR));
        label_2->setText(QApplication::translate("SendFlightPathData", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        editRecvPort->setText(QApplication::translate("SendFlightPathData", "1200", Q_NULLPTR));
        btnOk->setText(QApplication::translate("SendFlightPathData", "\347\241\256\350\256\244", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("SendFlightPathData", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SendFlightPathData: public Ui_SendFlightPathData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDFLIGHTPATHDATA_H
