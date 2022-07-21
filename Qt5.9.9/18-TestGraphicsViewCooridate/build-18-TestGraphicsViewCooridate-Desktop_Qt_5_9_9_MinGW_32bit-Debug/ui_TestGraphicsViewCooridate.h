/********************************************************************************
** Form generated from reading UI file 'TestGraphicsViewCooridate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTGRAPHICSVIEWCOORIDATE_H
#define UI_TESTGRAPHICSVIEWCOORIDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <customgraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_TestGraphicsViewCooridate
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *LabScene;
    QLabel *LabView;
    customGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestGraphicsViewCooridate)
    {
        if (TestGraphicsViewCooridate->objectName().isEmpty())
            TestGraphicsViewCooridate->setObjectName(QStringLiteral("TestGraphicsViewCooridate"));
        TestGraphicsViewCooridate->resize(1000, 800);
        TestGraphicsViewCooridate->setMinimumSize(QSize(800, 600));
        TestGraphicsViewCooridate->setMaximumSize(QSize(2000, 1600));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestGraphicsViewCooridate->setFont(font);
        centralwidget = new QWidget(TestGraphicsViewCooridate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LabScene = new QLabel(centralwidget);
        LabScene->setObjectName(QStringLiteral("LabScene"));

        gridLayout->addWidget(LabScene, 0, 0, 1, 1);

        LabView = new QLabel(centralwidget);
        LabView->setObjectName(QStringLiteral("LabView"));

        gridLayout->addWidget(LabView, 1, 0, 1, 1);

        graphicsView = new customGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 2, 0, 1, 1);

        TestGraphicsViewCooridate->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestGraphicsViewCooridate);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 28));
        TestGraphicsViewCooridate->setMenuBar(menubar);
        statusbar = new QStatusBar(TestGraphicsViewCooridate);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestGraphicsViewCooridate->setStatusBar(statusbar);

        retranslateUi(TestGraphicsViewCooridate);

        QMetaObject::connectSlotsByName(TestGraphicsViewCooridate);
    } // setupUi

    void retranslateUi(QMainWindow *TestGraphicsViewCooridate)
    {
        TestGraphicsViewCooridate->setWindowTitle(QApplication::translate("TestGraphicsViewCooridate", "TestGraphicsViewCooridate", Q_NULLPTR));
        LabScene->setText(QApplication::translate("TestGraphicsViewCooridate", "TextLabel", Q_NULLPTR));
        LabView->setText(QApplication::translate("TestGraphicsViewCooridate", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestGraphicsViewCooridate: public Ui_TestGraphicsViewCooridate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTGRAPHICSVIEWCOORIDATE_H
