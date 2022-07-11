/********************************************************************************
** Form generated from reading UI file 'testdelegate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDELEGATE_H
#define UI_TESTDELEGATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestDelegate
{
public:
    QAction *actOpen;
    QAction *actAppend;
    QAction *actSave;
    QAction *actInsert;
    QAction *actDelete;
    QAction *actExit;
    QAction *actModelData;
    QAction *actAlignLeft;
    QAction *actAlignCenter;
    QAction *actAlignRight;
    QAction *actFontBold;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestDelegate)
    {
        if (TestDelegate->objectName().isEmpty())
            TestDelegate->setObjectName(QStringLiteral("TestDelegate"));
        TestDelegate->resize(2171, 1072);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestDelegate->setFont(font);
        actOpen = new QAction(TestDelegate);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/306.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actAppend = new QAction(TestDelegate);
        actAppend->setObjectName(QStringLiteral("actAppend"));
        actAppend->setCheckable(false);
        actAppend->setChecked(false);
        actAppend->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/append.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAppend->setIcon(icon1);
        actSave = new QAction(TestDelegate);
        actSave->setObjectName(QStringLiteral("actSave"));
        actSave->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon2);
        actInsert = new QAction(TestDelegate);
        actInsert->setObjectName(QStringLiteral("actInsert"));
        actInsert->setEnabled(false);
        actInsert->setIcon(icon);
        actDelete = new QAction(TestDelegate);
        actDelete->setObjectName(QStringLiteral("actDelete"));
        actDelete->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon3);
        actExit = new QAction(TestDelegate);
        actExit->setObjectName(QStringLiteral("actExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon4);
        actModelData = new QAction(TestDelegate);
        actModelData->setObjectName(QStringLiteral("actModelData"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/import1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actModelData->setIcon(icon5);
        actAlignLeft = new QAction(TestDelegate);
        actAlignLeft->setObjectName(QStringLiteral("actAlignLeft"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons/508.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignLeft->setIcon(icon6);
        actAlignCenter = new QAction(TestDelegate);
        actAlignCenter->setObjectName(QStringLiteral("actAlignCenter"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("icons/510.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignCenter->setIcon(icon7);
        actAlignRight = new QAction(TestDelegate);
        actAlignRight->setObjectName(QStringLiteral("actAlignRight"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("icons/512.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignRight->setIcon(icon8);
        actFontBold = new QAction(TestDelegate);
        actFontBold->setObjectName(QStringLiteral("actFontBold"));
        actFontBold->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral("icons/500.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontBold->setIcon(icon9);
        centralwidget = new QWidget(TestDelegate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 2108, 1052));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(layoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(1050, 900));
        plainTextEdit->setMaximumSize(QSize(1050, 900));
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        horizontalLayout->addWidget(plainTextEdit);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(1050, 900));
        tableView->setMaximumSize(QSize(1050, 900));
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tableView->setAlternatingRowColors(true);

        horizontalLayout->addWidget(tableView);

        TestDelegate->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestDelegate);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2171, 28));
        TestDelegate->setMenuBar(menubar);
        statusbar = new QStatusBar(TestDelegate);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestDelegate->setStatusBar(statusbar);
        toolBar = new QToolBar(TestDelegate);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestDelegate->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actOpen);
        toolBar->addAction(actSave);
        toolBar->addAction(actModelData);
        toolBar->addAction(actAppend);
        toolBar->addAction(actInsert);
        toolBar->addAction(actDelete);
        toolBar->addAction(actAlignLeft);
        toolBar->addAction(actAlignCenter);
        toolBar->addAction(actAlignRight);
        toolBar->addAction(actFontBold);
        toolBar->addAction(actExit);

        retranslateUi(TestDelegate);

        QMetaObject::connectSlotsByName(TestDelegate);
    } // setupUi

    void retranslateUi(QMainWindow *TestDelegate)
    {
        TestDelegate->setWindowTitle(QApplication::translate("TestDelegate", "TestDelegate", Q_NULLPTR));
        actOpen->setText(QApplication::translate("TestDelegate", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("TestDelegate", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAppend->setText(QApplication::translate("TestDelegate", "\346\267\273\345\212\240\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAppend->setToolTip(QApplication::translate("TestDelegate", "\346\267\273\345\212\240\344\270\200\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSave->setText(QApplication::translate("TestDelegate", "\345\217\246\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSave->setToolTip(QApplication::translate("TestDelegate", "\350\241\250\346\240\274\345\206\205\345\256\271\345\217\246\345\255\230\344\270\272\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actInsert->setText(QApplication::translate("TestDelegate", "\346\217\222\345\205\245\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actInsert->setToolTip(QApplication::translate("TestDelegate", "\346\217\222\345\205\245\344\270\200\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDelete->setText(QApplication::translate("TestDelegate", "\345\210\240\351\231\244\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDelete->setToolTip(QApplication::translate("TestDelegate", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actExit->setText(QApplication::translate("TestDelegate", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actExit->setToolTip(QApplication::translate("TestDelegate", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actModelData->setText(QApplication::translate("TestDelegate", "\346\250\241\345\236\213\346\225\260\346\215\256\351\242\204\350\247\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actModelData->setToolTip(QApplication::translate("TestDelegate", "\346\250\241\345\236\213\346\225\260\346\215\256\346\230\276\347\244\272\345\210\260\346\226\207\346\234\254\346\241\206\351\207\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignLeft->setText(QApplication::translate("TestDelegate", "\345\261\205\345\267\246", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignLeft->setToolTip(QApplication::translate("TestDelegate", "\346\226\207\345\255\227\345\267\246\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignCenter->setText(QApplication::translate("TestDelegate", "\345\261\205\344\270\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignCenter->setToolTip(QApplication::translate("TestDelegate", "\346\226\207\345\255\227\345\261\205\344\270\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignRight->setText(QApplication::translate("TestDelegate", "\345\261\205\345\217\263", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignRight->setToolTip(QApplication::translate("TestDelegate", "\346\226\207\345\255\227\345\217\263\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFontBold->setText(QApplication::translate("TestDelegate", "\347\262\227\344\275\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFontBold->setToolTip(QApplication::translate("TestDelegate", "\347\262\227\344\275\223\345\255\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestDelegate", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestDelegate: public Ui_TestDelegate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDELEGATE_H
