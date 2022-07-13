#ifndef LOG_H
#define LOG_H
#include <QString>
class Log
{
public:
  enum class logType  {
      default_type, // 默认函数类型,6个编译器生成的构造函数
      dynamic_slot_type, // 自定义的槽函数,是某些信号的响应
      static_slot_type,// UI组件信号的槽函数
      initialize_type,// 用于初始化的一类函数
      signal_type,// 自定义的信号
      forward_type, // 转交/中介函数
      other_type, // 其它类型
  };
public:
  Log();
private:
  QString * saveFileName;
};

#endif // LOG_H
