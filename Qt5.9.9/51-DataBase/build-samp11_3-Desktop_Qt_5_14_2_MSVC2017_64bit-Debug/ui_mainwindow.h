/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpenDB;
    QAction *actQuit;
    QAction *actRecInsert;
    QAction *actRecDelete;
    QAction *actRecEdit;
    QAction *actScan;
    QWidget *centralWidget;
    QTableView *tableView;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(551, 387);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        actOpenDB = new QAction(MainWindow);
        actOpenDB->setObjectName(QString::fromUtf8("actOpenDB"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/open3.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpenDB->setIcon(icon);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actRecInsert = new QAction(MainWindow);
        actRecInsert->setObjectName(QString::fromUtf8("actRecInsert"));
        actRecInsert->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/306.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecInsert->setIcon(icon2);
        actRecDelete = new QAction(MainWindow);
        actRecDelete->setObjectName(QString::fromUtf8("actRecDelete"));
        actRecDelete->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/delete1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecDelete->setIcon(icon3);
        actRecEdit = new QAction(MainWindow);
        actRecEdit->setObjectName(QString::fromUtf8("actRecEdit"));
        actRecEdit->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/812.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecEdit->setIcon(icon4);
        actScan = new QAction(MainWindow);
        actScan->setObjectName(QString::fromUtf8("actScan"));
        actScan->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/up.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actScan->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 10, 441, 261));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 551, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actOpenDB);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actRecInsert);
        mainToolBar->addAction(actRecEdit);
        mainToolBar->addAction(actRecDelete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actScan);
        mainToolBar->addAction(actQuit);

        retranslateUi(MainWindow);
        QObject::connect(actQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QSqlQuery\347\232\204\344\275\277\347\224\250", nullptr));
        actOpenDB->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\225\260\346\215\256\345\272\223", nullptr));
#if QT_CONFIG(tooltip)
        actOpenDB->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\225\260\346\215\256\345\272\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actQuit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actRecInsert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actRecInsert->setToolTip(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actRecDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actRecDelete->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actRecEdit->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actRecEdit->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        actScan->setText(QCoreApplication::translate("MainWindow", "\346\266\250\345\267\245\350\265\204", nullptr));
#if QT_CONFIG(tooltip)
        actScan->setToolTip(QCoreApplication::translate("MainWindow", "\346\266\250\345\267\245\350\265\204", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
