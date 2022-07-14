/********************************************************************************
** Form generated from reading UI file 'TestMultiWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMULTIWINDOW_H
#define UI_TESTMULTIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMultiWindow
{
public:
    QAction *actWindowInsite;
    QAction *actWidgetInsite;
    QAction *actQuit;
    QAction *actDoc_Open;
    QAction *actWindow;
    QAction *actWidget;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestMultiWindow)
    {
        if (TestMultiWindow->objectName().isEmpty())
            TestMultiWindow->setObjectName(QStringLiteral("TestMultiWindow"));
        TestMultiWindow->resize(1185, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestMultiWindow->setFont(font);
        actWindowInsite = new QAction(TestMultiWindow);
        actWindowInsite->setObjectName(QStringLiteral("actWindowInsite"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actWindowInsite->setIcon(icon);
        actWidgetInsite = new QAction(TestMultiWindow);
        actWidgetInsite->setObjectName(QStringLiteral("actWidgetInsite"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actWidgetInsite->setIcon(icon1);
        actQuit = new QAction(TestMultiWindow);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actDoc_Open = new QAction(TestMultiWindow);
        actDoc_Open->setObjectName(QStringLiteral("actDoc_Open"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_Open->setIcon(icon3);
        actWindow = new QAction(TestMultiWindow);
        actWindow->setObjectName(QStringLiteral("actWindow"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/3.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actWindow->setIcon(icon4);
        actWidget = new QAction(TestMultiWindow);
        actWidget->setObjectName(QStringLiteral("actWidget"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/804.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actWidget->setIcon(icon5);
        centralwidget = new QWidget(TestMultiWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(230, 100, 601, 311));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        TestMultiWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestMultiWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1185, 28));
        TestMultiWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TestMultiWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestMultiWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(TestMultiWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestMultiWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actWidgetInsite);
        toolBar->addAction(actWidget);
        toolBar->addAction(actWindowInsite);
        toolBar->addAction(actWindow);
        toolBar->addAction(actQuit);

        retranslateUi(TestMultiWindow);
        QObject::connect(actQuit, SIGNAL(triggered()), TestMultiWindow, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TestMultiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestMultiWindow)
    {
        TestMultiWindow->setWindowTitle(QApplication::translate("TestMultiWindow", "TestMultiWindow", Q_NULLPTR));
        actWindowInsite->setText(QApplication::translate("TestMultiWindow", "\345\265\214\345\205\245\345\274\217MainWindow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWindowInsite->setToolTip(QApplication::translate("TestMultiWindow", "\345\265\214\345\205\245\345\274\217MainWindow", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actWidgetInsite->setText(QApplication::translate("TestMultiWindow", "\345\265\214\345\205\245\345\274\217Widget", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWidgetInsite->setToolTip(QApplication::translate("TestMultiWindow", "Widget\345\265\214\345\205\245\345\274\217\347\252\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestMultiWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestMultiWindow", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDoc_Open->setText(QApplication::translate("TestMultiWindow", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDoc_Open->setToolTip(QApplication::translate("TestMultiWindow", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actWindow->setText(QApplication::translate("TestMultiWindow", "\347\213\254\347\253\213MainWindow\347\252\227\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWindow->setToolTip(QApplication::translate("TestMultiWindow", "\347\213\254\347\253\213MainWindow\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actWidget->setText(QApplication::translate("TestMultiWindow", "\347\213\254\347\253\213Widget\347\252\227\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actWidget->setToolTip(QApplication::translate("TestMultiWindow", "\346\226\260\345\273\272Widget\347\213\254\347\253\213\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestMultiWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestMultiWindow: public Ui_TestMultiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMULTIWINDOW_H
