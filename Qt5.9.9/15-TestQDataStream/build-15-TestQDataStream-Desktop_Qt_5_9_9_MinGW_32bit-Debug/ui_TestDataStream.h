/********************************************************************************
** Form generated from reading UI file 'TestDataStream.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDATASTREAM_H
#define UI_TESTDATASTREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestDataStream
{
public:
    QAction *actOpen;
    QAction *actSave;
    QAction *actAppend;
    QAction *actInsert;
    QAction *actDelete;
    QAction *actExit;
    QAction *actModelData;
    QAction *actAlignLeft;
    QAction *actAlignCenter;
    QAction *actAlignRight;
    QAction *actFontBold;
    QAction *actTabReset;
    QAction *actOpenBin;
    QAction *actSaveBin;
    QAction *actOpenTxt;
    QAction *actSaveTxt;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QPlainTextEdit *plainTextEdit;
    QWidget *tab2;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar1;
    QToolBar *toolBar2;

    void setupUi(QMainWindow *TestDataStream)
    {
        if (TestDataStream->objectName().isEmpty())
            TestDataStream->setObjectName(QStringLiteral("TestDataStream"));
        TestDataStream->resize(1450, 850);
        TestDataStream->setMinimumSize(QSize(1450, 850));
        TestDataStream->setMaximumSize(QSize(1450, 850));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        TestDataStream->setFont(font);
        actOpen = new QAction(TestDataStream);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actSave = new QAction(TestDataStream);
        actSave->setObjectName(QStringLiteral("actSave"));
        actSave->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon1);
        actAppend = new QAction(TestDataStream);
        actAppend->setObjectName(QStringLiteral("actAppend"));
        actAppend->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/append.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAppend->setIcon(icon2);
        actInsert = new QAction(TestDataStream);
        actInsert->setObjectName(QStringLiteral("actInsert"));
        actInsert->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/306.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actInsert->setIcon(icon3);
        actDelete = new QAction(TestDataStream);
        actDelete->setObjectName(QStringLiteral("actDelete"));
        actDelete->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon4);
        actExit = new QAction(TestDataStream);
        actExit->setObjectName(QStringLiteral("actExit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon5);
        actModelData = new QAction(TestDataStream);
        actModelData->setObjectName(QStringLiteral("actModelData"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/import1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actModelData->setIcon(icon6);
        actAlignLeft = new QAction(TestDataStream);
        actAlignLeft->setObjectName(QStringLiteral("actAlignLeft"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/508.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignLeft->setIcon(icon7);
        actAlignCenter = new QAction(TestDataStream);
        actAlignCenter->setObjectName(QStringLiteral("actAlignCenter"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/510.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignCenter->setIcon(icon8);
        actAlignRight = new QAction(TestDataStream);
        actAlignRight->setObjectName(QStringLiteral("actAlignRight"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/512.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignRight->setIcon(icon9);
        actFontBold = new QAction(TestDataStream);
        actFontBold->setObjectName(QStringLiteral("actFontBold"));
        actFontBold->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/500.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontBold->setIcon(icon10);
        actTabReset = new QAction(TestDataStream);
        actTabReset->setObjectName(QStringLiteral("actTabReset"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTabReset->setIcon(icon11);
        actOpenBin = new QAction(TestDataStream);
        actOpenBin->setObjectName(QStringLiteral("actOpenBin"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/126.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpenBin->setIcon(icon12);
        actSaveBin = new QAction(TestDataStream);
        actSaveBin->setObjectName(QStringLiteral("actSaveBin"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/066.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        actSaveBin->setIcon(icon13);
        actOpenTxt = new QAction(TestDataStream);
        actOpenTxt->setObjectName(QStringLiteral("actOpenTxt"));
        actOpenTxt->setIcon(icon);
        actSaveTxt = new QAction(TestDataStream);
        actSaveTxt->setObjectName(QStringLiteral("actSaveTxt"));
        actSaveTxt->setIcon(icon1);
        centralwidget = new QWidget(TestDataStream);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 1441, 681));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        plainTextEdit = new QPlainTextEdit(tab1);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 1271, 621));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tableView = new QTableView(tab2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 1421, 621));
        tableView->setFont(font);
        tabWidget->addTab(tab2, QString());
        TestDataStream->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestDataStream);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1450, 29));
        TestDataStream->setMenuBar(menubar);
        statusbar = new QStatusBar(TestDataStream);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestDataStream->setStatusBar(statusbar);
        toolBar1 = new QToolBar(TestDataStream);
        toolBar1->setObjectName(QStringLiteral("toolBar1"));
        toolBar1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestDataStream->addToolBar(Qt::TopToolBarArea, toolBar1);
        toolBar2 = new QToolBar(TestDataStream);
        toolBar2->setObjectName(QStringLiteral("toolBar2"));
        toolBar2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestDataStream->addToolBar(Qt::TopToolBarArea, toolBar2);
        TestDataStream->insertToolBarBreak(toolBar2);

        toolBar1->addAction(actOpen);
        toolBar1->addAction(actSave);
        toolBar1->addAction(actOpenBin);
        toolBar1->addAction(actSaveBin);
        toolBar1->addAction(actTabReset);
        toolBar1->addAction(actAppend);
        toolBar1->addAction(actInsert);
        toolBar1->addAction(actDelete);
        toolBar2->addAction(actOpenTxt);
        toolBar2->addAction(actSaveTxt);
        toolBar2->addAction(actModelData);
        toolBar2->addAction(actAlignLeft);
        toolBar2->addAction(actAlignCenter);
        toolBar2->addAction(actAlignRight);
        toolBar2->addAction(actFontBold);
        toolBar2->addAction(actExit);

        retranslateUi(TestDataStream);
        QObject::connect(actExit, SIGNAL(triggered()), TestDataStream, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TestDataStream);
    } // setupUi

    void retranslateUi(QMainWindow *TestDataStream)
    {
        TestDataStream->setWindowTitle(QApplication::translate("TestDataStream", "TestDataStream", Q_NULLPTR));
        actOpen->setText(QApplication::translate("TestDataStream", "\346\211\223\345\274\200stm\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("TestDataStream", "\346\211\223\345\274\200\351\242\204\345\256\232\344\271\211\347\274\226\347\240\201\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSave->setText(QApplication::translate("TestDataStream", "\344\277\235\345\255\230stm\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSave->setToolTip(QApplication::translate("TestDataStream", "\344\277\235\345\255\230\344\270\272\351\242\204\345\256\232\344\271\211\347\274\226\347\240\201\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAppend->setText(QApplication::translate("TestDataStream", "\346\267\273\345\212\240\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAppend->setToolTip(QApplication::translate("TestDataStream", "\346\267\273\345\212\240\344\270\200\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actInsert->setText(QApplication::translate("TestDataStream", "\346\217\222\345\205\245\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actInsert->setToolTip(QApplication::translate("TestDataStream", "\346\217\222\345\205\245\344\270\200\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDelete->setText(QApplication::translate("TestDataStream", "\345\210\240\351\231\244\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDelete->setToolTip(QApplication::translate("TestDataStream", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actExit->setText(QApplication::translate("TestDataStream", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actExit->setToolTip(QApplication::translate("TestDataStream", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actModelData->setText(QApplication::translate("TestDataStream", "\346\226\207\346\234\254\346\230\276\347\244\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actModelData->setToolTip(QApplication::translate("TestDataStream", "\346\250\241\345\236\213\346\225\260\346\215\256\346\230\276\347\244\272\345\210\260\346\226\207\346\234\254\346\241\206\351\207\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignLeft->setText(QApplication::translate("TestDataStream", "\345\261\205\345\267\246", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignLeft->setToolTip(QApplication::translate("TestDataStream", "\346\226\207\345\255\227\345\267\246\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignCenter->setText(QApplication::translate("TestDataStream", "\345\261\205\344\270\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignCenter->setToolTip(QApplication::translate("TestDataStream", "\346\226\207\345\255\227\345\261\205\344\270\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignRight->setText(QApplication::translate("TestDataStream", "\345\261\205\345\217\263", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignRight->setToolTip(QApplication::translate("TestDataStream", "\346\226\207\345\255\227\345\217\263\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFontBold->setText(QApplication::translate("TestDataStream", "\347\262\227\344\275\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFontBold->setToolTip(QApplication::translate("TestDataStream", "\347\262\227\344\275\223\345\255\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actTabReset->setText(QApplication::translate("TestDataStream", "\350\241\250\346\240\274\345\244\215\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTabReset->setToolTip(QApplication::translate("TestDataStream", "\350\241\250\346\240\274\345\244\215\344\275\215", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actOpenBin->setText(QApplication::translate("TestDataStream", "\346\211\223\345\274\200dat\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpenBin->setToolTip(QApplication::translate("TestDataStream", "\346\211\223\345\274\200\346\240\207\345\207\206\347\274\226\347\240\201\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSaveBin->setText(QApplication::translate("TestDataStream", "\344\277\235\345\255\230dat\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSaveBin->setToolTip(QApplication::translate("TestDataStream", "\344\277\235\345\255\230\344\270\272\346\240\207\345\207\206\347\274\226\347\240\201\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actOpenTxt->setText(QApplication::translate("TestDataStream", "\346\211\223\345\274\200txt\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpenTxt->setToolTip(QApplication::translate("TestDataStream", "\346\211\223\345\274\200txt\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSaveTxt->setText(QApplication::translate("TestDataStream", "\344\277\235\345\255\230txt\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSaveTxt->setToolTip(QApplication::translate("TestDataStream", "\344\277\235\345\255\230txt\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("TestDataStream", "\346\226\207\346\234\254", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("TestDataStream", "\350\241\250\346\240\274", Q_NULLPTR));
        toolBar1->setWindowTitle(QApplication::translate("TestDataStream", "toolBar", Q_NULLPTR));
        toolBar2->setWindowTitle(QApplication::translate("TestDataStream", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestDataStream: public Ui_TestDataStream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDATASTREAM_H
