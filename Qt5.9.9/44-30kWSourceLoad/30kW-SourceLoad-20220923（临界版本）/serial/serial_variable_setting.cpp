#include "serial/serial_variable_setting.h"
#include <QTime>
#include <QMessageBox>

SerialVariableSetting::SerialVariableSetting(QSerialPort * port,QObject * parent):QObject(parent)
          ,mPort(port)
{
       // 串口资源只有1个，一般来说启动连接以后，串口就被SerialFixedQueryThread接管
       // 串口的启动和关闭只能在SerialFixedQueryThread内执行
       // 启动的时候定时查询就已经开始了，之后才能设定VIPR的值
       // 所以一般来说串口应当是已打开的状态
}

void SerialVariableSetting::setVariable(const QByteArray& value,SETTINGVARIABLE type)
{
       if (!mPort->isOpen()) // 如果真的因为某些原因是没打开的状态
       {
            QMessageBox::critical(nullptr,tr("错误"),tr("串口未打开!"));
            return;
       }
       // 写入命令时应当让固定查询暂停,否则写入的数据会乱,读取完毕后再恢复
       // 因为定时器不允许跨线程停止,所以只能借助信号传递暂停定时器的信号
       // "SOUR:VOLT 7.000",""SOUR:VOLT?" => "SOUR:VOLT 7.000;:SOUR:VOLT?\n" 设定后紧接着查询设定的结果
       auto sc = getSetCommand(value,type);
       auto qc = getQueryCommand(type);
       auto c = sc+SymbolCommandBytes(SEMICOLON)+SymbolCommandBytes(COLON)+qc + SymbolCommandBytes(EOI);

        QMutexLocker locker(&mMutex);
        mPort->write(c);
}

QByteArray SerialVariableSetting::getSetCommand(const QByteArray &value, SETTINGVARIABLE type)
{
          QByteArray ret;
          switch (type)
          {
                case PowerSource: ret = SourceCommandBytes(SOURce::SOUR_POW_LIM);break;
                case PowerLoad: ret = SourceCommandBytes(SOURce::SOUR_POW_LIM_NEG);break;
                case ResistanceSource: ret = SourceCommandBytes(SOURce::SOUR_RES_LIM);break;
                case ResistanceLoad: ret = SourceCommandBytes(SOURce::SOUR_RES_LIM_NEG);break;

                case Voltage: ret = SourceCommandBytes(SOURce::SOUR_VOLT);break;
                case CurrentSource: ret = SourceCommandBytes(SOURce::SOUR_CURR_LIM);break;
                case CurrentLoad: ret = SourceCommandBytes(SOURce::SOUR_CURR_LIM_NEG);break;

                case Current: ret = SourceCommandBytes(SOURce::SOUR_CURR);break;
                case VoltageSource: ret = SourceCommandBytes(SOURce::SOUR_VOLT_LIM);break;
                case VoltageLoad: ret = SourceCommandBytes(SOURce::SOUR_VOLT_LIM_NEG);break;
                default: break; // 没有发送角色直接退出
          }
          // 命令+空格+值+结束符才是完整的命令(结束符在setVariable内添加)
          ret = ret +SymbolCommandBytes(SYMbol::SPACE) + value;
          return ret;
}

QByteArray SerialVariableSetting::getQueryCommand(SETTINGVARIABLE type)
{
          QByteArray  ret;
          switch (type)
          {
                case PowerSource: ret = SourceCommandBytes(SOURce::SOUR_POW_LIM_INQUIRE);break;
                case PowerLoad: ret = SourceCommandBytes(SOURce::SOUR_POW_LIM_NEG_INQUIRE);break;
                case ResistanceSource: ret = SourceCommandBytes(SOURce::SOUR_RES_LIM_INQUIRE);break;
                case ResistanceLoad: ret = SourceCommandBytes(SOURce::SOUR_RES_LIM_NEG_INQUIRE);break;

                case Voltage: ret = SourceCommandBytes(SOURce::SOUR_VOLT_INQUIRE);break;
                case CurrentSource: ret = SourceCommandBytes(SOURce::SOUR_CURR_LIM_INQUIRE);break;
                case CurrentLoad: ret = SourceCommandBytes(SOURce::SOUR_CURR_LIM_NEG_INQUIRE);break;

                case Current: ret = SourceCommandBytes(SOURce::SOUR_CURR_INQUIRE);break;
                case VoltageSource: ret = SourceCommandBytes(SOURce::SOUR_VOLT_LIM_INQUIRE);break;
                case VoltageLoad: ret = SourceCommandBytes(SOURce::SOUR_VOLT_LIM_NEG_INQUIRE);break;

                default: break;
          }
          return ret;
}

