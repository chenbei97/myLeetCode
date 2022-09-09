#ifndef SERIALFIXEDQUERYTHREAD_H
#define SERIALFIXEDQUERYTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QSerialPort>
#include <QDebug>
#include <core/spic_command.h>
#include <core/enum.h>

typedef SPICCOMAND::MEASure MEAS;
typedef SPICCOMAND::SYMbol SYM;

// 命令是MEAS子系统依次查询电压、电流、功率和电阻(暂时空出)的命令
// 使用带头路径的命令：MEAS:VOLT?;CURR?;POW?\n
// 或者使用不带头路径的完整命令：MEAS:VOLT?;:MEAS:CURR?:MEAS:POW?\n 这里选择第2种类型

static const QByteArray MEAS_VCPR =  MeasureCommandBytes(MEAS::MEAS_VOLT_AVE_INQUIRE)+ //MEAS:VOLT?
                                                                    SymbolCommandBytes(SYM::SEMICOLON)+// 分号";"
                                                                    SymbolCommandBytes(SYM::COLON)+// 冒号 ":"
                                                                    MeasureCommandBytes(MEAS::MEAS_CURR_AVE_INQUIRE)+ // MEAS:CURR?
                                                                    SymbolCommandBytes(SYM::SEMICOLON)+// 分号";"
                                                                    SymbolCommandBytes(SYM::COLON)+// 冒号 ":"
                                                                    MeasureCommandBytes(MEAS::MEAS_POW_AVE_INQUIRE)+ // MEAS:POW?
                                                                    SymbolCommandBytes(SYM::EOI); // 结束符"\n"

class SerialFixedQueryThread : public QThread
{
      Q_OBJECT
public:
      explicit SerialFixedQueryThread(QObject * parent = Q_NULLPTR);
      ~SerialFixedQueryThread();
      void startFixedQueryThread(QSerialPort * port);
public slots:
      void on_SendInfo(SETTINGVARIABLE role,QByteArray request); // 响应来自communication的sendInfo信号,确定设定的角色和设定的值
protected:
      void run() override;
private:
      static const quint32 mQueryInterval = 300; // 300ms固定查询
      bool mQuit;
      QMutex mMutex;
      QWaitCondition mCond;
      QSerialPort * mPort;
      SETTINGVARIABLE mRole; // 保存设定查询的角色
      QByteArray mRequestBytes; // 保存要设定的值
signals:
      void errorCode(TIMEOUTCODE code); // 请求超时或者回复超时
      void errorCode(SERIALERROR code); // 串口的错误类型
      void availableFixedQueryData(QByteArray data); // 串口读取到的定时查询数据
      void availableSetQueryData(QByteArray response,QByteArray request,SETTINGVARIABLE role); // 串口读取到的设定查询数据
};

#endif // SERIALFIXEDQUERYTHREAD_H
