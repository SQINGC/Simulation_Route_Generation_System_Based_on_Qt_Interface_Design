/********************************************************************************
** Form generated from reading UI file 'connectDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDLG_H
#define UI_CONNECTDLG_H

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

class Ui_connectDlg
{
public:
    QLabel *label;
    QLineEdit *editTargetAddress;
    QLabel *label_2;
    QLineEdit *editTargetPort;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *connectDlg)
    {
        if (connectDlg->objectName().isEmpty())
            connectDlg->setObjectName(QStringLiteral("connectDlg"));
        connectDlg->resize(380, 130);
        label = new QLabel(connectDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 81, 16));
        editTargetAddress = new QLineEdit(connectDlg);
        editTargetAddress->setObjectName(QStringLiteral("editTargetAddress"));
        editTargetAddress->setGeometry(QRect(110, 20, 141, 31));
        label_2 = new QLabel(connectDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 30, 61, 16));
        editTargetPort = new QLineEdit(connectDlg);
        editTargetPort->setObjectName(QStringLiteral("editTargetPort"));
        editTargetPort->setGeometry(QRect(310, 20, 61, 31));
        btnOk = new QPushButton(connectDlg);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(220, 90, 93, 28));
        btnCancel = new QPushButton(connectDlg);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(70, 90, 93, 28));

        retranslateUi(connectDlg);

        QMetaObject::connectSlotsByName(connectDlg);
    } // setupUi

    void retranslateUi(QDialog *connectDlg)
    {
        connectDlg->setWindowTitle(QApplication::translate("connectDlg", "\350\276\223\345\205\245\346\216\245\346\224\266\346\226\271\345\234\260\345\235\200", Q_NULLPTR));
        label->setText(QApplication::translate("connectDlg", "\346\216\245\346\224\266\347\253\257\345\234\260\345\235\200", Q_NULLPTR));
        editTargetAddress->setText(QApplication::translate("connectDlg", "172.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("connectDlg", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        editTargetPort->setText(QApplication::translate("connectDlg", "3000", Q_NULLPTR));
        btnOk->setText(QApplication::translate("connectDlg", "\347\241\256\350\256\244", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("connectDlg", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class connectDlg: public Ui_connectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDLG_H
