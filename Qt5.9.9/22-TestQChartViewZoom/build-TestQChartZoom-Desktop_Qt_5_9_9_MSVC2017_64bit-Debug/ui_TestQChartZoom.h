/********************************************************************************
** Form generated from reading UI file 'TestQChartZoom.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQCHARTZOOM_H
#define UI_TESTQCHARTZOOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <customChartView.h>

QT_BEGIN_NAMESPACE

class Ui_TestQChartZoom
{
public:
    QAction *actZoomReset;
    QAction *actQuit;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    customChartView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestQChartZoom)
    {
        if (TestQChartZoom->objectName().isEmpty())
            TestQChartZoom->setObjectName(QStringLiteral("TestQChartZoom"));
        TestQChartZoom->resize(1000, 800);
        TestQChartZoom->setMinimumSize(QSize(1000, 800));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQChartZoom->setFont(font);
        actZoomReset = new QAction(TestQChartZoom);
        actZoomReset->setObjectName(QStringLiteral("actZoomReset"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/414.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomReset->setIcon(icon);
        actQuit = new QAction(TestQChartZoom);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actZoomIn = new QAction(TestQChartZoom);
        actZoomIn->setObjectName(QStringLiteral("actZoomIn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/418.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon2);
        actZoomOut = new QAction(TestQChartZoom);
        actZoomOut->setObjectName(QStringLiteral("actZoomOut"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/416.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon3);
        centralwidget = new QWidget(TestQChartZoom);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new customChartView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        TestQChartZoom->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestQChartZoom);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 23));
        TestQChartZoom->setMenuBar(menubar);
        statusbar = new QStatusBar(TestQChartZoom);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQChartZoom->setStatusBar(statusbar);
        toolBar = new QToolBar(TestQChartZoom);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestQChartZoom->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actZoomIn);
        toolBar->addAction(actZoomOut);
        toolBar->addAction(actZoomReset);
        toolBar->addAction(actQuit);

        retranslateUi(TestQChartZoom);
        QObject::connect(actQuit, SIGNAL(triggered()), TestQChartZoom, SLOT(close()));

        QMetaObject::connectSlotsByName(TestQChartZoom);
    } // setupUi

    void retranslateUi(QMainWindow *TestQChartZoom)
    {
        TestQChartZoom->setWindowTitle(QApplication::translate("TestQChartZoom", "TestQChartZoom", Q_NULLPTR));
        actZoomReset->setText(QApplication::translate("TestQChartZoom", "\345\216\237\345\247\213\345\244\247\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actZoomReset->setToolTip(QApplication::translate("TestQChartZoom", "\345\216\237\345\247\213\345\244\247\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestQChartZoom", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestQChartZoom", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actZoomIn->setText(QApplication::translate("TestQChartZoom", "\346\224\276\345\244\247", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actZoomIn->setToolTip(QApplication::translate("TestQChartZoom", "\346\224\276\345\244\247", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actZoomOut->setText(QApplication::translate("TestQChartZoom", "\347\274\251\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actZoomOut->setToolTip(QApplication::translate("TestQChartZoom", "\347\274\251\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestQChartZoom", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQChartZoom: public Ui_TestQChartZoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQCHARTZOOM_H
