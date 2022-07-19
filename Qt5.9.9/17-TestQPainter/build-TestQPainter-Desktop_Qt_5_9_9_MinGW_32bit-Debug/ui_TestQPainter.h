/********************************************************************************
** Form generated from reading UI file 'TestQPainter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQPAINTER_H
#define UI_TESTQPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQPainter
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestQPainter)
    {
        if (TestQPainter->objectName().isEmpty())
            TestQPainter->setObjectName(QStringLiteral("TestQPainter"));
        TestQPainter->resize(700, 550);
        centralwidget = new QWidget(TestQPainter);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TestQPainter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestQPainter);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 25));
        TestQPainter->setMenuBar(menubar);
        statusbar = new QStatusBar(TestQPainter);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQPainter->setStatusBar(statusbar);

        retranslateUi(TestQPainter);

        QMetaObject::connectSlotsByName(TestQPainter);
    } // setupUi

    void retranslateUi(QMainWindow *TestQPainter)
    {
        TestQPainter->setWindowTitle(QApplication::translate("TestQPainter", "TestQPainter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQPainter: public Ui_TestQPainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQPAINTER_H
