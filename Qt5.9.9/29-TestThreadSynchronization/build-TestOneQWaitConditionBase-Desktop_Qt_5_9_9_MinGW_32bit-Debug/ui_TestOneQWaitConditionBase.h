/********************************************************************************
** Form generated from reading UI file 'TestOneQWaitConditionBase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTONEQWAITCONDITIONBASE_H
#define UI_TESTONEQWAITCONDITIONBASE_H

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

class Ui_TestOneQWaitConditionBase
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
    QLabel *LabPic;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabA;
    QLabel *LabB;

    void setupUi(QMainWindow *TestOneQWaitConditionBase)
    {
        if (TestOneQWaitConditionBase->objectName().isEmpty())
            TestOneQWaitConditionBase->setObjectName(QStringLiteral("TestOneQWaitConditionBase"));
        TestOneQWaitConditionBase->resize(932, 820);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestOneQWaitConditionBase->setFont(font);
        centralwidget = new QWidget(TestOneQWaitConditionBase);
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

        LabPic = new QLabel(groupBox);
        LabPic->setObjectName(QStringLiteral("LabPic"));
        LabPic->setMinimumSize(QSize(150, 0));
        LabPic->setPixmap(QPixmap(QString::fromUtf8(":/images/d0.jpg")));

        horizontalLayout_3->addWidget(LabPic);


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

        TestOneQWaitConditionBase->setCentralWidget(centralwidget);

        retranslateUi(TestOneQWaitConditionBase);

        QMetaObject::connectSlotsByName(TestOneQWaitConditionBase);
    } // setupUi

    void retranslateUi(QMainWindow *TestOneQWaitConditionBase)
    {
        TestOneQWaitConditionBase->setWindowTitle(QApplication::translate("TestOneQWaitConditionBase", "TestOneQWaitConditionBase", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestOneQWaitConditionBase", "\347\272\277\347\250\213", Q_NULLPTR));
        btnStartThread->setText(QApplication::translate("TestOneQWaitConditionBase", "\345\220\257\345\212\250\347\272\277\347\250\213", Q_NULLPTR));
        btnStopThread->setText(QApplication::translate("TestOneQWaitConditionBase", "\347\273\223\346\235\237\347\272\277\347\250\213", Q_NULLPTR));
        btnClear->setText(QApplication::translate("TestOneQWaitConditionBase", "\346\270\205\347\251\272\346\226\207\346\234\254", Q_NULLPTR));
        LabPic->setText(QString());
        LabA->setText(QApplication::translate("TestOneQWaitConditionBase", "Thread Producer\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        LabB->setText(QApplication::translate("TestOneQWaitConditionBase", "Thread Consumer\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestOneQWaitConditionBase: public Ui_TestOneQWaitConditionBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTONEQWAITCONDITIONBASE_H
