/********************************************************************************
** Form generated from reading UI file 'TestTwoQWaitConditionBase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTWOQWAITCONDITIONBASE_H
#define UI_TESTTWOQWAITCONDITIONBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestTwoQWaitConditionBase
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *TestTwoQWaitConditionBase)
    {
        if (TestTwoQWaitConditionBase->objectName().isEmpty())
            TestTwoQWaitConditionBase->setObjectName(QStringLiteral("TestTwoQWaitConditionBase"));
        TestTwoQWaitConditionBase->resize(993, 403);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestTwoQWaitConditionBase->setFont(font);
        centralwidget = new QWidget(TestTwoQWaitConditionBase);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 100));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_2->addWidget(plainTextEdit, 0, 1, 1, 1);

        TestTwoQWaitConditionBase->setCentralWidget(centralwidget);

        retranslateUi(TestTwoQWaitConditionBase);

        QMetaObject::connectSlotsByName(TestTwoQWaitConditionBase);
    } // setupUi

    void retranslateUi(QMainWindow *TestTwoQWaitConditionBase)
    {
        TestTwoQWaitConditionBase->setWindowTitle(QApplication::translate("TestTwoQWaitConditionBase", "TestTwoQWaitConditionBase", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TestTwoQWaitConditionBase", "\345\274\200\345\220\257\347\224\237\344\272\247\346\266\210\350\264\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestTwoQWaitConditionBase: public Ui_TestTwoQWaitConditionBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTWOQWAITCONDITIONBASE_H
