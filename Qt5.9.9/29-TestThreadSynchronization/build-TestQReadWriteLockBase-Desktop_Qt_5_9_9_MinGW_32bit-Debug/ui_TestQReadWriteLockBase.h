/********************************************************************************
** Form generated from reading UI file 'TestQReadWriteLockBase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQREADWRITELOCKBASE_H
#define UI_TESTQREADWRITELOCKBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQReadWriteLockBase
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_6;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_7;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *TestQReadWriteLockBase)
    {
        if (TestQReadWriteLockBase->objectName().isEmpty())
            TestQReadWriteLockBase->setObjectName(QStringLiteral("TestQReadWriteLockBase"));
        TestQReadWriteLockBase->resize(1042, 525);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQReadWriteLockBase->setFont(font);
        centralwidget = new QWidget(TestQReadWriteLockBase);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(260, 440));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 221, 471));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(710, 430));

        gridLayout->addWidget(plainTextEdit, 0, 1, 1, 1);

        TestQReadWriteLockBase->setCentralWidget(centralwidget);

        retranslateUi(TestQReadWriteLockBase);

        QMetaObject::connectSlotsByName(TestQReadWriteLockBase);
    } // setupUi

    void retranslateUi(QMainWindow *TestQReadWriteLockBase)
    {
        TestQReadWriteLockBase->setWindowTitle(QApplication::translate("TestQReadWriteLockBase", "TestQReadWriteLockBase", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton_2->setText(QApplication::translate("TestQReadWriteLockBase", "\345\274\200\345\247\213\345\206\231\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("TestQReadWriteLockBase", "\345\201\234\346\255\242\345\206\231\346\223\215\344\275\234", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TestQReadWriteLockBase", "\345\274\200\345\247\213\350\257\273\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("TestQReadWriteLockBase", "\345\201\234\346\255\242\350\257\273\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("TestQReadWriteLockBase", "\345\274\200\345\247\213\344\277\235\345\255\230\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("TestQReadWriteLockBase", "\345\201\234\346\255\242\344\277\235\345\255\230\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("TestQReadWriteLockBase", "\345\205\250\351\203\250\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQReadWriteLockBase: public Ui_TestQReadWriteLockBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQREADWRITELOCKBASE_H
