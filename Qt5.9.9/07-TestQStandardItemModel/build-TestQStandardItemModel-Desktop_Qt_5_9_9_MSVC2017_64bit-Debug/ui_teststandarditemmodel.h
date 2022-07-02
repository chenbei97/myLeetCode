/********************************************************************************
** Form generated from reading UI file 'teststandarditemmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSTANDARDITEMMODEL_H
#define UI_TESTSTANDARDITEMMODEL_H

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

class Ui_TestStandardItemModel
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestStandardItemModel)
    {
        if (TestStandardItemModel->objectName().isEmpty())
            TestStandardItemModel->setObjectName(QStringLiteral("TestStandardItemModel"));
        TestStandardItemModel->resize(2150, 1030);
        TestStandardItemModel->setMinimumSize(QSize(2150, 1000));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestStandardItemModel->setFont(font);
        actOpen = new QAction(TestStandardItemModel);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/306.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actAppend = new QAction(TestStandardItemModel);
        actAppend->setObjectName(QStringLiteral("actAppend"));
        actAppend->setCheckable(false);
        actAppend->setChecked(false);
        actAppend->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/append.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAppend->setIcon(icon1);
        actSave = new QAction(TestStandardItemModel);
        actSave->setObjectName(QStringLiteral("actSave"));
        actSave->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon2);
        actInsert = new QAction(TestStandardItemModel);
        actInsert->setObjectName(QStringLiteral("actInsert"));
        actInsert->setEnabled(false);
        actInsert->setIcon(icon);
        actDelete = new QAction(TestStandardItemModel);
        actDelete->setObjectName(QStringLiteral("actDelete"));
        actDelete->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/delete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actDelete->setIcon(icon3);
        actExit = new QAction(TestStandardItemModel);
        actExit->setObjectName(QStringLiteral("actExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon4);
        actModelData = new QAction(TestStandardItemModel);
        actModelData->setObjectName(QStringLiteral("actModelData"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/import1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actModelData->setIcon(icon5);
        actAlignLeft = new QAction(TestStandardItemModel);
        actAlignLeft->setObjectName(QStringLiteral("actAlignLeft"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons/508.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignLeft->setIcon(icon6);
        actAlignCenter = new QAction(TestStandardItemModel);
        actAlignCenter->setObjectName(QStringLiteral("actAlignCenter"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("icons/510.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignCenter->setIcon(icon7);
        actAlignRight = new QAction(TestStandardItemModel);
        actAlignRight->setObjectName(QStringLiteral("actAlignRight"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("icons/512.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actAlignRight->setIcon(icon8);
        actFontBold = new QAction(TestStandardItemModel);
        actFontBold->setObjectName(QStringLiteral("actFontBold"));
        actFontBold->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral("icons/500.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFontBold->setIcon(icon9);
        centralwidget = new QWidget(TestStandardItemModel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 2108, 1052));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(1050, 900));
        plainTextEdit->setMaximumSize(QSize(1050, 900));
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        horizontalLayout->addWidget(plainTextEdit);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(1050, 900));
        tableView->setMaximumSize(QSize(1050, 900));
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tableView->setAlternatingRowColors(true);

        horizontalLayout->addWidget(tableView);

        TestStandardItemModel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestStandardItemModel);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2150, 23));
        TestStandardItemModel->setMenuBar(menubar);
        statusBar = new QStatusBar(TestStandardItemModel);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestStandardItemModel->setStatusBar(statusBar);
        toolBar = new QToolBar(TestStandardItemModel);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestStandardItemModel->addToolBar(Qt::TopToolBarArea, toolBar);

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

        retranslateUi(TestStandardItemModel);

        QMetaObject::connectSlotsByName(TestStandardItemModel);
    } // setupUi

    void retranslateUi(QMainWindow *TestStandardItemModel)
    {
        TestStandardItemModel->setWindowTitle(QApplication::translate("TestStandardItemModel", "TestStandardItemModel", Q_NULLPTR));
        actOpen->setText(QApplication::translate("TestStandardItemModel", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("TestStandardItemModel", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAppend->setText(QApplication::translate("TestStandardItemModel", "\346\267\273\345\212\240\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAppend->setToolTip(QApplication::translate("TestStandardItemModel", "\346\267\273\345\212\240\344\270\200\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSave->setText(QApplication::translate("TestStandardItemModel", "\345\217\246\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSave->setToolTip(QApplication::translate("TestStandardItemModel", "\350\241\250\346\240\274\345\206\205\345\256\271\345\217\246\345\255\230\344\270\272\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actInsert->setText(QApplication::translate("TestStandardItemModel", "\346\217\222\345\205\245\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actInsert->setToolTip(QApplication::translate("TestStandardItemModel", "\346\217\222\345\205\245\344\270\200\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDelete->setText(QApplication::translate("TestStandardItemModel", "\345\210\240\351\231\244\350\241\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDelete->setToolTip(QApplication::translate("TestStandardItemModel", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actExit->setText(QApplication::translate("TestStandardItemModel", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actExit->setToolTip(QApplication::translate("TestStandardItemModel", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actModelData->setText(QApplication::translate("TestStandardItemModel", "\346\250\241\345\236\213\346\225\260\346\215\256\351\242\204\350\247\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actModelData->setToolTip(QApplication::translate("TestStandardItemModel", "\346\250\241\345\236\213\346\225\260\346\215\256\346\230\276\347\244\272\345\210\260\346\226\207\346\234\254\346\241\206\351\207\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignLeft->setText(QApplication::translate("TestStandardItemModel", "\345\261\205\345\267\246", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignLeft->setToolTip(QApplication::translate("TestStandardItemModel", "\346\226\207\345\255\227\345\267\246\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignCenter->setText(QApplication::translate("TestStandardItemModel", "\345\261\205\344\270\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignCenter->setToolTip(QApplication::translate("TestStandardItemModel", "\346\226\207\345\255\227\345\261\205\344\270\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAlignRight->setText(QApplication::translate("TestStandardItemModel", "\345\261\205\345\217\263", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAlignRight->setToolTip(QApplication::translate("TestStandardItemModel", "\346\226\207\345\255\227\345\217\263\345\257\271\351\275\220", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFontBold->setText(QApplication::translate("TestStandardItemModel", "\347\262\227\344\275\223", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFontBold->setToolTip(QApplication::translate("TestStandardItemModel", "\347\262\227\344\275\223\345\255\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestStandardItemModel", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestStandardItemModel: public Ui_TestStandardItemModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSTANDARDITEMMODEL_H
