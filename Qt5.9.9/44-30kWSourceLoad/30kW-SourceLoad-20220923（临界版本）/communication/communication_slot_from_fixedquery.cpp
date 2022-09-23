#include "communication/communication.h"

// 处理来自定时查询的数据
void Communication::on_FixedQueryThread_AvailableFixedQueryData(QByteArray data)
{
      // 数据形式一般是"15.000;2.000;75.000\n"，有时候可能出现"15.000;2.000;75.000\n15.000;2.000;75.000\n"连发的情况
      if (data.endsWith('\n')) // 说明是一条完整的命令(一般一定满足)
      {
              QList<QByteArray> datas = data.split('\n');
              datas.pop_back(); // 把空字符串删掉
              // 处理连发的情况
              if (datas.count() > 1) // 刨除空字符串剩下的消息数量如果比1大说明有多条消息,类似("15.000;2.000;75.000", "15.000;2.000;76.000", "15.000;2.000;77.000", "")
              {
                    // 此时只要除空字符串以外的最后1条消息(也就是最新的消息),其它舍弃
                    QByteArray value = datas.back();
                    QList<QByteArray> values = value.split(';');
                    emit availableFixedQueryData(values); // 最后1条消息拆分的VIPR4个值发出去,给监控界面显示
                    return;
              }
               //  如果是1条消息会拆分出2个,第2个是空字符串,形如("15.000;2.000;75.000", "")
              QByteArray value = datas[0];
              QList<QByteArray> values = value.split(';');
              emit availableFixedQueryData(values);
      }
}

// 处理来自设定查询的回复
void Communication::on_FixedQueryThread_AvailableSetQueryData(QByteArray response,QByteArray request,SETTINGVARIABLE role)
{
        // 数据不包含分号,一般就是"5.000\n"这样形式,role确定是谁发的消息
        if (role == SETTINGVARIABLE::None)
        {
              //qDebug()<<QTime::currentTime()<<"  没有发送角色";
              return;
        }
        response.chop(1);// 去除"\n"
        // 如果返回的数据和设定的数据一致说明设定成功,否则失败
        // 这里不在serial_variablesetting.cpp中进行重新设定的操作，而是交给用户
        // qDebug()<<response.toDouble()<<" "<<request.toDouble();
        //因为设定值精度是3,回复值一般也是3,所以一般直接相等判断即可
        // 不过为了保证代码的健壮性,即使有一些差别也是允许的:
        // 3.456和3.455认为不相等(精度至少0.001),3.456和3.4564是相等的,和3.4565不相等,允许误差0.0005内
        // 2.000和2也是相等的
        bool ret = qAbs(response.toDouble() - request.toDouble()) < 0.0005; //
        if (response == request || ret ) // 要设定的值和返回的回复确实一致或者在允许范围内
        {
             // 设定成功 => 监控界面
              emit errorCode(false,role); // 这个错误码是自己定义的，不是来自固定查询线程
        }
        else
        {
             // 设定失败 => 监控界面
             emit errorCode(true,role);
        }
}

// 处理超时错误码
void Communication::on_FixedQueryThread_ErrorCode(TIMEOUTCODE code)
{
           emit errorCode(code); // 超时错误直接转发出去 => 监控界面
}

//  处理串口错误码
void Communication::on_FixedQueryThread_ErrorCode(SERIALERROR code)
{
          emit errorCode(code); // 除了转发出去 => 监控界面,因为串口出现错误还必须先停止连接
          if (code != SERIALERROR::NoError)
          {
                on_PortDisconnectBtn(); // 停止连接
                // 如果是串口错误造成的,要禁用连接串口按钮,必须重新配置串口才可连接
                // 因为一旦发生错误固定查询线程的run函数只执行了错误的那1次并发出1次错误码,那么本函数也只会执行1次,本函数也不会再执行告知用户出错
                // 不改变串口配置的话且连接按钮没有禁用,用户其实不知道已经发生了错误,如果再次点击连接就会异常退出
                // 所以规避的办法是直接禁止重连即可
                // 这样的话只有重新配置串口且发生了变化（也就是保证必须改变串口设置，如果只是打开配置串口界面然后关闭是不会发射update信号也就不会重置使能）
                // 才能让连接按钮恢复使能（这里的问题如果用户改变的不是串口名称而是其他属性？那只能说明用户是个傻吊，故在消息提示框内提示了要改变串口名称）
                PortConnectBtn->setEnabled(false);
                QMessageBox::critical(this, tr("串口打开错误，请检查串口名称是否正确!"), mPort->errorString());
          }
}
