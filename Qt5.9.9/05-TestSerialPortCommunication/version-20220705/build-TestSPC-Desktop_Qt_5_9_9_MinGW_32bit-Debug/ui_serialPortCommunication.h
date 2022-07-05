/********************************************************************************
** Form generated from reading UI file 'serialPortCommunication.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTCOMMUNICATION_H
#define UI_SERIALPORTCOMMUNICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortCommunication
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_Input1;
    QDoubleSpinBox *Input1;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Input2_PS;
    QDoubleSpinBox *Input2PS;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Input2_EL;
    QDoubleSpinBox *Input2EL;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Input3_PS;
    QDoubleSpinBox *powInputPS;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Input3_EL;
    QDoubleSpinBox *powInputEL;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openPowerSupply;
    QPushButton *closePowerSupply;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QComboBox *serialNameBox;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QComboBox *serialBaudRateBox;
    QVBoxLayout *verticalLayout_7;
    QPushButton *openSerialPort;
    QPushButton *closeSerialPort;
    QLabel *label_Ouput2;
    QDoubleSpinBox *Ouput2;
    QLabel *label_Ouput1;
    QDoubleSpinBox *Ouput1;
    QDoubleSpinBox *powOuput;
    QLabel *label_Ouput3;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *powerStatus;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *rbton;
    QRadioButton *rbtoff;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_4;
    QLabel *workMode;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbtCV;
    QRadioButton *rbtCC;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *workStatus;
    QCheckBox *checkBoxCV;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBoxCCPos;
    QCheckBox *checkBoxCCNeg;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBoxCPPos;
    QCheckBox *checkBoxCPNeg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SerialPortCommunication)
    {
        if (SerialPortCommunication->objectName().isEmpty())
            SerialPortCommunication->setObjectName(QStringLiteral("SerialPortCommunication"));
        SerialPortCommunication->resize(1050, 640);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        SerialPortCommunication->setFont(font);
        centralwidget = new QWidget(SerialPortCommunication);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 490, 741, 91));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_Input1 = new QLabel(widget);
        label_Input1->setObjectName(QStringLiteral("label_Input1"));
        label_Input1->setMinimumSize(QSize(120, 30));
        label_Input1->setMaximumSize(QSize(120, 30));

        verticalLayout_14->addWidget(label_Input1);

        Input1 = new QDoubleSpinBox(widget);
        Input1->setObjectName(QStringLiteral("Input1"));
        Input1->setMinimumSize(QSize(80, 30));
        Input1->setMaximumSize(QSize(80, 30));

        verticalLayout_14->addWidget(Input1);


        horizontalLayout_6->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Input2_PS = new QLabel(widget);
        label_Input2_PS->setObjectName(QStringLiteral("label_Input2_PS"));
        label_Input2_PS->setMinimumSize(QSize(120, 30));
        label_Input2_PS->setMaximumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(label_Input2_PS);

        Input2PS = new QDoubleSpinBox(widget);
        Input2PS->setObjectName(QStringLiteral("Input2PS"));
        Input2PS->setMinimumSize(QSize(80, 30));
        Input2PS->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(Input2PS);


        verticalLayout_15->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Input2_EL = new QLabel(widget);
        label_Input2_EL->setObjectName(QStringLiteral("label_Input2_EL"));
        label_Input2_EL->setMinimumSize(QSize(120, 30));
        label_Input2_EL->setMaximumSize(QSize(120, 30));

        horizontalLayout_3->addWidget(label_Input2_EL);

        Input2EL = new QDoubleSpinBox(widget);
        Input2EL->setObjectName(QStringLiteral("Input2EL"));
        Input2EL->setMinimumSize(QSize(80, 30));
        Input2EL->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(Input2EL);


        verticalLayout_15->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Input3_PS = new QLabel(widget);
        label_Input3_PS->setObjectName(QStringLiteral("label_Input3_PS"));
        label_Input3_PS->setMinimumSize(QSize(120, 30));
        label_Input3_PS->setMaximumSize(QSize(120, 30));

        horizontalLayout_4->addWidget(label_Input3_PS);

        powInputPS = new QDoubleSpinBox(widget);
        powInputPS->setObjectName(QStringLiteral("powInputPS"));
        powInputPS->setMinimumSize(QSize(80, 30));
        powInputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(powInputPS);


        verticalLayout_16->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Input3_EL = new QLabel(widget);
        label_Input3_EL->setObjectName(QStringLiteral("label_Input3_EL"));
        label_Input3_EL->setMinimumSize(QSize(120, 30));
        label_Input3_EL->setMaximumSize(QSize(120, 30));

        horizontalLayout_5->addWidget(label_Input3_EL);

        powInputEL = new QDoubleSpinBox(widget);
        powInputEL->setObjectName(QStringLiteral("powInputEL"));
        powInputEL->setMinimumSize(QSize(80, 30));
        powInputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(powInputEL);


        verticalLayout_16->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_16);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 240, 162, 88));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        openPowerSupply = new QPushButton(widget1);
        openPowerSupply->setObjectName(QStringLiteral("openPowerSupply"));
        openPowerSupply->setMinimumSize(QSize(160, 40));
        openPowerSupply->setMaximumSize(QSize(160, 40));

        verticalLayout_2->addWidget(openPowerSupply);

        closePowerSupply = new QPushButton(widget1);
        closePowerSupply->setObjectName(QStringLiteral("closePowerSupply"));
        closePowerSupply->setMinimumSize(QSize(160, 40));
        closePowerSupply->setMaximumSize(QSize(160, 40));

        verticalLayout_2->addWidget(closePowerSupply);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 350, 166, 240));
        verticalLayout = new QVBoxLayout(widget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_13 = new QLabel(widget2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(160, 20));
        label_13->setMaximumSize(QSize(160, 20));
        label_13->setSizeIncrement(QSize(160, 20));

        verticalLayout_5->addWidget(label_13);

        serialNameBox = new QComboBox(widget2);
        serialNameBox->setObjectName(QStringLiteral("serialNameBox"));
        serialNameBox->setMinimumSize(QSize(160, 40));
        serialNameBox->setMaximumSize(QSize(160, 40));

        verticalLayout_5->addWidget(serialNameBox);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_14 = new QLabel(widget2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(160, 20));
        label_14->setMaximumSize(QSize(160, 20));

        verticalLayout_6->addWidget(label_14);

        serialBaudRateBox = new QComboBox(widget2);
        serialBaudRateBox->setObjectName(QStringLiteral("serialBaudRateBox"));
        serialBaudRateBox->setMinimumSize(QSize(160, 40));
        serialBaudRateBox->setMaximumSize(QSize(160, 40));

        verticalLayout_6->addWidget(serialBaudRateBox);


        verticalLayout_8->addLayout(verticalLayout_6);


        verticalLayout->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        openSerialPort = new QPushButton(widget2);
        openSerialPort->setObjectName(QStringLiteral("openSerialPort"));
        openSerialPort->setMinimumSize(QSize(160, 40));
        openSerialPort->setMaximumSize(QSize(160, 40));

        verticalLayout_7->addWidget(openSerialPort);

        closeSerialPort = new QPushButton(widget2);
        closeSerialPort->setObjectName(QStringLiteral("closeSerialPort"));
        closeSerialPort->setMinimumSize(QSize(160, 40));
        closeSerialPort->setMaximumSize(QSize(160, 40));

        verticalLayout_7->addWidget(closeSerialPort);


        verticalLayout->addLayout(verticalLayout_7);

        label_Ouput2 = new QLabel(centralwidget);
        label_Ouput2->setObjectName(QStringLiteral("label_Ouput2"));
        label_Ouput2->setGeometry(QRect(470, 350, 180, 30));
        label_Ouput2->setMinimumSize(QSize(180, 30));
        label_Ouput2->setMaximumSize(QSize(180, 30));
        QFont font1;
        font1.setPointSize(20);
        label_Ouput2->setFont(font1);
        Ouput2 = new QDoubleSpinBox(centralwidget);
        Ouput2->setObjectName(QStringLiteral("Ouput2"));
        Ouput2->setGeometry(QRect(465, 390, 225, 80));
        Ouput2->setMinimumSize(QSize(225, 80));
        Ouput2->setMaximumSize(QSize(225, 80));
        label_Ouput1 = new QLabel(centralwidget);
        label_Ouput1->setObjectName(QStringLiteral("label_Ouput1"));
        label_Ouput1->setGeometry(QRect(220, 350, 180, 30));
        label_Ouput1->setMinimumSize(QSize(180, 30));
        label_Ouput1->setMaximumSize(QSize(180, 30));
        label_Ouput1->setFont(font1);
        Ouput1 = new QDoubleSpinBox(centralwidget);
        Ouput1->setObjectName(QStringLiteral("Ouput1"));
        Ouput1->setGeometry(QRect(220, 390, 225, 80));
        Ouput1->setMinimumSize(QSize(225, 80));
        Ouput1->setMaximumSize(QSize(225, 80));
        powOuput = new QDoubleSpinBox(centralwidget);
        powOuput->setObjectName(QStringLiteral("powOuput"));
        powOuput->setGeometry(QRect(710, 390, 225, 80));
        powOuput->setMinimumSize(QSize(225, 80));
        powOuput->setMaximumSize(QSize(225, 80));
        label_Ouput3 = new QLabel(centralwidget);
        label_Ouput3->setObjectName(QStringLiteral("label_Ouput3"));
        label_Ouput3->setGeometry(QRect(710, 350, 180, 30));
        label_Ouput3->setMinimumSize(QSize(180, 30));
        label_Ouput3->setMaximumSize(QSize(180, 30));
        label_Ouput3->setFont(font1);
        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(12, 13, 170, 50));
        verticalLayout_3 = new QVBoxLayout(widget3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        powerStatus = new QLabel(widget3);
        powerStatus->setObjectName(QStringLiteral("powerStatus"));
        powerStatus->setMinimumSize(QSize(160, 20));
        powerStatus->setMaximumSize(QSize(160, 20));

        verticalLayout_3->addWidget(powerStatus);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        rbton = new QRadioButton(widget3);
        rbton->setObjectName(QStringLiteral("rbton"));
        rbton->setMinimumSize(QSize(80, 20));
        rbton->setMaximumSize(QSize(80, 20));

        horizontalLayout_7->addWidget(rbton);

        rbtoff = new QRadioButton(widget3);
        rbtoff->setObjectName(QStringLiteral("rbtoff"));
        rbtoff->setMinimumSize(QSize(80, 20));
        rbtoff->setMaximumSize(QSize(80, 20));
        rbtoff->setChecked(true);

        horizontalLayout_7->addWidget(rbtoff);


        verticalLayout_3->addLayout(horizontalLayout_7);

        widget4 = new QWidget(centralwidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(12, 79, 170, 50));
        verticalLayout_4 = new QVBoxLayout(widget4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        workMode = new QLabel(widget4);
        workMode->setObjectName(QStringLiteral("workMode"));
        workMode->setMinimumSize(QSize(160, 20));
        workMode->setMaximumSize(QSize(160, 20));

        verticalLayout_4->addWidget(workMode);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rbtCV = new QRadioButton(widget4);
        rbtCV->setObjectName(QStringLiteral("rbtCV"));
        rbtCV->setMinimumSize(QSize(80, 20));
        rbtCV->setMaximumSize(QSize(80, 20));
        rbtCV->setChecked(true);

        horizontalLayout->addWidget(rbtCV);

        rbtCC = new QRadioButton(widget4);
        rbtCC->setObjectName(QStringLiteral("rbtCC"));
        rbtCC->setEnabled(true);
        rbtCC->setMinimumSize(QSize(80, 20));
        rbtCC->setMaximumSize(QSize(80, 20));
        rbtCC->setChecked(false);

        horizontalLayout->addWidget(rbtCC);


        verticalLayout_4->addLayout(horizontalLayout);

        widget5 = new QWidget(centralwidget);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(10, 150, 170, 80));
        verticalLayout_9 = new QVBoxLayout(widget5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        workStatus = new QLabel(widget5);
        workStatus->setObjectName(QStringLiteral("workStatus"));
        workStatus->setMinimumSize(QSize(80, 20));
        workStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_8->addWidget(workStatus);

        checkBoxCV = new QCheckBox(widget5);
        checkBoxCV->setObjectName(QStringLiteral("checkBoxCV"));
        checkBoxCV->setMinimumSize(QSize(80, 20));
        checkBoxCV->setMaximumSize(QSize(80, 20));
        checkBoxCV->setChecked(true);

        horizontalLayout_8->addWidget(checkBoxCV);


        verticalLayout_9->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBoxCCPos = new QCheckBox(widget5);
        checkBoxCCPos->setObjectName(QStringLiteral("checkBoxCCPos"));
        checkBoxCCPos->setMinimumSize(QSize(80, 20));
        checkBoxCCPos->setMaximumSize(QSize(80, 20));

        horizontalLayout_9->addWidget(checkBoxCCPos);

        checkBoxCCNeg = new QCheckBox(widget5);
        checkBoxCCNeg->setObjectName(QStringLiteral("checkBoxCCNeg"));
        checkBoxCCNeg->setMinimumSize(QSize(80, 20));
        checkBoxCCNeg->setMaximumSize(QSize(80, 20));

        horizontalLayout_9->addWidget(checkBoxCCNeg);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBoxCPPos = new QCheckBox(widget5);
        checkBoxCPPos->setObjectName(QStringLiteral("checkBoxCPPos"));
        checkBoxCPPos->setMinimumSize(QSize(80, 20));
        checkBoxCPPos->setMaximumSize(QSize(80, 20));

        horizontalLayout_10->addWidget(checkBoxCPPos);

        checkBoxCPNeg = new QCheckBox(widget5);
        checkBoxCPNeg->setObjectName(QStringLiteral("checkBoxCPNeg"));
        checkBoxCPNeg->setMinimumSize(QSize(80, 20));
        checkBoxCPNeg->setMaximumSize(QSize(80, 20));

        horizontalLayout_10->addWidget(checkBoxCPNeg);


        verticalLayout_9->addLayout(horizontalLayout_10);

        SerialPortCommunication->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SerialPortCommunication);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1050, 25));
        SerialPortCommunication->setMenuBar(menubar);
        statusbar = new QStatusBar(SerialPortCommunication);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SerialPortCommunication->setStatusBar(statusbar);

        retranslateUi(SerialPortCommunication);

        QMetaObject::connectSlotsByName(SerialPortCommunication);
    } // setupUi

    void retranslateUi(QMainWindow *SerialPortCommunication)
    {
        SerialPortCommunication->setWindowTitle(QApplication::translate("SerialPortCommunication", "SerialPortCommunication", Q_NULLPTR));
        label_Input1->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\345\216\213\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_Input2_PS->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\265\201\350\256\276\347\275\256(PS)\357\274\232", Q_NULLPTR));
        label_Input2_EL->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\265\201\350\256\276\347\275\256(EL)\357\274\232", Q_NULLPTR));
        label_Input3_PS->setText(QApplication::translate("SerialPortCommunication", "\345\212\237\347\216\207\350\256\276\347\275\256(PS)\357\274\232", Q_NULLPTR));
        label_Input3_EL->setText(QApplication::translate("SerialPortCommunication", "\345\212\237\347\216\207\350\256\276\347\275\256(EL)\357\274\232", Q_NULLPTR));
        openPowerSupply->setText(QApplication::translate("SerialPortCommunication", "\345\274\200\345\220\257\347\224\265\346\272\220", Q_NULLPTR));
        closePowerSupply->setText(QApplication::translate("SerialPortCommunication", "\345\205\263\351\227\255\347\224\265\346\272\220", Q_NULLPTR));
        label_13->setText(QApplication::translate("SerialPortCommunication", "\351\200\211\346\213\251\345\217\257\347\224\250\344\270\262\345\217\243", Q_NULLPTR));
        label_14->setText(QApplication::translate("SerialPortCommunication", "\351\200\211\346\213\251\345\217\257\347\224\250\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        openSerialPort->setText(QApplication::translate("SerialPortCommunication", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        closeSerialPort->setText(QApplication::translate("SerialPortCommunication", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        label_Ouput2->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\265\201\345\233\236\350\257\273\357\274\232", Q_NULLPTR));
        label_Ouput1->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\345\216\213\345\233\236\350\257\273:", Q_NULLPTR));
        label_Ouput3->setText(QApplication::translate("SerialPortCommunication", "\345\212\237\347\216\207\345\233\236\350\257\273\357\274\232", Q_NULLPTR));
        powerStatus->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\272\220\347\212\266\346\200\201", Q_NULLPTR));
        rbton->setText(QApplication::translate("SerialPortCommunication", "ON", Q_NULLPTR));
        rbtoff->setText(QApplication::translate("SerialPortCommunication", "OFF", Q_NULLPTR));
        workMode->setText(QApplication::translate("SerialPortCommunication", "\350\277\220\350\241\214\346\250\241\345\274\217", Q_NULLPTR));
        rbtCV->setText(QApplication::translate("SerialPortCommunication", "CV", Q_NULLPTR));
        rbtCC->setText(QApplication::translate("SerialPortCommunication", "CC ", Q_NULLPTR));
        workStatus->setText(QApplication::translate("SerialPortCommunication", "\350\277\220\350\241\214\347\212\266\346\200\201", Q_NULLPTR));
        checkBoxCV->setText(QApplication::translate("SerialPortCommunication", "CV", Q_NULLPTR));
        checkBoxCCPos->setText(QApplication::translate("SerialPortCommunication", "CC+", Q_NULLPTR));
        checkBoxCCNeg->setText(QApplication::translate("SerialPortCommunication", "CC-", Q_NULLPTR));
        checkBoxCPPos->setText(QApplication::translate("SerialPortCommunication", "CP+", Q_NULLPTR));
        checkBoxCPNeg->setText(QApplication::translate("SerialPortCommunication", "CR-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialPortCommunication: public Ui_SerialPortCommunication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTCOMMUNICATION_H
