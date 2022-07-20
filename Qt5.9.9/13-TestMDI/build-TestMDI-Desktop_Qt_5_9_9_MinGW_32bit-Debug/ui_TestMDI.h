/********************************************************************************
** Form generated from reading UI file 'TestMDI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMDI_H
#define UI_TESTMDI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMDI
{
public:
    QAction *actDoc_New;
    QAction *actQuit;
    QAction *actDoc_Open;
    QAction *actFont;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actViewMode;
    QAction *actCascade;
    QAction *actTile;
    QAction *actCloseALL;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestMDI)
    {
        if (TestMDI->objectName().isEmpty())
            TestMDI->setObjectName(QStringLiteral("TestMDI"));
        TestMDI->resize(1550, 883);
        TestMDI->setMinimumSize(QSize(1550, 0));
        TestMDI->setMaximumSize(QSize(1600, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestMDI->setFont(font);
        actDoc_New = new QAction(TestMDI);
        actDoc_New->setObjectName(QStringLiteral("actDoc_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_New->setIcon(icon);
        actQuit = new QAction(TestMDI);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actDoc_Open = new QAction(TestMDI);
        actDoc_Open->setObjectName(QStringLiteral("actDoc_Open"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_Open->setIcon(icon2);
        actFont = new QAction(TestMDI);
        actFont->setObjectName(QStringLiteral("actFont"));
        actFont->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/506.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFont->setIcon(icon3);
        actCut = new QAction(TestMDI);
        actCut->setObjectName(QStringLiteral("actCut"));
        actCut->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/200.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon4);
        actCopy = new QAction(TestMDI);
        actCopy->setObjectName(QStringLiteral("actCopy"));
        actCopy->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/202.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon5);
        actPaste = new QAction(TestMDI);
        actPaste->setObjectName(QStringLiteral("actPaste"));
        actPaste->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/204.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon6);
        actViewMode = new QAction(TestMDI);
        actViewMode->setObjectName(QStringLiteral("actViewMode"));
        actViewMode->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/230.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actViewMode->setIcon(icon7);
        actCascade = new QAction(TestMDI);
        actCascade->setObjectName(QStringLiteral("actCascade"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/400.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCascade->setIcon(icon8);
        actTile = new QAction(TestMDI);
        actTile->setObjectName(QStringLiteral("actTile"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/406.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTile->setIcon(icon9);
        actCloseALL = new QAction(TestMDI);
        actCloseALL->setObjectName(QStringLiteral("actCloseALL"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/128.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCloseALL->setIcon(icon10);
        centralwidget = new QWidget(TestMDI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(10, 10, 1521, 781));
        TestMDI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestMDI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1550, 32));
        TestMDI->setMenuBar(menubar);
        statusbar = new QStatusBar(TestMDI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestMDI->setStatusBar(statusbar);
        toolBar = new QToolBar(TestMDI);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestMDI->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actDoc_New);
        toolBar->addAction(actDoc_Open);
        toolBar->addAction(actViewMode);
        toolBar->addAction(actCascade);
        toolBar->addAction(actTile);
        toolBar->addAction(actCloseALL);
        toolBar->addAction(actFont);
        toolBar->addAction(actCopy);
        toolBar->addAction(actCut);
        toolBar->addAction(actPaste);
        toolBar->addAction(actQuit);

        retranslateUi(TestMDI);
        QObject::connect(actQuit, SIGNAL(triggered()), TestMDI, SLOT(close()));

        QMetaObject::connectSlotsByName(TestMDI);
    } // setupUi

    void retranslateUi(QMainWindow *TestMDI)
    {
        TestMDI->setWindowTitle(QApplication::translate("TestMDI", "TestMDI", Q_NULLPTR));
        actDoc_New->setText(QApplication::translate("TestMDI", "\346\226\260\345\273\272\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDoc_New->setToolTip(QApplication::translate("TestMDI", "\346\226\260\345\273\272\346\226\207\346\241\243\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestMDI", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestMDI", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDoc_Open->setText(QApplication::translate("TestMDI", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDoc_Open->setToolTip(QApplication::translate("TestMDI", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFont->setText(QApplication::translate("TestMDI", "\345\255\227\344\275\223\350\256\276\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFont->setToolTip(QApplication::translate("TestMDI", "\345\255\227\344\275\223\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCut->setText(QApplication::translate("TestMDI", "\345\211\252\345\210\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCut->setToolTip(QApplication::translate("TestMDI", "\345\211\252\345\210\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCopy->setText(QApplication::translate("TestMDI", "\345\244\215\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCopy->setToolTip(QApplication::translate("TestMDI", "\345\244\215\345\210\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actPaste->setText(QApplication::translate("TestMDI", "\347\262\230\350\264\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actPaste->setToolTip(QApplication::translate("TestMDI", "\347\262\230\350\264\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actViewMode->setText(QApplication::translate("TestMDI", "MDI\346\250\241\345\274\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actViewMode->setToolTip(QApplication::translate("TestMDI", "\347\252\227\345\217\243\346\250\241\345\274\217\346\210\226\351\241\265\351\235\242\346\250\241\345\274\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCascade->setText(QApplication::translate("TestMDI", "\347\272\247\350\201\224\345\261\225\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCascade->setToolTip(QApplication::translate("TestMDI", "\347\252\227\345\217\243\347\272\247\350\201\224\345\261\225\345\274\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actTile->setText(QApplication::translate("TestMDI", "\345\271\263\351\223\272\345\261\225\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTile->setToolTip(QApplication::translate("TestMDI", "\347\252\227\345\217\243\345\271\263\351\223\272\345\261\225\345\274\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCloseALL->setText(QApplication::translate("TestMDI", "\345\205\263\351\227\255\345\205\250\351\203\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCloseALL->setToolTip(QApplication::translate("TestMDI", "\345\205\263\351\227\255\346\211\200\346\234\211\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestMDI", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestMDI: public Ui_TestMDI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMDI_H