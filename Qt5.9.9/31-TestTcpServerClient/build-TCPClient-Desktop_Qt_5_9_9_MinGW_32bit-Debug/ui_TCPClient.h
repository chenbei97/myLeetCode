/********************************************************************************
** Form generated from reading UI file 'TCPClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPClient
{
public:
    QAction *actConnect;
    QAction *actDisconnect;
    QAction *actQuit;
    QAction *actClear;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboServer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinPort;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *editMsg;
    QPushButton *btnSend;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TCPClient)
    {
        if (TCPClient->objectName().isEmpty())
            TCPClient->setObjectName(QStringLiteral("TCPClient"));
        TCPClient->resize(640, 576);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TCPClient->setFont(font);
        actConnect = new QAction(TCPClient);
        actConnect->setObjectName(QStringLiteral("actConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/051.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actConnect->setIcon(icon);
        actDisconnect = new QAction(TCPClient);
        actDisconnect->setObjectName(QStringLiteral("actDisconnect"));
        actDisconnect->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/075.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actDisconnect->setIcon(icon1);
        actQuit = new QAction(TCPClient);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actClear = new QAction(TCPClient);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon3);
        centralwidget = new QWidget(TCPClient);
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

        horizontalLayout->addWidget(label);

        comboServer = new QComboBox(centralwidget);
        comboServer->setObjectName(QStringLiteral("comboServer"));
        comboServer->setMinimumSize(QSize(130, 30));
        comboServer->setEditable(true);

        horizontalLayout->addWidget(comboServer);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 30));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        spinPort = new QSpinBox(centralwidget);
        spinPort->setObjectName(QStringLiteral("spinPort"));
        spinPort->setMinimumSize(QSize(80, 30));
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
        editMsg->setMinimumSize(QSize(300, 30));

        horizontalLayout_3->addWidget(editMsg);

        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setMinimumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        TCPClient->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TCPClient);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TCPClient->setStatusBar(statusbar);
        toolBar = new QToolBar(TCPClient);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TCPClient->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actConnect);
        toolBar->addAction(actDisconnect);
        toolBar->addAction(actClear);
        toolBar->addAction(actQuit);

        retranslateUi(TCPClient);
        QObject::connect(actQuit, SIGNAL(triggered()), TCPClient, SLOT(close()));

        QMetaObject::connectSlotsByName(TCPClient);
    } // setupUi

    void retranslateUi(QMainWindow *TCPClient)
    {
        TCPClient->setWindowTitle(QApplication::translate("TCPClient", "TCPClient", Q_NULLPTR));
        actConnect->setText(QApplication::translate("TCPClient", "\350\277\236\346\216\245\345\210\260\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actConnect->setToolTip(QApplication::translate("TCPClient", "\350\277\236\346\216\245\345\210\260TCP\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDisconnect->setText(QApplication::translate("TCPClient", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDisconnect->setToolTip(QApplication::translate("TCPClient", "\346\226\255\345\274\200TCP\350\277\236\346\216\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TCPClient", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TCPClient", "\351\200\200\345\207\272\346\234\254\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("TCPClient", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("TCPClient", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("TCPClient", "\350\277\236\346\216\245\347\232\204\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        comboServer->clear();
        comboServer->insertItems(0, QStringList()
         << QApplication::translate("TCPClient", "127.0.0.1", Q_NULLPTR)
         << QApplication::translate("TCPClient", "localHost", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("TCPClient", "\350\277\236\346\216\245\347\232\204\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        btnSend->setText(QApplication::translate("TCPClient", "\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TCPClient", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TCPClient: public Ui_TCPClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
