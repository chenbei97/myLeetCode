#ifndef TESTBATTERY_H
#define TESTBATTERY_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TestBattery; }
QT_END_NAMESPACE

class TestBattery : public QMainWindow
{
    Q_OBJECT

public:
    TestBattery(QWidget *parent = nullptr);
    ~TestBattery();

private slots:
    void on_qBattery_powerLevelChanged(int powerlevel);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::TestBattery *ui;
};
#endif // TESTBATTERY_H
