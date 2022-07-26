#ifndef QBATTERY_H
#define QBATTERY_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>

#include <QtDesigner/QDesignerExportWidget> // 1. 第1个区别,要包含该头文件
// Qt5.7以下版本为#include <QtDesigner/QDesignerExportWidget>
// 以上版本为#include <QtUiPlugin/QDesignerExportWidget>
// 定义自定义小部件时使用此宏，以确保它们从插件中正确导出以与 Qt Designer 一起使用
class QDESIGNER_WIDGET_EXPORT QBattery : public QWidget // 2. 第2个区别,声明此类的宏
{
    Q_OBJECT
    Q_PROPERTY(int  powerLevel READ powerLevel WRITE setPowerLevel NOTIFY powerLevelChanged DESIGNABLE true) // 3. 第3个区别,DESIGNABLE=true设置UI设计器是否可见默认true
// 除了以上3个区别其它的完全一样,源文件的实现也是一样
public:
    explicit QBattery(QWidget *parent = 0);
    void setPowerLevel(int pow);//设置当前电量
    int powerLevel(); // 读取当前电量
    void setWarnLevel(int warn);//设置电量低阈值
    int warnLevel();// 读取阈电量低值
//    QSize sizeHint();//报告缺省大小
private:
    QColor  mColorBack=Qt::white;//背景颜色
    QColor  mColorBorder=Qt::black;//电池边框颜色
    QColor  mColorPower=Qt::green;//电量柱颜色
    QColor  mColorWarning=Qt::red;//电量短缺时的颜色
    int mPowerLevel=60;//电量0-100
    int mWarnLevel=20;//电量低警示阈值
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE; // 重载绘图事件
signals:
    void   powerLevelChanged(int powerlevel); // 属性值变化以后信号发射
};

#endif // QBATTERY_H
