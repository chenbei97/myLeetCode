/********************************************************************************
** Form generated from reading UI file 'testserialport.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSERIALPORT_H
#define UI_TESTSERIALPORT_H

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

class Ui_TestSerialPort
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QRadioButton *rbton;
    QRadioButton *rbtoff;
    QLabel *label_12;
    QComboBox *serialNameBox;
    QLabel *label_13;
    QComboBox *serialBaudRateBox;
    QLabel *label_14;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *volInput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *volOuput;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *curInput;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *curOuputEL;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *curOuputPS;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *powInput;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QDoubleSpinBox *powOuputEL;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *powOuputPS;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *RInput;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QDoubleSpinBox *ROuputEL;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QDoubleSpinBox *ROuputPS;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestSerialPort)
    {
        if (TestSerialPort->objectName().isEmpty())
            TestSerialPort->setObjectName(QStringLiteral("TestSerialPort"));
        TestSerialPort->resize(996, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestSerialPort->setFont(font);
        centralwidget = new QWidget(TestSerialPort);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 200, 241, 71));
        rbton = new QRadioButton(centralwidget);
        rbton->setObjectName(QStringLiteral("rbton"));
        rbton->setGeometry(QRect(50, 350, 71, 21));
        rbtoff = new QRadioButton(centralwidget);
        rbtoff->setObjectName(QStringLiteral("rbtoff"));
        rbtoff->setGeometry(QRect(170, 350, 112, 21));
        rbtoff->setChecked(true);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 300, 201, 31));
        serialNameBox = new QComboBox(centralwidget);
        serialNameBox->setObjectName(QStringLiteral("serialNameBox"));
        serialNameBox->setGeometry(QRect(670, 220, 201, 41));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(680, 190, 131, 21));
        serialBaudRateBox = new QComboBox(centralwidget);
        serialBaudRateBox->setObjectName(QStringLiteral("serialBaudRateBox"));
        serialBaudRateBox->setGeometry(QRect(670, 350, 201, 41));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(680, 320, 131, 21));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 20, 856, 112));
        horizontalLayout_12 = new QHBoxLayout(widget);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 30));
        label->setMaximumSize(QSize(120, 30));

        horizontalLayout->addWidget(label);

        volInput = new QDoubleSpinBox(widget);
        volInput->setObjectName(QStringLiteral("volInput"));
        volInput->setMinimumSize(QSize(80, 30));
        volInput->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(volInput);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 30));
        label_2->setMaximumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(label_2);

        volOuput = new QDoubleSpinBox(widget);
        volOuput->setObjectName(QStringLiteral("volOuput"));
        volOuput->setMinimumSize(QSize(80, 30));
        volOuput->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(volOuput);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_12->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(120, 30));
        label_3->setMaximumSize(QSize(120, 30));

        horizontalLayout_3->addWidget(label_3);

        curInput = new QDoubleSpinBox(widget);
        curInput->setObjectName(QStringLiteral("curInput"));
        curInput->setMinimumSize(QSize(80, 30));
        curInput->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(curInput);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(120, 30));
        label_4->setMaximumSize(QSize(120, 30));

        horizontalLayout_4->addWidget(label_4);

        curOuputEL = new QDoubleSpinBox(widget);
        curOuputEL->setObjectName(QStringLiteral("curOuputEL"));
        curOuputEL->setMinimumSize(QSize(80, 30));
        curOuputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(curOuputEL);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(120, 30));
        label_5->setMaximumSize(QSize(120, 30));

        horizontalLayout_5->addWidget(label_5);

        curOuputPS = new QDoubleSpinBox(widget);
        curOuputPS->setObjectName(QStringLiteral("curOuputPS"));
        curOuputPS->setMinimumSize(QSize(80, 30));
        curOuputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(curOuputPS);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_12->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        powInput = new QDoubleSpinBox(widget);
        powInput->setObjectName(QStringLiteral("powInput"));
        powInput->setMinimumSize(QSize(80, 30));
        powInput->setMaximumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(powInput);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        powOuputEL = new QDoubleSpinBox(widget);
        powOuputEL->setObjectName(QStringLiteral("powOuputEL"));
        powOuputEL->setMinimumSize(QSize(80, 30));
        powOuputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_7->addWidget(powOuputEL);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        powOuputPS = new QDoubleSpinBox(widget);
        powOuputPS->setObjectName(QStringLiteral("powOuputPS"));
        powOuputPS->setMinimumSize(QSize(80, 30));
        powOuputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_8->addWidget(powOuputPS);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_12->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        RInput = new QDoubleSpinBox(widget);
        RInput->setObjectName(QStringLiteral("RInput"));
        RInput->setMinimumSize(QSize(80, 30));
        RInput->setMaximumSize(QSize(80, 30));

        horizontalLayout_9->addWidget(RInput);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        ROuputEL = new QDoubleSpinBox(widget);
        ROuputEL->setObjectName(QStringLiteral("ROuputEL"));
        ROuputEL->setMinimumSize(QSize(80, 30));
        ROuputEL->setMaximumSize(QSize(80, 30));

        horizontalLayout_10->addWidget(ROuputEL);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        ROuputPS = new QDoubleSpinBox(widget);
        ROuputPS->setObjectName(QStringLiteral("ROuputPS"));
        ROuputPS->setMinimumSize(QSize(80, 30));
        ROuputPS->setMaximumSize(QSize(80, 30));

        horizontalLayout_11->addWidget(ROuputPS);


        verticalLayout_2->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_2);

        TestSerialPort->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestSerialPort);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 996, 28));
        TestSerialPort->setMenuBar(menubar);
        statusbar = new QStatusBar(TestSerialPort);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestSerialPort->setStatusBar(statusbar);

        retranslateUi(TestSerialPort);

        QMetaObject::connectSlotsByName(TestSerialPort);
    } // setupUi

    void retranslateUi(QMainWindow *TestSerialPort)
    {
        TestSerialPort->setWindowTitle(QApplication::translate("TestSerialPort", "TestSerialPort", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TestSerialPort", "\345\274\200\345\220\257\347\224\265\346\272\220", Q_NULLPTR));
        rbton->setText(QApplication::translate("TestSerialPort", "ON", Q_NULLPTR));
        rbtoff->setText(QApplication::translate("TestSerialPort", "OFF", Q_NULLPTR));
        label_12->setText(QApplication::translate("TestSerialPort", "\347\224\265\346\272\220\347\212\266\346\200\201", Q_NULLPTR));
        label_13->setText(QApplication::translate("TestSerialPort", "\345\217\257\347\224\250\344\270\262\345\217\243", Q_NULLPTR));
        label_14->setText(QApplication::translate("TestSerialPort", "\345\217\257\347\224\250\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label->setText(QApplication::translate("TestSerialPort", "\347\224\265\345\216\213\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("TestSerialPort", "\347\224\265\345\216\213\345\233\236\350\257\273", Q_NULLPTR));
        label_3->setText(QApplication::translate("TestSerialPort", "\347\224\265\346\265\201\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("TestSerialPort", "\347\224\265\346\265\201\345\233\236\350\257\273(EL)", Q_NULLPTR));
        label_5->setText(QApplication::translate("TestSerialPort", "\347\224\265\346\265\201\345\233\236\350\257\273(PS)", Q_NULLPTR));
        label_6->setText(QApplication::translate("TestSerialPort", "\345\212\237\347\216\207\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("TestSerialPort", "\345\212\237\347\216\207\345\233\236\350\257\273(EL)", Q_NULLPTR));
        label_8->setText(QApplication::translate("TestSerialPort", "\345\212\237\347\216\207\345\233\236\350\257\273(PS)", Q_NULLPTR));
        label_9->setText(QApplication::translate("TestSerialPort", "\345\206\205\351\230\273\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("TestSerialPort", "\345\206\205\351\230\273\345\233\236\350\257\273(EL)", Q_NULLPTR));
        label_11->setText(QApplication::translate("TestSerialPort", "\345\206\205\351\230\273\345\233\236\350\257\273(PS)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestSerialPort: public Ui_TestSerialPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSERIALPORT_H
