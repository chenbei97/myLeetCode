/********************************************************************************
** Form generated from reading UI file 'portConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTCONFIG_H
#define UI_PORTCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_portConfig
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QComboBox *availPortsComboBox;
    QVBoxLayout *verticalLayout;
    QLabel *portNumberId;
    QLabel *portLocation;
    QLabel *portDesrciption;
    QLabel *portManufacturer;
    QLabel *portVendor;
    QLabel *portProductId;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *portBaudRate;
    QComboBox *portBaudRateCombo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *portDataBits;
    QComboBox *portDataBitsCombo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *portParity;
    QComboBox *portParityCombo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *portStopBit;
    QComboBox *portStopBitCombo;
    QHBoxLayout *horizontalLayout_5;
    QLabel *portFlowControl;
    QComboBox *portFlowControlCombo;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnConfigSure;

    void setupUi(QDialog *portConfig)
    {
        if (portConfig->objectName().isEmpty())
            portConfig->setObjectName(QStringLiteral("portConfig"));
        portConfig->resize(1000, 350);
        portConfig->setMinimumSize(QSize(1000, 350));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        portConfig->setFont(font);
        gridLayout_3 = new QGridLayout(portConfig);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(portConfig);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(450, 330));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        availPortsComboBox = new QComboBox(groupBox);
        availPortsComboBox->setObjectName(QStringLiteral("availPortsComboBox"));
        availPortsComboBox->setMinimumSize(QSize(300, 30));

        verticalLayout_2->addWidget(availPortsComboBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        portNumberId = new QLabel(groupBox);
        portNumberId->setObjectName(QStringLiteral("portNumberId"));
        portNumberId->setMinimumSize(QSize(300, 30));

        verticalLayout->addWidget(portNumberId);

        portLocation = new QLabel(groupBox);
        portLocation->setObjectName(QStringLiteral("portLocation"));
        portLocation->setMinimumSize(QSize(300, 30));

        verticalLayout->addWidget(portLocation);

        portDesrciption = new QLabel(groupBox);
        portDesrciption->setObjectName(QStringLiteral("portDesrciption"));
        portDesrciption->setMinimumSize(QSize(300, 30));

        verticalLayout->addWidget(portDesrciption);

        portManufacturer = new QLabel(groupBox);
        portManufacturer->setObjectName(QStringLiteral("portManufacturer"));
        portManufacturer->setMinimumSize(QSize(300, 30));

        verticalLayout->addWidget(portManufacturer);

        portVendor = new QLabel(groupBox);
        portVendor->setObjectName(QStringLiteral("portVendor"));
        portVendor->setMinimumSize(QSize(300, 30));

        verticalLayout->addWidget(portVendor);

        portProductId = new QLabel(groupBox);
        portProductId->setObjectName(QStringLiteral("portProductId"));
        portProductId->setMinimumSize(QSize(300, 30));

        verticalLayout->addWidget(portProductId);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(portConfig);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(450, 330));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        portBaudRate = new QLabel(groupBox_2);
        portBaudRate->setObjectName(QStringLiteral("portBaudRate"));
        portBaudRate->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(portBaudRate);

        portBaudRateCombo = new QComboBox(groupBox_2);
        portBaudRateCombo->setObjectName(QStringLiteral("portBaudRateCombo"));
        portBaudRateCombo->setMinimumSize(QSize(200, 30));

        horizontalLayout->addWidget(portBaudRateCombo);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        portDataBits = new QLabel(groupBox_2);
        portDataBits->setObjectName(QStringLiteral("portDataBits"));
        portDataBits->setMinimumSize(QSize(150, 30));

        horizontalLayout_2->addWidget(portDataBits);

        portDataBitsCombo = new QComboBox(groupBox_2);
        portDataBitsCombo->setObjectName(QStringLiteral("portDataBitsCombo"));
        portDataBitsCombo->setMinimumSize(QSize(200, 30));

        horizontalLayout_2->addWidget(portDataBitsCombo);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        portParity = new QLabel(groupBox_2);
        portParity->setObjectName(QStringLiteral("portParity"));
        portParity->setMinimumSize(QSize(150, 30));

        horizontalLayout_3->addWidget(portParity);

        portParityCombo = new QComboBox(groupBox_2);
        portParityCombo->setObjectName(QStringLiteral("portParityCombo"));
        portParityCombo->setMinimumSize(QSize(200, 30));

        horizontalLayout_3->addWidget(portParityCombo);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        portStopBit = new QLabel(groupBox_2);
        portStopBit->setObjectName(QStringLiteral("portStopBit"));
        portStopBit->setMinimumSize(QSize(150, 30));

        horizontalLayout_4->addWidget(portStopBit);

        portStopBitCombo = new QComboBox(groupBox_2);
        portStopBitCombo->setObjectName(QStringLiteral("portStopBitCombo"));
        portStopBitCombo->setMinimumSize(QSize(200, 30));

        horizontalLayout_4->addWidget(portStopBitCombo);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        portFlowControl = new QLabel(groupBox_2);
        portFlowControl->setObjectName(QStringLiteral("portFlowControl"));
        portFlowControl->setMinimumSize(QSize(150, 30));

        horizontalLayout_5->addWidget(portFlowControl);

        portFlowControlCombo = new QComboBox(groupBox_2);
        portFlowControlCombo->setObjectName(QStringLiteral("portFlowControlCombo"));
        portFlowControlCombo->setMinimumSize(QSize(200, 30));

        horizontalLayout_5->addWidget(portFlowControlCombo);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        btnConfigSure = new QPushButton(groupBox_2);
        btnConfigSure->setObjectName(QStringLiteral("btnConfigSure"));
        btnConfigSure->setMinimumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(btnConfigSure);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);


        retranslateUi(portConfig);

        QMetaObject::connectSlotsByName(portConfig);
    } // setupUi

    void retranslateUi(QDialog *portConfig)
    {
        portConfig->setWindowTitle(QApplication::translate("portConfig", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("portConfig", "\351\200\211\346\213\251\344\270\262\345\217\243", Q_NULLPTR));
        portNumberId->setText(QApplication::translate("portConfig", "\344\270\262\345\217\243\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        portLocation->setText(QApplication::translate("portConfig", "\344\270\262\345\217\243\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        portDesrciption->setText(QApplication::translate("portConfig", "\346\217\217\350\277\260\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        portManufacturer->setText(QApplication::translate("portConfig", "\345\210\266\351\200\240\345\225\206\357\274\232", Q_NULLPTR));
        portVendor->setText(QApplication::translate("portConfig", "\344\276\233\345\272\224\345\225\206\357\274\232", Q_NULLPTR));
        portProductId->setText(QApplication::translate("portConfig", "\344\272\247\345\223\201\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("portConfig", "\344\270\262\345\217\243\351\205\215\347\275\256", Q_NULLPTR));
        portBaudRate->setText(QApplication::translate("portConfig", "BaudRate\357\274\232", Q_NULLPTR));
        portDataBits->setText(QApplication::translate("portConfig", "Data Bit\357\274\232", Q_NULLPTR));
        portParity->setText(QApplication::translate("portConfig", "Parity\357\274\232", Q_NULLPTR));
        portStopBit->setText(QApplication::translate("portConfig", "Stop Bit\357\274\232", Q_NULLPTR));
        portFlowControl->setText(QApplication::translate("portConfig", "Flow Control\357\274\232", Q_NULLPTR));
        btnConfigSure->setText(QApplication::translate("portConfig", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class portConfig: public Ui_portConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTCONFIG_H
