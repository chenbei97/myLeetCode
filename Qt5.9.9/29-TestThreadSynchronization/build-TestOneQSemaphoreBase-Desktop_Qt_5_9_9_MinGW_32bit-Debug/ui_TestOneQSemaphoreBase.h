/********************************************************************************
** Form generated from reading UI file 'TestOneQSemaphoreBase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTONEQSEMAPHOREBASE_H
#define UI_TESTONEQSEMAPHOREBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestOneQSemaphoreBase
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartThread;
    QPushButton *btnStopThread;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabA;
    QLabel *LabB;

    void setupUi(QMainWindow *TestOneQSemaphoreBase)
    {
        if (TestOneQSemaphoreBase->objectName().isEmpty())
            TestOneQSemaphoreBase->setObjectName(QStringLiteral("TestOneQSemaphoreBase"));
        TestOneQSemaphoreBase->resize(840, 631);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestOneQSemaphoreBase->setFont(font);
        centralwidget = new QWidget(TestOneQSemaphoreBase);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartThread = new QPushButton(groupBox);
        btnStartThread->setObjectName(QStringLiteral("btnStartThread"));

        horizontalLayout->addWidget(btnStartThread);

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


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LabA = new QLabel(groupBox);
        LabA->setObjectName(QStringLiteral("LabA"));

        horizontalLayout_2->addWidget(LabA);

        LabB = new QLabel(groupBox);
        LabB->setObjectName(QStringLiteral("LabB"));

        horizontalLayout_2->addWidget(LabB);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        TestOneQSemaphoreBase->setCentralWidget(centralwidget);

        retranslateUi(TestOneQSemaphoreBase);

        QMetaObject::connectSlotsByName(TestOneQSemaphoreBase);
    } // setupUi

    void retranslateUi(QMainWindow *TestOneQSemaphoreBase)
    {
        TestOneQSemaphoreBase->setWindowTitle(QApplication::translate("TestOneQSemaphoreBase", "TestOneQSemaphoreBase", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestOneQSemaphoreBase", "\347\272\277\347\250\213", Q_NULLPTR));
        btnStartThread->setText(QApplication::translate("TestOneQSemaphoreBase", "\345\220\257\345\212\250\347\272\277\347\250\213", Q_NULLPTR));
        btnStopThread->setText(QApplication::translate("TestOneQSemaphoreBase", "\347\273\223\346\235\237\347\272\277\347\250\213", Q_NULLPTR));
        btnClear->setText(QApplication::translate("TestOneQSemaphoreBase", "\346\270\205\347\251\272\346\226\207\346\234\254", Q_NULLPTR));
        LabA->setText(QApplication::translate("TestOneQSemaphoreBase", "Thread Producer\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        LabB->setText(QApplication::translate("TestOneQSemaphoreBase", "Thread Consumer\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestOneQSemaphoreBase: public Ui_TestOneQSemaphoreBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTONEQSEMAPHOREBASE_H
