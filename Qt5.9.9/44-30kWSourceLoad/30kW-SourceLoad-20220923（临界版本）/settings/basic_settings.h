#ifndef BASICCOMMONSETTINGS_H
#define BASICCOMMONSETTINGS_H
// 基本设置中的常用设置界面对话框,根据listwidget的选择stackwidget显示不同的界面
#include <QDialog>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QDebug>
#include "settings/basic_common_settings.h"
#include "settings/basic_analog_interface.h"
#include "settings/basic_parallel_settings.h"

class BasicSettings : public QDialog
{
    Q_OBJECT
public:
    struct Settings // 5个堆叠界面的信息
    {
          // 这里的默认构造函数不需要提供,因为成员的构造函数已经提供
          CommonSettings::Settings  commonSettings;
          AnalogInterface::Settings analogInterfaceSettings;
          ParallelSettings::Settings parallelSettings;
    };
    explicit BasicSettings(QWidget*parent=nullptr);
    BasicSettings::Settings settings() const;
    void setSettings(const BasicSettings::Settings & settings);
private:
    void initUI();
    void initConnections();
private slots:
    void on_okBtn();
signals:
    void basicSettings(const BasicSettings::Settings & settings);
private:
    QGridLayout * mainLayout;
    QHBoxLayout * topLayout;
    QHBoxLayout * bottomLayout;
    QListWidget * listwidget;
    QStackedWidget * stackwidget;
    QPushButton * okBtn;
    QPushButton * cancelBtn;
    BasicSettings::Settings mSettings;
private:
    CommonSettings * mCommonSettings;
    AnalogInterface * mAnalogInterface;
    ParallelSettings * mParallelSettings;
};
//Q_DECLARE_METATYPE(BasicSettings::Settings);
#endif // BASICCOMMONSETTINGS_H
