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
    QWidget *layoutWidget;
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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openPowerSupply;
    QPushButton *closePowerSupply;
    QWidget *layoutWidget2;
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
    QDoubleSpinBox *currOuput;
    QLabel *label_Ouput1;
    QDoubleSpinBox *voltOuput;
    QDoubleSpinBox *powOuput;
    QLabel *label_Ouput3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *powerStatus;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *rbton;
    QCheckBox *rbtoff;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QLabel *workMode;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbtCV;
    QRadioButton *rbtCC;
    QWidget *layoutWidget5;
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
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 490, 741, 91));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_Input1 = new QLabel(layoutWidget);
        label_Input1->setObjectName(QStringLiteral("label_Input1"));
        label_Input1->setMinimumSize(QSize(120, 30));
        label_Input1->setMaximumSize(QSize(120, 30));

        verticalLayout_14->addWidget(label_Input1);

        Input1 = new QDoubleSpinBox(layoutWidget);
        Input1->setObjectName(QStringLiteral("Input1"));
        Input1->setMinimumSize(QSize(80, 30));
        Input1->setMaximumSize(QSize(80, 30));

        verticalLayout_14->addWidget(Input1);


        horizontalLayout_6->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Input2_PS = new QLabel(layoutWidget);
        label_Input2_PS->setObjectName(QStringLiteral("label_Input2_PS"));
        label_Input2_PS->setMinimumSize(QSize(120, 30));
        label_Input2_PS->setMaximumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(label_Input2_PS);

        Input2PS = new QDoubleSpinBox(layoutWidget);
        Input2PS->setObjectName(QStringLiteral("Input2PS"));
        Input2PS->setMinimumSize(QSize(80, 30));
        Input2PS->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(Input2PS);


        verticalLayout_15->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Input2_EL = new QLabel(layoutWidget);
        label_Input2_EL->setObjectName(QStringLiteral("label_Input2_EL"));
        label_Input2_EL->setMinimumSize(QSize(120, 30));
        label_Input2_EL->setMaximumSize(QSize(120, 30));

        horizontalLayout_3->addWidget(label_Input2_EL);

        Input2EL = new QDoubleSpinBox(layoutWidget);
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
        label_Input3_PS = new QLabel(layoutWidget);
        label_Input3_PS->setObjectName(QStringLiteral("label_Input3_PS"));
        label_Input3_PS->setMinimumSize(QSize(120, 30));
        label_Input3_PS->setMaximumSize(QSize(120, 30));

        horizontalLayout_4->addWidget(label_Input3_PS);

        powInputPS = new QDoubleSpinBox(layoutWidget);
        powInputPS->setObjectName(QStringLiteral("powInputPS"));
        powInputPS->setMinimumSize(QSize(80, 30));
        powInputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(powInputPS);


        verticalLayout_16->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Input3_EL = new QLabel(layoutWidget);
        label_Input3_EL->setObjectName(QStringLiteral("label_Input3_EL"));
        label_Input3_EL->setMinimumSize(QSize(120, 30));
        label_Input3_EL->setMaximumSize(QSize(120, 30));

        horizontalLayout_5->addWidget(label_Input3_EL);

        powInputEL = new QDoubleSpinBox(layoutWidget);
        powInputEL->setObjectName(QStringLiteral("powInputEL"));
        powInputEL->setMinimumSize(QSize(80, 30));
        powInputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(powInputEL);


        verticalLayout_16->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_16);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 240, 162, 88));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        openPowerSupply = new QPushButton(layoutWidget1);
        openPowerSupply->setObjectName(QStringLiteral("openPowerSupply"));
        openPowerSupply->setMinimumSize(QSize(160, 40));
        openPowerSupply->setMaximumSize(QSize(160, 40));

        verticalLayout_2->addWidget(openPowerSupply);

        closePowerSupply = new QPushButton(layoutWidget1);
        closePowerSupply->setObjectName(QStringLiteral("closePowerSupply"));
        closePowerSupply->setMinimumSize(QSize(160, 40));
        closePowerSupply->setMaximumSize(QSize(160, 40));

        verticalLayout_2->addWidget(closePowerSupply);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 350, 166, 240));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(160, 20));
        label_13->setMaximumSize(QSize(160, 20));
        label_13->setSizeIncrement(QSize(160, 20));

        verticalLayout_5->addWidget(label_13);

        serialNameBox = new QComboBox(layoutWidget2);
        serialNameBox->setObjectName(QStringLiteral("serialNameBox"));
        serialNameBox->setMinimumSize(QSize(160, 40));
        serialNameBox->setMaximumSize(QSize(160, 40));

        verticalLayout_5->addWidget(serialNameBox);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(160, 20));
        label_14->setMaximumSize(QSize(160, 20));

        verticalLayout_6->addWidget(label_14);

        serialBaudRateBox = new QComboBox(layoutWidget2);
        serialBaudRateBox->setObjectName(QStringLiteral("serialBaudRateBox"));
        serialBaudRateBox->setMinimumSize(QSize(160, 40));
        serialBaudRateBox->setMaximumSize(QSize(160, 40));

        verticalLayout_6->addWidget(serialBaudRateBox);


        verticalLayout_8->addLayout(verticalLayout_6);


        verticalLayout->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        openSerialPort = new QPushButton(layoutWidget2);
        openSerialPort->setObjectName(QStringLiteral("openSerialPort"));
        openSerialPort->setMinimumSize(QSize(160, 40));
        openSerialPort->setMaximumSize(QSize(160, 40));

        verticalLayout_7->addWidget(openSerialPort);

        closeSerialPort = new QPushButton(layoutWidget2);
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
        currOuput = new QDoubleSpinBox(centralwidget);
        currOuput->setObjectName(QStringLiteral("currOuput"));
        currOuput->setGeometry(QRect(465, 390, 225, 80));
        currOuput->setMinimumSize(QSize(225, 80));
        currOuput->setMaximumSize(QSize(225, 80));
        label_Ouput1 = new QLabel(centralwidget);
        label_Ouput1->setObjectName(QStringLiteral("label_Ouput1"));
        label_Ouput1->setGeometry(QRect(220, 350, 180, 30));
        label_Ouput1->setMinimumSize(QSize(180, 30));
        label_Ouput1->setMaximumSize(QSize(180, 30));
        label_Ouput1->setFont(font1);
        voltOuput = new QDoubleSpinBox(centralwidget);
        voltOuput->setObjectName(QStringLiteral("voltOuput"));
        voltOuput->setGeometry(QRect(220, 390, 225, 80));
        voltOuput->setMinimumSize(QSize(225, 80));
        voltOuput->setMaximumSize(QSize(225, 80));
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
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 90, 170, 50));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        powerStatus = new QLabel(layoutWidget3);
        powerStatus->setObjectName(QStringLiteral("powerStatus"));
        powerStatus->setMinimumSize(QSize(160, 20));
        powerStatus->setMaximumSize(QSize(160, 20));

        verticalLayout_3->addWidget(powerStatus);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        rbton = new QCheckBox(layoutWidget3);
        rbton->setObjectName(QStringLiteral("rbton"));
        rbton->setMinimumSize(QSize(80, 20));
        rbton->setMaximumSize(QSize(80, 20));

        horizontalLayout_7->addWidget(rbton);

        rbtoff = new QCheckBox(layoutWidget3);
        rbtoff->setObjectName(QStringLiteral("rbtoff"));
        rbtoff->setMinimumSize(QSize(80, 20));
        rbtoff->setMaximumSize(QSize(80, 20));
        rbtoff->setChecked(true);

        horizontalLayout_7->addWidget(rbtoff);


        verticalLayout_3->addLayout(horizontalLayout_7);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 170, 50));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        workMode = new QLabel(layoutWidget4);
        workMode->setObjectName(QStringLiteral("workMode"));
        workMode->setMinimumSize(QSize(160, 20));
        workMode->setMaximumSize(QSize(160, 20));

        verticalLayout_4->addWidget(workMode);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rbtCV = new QRadioButton(layoutWidget4);
        rbtCV->setObjectName(QStringLiteral("rbtCV"));
        rbtCV->setMinimumSize(QSize(80, 20));
        rbtCV->setMaximumSize(QSize(80, 20));
        rbtCV->setChecked(true);

        horizontalLayout->addWidget(rbtCV);

        rbtCC = new QRadioButton(layoutWidget4);
        rbtCC->setObjectName(QStringLiteral("rbtCC"));
        rbtCC->setEnabled(true);
        rbtCC->setMinimumSize(QSize(80, 20));
        rbtCC->setMaximumSize(QSize(80, 20));
        rbtCC->setChecked(false);

        horizontalLayout->addWidget(rbtCC);


        verticalLayout_4->addLayout(horizontalLayout);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 150, 170, 80));
        verticalLayout_9 = new QVBoxLayout(layoutWidget5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        workStatus = new QLabel(layoutWidget5);
        workStatus->setObjectName(QStringLiteral("workStatus"));
        workStatus->setMinimumSize(QSize(80, 20));
        workStatus->setMaximumSize(QSize(80, 20));

        horizontalLayout_8->addWidget(workStatus);

        checkBoxCV = new QCheckBox(layoutWidget5);
        checkBoxCV->setObjectName(QStringLiteral("checkBoxCV"));
        checkBoxCV->setMinimumSize(QSize(80, 20));
        checkBoxCV->setMaximumSize(QSize(80, 20));
        checkBoxCV->setChecked(true);

        horizontalLayout_8->addWidget(checkBoxCV);


        verticalLayout_9->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBoxCCPos = new QCheckBox(layoutWidget5);
        checkBoxCCPos->setObjectName(QStringLiteral("checkBoxCCPos"));
        checkBoxCCPos->setMinimumSize(QSize(80, 20));
        checkBoxCCPos->setMaximumSize(QSize(80, 20));

        horizontalLayout_9->addWidget(checkBoxCCPos);

        checkBoxCCNeg = new QCheckBox(layoutWidget5);
        checkBoxCCNeg->setObjectName(QStringLiteral("checkBoxCCNeg"));
        checkBoxCCNeg->setMinimumSize(QSize(80, 20));
        checkBoxCCNeg->setMaximumSize(QSize(80, 20));

        horizontalLayout_9->addWidget(checkBoxCCNeg);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBoxCPPos = new QCheckBox(layoutWidget5);
        checkBoxCPPos->setObjectName(QStringLiteral("checkBoxCPPos"));
        checkBoxCPPos->setMinimumSize(QSize(80, 20));
        checkBoxCPPos->setMaximumSize(QSize(80, 20));

        horizontalLayout_10->addWidget(checkBoxCPPos);

        checkBoxCPNeg = new QCheckBox(layoutWidget5);
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
        workMode->setText(QApplication::translate("SerialPortCommunication", "\345\267\245\344\275\234\346\250\241\345\274\217", Q_NULLPTR));
        rbtCV->setText(QApplication::translate("SerialPortCommunication", "CV", Q_NULLPTR));
        rbtCC->setText(QApplication::translate("SerialPortCommunication", "CC ", Q_NULLPTR));
        workStatus->setText(QApplication::translate("SerialPortCommunication", "\345\267\245\344\275\234\347\212\266\346\200\201", Q_NULLPTR));
        checkBoxCV->setText(QApplication::translate("SerialPortCommunication", "CV", Q_NULLPTR));
        checkBoxCCPos->setText(QApplication::translate("SerialPortCommunication", "CC+", Q_NULLPTR));
        checkBoxCCNeg->setText(QApplication::translate("SerialPortCommunication", "CC-", Q_NULLPTR));
        checkBoxCPPos->setText(QApplication::translate("SerialPortCommunication", "CP+", Q_NULLPTR));
        checkBoxCPNeg->setText(QApplication::translate("SerialPortCommunication", "CP-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialPortCommunication: public Ui_SerialPortCommunication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTCOMMUNICATION_H
