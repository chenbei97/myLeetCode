/********************************************************************************
** Form generated from reading UI file 'UdpUnitBroadCast.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPUNITBROADCAST_H
#define UI_UDPUNITBROADCAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpUnitBroadCast
{
public:
    QAction *actStart;
    QAction *actStop;
    QAction *actQuit;
    QAction *actClear;
    QAction *actHostInfo;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBindPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboTargetIP;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *spinTargetPort;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *editMsg;
    QToolButton *btnSend;
    QPushButton *btnBroadcast;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UdpUnitBroadCast)
    {
        if (UdpUnitBroadCast->objectName().isEmpty())
            UdpUnitBroadCast->setObjectName(QStringLiteral("UdpUnitBroadCast"));
        UdpUnitBroadCast->resize(666, 577);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        UdpUnitBroadCast->setFont(font);
        actStart = new QAction(UdpUnitBroadCast);
        actStart->setObjectName(QStringLiteral("actStart"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        actStop = new QAction(UdpUnitBroadCast);
        actStop->setObjectName(QStringLiteral("actStop"));
        actStop->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actQuit = new QAction(UdpUnitBroadCast);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actClear = new QAction(UdpUnitBroadCast);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon3);
        actHostInfo = new QAction(UdpUnitBroadCast);
        actHostInfo->setObjectName(QStringLiteral("actHostInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/110.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actHostInfo->setIcon(icon4);
        centralwidget = new QWidget(UdpUnitBroadCast);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinBindPort = new QSpinBox(centralwidget);
        spinBindPort->setObjectName(QStringLiteral("spinBindPort"));
        spinBindPort->setMinimumSize(QSize(100, 30));
        spinBindPort->setMinimum(1);
        spinBindPort->setMaximum(65535);
        spinBindPort->setValue(1200);

        horizontalLayout->addWidget(spinBindPort);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 30));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        comboTargetIP = new QComboBox(centralwidget);
        comboTargetIP->setObjectName(QStringLiteral("comboTargetIP"));
        comboTargetIP->setMinimumSize(QSize(120, 30));
        comboTargetIP->setEditable(true);
        comboTargetIP->setDuplicatesEnabled(false);

        horizontalLayout_2->addWidget(comboTargetIP);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(80, 30));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        spinTargetPort = new QSpinBox(centralwidget);
        spinTargetPort->setObjectName(QStringLiteral("spinTargetPort"));
        spinTargetPort->setMinimumSize(QSize(100, 30));
        spinTargetPort->setMinimum(1);
        spinTargetPort->setMaximum(65535);
        spinTargetPort->setValue(3355);

        horizontalLayout_3->addWidget(spinTargetPort);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        editMsg = new QLineEdit(centralwidget);
        editMsg->setObjectName(QStringLiteral("editMsg"));

        horizontalLayout_5->addWidget(editMsg);

        btnSend = new QToolButton(centralwidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(btnSend);

        btnBroadcast = new QPushButton(centralwidget);
        btnBroadcast->setObjectName(QStringLiteral("btnBroadcast"));
        btnBroadcast->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(btnBroadcast);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        UdpUnitBroadCast->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UdpUnitBroadCast);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UdpUnitBroadCast->setStatusBar(statusbar);
        toolBar = new QToolBar(UdpUnitBroadCast);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        UdpUnitBroadCast->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actStart);
        toolBar->addAction(actStop);
        toolBar->addAction(actHostInfo);
        toolBar->addAction(actClear);
        toolBar->addAction(actQuit);

        retranslateUi(UdpUnitBroadCast);
        QObject::connect(actQuit, SIGNAL(triggered()), UdpUnitBroadCast, SLOT(close()));

        QMetaObject::connectSlotsByName(UdpUnitBroadCast);
    } // setupUi

    void retranslateUi(QMainWindow *UdpUnitBroadCast)
    {
        UdpUnitBroadCast->setWindowTitle(QApplication::translate("UdpUnitBroadCast", "UdpUnitBroadCast", Q_NULLPTR));
        actStart->setText(QApplication::translate("UdpUnitBroadCast", "\347\273\221\345\256\232\347\253\257\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStart->setToolTip(QApplication::translate("UdpUnitBroadCast", "\347\273\221\345\256\232UDP\347\233\221\345\220\254\347\253\257\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("UdpUnitBroadCast", "\350\247\243\351\231\244\347\273\221\345\256\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("UdpUnitBroadCast", "\350\247\243\351\231\244\347\273\221\345\256\232", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("UdpUnitBroadCast", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("UdpUnitBroadCast", "\351\200\200\345\207\272\346\234\254\347\250\213\345\272\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("UdpUnitBroadCast", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("UdpUnitBroadCast", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actHostInfo->setText(QApplication::translate("UdpUnitBroadCast", "\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actHostInfo->setToolTip(QApplication::translate("UdpUnitBroadCast", "\350\216\267\345\217\226\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("UdpUnitBroadCast", "\347\273\221\345\256\232\347\253\257\345\217\243", Q_NULLPTR));
        label_3->setText(QApplication::translate("UdpUnitBroadCast", "\347\233\256\346\240\207\345\234\260\345\235\200", Q_NULLPTR));
        comboTargetIP->clear();
        comboTargetIP->insertItems(0, QStringList()
         << QApplication::translate("UdpUnitBroadCast", "127.0.0.1", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("UdpUnitBroadCast", "\347\233\256\346\240\207\347\253\257\345\217\243", Q_NULLPTR));
        btnSend->setText(QApplication::translate("UdpUnitBroadCast", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        btnBroadcast->setText(QApplication::translate("UdpUnitBroadCast", "\345\271\277\346\222\255\346\266\210\346\201\257", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("UdpUnitBroadCast", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UdpUnitBroadCast: public Ui_UdpUnitBroadCast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPUNITBROADCAST_H
