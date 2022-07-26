#include "TestBattery.h"
#include "ui_TestBattery.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
TestBattery::TestBattery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestBattery)
{
    ui->setupUi(this);
}

TestBattery::~TestBattery()
{
    delete ui;
}


void TestBattery::on_qBattery_powerLevelChanged(int powerlevel)
{
    QString str = QStringLiteral("current power: ")+QString::asprintf("%d %%",powerlevel);
    ui->label->setText(str);
}

void TestBattery::on_horizontalSlider_valueChanged(int value)
{
    ui->qBattery->setPowerLevel(value);
}
