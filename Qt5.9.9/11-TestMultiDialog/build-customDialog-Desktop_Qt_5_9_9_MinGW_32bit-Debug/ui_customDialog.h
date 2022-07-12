/********************************************************************************
** Form generated from reading UI file 'customDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMDIALOG_H
#define UI_CUSTOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customDialog
{
public:
    QAction *actTab_SetSize;
    QAction *actTab_SetHeader;
    QAction *actFile_Quit;
    QAction *actTab_Locate;
    QWidget *centralwidget;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *customDialog)
    {
        if (customDialog->objectName().isEmpty())
            customDialog->setObjectName(QStringLiteral("customDialog"));
        customDialog->resize(800, 600);
        customDialog->setMinimumSize(QSize(800, 600));
        customDialog->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        customDialog->setFont(font);
        actTab_SetSize = new QAction(customDialog);
        actTab_SetSize->setObjectName(QStringLiteral("actTab_SetSize"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/230.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTab_SetSize->setIcon(icon);
        actTab_SetHeader = new QAction(customDialog);
        actTab_SetHeader->setObjectName(QStringLiteral("actTab_SetHeader"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/516.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTab_SetHeader->setIcon(icon1);
        actFile_Quit = new QAction(customDialog);
        actFile_Quit->setObjectName(QStringLiteral("actFile_Quit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Quit->setIcon(icon2);
        actTab_Locate = new QAction(customDialog);
        actTab_Locate->setObjectName(QStringLiteral("actTab_Locate"));
        actTab_Locate->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/304.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTab_Locate->setIcon(icon3);
        centralwidget = new QWidget(customDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 771, 531));
        customDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(customDialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        customDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(customDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        customDialog->setStatusBar(statusbar);
        toolBar = new QToolBar(customDialog);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        customDialog->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actTab_SetSize);
        toolBar->addAction(actTab_SetHeader);
        toolBar->addAction(actTab_Locate);
        toolBar->addAction(actFile_Quit);

        retranslateUi(customDialog);
        QObject::connect(actFile_Quit, SIGNAL(triggered()), customDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(customDialog);
    } // setupUi

    void retranslateUi(QMainWindow *customDialog)
    {
        customDialog->setWindowTitle(QApplication::translate("customDialog", "customDialog", Q_NULLPTR));
        actTab_SetSize->setText(QApplication::translate("customDialog", "\350\256\276\347\275\256\350\241\214\346\225\260\345\210\227\346\225\260", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTab_SetSize->setToolTip(QApplication::translate("customDialog", "\350\256\276\347\275\256\350\241\250\346\240\274\350\241\214\346\225\260\345\210\227\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actTab_SetHeader->setText(QApplication::translate("customDialog", "\350\256\276\347\275\256\350\241\250\345\244\264\346\240\207\351\242\230", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTab_SetHeader->setToolTip(QApplication::translate("customDialog", "\350\256\276\347\275\256\350\241\250\345\244\264\346\240\207\351\242\230", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFile_Quit->setText(QApplication::translate("customDialog", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFile_Quit->setToolTip(QApplication::translate("customDialog", "\351\200\200\345\207\272\346\234\254\350\275\257\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actTab_Locate->setText(QApplication::translate("customDialog", "\345\256\232\344\275\215\345\215\225\345\205\203\346\240\274", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTab_Locate->setToolTip(QApplication::translate("customDialog", "\345\256\232\344\275\215\345\210\260\346\237\220\344\270\252\345\215\225\345\205\203\346\240\274", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("customDialog", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class customDialog: public Ui_customDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMDIALOG_H
