#ifndef SERIALPORTCOMMUNICATION_H
#define SERIALPORTCOMMUNICATION_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QCheckBox>
#include "fixedQueryThread.h"
#include "spctime.h"
#include "spiCommand.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SerialPortCommunication; }
QT_END_NAMESPACE

class SerialPortCommunication : public QMainWindow
{
  Q_OBJECT
public:
  SerialPortCommunication(QWidget *parent = nullptr);
  ~SerialPortCommunication();

private: // 初始化相关的函数
    // 一次性初始化
    void initialize(); // 1

    // 初始化静态视图组件的属性
    void initialize_serial_port(); // 11
    void initialize_io_spinbox();
    void initialize_serial_name_spinbox();
    void initialize_serial_baudrate_spinbox();
    void initialize_open_serial_pushbutton();
    void initialize_close_serial_pushbutton();
    void initialize_power_state_radiobutton();
    void initialize_work_mode_radiobutton();
    void initialize_work_status_checkbox();
    void initialize_open_supply_pushbutton();
    void initialize_close_supply_pushbutton();

    // 初始化动态组件的属性
    void initialize_fixedQuery_thread();
    void initialize_timer_timeout();
    void initialize_connection();
    void initialize_enumeration_value();
    void initialize_ouput_setting_value();

private: // 处理串口数据的方法函数
    void processing_fixed_quiery(const QList<QByteArray> & data); // 处理固定查询
    void processing_cvVolt(const QList<QByteArray> & data); // 处理CV模式的电压设定
    void processing_cvCurrPS(const QList<QByteArray> & data);// 处理CV模式的PS电流设定
    void processing_cvCurrEL(const QList<QByteArray> & data);// 处理CV模式的EL电流设定
    void processing_ccCurr(const QList<QByteArray> & data);// 处理CC模式的电压设定
    void processing_ccVoltPS(const QList<QByteArray> & data);// 处理CC模式的PS电压设定
    void processing_ccVoltEL(const QList<QByteArray> & data);// 处理CC模式的PS电压设定
    void processing_powPS(const QList<QByteArray> & data);// 处理PS功率设定
    void processing_powEL(const QList<QByteArray> & data);// 处理EL功率设定
    void processing_powON(const QList<QByteArray> & data);// 处理电源输出ON设定
    void processing_powOFF(const QList<QByteArray> & data); // 处理电源输出OFF设定

private slots: // 设定发送者的槽函数,每个函数绑定了1个发送者的角色
      void on_sendCommand(QString command);
      void fixedQuery(); // 定时查询函数,响应timeout信号
      void on_Input1_valueChanged(double arg1); // CC模式下设定输入电流值,CV模式下设定输入电压值
      void on_Input2PS_valueChanged(double arg1); // CC模式下设定PS的输入电压值,CV模式下设定PS的输入电流值
      void on_Input2EL_valueChanged(double arg1);// CC模式下设定EL的输入电压值,CV模式下设定EL的输入电流值
      void on_powInputEL_valueChanged(double arg1); // 无论是CC还是CV都设置EL的输入功率值
      void on_powInputPS_valueChanged(double arg1);// 无论是CC还是CV都设置PS的输入功率值
      void on_openPowerSupply_clicked(); // 打开电源槽函数,串口打开后可用
      void on_closePowerSupply_clicked(); // 关闭电源槽函数,串口打开后可用

private slots: // 普通槽函数
      void on_serialNameBox_currentIndexChanged(const QString &arg1); // 串口选择槽函数
      void on_serialBaudRateBox_currentIndexChanged(const QString &arg1); // 波特率选择槽函数
      void on_openSerialPort_clicked(); // 打开串口槽函数
      void on_closeSerialPort_clicked(); // 关闭串口槽函数
      void on_rbtCV_clicked(); // 设定为CV模式槽函数
      void on_rbtCC_clicked(); // 设定为CC模式槽函数

private slots:
      void receive_port_data(); //接收串口数据的槽函数,响应readReady信号

private: // 中介函数
    void select_processing_method(const QList<QByteArray>& data,const SPIC::senderInfo & sender) ;//依据发送者是谁选择串口处理方法
    void clear_state(); // 根据工作模式radiobutton切换界面显示状态
    void change_label_component(const SPIC::workMode &workMode =
        SPIC::workMode::CV_WORK_MODE); // 根据工作模式radiobutton切换界面显示状态
     void reset_spinbox_step();
     void reset_spinbox_value();
     void reset_spinbox_range();
     void reset_spinbox_suffix();
     void disconnect_connection();;

private: //辅助函数
    void delay(unsigned int msec);
    void sleep(unsigned int msec);
    bool strcpy(char* dst, char * src);
    bool strcpy(int* dst,char *src);

protected:
    void closeEvent(QCloseEvent * event) override;

private:
  static const unsigned int flushTime = 300; // 静态固定值直接初始化

  Ui::SerialPortCommunication *ui;
  QSerialPort * Port;
  QTimer * timer;
  fixedQueryThread *  fixed_query_thread; // 用于固定查询使用的线程

  //保存状态的枚举值
  SPIC::serialState serialstate;
  SPIC::powerState powerstate;
  SPIC::workMode workmode;
  SPIC::workStatus workstatus;
  SPIC::senderInfo senderinfo;
  // 保存设定值的变量
  double cv_volt;
  double cv_curr_ps;
  double cv_curr_el;
  double cc_curr;
  double cc_volt_ps;
  double cc_volt_el;
  double pow_ps;
  double pow_el;
};
#endif // SERIALPORTCOMMUNICATION_H
