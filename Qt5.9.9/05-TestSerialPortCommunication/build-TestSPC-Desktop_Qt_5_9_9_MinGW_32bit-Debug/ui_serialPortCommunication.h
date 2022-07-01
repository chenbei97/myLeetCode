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
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *openSerialPort;
    QPushButton *closeSerialPort;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QComboBox *serialNameBox;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QComboBox *serialBaudRateBox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *rbton;
    QRadioButton *rbtoff;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *volInput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *volOuput;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QDoubleSpinBox *backReadTime;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *curInput;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *curOuputEL;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDoubleSpinBox *curOuputPS;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *powInput;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QDoubleSpinBox *powOuputEL;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *powOuputPS;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QDoubleSpinBox *RInput;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QDoubleSpinBox *ROuputEL;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QDoubleSpinBox *ROuputPS;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SerialPortCommunication)
    {
        if (SerialPortCommunication->objectName().isEmpty())
            SerialPortCommunication->setObjectName(QStringLiteral("SerialPortCommunication"));
        SerialPortCommunication->resize(882, 605);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        SerialPortCommunication->setFont(font);
        centralwidget = new QWidget(SerialPortCommunication);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(700, 300, 162, 88));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        openSerialPort = new QPushButton(layoutWidget_3);
        openSerialPort->setObjectName(QStringLiteral("openSerialPort"));
        openSerialPort->setMinimumSize(QSize(160, 40));
        openSerialPort->setMaximumSize(QSize(160, 40));

        verticalLayout_7->addWidget(openSerialPort);

        closeSerialPort = new QPushButton(layoutWidget_3);
        closeSerialPort->setObjectName(QStringLiteral("closeSerialPort"));
        closeSerialPort->setMinimumSize(QSize(160, 40));
        closeSerialPort->setMaximumSize(QSize(160, 40));

        verticalLayout_7->addWidget(closeSerialPort);

        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(700, 140, 164, 147));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_13 = new QLabel(layoutWidget_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(160, 20));
        label_13->setMaximumSize(QSize(160, 20));
        label_13->setSizeIncrement(QSize(160, 20));

        verticalLayout_5->addWidget(label_13);

        serialNameBox = new QComboBox(layoutWidget_4);
        serialNameBox->setObjectName(QStringLiteral("serialNameBox"));
        serialNameBox->setMinimumSize(QSize(160, 40));
        serialNameBox->setMaximumSize(QSize(160, 40));

        verticalLayout_5->addWidget(serialNameBox);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_14 = new QLabel(layoutWidget_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(160, 20));
        label_14->setMaximumSize(QSize(160, 20));

        verticalLayout_6->addWidget(label_14);

        serialBaudRateBox = new QComboBox(layoutWidget_4);
        serialBaudRateBox->setObjectName(QStringLiteral("serialBaudRateBox"));
        serialBaudRateBox->setMinimumSize(QSize(160, 40));
        serialBaudRateBox->setMaximumSize(QSize(160, 40));

        verticalLayout_6->addWidget(serialBaudRateBox);


        verticalLayout_8->addLayout(verticalLayout_6);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(700, 400, 170, 96));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(160, 40));
        pushButton->setMaximumSize(QSize(160, 40));

        verticalLayout_9->addWidget(pushButton);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(160, 20));
        label_12->setMaximumSize(QSize(160, 20));

        verticalLayout_9->addWidget(label_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        rbton = new QRadioButton(layoutWidget_2);
        rbton->setObjectName(QStringLiteral("rbton"));
        rbton->setMinimumSize(QSize(80, 20));
        rbton->setMaximumSize(QSize(80, 20));

        horizontalLayout_13->addWidget(rbton);

        rbtoff = new QRadioButton(layoutWidget_2);
        rbtoff->setObjectName(QStringLiteral("rbtoff"));
        rbtoff->setMinimumSize(QSize(80, 20));
        rbtoff->setMaximumSize(QSize(80, 20));
        rbtoff->setChecked(true);

        horizontalLayout_13->addWidget(rbtoff);


        verticalLayout_9->addLayout(horizontalLayout_13);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 860, 113));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 30));
        label->setMaximumSize(QSize(120, 30));

        horizontalLayout->addWidget(label);

        volInput = new QDoubleSpinBox(layoutWidget);
        volInput->setObjectName(QStringLiteral("volInput"));
        volInput->setMinimumSize(QSize(80, 30));
        volInput->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(volInput);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 30));
        label_2->setMaximumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(label_2);

        volOuput = new QDoubleSpinBox(layoutWidget);
        volOuput->setObjectName(QStringLiteral("volOuput"));
        volOuput->setMinimumSize(QSize(80, 30));
        volOuput->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(volOuput);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(120, 30));
        label_15->setMaximumSize(QSize(120, 30));

        horizontalLayout_3->addWidget(label_15);

        backReadTime = new QDoubleSpinBox(layoutWidget);
        backReadTime->setObjectName(QStringLiteral("backReadTime"));
        backReadTime->setMinimumSize(QSize(80, 30));
        backReadTime->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(backReadTime);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_14->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(120, 30));
        label_3->setMaximumSize(QSize(120, 30));

        horizontalLayout_4->addWidget(label_3);

        curInput = new QDoubleSpinBox(layoutWidget);
        curInput->setObjectName(QStringLiteral("curInput"));
        curInput->setMinimumSize(QSize(80, 30));
        curInput->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(curInput);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 30));
        label_4->setMaximumSize(QSize(120, 30));

        horizontalLayout_5->addWidget(label_4);

        curOuputEL = new QDoubleSpinBox(layoutWidget);
        curOuputEL->setObjectName(QStringLiteral("curOuputEL"));
        curOuputEL->setMinimumSize(QSize(80, 30));
        curOuputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(curOuputEL);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(120, 30));
        label_5->setMaximumSize(QSize(120, 30));

        horizontalLayout_6->addWidget(label_5);

        curOuputPS = new QDoubleSpinBox(layoutWidget);
        curOuputPS->setObjectName(QStringLiteral("curOuputPS"));
        curOuputPS->setMinimumSize(QSize(80, 30));
        curOuputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(curOuputPS);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_14->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(120, 30));
        label_6->setMaximumSize(QSize(120, 30));

        horizontalLayout_7->addWidget(label_6);

        powInput = new QDoubleSpinBox(layoutWidget);
        powInput->setObjectName(QStringLiteral("powInput"));
        powInput->setMinimumSize(QSize(80, 30));
        powInput->setMaximumSize(QSize(80, 30));

        horizontalLayout_7->addWidget(powInput);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(120, 30));
        label_7->setMaximumSize(QSize(120, 30));

        horizontalLayout_8->addWidget(label_7);

        powOuputEL = new QDoubleSpinBox(layoutWidget);
        powOuputEL->setObjectName(QStringLiteral("powOuputEL"));
        powOuputEL->setMinimumSize(QSize(80, 30));
        powOuputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_8->addWidget(powOuputEL);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(120, 30));
        label_8->setMaximumSize(QSize(120, 30));

        horizontalLayout_9->addWidget(label_8);

        powOuputPS = new QDoubleSpinBox(layoutWidget);
        powOuputPS->setObjectName(QStringLiteral("powOuputPS"));
        powOuputPS->setMinimumSize(QSize(80, 30));
        powOuputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_9->addWidget(powOuputPS);


        verticalLayout_3->addLayout(horizontalLayout_9);


        horizontalLayout_14->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(120, 30));
        label_9->setMaximumSize(QSize(120, 30));

        horizontalLayout_10->addWidget(label_9);

        RInput = new QDoubleSpinBox(layoutWidget);
        RInput->setObjectName(QStringLiteral("RInput"));
        RInput->setMinimumSize(QSize(80, 30));
        RInput->setMaximumSize(QSize(80, 30));

        horizontalLayout_10->addWidget(RInput);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(120, 30));
        label_10->setMaximumSize(QSize(120, 30));

        horizontalLayout_11->addWidget(label_10);

        ROuputEL = new QDoubleSpinBox(layoutWidget);
        ROuputEL->setObjectName(QStringLiteral("ROuputEL"));
        ROuputEL->setMinimumSize(QSize(80, 30));
        ROuputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_11->addWidget(ROuputEL);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(120, 30));
        label_11->setMaximumSize(QSize(120, 30));

        horizontalLayout_12->addWidget(label_11);

        ROuputPS = new QDoubleSpinBox(layoutWidget);
        ROuputPS->setObjectName(QStringLiteral("ROuputPS"));
        ROuputPS->setMinimumSize(QSize(80, 30));
        ROuputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_12->addWidget(ROuputPS);


        verticalLayout_4->addLayout(horizontalLayout_12);


        horizontalLayout_14->addLayout(verticalLayout_4);

        SerialPortCommunication->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SerialPortCommunication);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 882, 28));
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
        openSerialPort->setText(QApplication::translate("SerialPortCommunication", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        closeSerialPort->setText(QApplication::translate("SerialPortCommunication", "\345\205\263\351\227\255\344\270\262\345\217\243", Q_NULLPTR));
        label_13->setText(QApplication::translate("SerialPortCommunication", "\351\200\211\346\213\251\345\217\257\347\224\250\344\270\262\345\217\243", Q_NULLPTR));
        label_14->setText(QApplication::translate("SerialPortCommunication", "\351\200\211\346\213\251\345\217\257\347\224\250\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SerialPortCommunication", "\345\274\200\345\220\257\347\224\265\346\272\220", Q_NULLPTR));
        label_12->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\272\220\347\212\266\346\200\201", Q_NULLPTR));
        rbton->setText(QApplication::translate("SerialPortCommunication", "ON", Q_NULLPTR));
        rbtoff->setText(QApplication::translate("SerialPortCommunication", "OFF", Q_NULLPTR));
        label->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\345\216\213\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\345\216\213\345\233\236\350\257\273", Q_NULLPTR));
        label_15->setText(QApplication::translate("SerialPortCommunication", "\345\233\236\350\257\273\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\265\201\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\265\201\345\233\236\350\257\273(EL)", Q_NULLPTR));
        label_5->setText(QApplication::translate("SerialPortCommunication", "\347\224\265\346\265\201\345\233\236\350\257\273(PS)", Q_NULLPTR));
        label_6->setText(QApplication::translate("SerialPortCommunication", "\345\212\237\347\216\207\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("SerialPortCommunication", "\345\212\237\347\216\207\345\233\236\350\257\273(EL)", Q_NULLPTR));
        label_8->setText(QApplication::translate("SerialPortCommunication", "\345\212\237\347\216\207\345\233\236\350\257\273(PS)", Q_NULLPTR));
        label_9->setText(QApplication::translate("SerialPortCommunication", "\345\206\205\351\230\273\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("SerialPortCommunication", "\345\206\205\351\230\273\345\233\236\350\257\273(EL)", Q_NULLPTR));
        label_11->setText(QApplication::translate("SerialPortCommunication", "\345\206\205\351\230\273\345\233\236\350\257\273(PS)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialPortCommunication: public Ui_SerialPortCommunication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTCOMMUNICATION_H
