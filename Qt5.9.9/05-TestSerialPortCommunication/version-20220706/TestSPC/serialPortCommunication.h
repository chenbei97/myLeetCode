#ifndef SERIALPORTCOMMUNICATION_H
#define SERIALPORTCOMMUNICATION_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QCheckBox>
#include "serialPortFactory.h"
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

private:
    void initialize_ui_components();
    void initialize_workstatus_components();
    void initialize_timer_component();
    void initialize_member_variables();
    void change_label_spinBox_component(const SPIC::workMode &workMode =
        SPIC::workMode::CV_WORK_MODE);

    void delay(unsigned int msec);
    void sleep(unsigned int msec);
    bool strcpy(char* dst, char * src);
    bool strcpy(int* dst,char *src);


    bool select_processing_method(const QList<QByteArray>& data,const SPIC::senderInfo & sender) ;//依据发送者是谁选择串口处理方法
    void processing_fixed_quiery(const QList<QByteArray> & data); // 处理固定查询
    void processing_cvVolt(const QList<QByteArray> & data); // 处理CV模式的电压设定
    void processing_cvCurrPS(const QList<QByteArray> & data);// 处理CV模式的PS电流设定
    void processing_cvCurrEL(const QList<QByteArray> & data);// 处理CV模式的EL电流设定
    void processing_ccCurr(const QList<QByteArray> & data);// 处理CC模式的电压设定
    void processing_ccVoltPS(const QList<QByteArray> & data);// 处理CC模式的PS电压设定
    void processing_ccVoltEL(const QList<QByteArray> & data);// 处理CC模式的PS电压设定
    void processing_powPS(const QList<QByteArray> & data);// 处理PS功率设定
    void processing_powEL(const QList<QByteArray> & data);// 处理EL功率设定

    void clearState(); // CV和CC模式切换时清空部分组件状态

private slots:
  // 打开和关闭串口
  void on_openSerialPort_clicked();
  void on_closeSerialPort_clicked();
  void receive_port_data(); //串口打开关联的处理串口的函数

  void on_serialNameBox_currentIndexChanged(const QString &arg1); // 串口选择->设置串口的性质(名称)
  void on_serialBaudRateBox_currentIndexChanged(const QString &arg1); // 波特率选择->设置串口的性质(波特率)

  void send_query_command(); // 定时器关联的查询函数
  void on_Input1_valueChanged(double arg1); // CC模式下设定输入电流值,CV模式下设定输入电压值
  void on_Input2PS_valueChanged(double arg1); // CC模式下设定PS的输入电压值,CV模式下设定PS的输入电流值
  void on_Input2EL_valueChanged(double arg1);// CC模式下设定EL的输入电压值,CV模式下设定EL的输入电流值
  void on_powInputEL_valueChanged(double arg1); // 无论是CC还是CV都设置EL的输入功率值
  void on_powInputPS_valueChanged(double arg1);// 无论是CC还是CV都设置PS的输入功率值

  void on_rbtCV_clicked(); // 设定为CV模式
  void on_rbtCC_clicked(); // 设定为CC模式

  void on_openPowerSupply_clicked(); // 打开电源,串口打开后可用
  void on_closePowerSupply_clicked(); // 关闭电源,串口打开后可用

private:
  Ui::SerialPortCommunication *ui;
  serialPortFactory  portFactory;
  QSerialPort * Port; // 直接在构造函数中初始化
  QTimer * timer; // 在initialize_timer_component函数被初始化
  static const unsigned int flushTime = 300; // 静态固定值直接初始化
  QList<QCheckBox*> workStatus; // 统一管理界面的工作状态组件,在initialize_workstatus_components函数被初始化

  //在initialize_member_variables函数被初始化
  SPIC::serialState serialstate;
  SPIC::powerState powerstate;
  SPIC::workMode workmode;
  SPIC::workStatus workstatus;
  SPIC::senderInfo senderinfo;
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
