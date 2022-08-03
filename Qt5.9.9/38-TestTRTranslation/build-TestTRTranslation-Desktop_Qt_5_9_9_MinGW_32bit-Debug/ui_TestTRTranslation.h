/********************************************************************************
** Form generated from reading UI file 'TestTRTranslation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTRTRANSLATION_H
#define UI_TESTTRTRANSLATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestTRTranslation
{
public:
    QAction *actTab_SetSize;
    QAction *actTab_SetHeader;
    QAction *actFile_Quit;
    QAction *actTab_Locate;
    QAction *actLang_CN;
    QAction *actLang_EN;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestTRTranslation)
    {
        if (TestTRTranslation->objectName().isEmpty())
            TestTRTranslation->setObjectName(QStringLiteral("TestTRTranslation"));
        TestTRTranslation->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestTRTranslation->setFont(font);
        actTab_SetSize = new QAction(TestTRTranslation);
        actTab_SetSize->setObjectName(QStringLiteral("actTab_SetSize"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/230.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTab_SetSize->setIcon(icon);
        actTab_SetHeader = new QAction(TestTRTranslation);
        actTab_SetHeader->setObjectName(QStringLiteral("actTab_SetHeader"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/516.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTab_SetHeader->setIcon(icon1);
        actFile_Quit = new QAction(TestTRTranslation);
        actFile_Quit->setObjectName(QStringLiteral("actFile_Quit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_Quit->setIcon(icon2);
        actTab_Locate = new QAction(TestTRTranslation);
        actTab_Locate->setObjectName(QStringLiteral("actTab_Locate"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/304.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actTab_Locate->setIcon(icon3);
        actLang_CN = new QAction(TestTRTranslation);
        actLang_CN->setObjectName(QStringLiteral("actLang_CN"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/CN.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actLang_CN->setIcon(icon4);
        actLang_EN = new QAction(TestTRTranslation);
        actLang_EN->setObjectName(QStringLiteral("actLang_EN"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/timg2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actLang_EN->setIcon(icon5);
        centralwidget = new QWidget(TestTRTranslation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        TestTRTranslation->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TestTRTranslation);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestTRTranslation->setStatusBar(statusbar);
        toolBar = new QToolBar(TestTRTranslation);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestTRTranslation->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actTab_SetHeader);
        toolBar->addAction(actTab_Locate);
        toolBar->addAction(actTab_SetSize);
        toolBar->addAction(actFile_Quit);
        toolBar->addAction(actLang_CN);
        toolBar->addAction(actLang_EN);

        retranslateUi(TestTRTranslation);
        QObject::connect(actFile_Quit, SIGNAL(triggered()), TestTRTranslation, SLOT(close()));

        QMetaObject::connectSlotsByName(TestTRTranslation);
    } // setupUi

    void retranslateUi(QMainWindow *TestTRTranslation)
    {
        TestTRTranslation->setWindowTitle(QApplication::translate("TestTRTranslation", "TestTRTranslation", Q_NULLPTR));
        actTab_SetSize->setText(QApplication::translate("TestTRTranslation", "\350\241\250\346\240\274\345\244\247\345\260\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTab_SetSize->setToolTip(QApplication::translate("TestTRTranslation", "\350\256\276\347\275\256\350\241\250\346\240\274\350\241\214\346\225\260\345\210\227\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actTab_SetHeader->setText(QApplication::translate("TestTRTranslation", "\350\256\276\347\275\256\350\241\250\345\244\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTab_SetHeader->setToolTip(QApplication::translate("TestTRTranslation", "\350\256\276\347\275\256\350\241\250\345\244\264\346\240\207\351\242\230", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actFile_Quit->setText(QApplication::translate("TestTRTranslation", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actFile_Quit->setToolTip(QApplication::translate("TestTRTranslation", "\351\200\200\345\207\272\346\234\254\350\275\257\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actTab_Locate->setText(QApplication::translate("TestTRTranslation", "\345\256\232\344\275\215\345\215\225\345\205\203\346\240\274", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actTab_Locate->setToolTip(QApplication::translate("TestTRTranslation", "\345\256\232\344\275\215\345\210\260\346\237\220\344\270\252\345\215\225\345\205\203\346\240\274", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actLang_CN->setText(QApplication::translate("TestTRTranslation", "\344\270\255\346\226\207", Q_NULLPTR));
        actLang_EN->setText(QApplication::translate("TestTRTranslation", "English", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TestTRTranslation", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestTRTranslation: public Ui_TestTRTranslation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTRTRANSLATION_H
