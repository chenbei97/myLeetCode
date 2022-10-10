#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include <QByteArray>
#include <QObject>
#include <QDebug>
#include <core/enum.h>

class ResponseProcessor : public QObject
{
      Q_OBJECT
public:
      explicit ResponseProcessor():mData(Q_NULLPTR),mSetRole(SETTINGVARIABLE::None),mSetValue(""){};
      void setData(const QByteArray& data);
      void updateRoleValue(SETTINGVARIABLE role,QByteArray value);
      void run();
private:
      QByteArray mData;
      SETTINGVARIABLE mSetRole; // 要设定的角色
      QByteArray mSetValue; // 要设定的值
      void processFixedQueryData(const QByteArray& data);
      void processSetQueryData(QByteArray data);
 signals:
      void fixedQuery(const QList<QByteArray>& data);
      void setQuery(bool ret,SETTINGVARIABLE role) ; // 用于设定查询-设定成功或失败 =>监控界面
};

inline void ResponseProcessor::setData(const QByteArray &data)
{
     mData = data;
}


inline void ResponseProcessor::updateRoleValue(SETTINGVARIABLE role, QByteArray value)
{
     mSetRole = role;
     mSetValue = value;
}


inline void ResponseProcessor::run()
{
        while (!mData.isEmpty())
        {
               int currEnd = mData.indexOf('\n'); // 可能为-1,返回数据可能因为错乱没有\n符号
               if(currEnd+1 == 0) mData.clear(); //这一步很重要,没有\n的数据直接抛弃
               // 如果不做处理，while一直卡住,因为remove总是(0,0),那么mData不会为空永远不会跳出
               // 那么外部的IO设备(串口或套接字)内部缓存会累积不能在下次被读取给mData,这样内存就会爆掉

               QByteArray mResponseValue = mData.left(currEnd+1); // 使用left来获取最早的数据,包含\n字符,此时就可以依据是否带分号来区分来自定时查询还是设定查询
               mData.remove(0,currEnd+1);// 拿到一条数据后清理消息队列的对应消息
              if (mResponseValue.contains(';'))  //只有定时查询查询的回复数据才带有分号
                  processFixedQueryData(mResponseValue); // 拆分数据发出去
              else
                  processSetQueryData(mResponseValue);
        }
}

// 固定查询的数据继续拆分
inline void ResponseProcessor::processFixedQueryData(const QByteArray& data)
{
      // 数据形式一般是"15.000;2.000;75.000\n"，有时候可能出现"15.000;2.000;75.000\n15.000;2.000;75.000\n"连发的情况
      // 要把单独的QByteArray格式拆分成QList<QByteArray>格式
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
                    emit fixedQuery(values); // 最后1条消息拆分的VIPR4个值发出去,给监控界面显示
                    return;
              }
               //  如果是1条消息会拆分出2个,第2个是空字符串,形如("15.000;2.000;75.000", "")
              QByteArray value = datas[0];
              QList<QByteArray> values = value.split(';');
              emit fixedQuery(values);
       }
}

// 设定查询只需要通知设定成功与否
inline void ResponseProcessor::processSetQueryData(QByteArray data)
{
        // 数据不包含分号,一般就是"5.000\n"这样形式,role确定是谁发的消息
        if (mSetRole == SETTINGVARIABLE::None)
        {
              //qDebug()<<QTime::currentTime()<<"  没有发送角色";
              return;
        }
        data.chop(1);// 去除"\n"
        // 如果返回的数据和设定的数据一致说明设定成功,否则失败
        // 这里不在serial_variablesetting.cpp中进行重新设定的操作，而是交给用户
        // qDebug()<<response.toDouble()<<" "<<request.toDouble();
        //因为设定值精度是3,回复值一般也是3,所以一般直接相等判断即可
        // 不过为了保证代码的健壮性,即使有一些差别也是允许的:
        // 3.456和3.455认为不相等(精度至少0.001),3.456和3.4564是相等的,和3.4565不相等,允许误差0.0005内
        // 2.000和2也是相等的
        bool ret = qAbs(data.toDouble() - mSetValue.toDouble()) < 0.0005;
        if ((data == mSetValue) || ret ) // 要设定的值和返回的回复确实一致或者在允许范围内
             emit setQuery(true,mSetRole); // 设定成功 => 查询线程 => 监控界面
        else
            emit setQuery(false,mSetRole);// 设定失败 => 查询线程 => 监控界面
}
#endif // DATA_PROCESSING_H

