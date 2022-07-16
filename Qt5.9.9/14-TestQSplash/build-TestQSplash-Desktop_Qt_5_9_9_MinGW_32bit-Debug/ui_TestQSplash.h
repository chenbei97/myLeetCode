/********************************************************************************
** Form generated from reading UI file 'TestQSplash.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQSPLASH_H
#define UI_TESTQSPLASH_H

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

class Ui_TestQSplash
{
public:
    QAction *actDoc_New;
    QAction *actQuit;
    QAction *actDoc_Open;
    QAction *actFont;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actCloseALL;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestQSplash)
    {
        if (TestQSplash->objectName().isEmpty())
            TestQSplash->setObjectName(QStringLiteral("TestQSplash"));
        TestQSplash->resize(1295, 913);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQSplash->setFont(font);
        actDoc_New = new QAction(TestQSplash);
        actDoc_New->setObjectName(QStringLiteral("actDoc_New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_New->setIcon(icon);
        actQuit = new QAction(TestQSplash);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon1);
        actDoc_Open = new QAction(TestQSplash);
        actDoc_Open->setObjectName(QStringLiteral("actDoc_Open"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDoc_Open->setIcon(icon2);
        actFont = new QAction(TestQSplash);
        actFont->setObjectName(QStringLiteral("actFont"));
        actFont->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/506.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFont->setIcon(icon3);
        actCut = new QAction(TestQSplash);
        actCut->setObjectName(QStringLiteral("actCut"));
        actCut->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/200.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon4);
        actCopy = new QAction(TestQSplash);
        actCopy->setObjectName(QStringLiteral("actCopy"));
        actCopy->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/202.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon5);
        actPaste = new QAction(TestQSplash);
        actPaste->setObjectName(QStringLiteral("actPaste"));
        actPaste->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/204.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon6);
        actCloseALL = new QAction(TestQSplash);
        actCloseALL->setObjectName(QStringLiteral("actCloseALL"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/128.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actCloseALL->setIcon(icon7);
        centralwidget = new QWidget(TestQSplash);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 40, 1231, 801));
        TestQSplash->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestQSplash);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1295, 28));
        TestQSplash->setMenuBar(menubar);
        statusbar = new QStatusBar(TestQSplash);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQSplash->setStatusBar(statusbar);
        toolBar = new QToolBar(TestQSplash);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestQSplash->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actDoc_New);
        toolBar->addAction(actDoc_Open);
        toolBar->addAction(actCloseALL);
        toolBar->addAction(actFont);
        toolBar->addAction(actCopy);
        toolBar->addAction(actCut);
        toolBar->addAction(actPaste);
        toolBar->addAction(actQuit);

        retranslateUi(TestQSplash);
        QObject::connect(actQuit, SIGNAL(triggered()), TestQSplash, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TestQSplash);
    } // setupUi

    void retranslateUi(QMainWindow *TestQSplash)
    {
        TestQSplash->setWindowTitle(QApplication::translate("TestQSplash", "TesyQSplash", Q_NULLPTR));
        actDoc_New->setText(QApplication::translate("TestQSplash", "\346\226\260\345\273\272\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDoc_New->setToolTip(QApplication::translate("TestQSplash", "\346\226\260\345\273\272\346\226\207\346\241\243\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestQSplash", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestQSplash", "\351\200\200\345\207\272\346\234\254\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDoc_Open->setText(QApplication::translate("TestQSplash", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDoc_Open->setToolTip(QApplication::translate("TestQSplash", "\346\211\223\345\274\200\346\226\207\346\241\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFont->setText(QApplication::translate("TestQSplash", "\345\255\227\344\275\223\350\256\276\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFont->setToolTip(QApplication::translate("TestQSplash", "\345\255\227\344\275\223\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCut->setText(QApplication::translate("TestQSplash", "\345\211\252\345\210\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCut->setToolTip(QApplication::translate("TestQSplash", "\345\211\252\345\210\207", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCopy->setText(QApplication::translate("TestQSplash", "\345\244\215\345\210\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCopy->setToolTip(QApplication::translate("TestQSplash", "\345\244\215\345\210\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actPaste->setText(QApplication::translate("TestQSplash", "\347\262\230\350\264\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actPaste->setToolTip(QApplication::translate("TestQSplash", "\347\262\230\350\264\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCloseALL->setText(QApplication::translate("TestQSplash", "\345\205\263\351\227\255\345\205\250\351\203\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCloseALL->setToolTip(QApplication::translate("TestQSplash", "\345\205\263\351\227\255\345\205\250\351\203\250\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestQSplash", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQSplash: public Ui_TestQSplash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQSPLASH_H
