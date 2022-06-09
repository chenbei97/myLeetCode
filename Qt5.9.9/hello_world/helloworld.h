#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QMainWindow>
#include  <QSpinBox>
#include  <QProgressBar>
#include  <QToolBar>
#include  <QAction>
 // 窗体类的业务类头文件,内含Ui私有属性，也就是窗体类的Gui文件

QT_BEGIN_NAMESPACE
// 在命名空间Ui下定义的类和下方的同名类不是1个
// 这个类其实定义在头文件"ui_helloworld.h",如果在VS中打开的可以看见
// Ui::helloWorld其实继承于ui_helloWorld类,相当于做了一层封装
// 整个过程是ui_helloWorld->(继承关系)Ui::helloWorld->(聚合关系)helloWorld
namespace Ui { class helloWorld; }
QT_END_NAMESPACE

class helloWorld : public QMainWindow // 继承自QMainWindow的类
{
    Q_OBJECT // 使用信号与槽机制必须加这个宏对象

public:
    helloWorld(QWidget *parent = nullptr); // 构造函数借助QWidget初始化
    ~helloWorld();

private slots: // 槽机制

    void on_btnclose_clicked();

    void on_handsome_stateChanged(int arg1);

    void on_sexBox_currentIndexChanged(int index);

    void on_actionclose_triggered();

    void on_actionreboot_triggered();

    void on_fontSizeBox_valueChanged(int fontsize);

    void on_startProgressbar_triggered();

private:
    Ui::helloWorld *ui; // Ui定义的类作为私有对象聚合
    void setTextColor();
    void init(); // 用于初始化一些控件的函数
    QSpinBox * fontSizeBox;
    QToolBar * toolbar;
    QProgressBar * progressbar;
    QAction * startProgressbar;
};
#endif // HELLOWORLD_H
