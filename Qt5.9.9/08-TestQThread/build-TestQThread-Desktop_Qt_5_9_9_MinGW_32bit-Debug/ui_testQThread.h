/********************************************************************************
** Form generated from reading UI file 'testQThread.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQTHREAD_H
#define UI_TESTQTHREAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQThread
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartThread;
    QPushButton *btnDiceBegin;
    QPushButton *btnDicePause;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QLabel *LabPic;
    QLabel *LabA;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestQThread)
    {
        if (TestQThread->objectName().isEmpty())
            TestQThread->setObjectName(QStringLiteral("TestQThread"));
        TestQThread->resize(1198, 745);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        TestQThread->setFont(font);
        centralwidget = new QWidget(TestQThread);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 0, 1141, 681));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartThread = new QPushButton(groupBox);
        btnStartThread->setObjectName(QStringLiteral("btnStartThread"));

        horizontalLayout->addWidget(btnStartThread);

        btnDiceBegin = new QPushButton(groupBox);
        btnDiceBegin->setObjectName(QStringLiteral("btnDiceBegin"));
        btnDiceBegin->setEnabled(false);

        horizontalLayout->addWidget(btnDiceBegin);

        btnDicePause = new QPushButton(groupBox);
        btnDicePause->setObjectName(QStringLiteral("btnDicePause"));
        btnDicePause->setEnabled(false);

        horizontalLayout->addWidget(btnDicePause);

        btnStopThread = new QPushButton(groupBox);
        btnStopThread->setObjectName(QStringLiteral("btnStopThread"));
        btnStopThread->setEnabled(false);

        horizontalLayout->addWidget(btnStopThread);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        horizontalLayout->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout_3->addWidget(plainTextEdit);

        LabPic = new QLabel(groupBox);
        LabPic->setObjectName(QStringLiteral("LabPic"));
        LabPic->setMinimumSize(QSize(150, 0));
        LabPic->setFont(font);
        LabPic->setPixmap(QPixmap(QString::fromUtf8("images/d0.jpg")));
        LabPic->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(LabPic);


        verticalLayout->addLayout(horizontalLayout_3);

        LabA = new QLabel(groupBox);
        LabA->setObjectName(QStringLiteral("LabA"));

        verticalLayout->addWidget(LabA);

        TestQThread->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestQThread);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1198, 36));
        TestQThread->setMenuBar(menubar);
        statusbar = new QStatusBar(TestQThread);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQThread->setStatusBar(statusbar);

        retranslateUi(TestQThread);

        QMetaObject::connectSlotsByName(TestQThread);
    } // setupUi

    void retranslateUi(QMainWindow *TestQThread)
    {
        TestQThread->setWindowTitle(QApplication::translate("TestQThread", "TestQThread", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestQThread", "\347\272\277\347\250\213", Q_NULLPTR));
        btnStartThread->setText(QApplication::translate("TestQThread", "\345\220\257\345\212\250\347\272\277\347\250\213", Q_NULLPTR));
        btnDiceBegin->setText(QApplication::translate("TestQThread", "\345\274\200\345\247\213\346\216\267\351\252\260\345\255\220", Q_NULLPTR));
        btnDicePause->setText(QApplication::translate("TestQThread", "\346\232\202\345\201\234\346\216\267\351\252\260\345\255\220", Q_NULLPTR));
        btnStopThread->setText(QApplication::translate("TestQThread", "\347\273\223\346\235\237\347\272\277\347\250\213", Q_NULLPTR));
        btnClear->setText(QApplication::translate("TestQThread", "\346\270\205\347\251\272\346\226\207\346\234\254", Q_NULLPTR));
        LabPic->setText(QString());
        LabA->setText(QApplication::translate("TestQThread", "Thread\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQThread: public Ui_TestQThread {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQTHREAD_H
