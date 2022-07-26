#ifndef CUSTOMBATTERY_H
#define CUSTOMBATTERY_H

#include <QObject>
#include <QWidget>
#include    <QColor>

class customBattery : public QWidget
{
    Q_OBJECT
    //自定义属性: 类型 属性名称 READ 读取函数名称 WRITE 设置函数名称 属性改变的信号函数
    Q_PROPERTY(int  powerLevel READ powerLevel WRITE setPowerLevel NOTIFY powerLevelChanged)
private:
    QColor  mColorBack=Qt::white;//背景颜色
    QColor  mColorBorder=Qt::black;//电池边框颜色
    QColor  mColorPower=Qt::green;//电量柱颜色
    QColor  mColorWarning=Qt::red;//电量短缺时的颜色
    int mPowerLevel=60;//电量0-100
    int mWarnLevel=20;//电量低警示阈值
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE; // 重载绘图事件
public:
    explicit customBattery(QWidget * parent);
    void setPowerLevel(int pow);//设置当前电量
    int powerLevel(); // 读取当前电量
    void setWarnLevel(int warn);//设置电量低阈值
    int warnLevel();// 读取阈电量低值
    QSize sizeHint();//报告缺省大小
signals:
    void   powerLevelChanged(int powerlevel); // 属性值变化以后信号发射
};

#endif // CUSTOMBATTERY_H
