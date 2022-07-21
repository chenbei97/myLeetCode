/********************************************************************************
** Form generated from reading UI file 'TestGraphicsViewDraw.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTGRAPHICSVIEWDRAW_H
#define UI_TESTGRAPHICSVIEWDRAW_H

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
#include "customgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_TestGraphicsViewDraw
{
public:
    QAction *actItem_Rect;
    QAction *actItem_Ellipse;
    QAction *actItem_Line;
    QAction *actEdit_Delete;
    QAction *actQuit;
    QAction *actItem_Text;
    QAction *actEdit_Front;
    QAction *actEdit_Back;
    QAction *actItem_Polygon;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actRotateLeft;
    QAction *actRotateRight;
    QAction *actRestore;
    QAction *actGroup;
    QAction *actGroupBreak;
    QAction *actItem_Circle;
    QAction *actItem_Triangle;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    customGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *TestGraphicsViewDraw)
    {
        if (TestGraphicsViewDraw->objectName().isEmpty())
            TestGraphicsViewDraw->setObjectName(QStringLiteral("TestGraphicsViewDraw"));
        TestGraphicsViewDraw->resize(1200, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestGraphicsViewDraw->setFont(font);
        actItem_Rect = new QAction(TestGraphicsViewDraw);
        actItem_Rect->setObjectName(QStringLiteral("actItem_Rect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/RECTANGL.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Rect->setIcon(icon);
        actItem_Ellipse = new QAction(TestGraphicsViewDraw);
        actItem_Ellipse->setObjectName(QStringLiteral("actItem_Ellipse"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ELLIPSE.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Ellipse->setIcon(icon1);
        actItem_Line = new QAction(TestGraphicsViewDraw);
        actItem_Line->setObjectName(QStringLiteral("actItem_Line"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/LINE.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Line->setIcon(icon2);
        actEdit_Delete = new QAction(TestGraphicsViewDraw);
        actEdit_Delete->setObjectName(QStringLiteral("actEdit_Delete"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/108.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actEdit_Delete->setIcon(icon3);
        actQuit = new QAction(TestGraphicsViewDraw);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon4);
        actItem_Text = new QAction(TestGraphicsViewDraw);
        actItem_Text->setObjectName(QStringLiteral("actItem_Text"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/800.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Text->setIcon(icon5);
        actEdit_Front = new QAction(TestGraphicsViewDraw);
        actEdit_Front->setObjectName(QStringLiteral("actEdit_Front"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/528.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actEdit_Front->setIcon(icon6);
        actEdit_Back = new QAction(TestGraphicsViewDraw);
        actEdit_Back->setObjectName(QStringLiteral("actEdit_Back"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/526.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actEdit_Back->setIcon(icon7);
        actItem_Polygon = new QAction(TestGraphicsViewDraw);
        actItem_Polygon->setObjectName(QStringLiteral("actItem_Polygon"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/FREEFORM.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Polygon->setIcon(icon8);
        actZoomIn = new QAction(TestGraphicsViewDraw);
        actZoomIn->setObjectName(QStringLiteral("actZoomIn"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon9);
        actZoomOut = new QAction(TestGraphicsViewDraw);
        actZoomOut->setObjectName(QStringLiteral("actZoomOut"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon10);
        actRotateLeft = new QAction(TestGraphicsViewDraw);
        actRotateLeft->setObjectName(QStringLiteral("actRotateLeft"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/rotateleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actRotateLeft->setIcon(icon11);
        actRotateRight = new QAction(TestGraphicsViewDraw);
        actRotateRight->setObjectName(QStringLiteral("actRotateRight"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/rotateright.png"), QSize(), QIcon::Normal, QIcon::Off);
        actRotateRight->setIcon(icon12);
        actRestore = new QAction(TestGraphicsViewDraw);
        actRestore->setObjectName(QStringLiteral("actRestore"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/420.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRestore->setIcon(icon13);
        actGroup = new QAction(TestGraphicsViewDraw);
        actGroup->setObjectName(QStringLiteral("actGroup"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/UNGROUP.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        actGroup->setIcon(icon14);
        actGroupBreak = new QAction(TestGraphicsViewDraw);
        actGroupBreak->setObjectName(QStringLiteral("actGroupBreak"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/128.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actGroupBreak->setIcon(icon15);
        actItem_Circle = new QAction(TestGraphicsViewDraw);
        actItem_Circle->setObjectName(QStringLiteral("actItem_Circle"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/08.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Circle->setIcon(icon16);
        actItem_Triangle = new QAction(TestGraphicsViewDraw);
        actItem_Triangle->setObjectName(QStringLiteral("actItem_Triangle"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/Icon1242.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actItem_Triangle->setIcon(icon17);
        centralwidget = new QWidget(TestGraphicsViewDraw);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new customGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(1100, 500));
        graphicsView->setMaximumSize(QSize(1100, 500));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        TestGraphicsViewDraw->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestGraphicsViewDraw);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 28));
        TestGraphicsViewDraw->setMenuBar(menubar);
        statusbar = new QStatusBar(TestGraphicsViewDraw);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestGraphicsViewDraw->setStatusBar(statusbar);
        toolBar = new QToolBar(TestGraphicsViewDraw);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestGraphicsViewDraw->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(TestGraphicsViewDraw);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        toolBar_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        TestGraphicsViewDraw->addToolBar(Qt::LeftToolBarArea, toolBar_2);

        toolBar->addAction(actZoomIn);
        toolBar->addAction(actZoomOut);
        toolBar->addAction(actRestore);
        toolBar->addAction(actRotateLeft);
        toolBar->addAction(actRotateRight);
        toolBar->addAction(actEdit_Front);
        toolBar->addAction(actEdit_Back);
        toolBar->addAction(actGroup);
        toolBar->addAction(actGroupBreak);
        toolBar->addAction(actEdit_Delete);
        toolBar->addAction(actQuit);
        toolBar_2->addAction(actItem_Rect);
        toolBar_2->addAction(actItem_Ellipse);
        toolBar_2->addAction(actItem_Circle);
        toolBar_2->addAction(actItem_Triangle);
        toolBar_2->addAction(actItem_Polygon);
        toolBar_2->addAction(actItem_Line);
        toolBar_2->addAction(actItem_Text);

        retranslateUi(TestGraphicsViewDraw);
        QObject::connect(actQuit, SIGNAL(triggered()), TestGraphicsViewDraw, SLOT(close()));

        QMetaObject::connectSlotsByName(TestGraphicsViewDraw);
    } // setupUi

    void retranslateUi(QMainWindow *TestGraphicsViewDraw)
    {
        TestGraphicsViewDraw->setWindowTitle(QApplication::translate("TestGraphicsViewDraw", "TestGraphicsViewDraw", Q_NULLPTR));
        actItem_Rect->setText(QApplication::translate("TestGraphicsViewDraw", "\347\237\251\345\275\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Rect->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\267\273\345\212\240\347\237\251\345\275\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actItem_Ellipse->setText(QApplication::translate("TestGraphicsViewDraw", "\346\244\255\345\234\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Ellipse->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\267\273\345\212\240\346\244\255\345\234\206\345\236\213", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actItem_Line->setText(QApplication::translate("TestGraphicsViewDraw", "\347\233\264\347\272\277", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Line->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\267\273\345\212\240\347\233\264\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actEdit_Delete->setText(QApplication::translate("TestGraphicsViewDraw", "\345\210\240\351\231\244", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actEdit_Delete->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\210\240\351\231\244\351\200\211\344\270\255\347\232\204\345\233\276\345\205\203", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestGraphicsViewDraw", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actItem_Text->setText(QApplication::translate("TestGraphicsViewDraw", "\346\226\207\345\255\227", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Text->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\267\273\345\212\240\346\226\207\345\255\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actEdit_Front->setText(QApplication::translate("TestGraphicsViewDraw", "\345\211\215\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actEdit_Front->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\261\205\344\272\216\346\234\200\345\211\215\351\235\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actEdit_Back->setText(QApplication::translate("TestGraphicsViewDraw", "\345\220\216\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actEdit_Back->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\261\205\344\272\216\346\234\200\345\220\216\351\235\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actItem_Polygon->setText(QApplication::translate("TestGraphicsViewDraw", "\346\242\257\345\275\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Polygon->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\267\273\345\212\240\346\242\257\345\275\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actZoomIn->setText(QApplication::translate("TestGraphicsViewDraw", "\346\224\276\345\244\247", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actZoomIn->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\224\276\345\244\247", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actZoomOut->setText(QApplication::translate("TestGraphicsViewDraw", "\347\274\251\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actZoomOut->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\347\274\251\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRotateLeft->setText(QApplication::translate("TestGraphicsViewDraw", "\345\267\246\346\227\213\350\275\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRotateLeft->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\267\246\346\227\213\350\275\254", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRotateRight->setText(QApplication::translate("TestGraphicsViewDraw", "\345\217\263\346\227\213\350\275\254", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRotateRight->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\217\263\346\227\213\350\275\254", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actRestore->setText(QApplication::translate("TestGraphicsViewDraw", "\346\201\242\345\244\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRestore->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\346\201\242\345\244\215\345\244\247\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actGroup->setText(QApplication::translate("TestGraphicsViewDraw", "\347\273\204\345\220\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actGroup->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\347\273\204\345\220\210", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actGroupBreak->setText(QApplication::translate("TestGraphicsViewDraw", "\346\211\223\346\225\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actGroupBreak->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\217\226\346\266\210\347\273\204\345\220\210", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actItem_Circle->setText(QApplication::translate("TestGraphicsViewDraw", "\345\234\206\345\275\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Circle->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\345\234\206\345\275\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actItem_Triangle->setText(QApplication::translate("TestGraphicsViewDraw", "\344\270\211\350\247\222\345\275\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actItem_Triangle->setToolTip(QApplication::translate("TestGraphicsViewDraw", "\344\270\211\350\247\222\345\275\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestGraphicsViewDraw", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("TestGraphicsViewDraw", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestGraphicsViewDraw: public Ui_TestGraphicsViewDraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTGRAPHICSVIEWDRAW_H
