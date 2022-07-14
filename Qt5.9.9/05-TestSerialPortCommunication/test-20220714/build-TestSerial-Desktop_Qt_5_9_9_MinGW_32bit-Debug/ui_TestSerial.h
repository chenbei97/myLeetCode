/********************************************************************************
** Form generated from reading UI file 'TestSerial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSERIAL_H
#define UI_TESTSERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestSerial
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestSerial)
    {
        if (TestSerial->objectName().isEmpty())
            TestSerial->setObjectName(QStringLiteral("TestSerial"));
        TestSerial->resize(800, 600);
        centralwidget = new QWidget(TestSerial);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 250, 141, 51));
        TestSerial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestSerial);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        TestSerial->setMenuBar(menubar);
        statusbar = new QStatusBar(TestSerial);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestSerial->setStatusBar(statusbar);

        retranslateUi(TestSerial);

        QMetaObject::connectSlotsByName(TestSerial);
    } // setupUi

    void retranslateUi(QMainWindow *TestSerial)
    {
        TestSerial->setWindowTitle(QApplication::translate("TestSerial", "TestSerial", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestSerial: public Ui_TestSerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSERIAL_H
