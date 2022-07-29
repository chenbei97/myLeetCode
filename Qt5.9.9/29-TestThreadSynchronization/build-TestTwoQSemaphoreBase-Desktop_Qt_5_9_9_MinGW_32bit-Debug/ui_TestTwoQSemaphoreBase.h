/********************************************************************************
** Form generated from reading UI file 'TestTwoQSemaphoreBase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTWOQSEMAPHOREBASE_H
#define UI_TESTTWOQSEMAPHOREBASE_H

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

class Ui_TestTwoQSemaphoreBase
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *TestTwoQSemaphoreBase)
    {
        if (TestTwoQSemaphoreBase->objectName().isEmpty())
            TestTwoQSemaphoreBase->setObjectName(QStringLiteral("TestTwoQSemaphoreBase"));
        TestTwoQSemaphoreBase->resize(1019, 609);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestTwoQSemaphoreBase->setFont(font);
        centralwidget = new QWidget(TestTwoQSemaphoreBase);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 1, 1, 1);

        TestTwoQSemaphoreBase->setCentralWidget(centralwidget);

        retranslateUi(TestTwoQSemaphoreBase);

        QMetaObject::connectSlotsByName(TestTwoQSemaphoreBase);
    } // setupUi

    void retranslateUi(QMainWindow *TestTwoQSemaphoreBase)
    {
        TestTwoQSemaphoreBase->setWindowTitle(QApplication::translate("TestTwoQSemaphoreBase", "TestTwoQSemaphoreBase", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TestTwoQSemaphoreBase", "\345\274\200\345\220\257\347\224\237\344\272\247\346\266\210\350\264\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestTwoQSemaphoreBase: public Ui_TestTwoQSemaphoreBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTWOQSEMAPHOREBASE_H
