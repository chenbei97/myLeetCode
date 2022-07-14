/********************************************************************************
** Form generated from reading UI file 'QFormTable.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFORMTABLE_H
#define UI_QFORMTABLE_H

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

class Ui_QFormTable
{
public:
    QAction *actSize;
    QAction *actSetHeader;
    QAction *actClose;
    QWidget *centralwidget;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QFormTable)
    {
        if (QFormTable->objectName().isEmpty())
            QFormTable->setObjectName(QStringLiteral("QFormTable"));
        QFormTable->resize(975, 780);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        QFormTable->setFont(font);
        actSize = new QAction(QFormTable);
        actSize->setObjectName(QStringLiteral("actSize"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/230.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSize->setIcon(icon);
        actSetHeader = new QAction(QFormTable);
        actSetHeader->setObjectName(QStringLiteral("actSetHeader"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/516.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSetHeader->setIcon(icon1);
        actClose = new QAction(QFormTable);
        actClose->setObjectName(QStringLiteral("actClose"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClose->setIcon(icon2);
        centralwidget = new QWidget(QFormTable);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 50, 941, 681));
        QFormTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QFormTable);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 975, 28));
        QFormTable->setMenuBar(menubar);
        statusbar = new QStatusBar(QFormTable);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QFormTable->setStatusBar(statusbar);
        toolBar = new QToolBar(QFormTable);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        QFormTable->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actSize);
        toolBar->addAction(actSetHeader);
        toolBar->addAction(actClose);

        retranslateUi(QFormTable);
        QObject::connect(actClose, SIGNAL(triggered()), QFormTable, SLOT(close()));

        QMetaObject::connectSlotsByName(QFormTable);
    } // setupUi

    void retranslateUi(QMainWindow *QFormTable)
    {
        QFormTable->setWindowTitle(QApplication::translate("QFormTable", "MainWindow", Q_NULLPTR));
        actSize->setText(QApplication::translate("QFormTable", "\345\256\232\344\271\211\350\241\250\346\240\274\345\244\247\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSize->setToolTip(QApplication::translate("QFormTable", "\345\256\232\344\271\211\350\241\250\346\240\274\345\244\247\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSetHeader->setText(QApplication::translate("QFormTable", "\350\256\276\347\275\256\350\241\250\345\244\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSetHeader->setToolTip(QApplication::translate("QFormTable", "\350\256\276\347\275\256\350\241\250\345\244\264\346\226\207\345\255\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClose->setText(QApplication::translate("QFormTable", "\345\205\263\351\227\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClose->setToolTip(QApplication::translate("QFormTable", "\345\205\263\351\227\255\346\234\254\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("QFormTable", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QFormTable: public Ui_QFormTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORMTABLE_H
