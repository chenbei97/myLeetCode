/********************************************************************************
** Form generated from reading UI file 'TestQ3DBarScatterSurface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQ3DBARSCATTERSURFACE_H
#define UI_TESTQ3DBARSCATTERSURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQ3DBarScatterSurface
{
public:
    QAction *act3DBar;
    QAction *act3DScatter;
    QAction *act3DSurface;
    QAction *act3DMap;
    QAction *actExit;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestQ3DBarScatterSurface)
    {
        if (TestQ3DBarScatterSurface->objectName().isEmpty())
            TestQ3DBarScatterSurface->setObjectName(QStringLiteral("TestQ3DBarScatterSurface"));
        TestQ3DBarScatterSurface->resize(848, 191);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQ3DBarScatterSurface->setFont(font);
        TestQ3DBarScatterSurface->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        act3DBar = new QAction(TestQ3DBarScatterSurface);
        act3DBar->setObjectName(QStringLiteral("act3DBar"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/3DBar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        act3DBar->setIcon(icon);
        act3DScatter = new QAction(TestQ3DBarScatterSurface);
        act3DScatter->setObjectName(QStringLiteral("act3DScatter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/3DScatter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        act3DScatter->setIcon(icon1);
        act3DSurface = new QAction(TestQ3DBarScatterSurface);
        act3DSurface->setObjectName(QStringLiteral("act3DSurface"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/3DSurface.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        act3DSurface->setIcon(icon2);
        act3DMap = new QAction(TestQ3DBarScatterSurface);
        act3DMap->setObjectName(QStringLiteral("act3DMap"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/3DMap.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        act3DMap->setIcon(icon3);
        actExit = new QAction(TestQ3DBarScatterSurface);
        actExit->setObjectName(QStringLiteral("actExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/exit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon4);
        centralwidget = new QWidget(TestQ3DBarScatterSurface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 30, 291, 51));
        TestQ3DBarScatterSurface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestQ3DBarScatterSurface);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 848, 28));
        TestQ3DBarScatterSurface->setMenuBar(menubar);
        statusbar = new QStatusBar(TestQ3DBarScatterSurface);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQ3DBarScatterSurface->setStatusBar(statusbar);
        toolBar = new QToolBar(TestQ3DBarScatterSurface);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestQ3DBarScatterSurface->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(act3DBar);
        toolBar->addAction(act3DScatter);
        toolBar->addAction(act3DSurface);
        toolBar->addAction(act3DMap);
        toolBar->addAction(actExit);

        retranslateUi(TestQ3DBarScatterSurface);

        QMetaObject::connectSlotsByName(TestQ3DBarScatterSurface);
    } // setupUi

    void retranslateUi(QMainWindow *TestQ3DBarScatterSurface)
    {
        TestQ3DBarScatterSurface->setWindowTitle(QApplication::translate("TestQ3DBarScatterSurface", "TestQ3DBarScatterSurface", Q_NULLPTR));
        act3DBar->setText(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\346\237\261\347\212\266\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        act3DBar->setToolTip(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\346\237\261\347\212\266\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        act3DScatter->setText(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\346\225\243\347\202\271\345\233\276", Q_NULLPTR));
        act3DSurface->setText(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\346\233\262\351\235\242\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        act3DSurface->setToolTip(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\346\233\262\351\235\242\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        act3DMap->setText(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\345\234\260\345\275\242\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        act3DMap->setToolTip(QApplication::translate("TestQ3DBarScatterSurface", "\344\270\211\347\273\264\345\234\260\345\275\242\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actExit->setText(QApplication::translate("TestQ3DBarScatterSurface", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actExit->setToolTip(QApplication::translate("TestQ3DBarScatterSurface", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("TestQ3DBarScatterSurface", "\351\200\211\346\213\251\344\270\211\347\273\264\345\234\260\345\275\242\345\233\276\347\211\207", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TestQ3DBarScatterSurface", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQ3DBarScatterSurface: public Ui_TestQ3DBarScatterSurface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQ3DBARSCATTERSURFACE_H
