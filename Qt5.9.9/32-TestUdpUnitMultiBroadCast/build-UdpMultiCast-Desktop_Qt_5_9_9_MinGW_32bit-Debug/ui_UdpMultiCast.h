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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpMultiCast
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UdpMultiCast)
    {
        if (UdpMultiCast->objectName().isEmpty())
            UdpMultiCast->setObjectName(QStringLiteral("UdpMultiCast"));
        UdpMultiCast->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        UdpMultiCast->setFont(font);
        centralwidget = new QWidget(UdpMultiCast);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        UdpMultiCast->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UdpMultiCast);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UdpMultiCast->setStatusBar(statusbar);

        retranslateUi(UdpMultiCast);

        QMetaObject::connectSlotsByName(UdpMultiCast);
    } // setupUi

    void retranslateUi(QMainWindow *UdpMultiCast)
    {
        UdpMultiCast->setWindowTitle(QApplication::translate("UdpMultiCast", "UdpMultiCast", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UdpMultiCast: public Ui_UdpMultiCast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPMULTICAST_H
