/********************************************************************************
** Form generated from reading UI file 'TCPServer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPServer
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
    QLabel *label_2;
    QComboBox *comboIP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinPort;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *editMsg;
    QToolButton *btnSend;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TCPServer)
    {
        if (TCPServer->objectName().isEmpty())
            TCPServer->setObjectName(QStringLiteral("TCPServer"));
        TCPServer->resize(691, 529);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TCPServer->setFont(font);
        actStart = new QAction(TCPServer);
        actStart->setObjectName(QStringLiteral("actStart"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        actStop = new QAction(TCPServer);
        actStop->setObjectName(QStringLiteral("actStop"));
        actStop->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actQuit = new QAction(TCPServer);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actClear = new QAction(TCPServer);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon3);
        actHostInfo = new QAction(TCPServer);
        actHostInfo->setObjectName(QStringLiteral("actHostInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/110.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actHostInfo->setIcon(icon4);
        centralwidget = new QWidget(TCPServer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(175, 30));
        label_2->setMaximumSize(QSize(9999, 9999));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        comboIP = new QComboBox(centralwidget);
        comboIP->setObjectName(QStringLiteral("comboIP"));
        comboIP->setMinimumSize(QSize(250, 30));
        comboIP->setMaximumSize(QSize(9999, 9999));
        comboIP->setEditable(true);
        comboIP->setDuplicatesEnabled(false);

        horizontalLayout->addWidget(comboIP);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(171, 30));
        label->setMaximumSize(QSize(9999, 9999));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        spinPort = new QSpinBox(centralwidget);
        spinPort->setObjectName(QStringLiteral("spinPort"));
        spinPort->setMinimumSize(QSize(200, 30));
        spinPort->setMaximumSize(QSize(9999, 9999));
        spinPort->setMinimum(1);
        spinPort->setMaximum(65535);
        spinPort->setValue(1200);

        horizontalLayout_2->addWidget(spinPort);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        editMsg = new QLineEdit(centralwidget);
        editMsg->setObjectName(QStringLiteral("editMsg"));
        editMsg->setMinimumSize(QSize(305, 30));

        horizontalLayout_3->addWidget(editMsg);

        btnSend = new QToolButton(centralwidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setMinimumSize(QSize(100, 30));
        btnSend->setMaximumSize(QSize(9999, 9999));

        horizontalLayout_3->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        TCPServer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TCPServer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TCPServer->setStatusBar(statusbar);
        toolBar = new QToolBar(TCPServer);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TCPServer->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actStart);
        toolBar->addAction(actStop);
        toolBar->addAction(actHostInfo);
        toolBar->addAction(actClear);
        toolBar->addAction(actQuit);

        retranslateUi(TCPServer);
        QObject::connect(actQuit, SIGNAL(triggered()), TCPServer, SLOT(close()));

        QMetaObject::connectSlotsByName(TCPServer);
    } // setupUi

    void retranslateUi(QMainWindow *TCPServer)
    {
        TCPServer->setWindowTitle(QApplication::translate("TCPServer", "TCPServer", Q_NULLPTR));
        actStart->setText(QApplication::translate("TCPServer", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStart->setToolTip(QApplication::translate("TCPServer", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("TCPServer", "\345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("TCPServer", "\345\201\234\346\255\242\347\233\221\345\220\254", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TCPServer", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TCPServer", "\351\200\200\345\207\272\346\234\254\347\250\213\345\272\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("TCPServer", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("TCPServer", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actHostInfo->setText(QApplication::translate("TCPServer", "\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actHostInfo->setToolTip(QApplication::translate("TCPServer", "\350\216\267\345\217\226\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("TCPServer", "\346\234\215\345\212\241\345\231\250\347\233\221\345\220\254\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        comboIP->clear();
        comboIP->insertItems(0, QStringList()
         << QApplication::translate("TCPServer", "127.0.0.1", Q_NULLPTR)
        );
        label->setText(QApplication::translate("TCPServer", "\346\234\215\345\212\241\345\231\250\347\233\221\345\220\254\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        btnSend->setText(QApplication::translate("TCPServer", "\346\234\215\345\212\241\345\231\250\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TCPServer", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TCPServer: public Ui_TCPServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
