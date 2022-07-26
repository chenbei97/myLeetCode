/********************************************************************************
** Form generated from reading UI file 'TestBattery.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTBATTERY_H
#define UI_TESTBATTERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "qbattery.h"

QT_BEGIN_NAMESPACE

class Ui_TestBattery
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QBattery *qBattery;
    QGroupBox *groupBox;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QMainWindow *TestBattery)
    {
        if (TestBattery->objectName().isEmpty())
            TestBattery->setObjectName(QString::fromUtf8("TestBattery"));
        TestBattery->resize(605, 375);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        TestBattery->setFont(font);
        centralwidget = new QWidget(TestBattery);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        qBattery = new QBattery(centralwidget);
        qBattery->setObjectName(QString::fromUtf8("qBattery"));

        gridLayout->addWidget(qBattery, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 10, 501, 41));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 231, 41));

        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        TestBattery->setCentralWidget(centralwidget);

        retranslateUi(TestBattery);

        QMetaObject::connectSlotsByName(TestBattery);
    } // setupUi

    void retranslateUi(QMainWindow *TestBattery)
    {
        TestBattery->setWindowTitle(QCoreApplication::translate("TestBattery", "TestBattery", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("TestBattery", "current power: 60%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestBattery: public Ui_TestBattery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTBATTERY_H
