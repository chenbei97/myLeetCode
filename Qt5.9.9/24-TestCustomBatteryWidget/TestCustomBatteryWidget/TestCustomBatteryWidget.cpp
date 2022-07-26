#include "TestCustomBatteryWidget.h"
#include "ui_TestCustomBatteryWidget.h"

TestCustomBatteryWidget::TestCustomBatteryWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestCustomBatteryWidget)
{
    ui->setupUi(this);
}

TestCustomBatteryWidget::~TestCustomBatteryWidget()
{
    delete ui;
}

// 1. 滑动条设置电量值
void TestCustomBatteryWidget::on_horizontalSlider_valueChanged(int value)
{
    ui->battery->setPowerLevel(value);
}

// 2. 电量值变化的槽函数
// 提升QWidget为customBattery类之后,改变信号与槽,就可以设置信号,这个信号绑定到此槽函数
// 那么在滑动条设置值时,部件就会发射值改变的信号,响应到此槽函数改变状态栏信息
void TestCustomBatteryWidget::on_battery_powerLevelChanged(int value)
{
    // 该宏在编译时从字符串文字 str 生成 QString 的数据
    // 在这种情况下，从中创建一个 QString 是免费的，并且生成的字符串数据存储在已编译目标文件的只读段中
    ui->LabInfo->setText(QStringLiteral("当前电量：")+QString::asprintf("%d %%",value));
}

