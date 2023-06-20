/********************************************************************************
** Form generated from reading UI file 'setaflightpath.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETAFLIGHTPATH_H
#define UI_SETAFLIGHTPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setAFlightPath
{
public:
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QDoubleSpinBox *spinvx;
    QLabel *label_7;
    QDoubleSpinBox *spinvy;
    QLabel *label_8;
    QDoubleSpinBox *spinvz;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QRadioButton *radioHelicopter;
    QRadioButton *radioPlane;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QComboBox *cmbType;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioenemy;
    QRadioButton *radiooos;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *spinlocy;
    QDoubleSpinBox *spinlocz;
    QDoubleSpinBox *spinlocx;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QLabel *label_12;
    QDoubleSpinBox *spinax;
    QLabel *label_13;
    QDoubleSpinBox *spinay;
    QLabel *label_14;
    QDoubleSpinBox *spinaz;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QComboBox *cmbtypex;
    QLabel *label_10;
    QComboBox *cmbtypey;
    QLabel *label_11;
    QComboBox *cmbtypez;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QLabel *label_15;
    QDoubleSpinBox *spinwx;
    QLabel *label_16;
    QDoubleSpinBox *spinwy;
    QLabel *label_17;
    QDoubleSpinBox *spinwz;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editID;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout;
    QComboBox *cmbFlightPath;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnCancel;
    QPushButton *btnOK;

    void setupUi(QDialog *setAFlightPath)
    {
        if (setAFlightPath->objectName().isEmpty())
            setAFlightPath->setObjectName(QStringLiteral("setAFlightPath"));
        setAFlightPath->resize(698, 296);
        groupBox_3 = new QGroupBox(setAFlightPath);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(273, 118, 149, 116));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        spinvx = new QDoubleSpinBox(groupBox_3);
        spinvx->setObjectName(QStringLiteral("spinvx"));
        spinvx->setDecimals(2);
        spinvx->setMinimum(-9999);
        spinvx->setMaximum(9999);
        spinvx->setSingleStep(0.1);
        spinvx->setValue(20);

        gridLayout_4->addWidget(spinvx, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        spinvy = new QDoubleSpinBox(groupBox_3);
        spinvy->setObjectName(QStringLiteral("spinvy"));
        spinvy->setDecimals(2);
        spinvy->setMinimum(-9999);
        spinvy->setMaximum(9999);
        spinvy->setSingleStep(0.1);
        spinvy->setValue(0);

        gridLayout_4->addWidget(spinvy, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        spinvz = new QDoubleSpinBox(groupBox_3);
        spinvz->setObjectName(QStringLiteral("spinvz"));
        spinvz->setDecimals(2);
        spinvz->setMinimum(-9999);
        spinvz->setMaximum(9999);
        spinvz->setSingleStep(0.1);
        spinvz->setValue(0);

        gridLayout_4->addWidget(spinvz, 2, 1, 1, 1);

        groupBox_6 = new QGroupBox(setAFlightPath);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(13, 49, 160, 58));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        radioHelicopter = new QRadioButton(groupBox_6);
        radioHelicopter->setObjectName(QStringLiteral("radioHelicopter"));

        gridLayout_6->addWidget(radioHelicopter, 0, 1, 1, 1);

        radioPlane = new QRadioButton(groupBox_6);
        radioPlane->setObjectName(QStringLiteral("radioPlane"));
        radioPlane->setChecked(true);

        gridLayout_6->addWidget(radioPlane, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(setAFlightPath);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(332, 49, 141, 60));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        cmbType = new QComboBox(groupBox_8);
        cmbType->setObjectName(QStringLiteral("cmbType"));

        gridLayout_8->addWidget(cmbType, 0, 0, 1, 1);

        groupBox = new QGroupBox(setAFlightPath);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(180, 49, 145, 58));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioenemy = new QRadioButton(groupBox);
        radioenemy->setObjectName(QStringLiteral("radioenemy"));
        radioenemy->setChecked(true);

        gridLayout->addWidget(radioenemy, 0, 0, 1, 1);

        radiooos = new QRadioButton(groupBox);
        radiooos->setObjectName(QStringLiteral("radiooos"));

        gridLayout->addWidget(radiooos, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(setAFlightPath);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(13, 118, 117, 116));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        spinlocy = new QDoubleSpinBox(groupBox_2);
        spinlocy->setObjectName(QStringLiteral("spinlocy"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinlocy->sizePolicy().hasHeightForWidth());
        spinlocy->setSizePolicy(sizePolicy);
        spinlocy->setAccelerated(true);
        spinlocy->setMinimum(-99999);
        spinlocy->setMaximum(99999);

        gridLayout_3->addWidget(spinlocy, 1, 1, 1, 1);

        spinlocz = new QDoubleSpinBox(groupBox_2);
        spinlocz->setObjectName(QStringLiteral("spinlocz"));
        sizePolicy.setHeightForWidth(spinlocz->sizePolicy().hasHeightForWidth());
        spinlocz->setSizePolicy(sizePolicy);
        spinlocz->setMinimum(-99999);
        spinlocz->setMaximum(99999);

        gridLayout_3->addWidget(spinlocz, 2, 1, 1, 1);

        spinlocx = new QDoubleSpinBox(groupBox_2);
        spinlocx->setObjectName(QStringLiteral("spinlocx"));
        sizePolicy.setHeightForWidth(spinlocx->sizePolicy().hasHeightForWidth());
        spinlocx->setSizePolicy(sizePolicy);
        spinlocx->setFocusPolicy(Qt::ClickFocus);
        spinlocx->setWrapping(true);
        spinlocx->setFrame(true);
        spinlocx->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinlocx->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinlocx->setMinimum(-99999);
        spinlocx->setMaximum(99999);
        spinlocx->setValue(10);

        gridLayout_3->addWidget(spinlocx, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        groupBox_5 = new QGroupBox(setAFlightPath);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(429, 118, 117, 116));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        spinax = new QDoubleSpinBox(groupBox_5);
        spinax->setObjectName(QStringLiteral("spinax"));

        gridLayout_5->addWidget(spinax, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 1, 0, 1, 1);

        spinay = new QDoubleSpinBox(groupBox_5);
        spinay->setObjectName(QStringLiteral("spinay"));

        gridLayout_5->addWidget(spinay, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_5->addWidget(label_14, 2, 0, 1, 1);

        spinaz = new QDoubleSpinBox(groupBox_5);
        spinaz->setObjectName(QStringLiteral("spinaz"));

        gridLayout_5->addWidget(spinaz, 2, 1, 1, 1);

        groupBox_4 = new QGroupBox(setAFlightPath);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(137, 118, 126, 116));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        cmbtypex = new QComboBox(groupBox_4);
        cmbtypex->setObjectName(QStringLiteral("cmbtypex"));

        gridLayout_2->addWidget(cmbtypex, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        cmbtypey = new QComboBox(groupBox_4);
        cmbtypey->setObjectName(QStringLiteral("cmbtypey"));

        gridLayout_2->addWidget(cmbtypey, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        cmbtypez = new QComboBox(groupBox_4);
        cmbtypez->setObjectName(QStringLiteral("cmbtypez"));

        gridLayout_2->addWidget(cmbtypez, 2, 1, 1, 1);

        groupBox_7 = new QGroupBox(setAFlightPath);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(561, 118, 121, 116));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_7->addWidget(label_15, 0, 0, 1, 1);

        spinwx = new QDoubleSpinBox(groupBox_7);
        spinwx->setObjectName(QStringLiteral("spinwx"));

        gridLayout_7->addWidget(spinwx, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_7->addWidget(label_16, 1, 0, 1, 1);

        spinwy = new QDoubleSpinBox(groupBox_7);
        spinwy->setObjectName(QStringLiteral("spinwy"));

        gridLayout_7->addWidget(spinwy, 1, 1, 1, 1);

        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_7->addWidget(label_17, 2, 0, 1, 1);

        spinwz = new QDoubleSpinBox(groupBox_7);
        spinwz->setObjectName(QStringLiteral("spinwz"));

        gridLayout_7->addWidget(spinwz, 2, 1, 1, 1);

        layoutWidget = new QWidget(setAFlightPath);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 11, 360, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        editID = new QLineEdit(layoutWidget);
        editID->setObjectName(QStringLiteral("editID"));
        editID->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editID->sizePolicy().hasHeightForWidth());
        editID->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(editID);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        groupBox_9 = new QGroupBox(setAFlightPath);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(480, 49, 111, 60));
        verticalLayout = new QVBoxLayout(groupBox_9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cmbFlightPath = new QComboBox(groupBox_9);
        cmbFlightPath->setObjectName(QStringLiteral("cmbFlightPath"));

        verticalLayout->addWidget(cmbFlightPath);

        layoutWidget1 = new QWidget(setAFlightPath);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(230, 240, 195, 30));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnCancel = new QPushButton(layoutWidget1);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_5->addWidget(btnCancel);

        btnOK = new QPushButton(layoutWidget1);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_5->addWidget(btnOK);


        retranslateUi(setAFlightPath);

        QMetaObject::connectSlotsByName(setAFlightPath);
    } // setupUi

    void retranslateUi(QDialog *setAFlightPath)
    {
        setAFlightPath->setWindowTitle(QApplication::translate("setAFlightPath", "\350\276\223\345\205\245\350\210\252\350\267\257\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("setAFlightPath", "\345\210\235\345\247\213\351\200\237\345\272\246(m/s)", Q_NULLPTR));
        label_6->setText(QApplication::translate("setAFlightPath", "vx:", Q_NULLPTR));
        label_7->setText(QApplication::translate("setAFlightPath", "vy:", Q_NULLPTR));
        label_8->setText(QApplication::translate("setAFlightPath", "vz:", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("setAFlightPath", "\347\233\256\346\240\207\347\261\273\345\236\213", Q_NULLPTR));
        radioHelicopter->setText(QApplication::translate("setAFlightPath", "\347\233\264\345\215\207\346\234\272", Q_NULLPTR));
        radioPlane->setText(QApplication::translate("setAFlightPath", "\351\243\236\346\234\272", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("setAFlightPath", "\350\277\220\345\212\250\347\261\273\345\236\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("setAFlightPath", "\346\230\257\345\220\246\344\270\272\346\225\214\346\226\271", Q_NULLPTR));
        radioenemy->setText(QApplication::translate("setAFlightPath", "\346\225\214\346\226\271", Q_NULLPTR));
        radiooos->setText(QApplication::translate("setAFlightPath", "\345\267\261\346\226\271", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("setAFlightPath", "\345\210\235\345\247\213\344\275\215\347\275\256(m)", Q_NULLPTR));
        label_3->setText(QApplication::translate("setAFlightPath", "x:", Q_NULLPTR));
        label_5->setText(QApplication::translate("setAFlightPath", "y:", Q_NULLPTR));
        label_4->setText(QApplication::translate("setAFlightPath", "z:", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("setAFlightPath", "\345\212\240\351\200\237\345\272\246(m/s^2)", Q_NULLPTR));
        label_12->setText(QApplication::translate("setAFlightPath", "ax", Q_NULLPTR));
        label_13->setText(QApplication::translate("setAFlightPath", "ay", Q_NULLPTR));
        label_14->setText(QApplication::translate("setAFlightPath", "az", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("setAFlightPath", "\345\220\204\346\226\271\345\220\221\350\277\220\345\212\250\347\261\273\345\236\213", Q_NULLPTR));
        label_9->setText(QApplication::translate("setAFlightPath", "x", Q_NULLPTR));
        label_10->setText(QApplication::translate("setAFlightPath", "y", Q_NULLPTR));
        label_11->setText(QApplication::translate("setAFlightPath", "z", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("setAFlightPath", "\350\247\222\351\200\237\345\272\246(m/s^2)", Q_NULLPTR));
        label_15->setText(QApplication::translate("setAFlightPath", "\352\236\267x", Q_NULLPTR));
        label_16->setText(QApplication::translate("setAFlightPath", "\352\236\267y", Q_NULLPTR));
        label_17->setText(QApplication::translate("setAFlightPath", "\352\236\267z", Q_NULLPTR));
        label->setText(QApplication::translate("setAFlightPath", "ID\345\217\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("setAFlightPath", "\345\210\267\346\226\260ID", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("setAFlightPath", "\350\210\252\350\267\257\351\200\211\346\213\251", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("setAFlightPath", "\345\217\226\346\266\210", Q_NULLPTR));
        btnOK->setText(QApplication::translate("setAFlightPath", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class setAFlightPath: public Ui_setAFlightPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETAFLIGHTPATH_H
