/********************************************************************************
** Form generated from reading UI file 'TestCustomBatteryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCUSTOMBATTERYWIDGET_H
#define UI_TESTCUSTOMBATTERYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <customBattery.h>

QT_BEGIN_NAMESPACE

class Ui_TestCustomBatteryWidget
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    customBattery *battery;
    QSlider *horizontalSlider;
    QLabel *LabInfo;

    void setupUi(QMainWindow *TestCustomBatteryWidget)
    {
        if (TestCustomBatteryWidget->objectName().isEmpty())
            TestCustomBatteryWidget->setObjectName(QStringLiteral("TestCustomBatteryWidget"));
        TestCustomBatteryWidget->resize(400, 300);
        TestCustomBatteryWidget->setMinimumSize(QSize(0, 0));
        TestCustomBatteryWidget->setMaximumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestCustomBatteryWidget->setFont(font);
        centralwidget = new QWidget(TestCustomBatteryWidget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        battery = new customBattery(centralwidget);
        battery->setObjectName(QStringLiteral("battery"));

        gridLayout->addWidget(battery, 0, 0, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        LabInfo = new QLabel(centralwidget);
        LabInfo->setObjectName(QStringLiteral("LabInfo"));
        LabInfo->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(LabInfo, 2, 0, 1, 1);

        TestCustomBatteryWidget->setCentralWidget(centralwidget);

        retranslateUi(TestCustomBatteryWidget);

        QMetaObject::connectSlotsByName(TestCustomBatteryWidget);
    } // setupUi

    void retranslateUi(QMainWindow *TestCustomBatteryWidget)
    {
        TestCustomBatteryWidget->setWindowTitle(QApplication::translate("TestCustomBatteryWidget", "TestCustomBatteryWidget", Q_NULLPTR));
        LabInfo->setText(QApplication::translate("TestCustomBatteryWidget", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestCustomBatteryWidget: public Ui_TestCustomBatteryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCUSTOMBATTERYWIDGET_H
