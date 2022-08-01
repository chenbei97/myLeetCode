/********************************************************************************
** Form generated from reading UI file 'UdpMultiCast.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPMULTICAST_H
#define UI_UDPMULTICAST_H

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

class Ui_UdpMultiCast
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
    QLabel *label_3;
    QComboBox *comboIP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinPort;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *editMsg;
    QPushButton *btnMulticast;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *UdpMultiCast)
    {
        if (UdpMultiCast->objectName().isEmpty())
            UdpMultiCast->setObjectName(QStringLiteral("UdpMultiCast"));
        UdpMultiCast->resize(672, 539);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        UdpMultiCast->setFont(font);
        actStart = new QAction(UdpMultiCast);
        actStart->setObjectName(QStringLiteral("actStart"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        actStop = new QAction(UdpMultiCast);
        actStop->setObjectName(QStringLiteral("actStop"));
        actStop->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actQuit = new QAction(UdpMultiCast);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actClear = new QAction(UdpMultiCast);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon3);
        actHostInfo = new QAction(UdpMultiCast);
        actHostInfo->setObjectName(QStringLiteral("actHostInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/110.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actHostInfo->setIcon(icon4);
        centralwidget = new QWidget(UdpMultiCast);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 30));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        comboIP = new QComboBox(centralwidget);
        comboIP->setObjectName(QStringLiteral("comboIP"));
        comboIP->setMinimumSize(QSize(225, 30));
        comboIP->setEditable(true);
        comboIP->setDuplicatesEnabled(false);

        horizontalLayout->addWidget(comboIP);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        spinPort = new QSpinBox(centralwidget);
        spinPort->setObjectName(QStringLiteral("spinPort"));
        spinPort->setMinimumSize(QSize(225, 30));
        spinPort->setMinimum(1);
        spinPort->setMaximum(65535);
        spinPort->setValue(35320);

        horizontalLayout_2->addWidget(spinPort);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        editMsg = new QLineEdit(centralwidget);
        editMsg->setObjectName(QStringLiteral("editMsg"));

        horizontalLayout_3->addWidget(editMsg);

        btnMulticast = new QPushButton(centralwidget);
        btnMulticast->setObjectName(QStringLiteral("btnMulticast"));
        btnMulticast->setMinimumSize(QSize(120, 30));

        horizontalLayout_3->addWidget(btnMulticast);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        UdpMultiCast->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UdpMultiCast);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UdpMultiCast->setStatusBar(statusbar);
        toolBar = new QToolBar(UdpMultiCast);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        UdpMultiCast->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actStart);
        toolBar->addAction(actStop);
        toolBar->addAction(actHostInfo);
        toolBar->addAction(actClear);
        toolBar->addAction(actQuit);

        retranslateUi(UdpMultiCast);
        QObject::connect(actQuit, SIGNAL(triggered()), UdpMultiCast, SLOT(close()));

        QMetaObject::connectSlotsByName(UdpMultiCast);
    } // setupUi

    void retranslateUi(QMainWindow *UdpMultiCast)
    {
        UdpMultiCast->setWindowTitle(QApplication::translate("UdpMultiCast", "UdpMultiCast", Q_NULLPTR));
        actStart->setText(QApplication::translate("UdpMultiCast", "\345\212\240\345\205\245\347\273\204\346\222\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStart->setToolTip(QApplication::translate("UdpMultiCast", "\345\212\240\345\205\245\347\273\204\346\222\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("UdpMultiCast", "\351\200\200\345\207\272\347\273\204\346\222\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("UdpMultiCast", "\351\200\200\345\207\272\347\273\204\346\222\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("UdpMultiCast", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("UdpMultiCast", "\351\200\200\345\207\272\346\234\254\347\250\213\345\272\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("UdpMultiCast", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("UdpMultiCast", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actHostInfo->setText(QApplication::translate("UdpMultiCast", "\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actHostInfo->setToolTip(QApplication::translate("UdpMultiCast", "\350\216\267\345\217\226\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("UdpMultiCast", "\347\273\204\346\222\255\345\234\260\345\235\200", Q_NULLPTR));
        comboIP->clear();
        comboIP->insertItems(0, QStringList()
         << QApplication::translate("UdpMultiCast", "239.255.43.21", Q_NULLPTR)
         << QApplication::translate("UdpMultiCast", "239.255.100.1", Q_NULLPTR)
         << QApplication::translate("UdpMultiCast", "239.255.255.100", Q_NULLPTR)
        );
        label->setText(QApplication::translate("UdpMultiCast", "\347\273\204\346\222\255\347\253\257\345\217\243", Q_NULLPTR));
        btnMulticast->setText(QApplication::translate("UdpMultiCast", "\347\273\204\346\222\255\346\266\210\346\201\257", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("UdpMultiCast", "224.0.0.0\357\275\236224.0.0.255\344\270\272\351\242\204\347\225\231\347\232\204\347\273\204\346\222\255\345\234\260\345\235\200(\346\260\270\344\271\205\345\234\260\345\235\200),\345\234\260\345\235\200224.0.0.0\344\277\235\347\225\231\344\270\215\345\201\232\345\210\206\351\205\215,\345\205\266\345\256\203255\344\270\252\345\234\260\345\235\200\344\276\233\350\267\257\347\224\261\345\215\217\350\256\256\344\275\277\347\224\250;\n"
"224.0.1.0\357\275\236224.0.1.255\346\230\257\345\205\254\347\224\250\347\273\204\346\222\255\345\234\260\345\235\200,\345\217\257\347\224\250\344\272\216Internet;\n"
"224.0.2.0\357\275\236238.255.255.255\344\270\272\347\224\250\346\210\267\345\217\257\347\224\250\347\232\204\347\273\204\346\222\255\345\234\260\345\235\200(\344\270\264\346\227\266\347\273\204\345\234\260\345\235\200),\345\205\250\347\275\221\350\214\203\345\233\264\345\206\205\346\234\211\346\225\210;\n"
"239.0.0.0\357\275\236239.255.255.255\344\270\272\346\234\254\345\234\260\347\256\241\347\220\206\347\273\204\346"
                        "\222\255\345\234\260\345\235\200\350\214\203\345\233\264,\344\273\205\345\234\250\347\211\271\345\256\232\347\232\204\346\234\254\345\234\260\350\214\203\345\233\264\345\206\205\346\234\211\346\225\210.\n"
"\346\225\205\350\213\245\346\230\257\345\256\266\345\272\255\346\210\226\350\200\205\345\212\236\345\205\254\345\256\244\345\261\200\345\237\237\347\275\221\345\206\205\346\265\213\350\257\225UDP\347\273\204\346\222\255\345\212\237\350\203\275,\345\217\257\344\273\245\344\275\277\347\224\250\347\232\204\345\234\260\345\235\200\350\214\203\345\233\264\346\230\257239.0.0.0~239.255.255.255", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("UdpMultiCast", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UdpMultiCast: public Ui_UdpMultiCast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPMULTICAST_H
