#ifndef TESTCUSTOMBATTERYWIDGET_H
#define TESTCUSTOMBATTERYWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TestCustomBatteryWidget; }
QT_END_NAMESPACE

class TestCustomBatteryWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestCustomBatteryWidget(QWidget *parent = nullptr);
    ~TestCustomBatteryWidget();
private slots:
    void on_battery_powerLevelChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
private:
    Ui::TestCustomBatteryWidget *ui;
};
#endif // TESTCUSTOMBATTERYWIDGET_H
