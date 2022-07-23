/*
 * @Author: chenbei
 * @Date: 2022-07-23 19:23:05
 * @LastEditTime: 2022-07-23 20:26:35
 * @FilePath: \\myLeetCode\\STLTestCode\\C++HeaderFileCodeSpecification.h
 * @Description: C++头文件的代码规范示例
 * @Signature: A boy without dreams
 */

 /************************************************************
关于代码规范的注意点都使用尖括号<>注明
1. 头文件扩展名.h 文件名全小写,可包含下划线或者短线
************************************************************/

// Copyright 2022 Google Inc. <版权声明>
// License(BSD/GPL/...) <许可证声明>
// Author: chenbei <作者>
// This is ... <文件内容简短说明>

#ifndef PROJECT_EVENTLOOP_H_    // <防止重复包含>
#define PROJECT_EVENTLOOOP_H_   // <宏格式为:<project>_<path>_<file>_ >

class Channel;  // <头文件中尽量使用前置声明,STL类例外不使用前置声明,使用# include >

namespace mynamespace { // <命名空间全小写,顶头无空格,cc文件提倡使用不具名空间>

class EventLoop : public CallbackInterface { // <类名大写开头单词,使用组合比使用继承更好;若用继承只用公有继承;接口类命名以"Interface"结尾>
 public: // <访问限定符1个空格缩进>
    // <每一个限定符内,声明顺序如下>
    // 1. typedefs和enums
    // 2. 常量
    // 3. 构造函数
    // 4. 析构函数
    // 5. 成员函数，含静态数据成员
    // 6. 成员变量，含静态成员变量
  typedef vector<int> IntVector;
  enum UrlTableErrors { // <2空格缩进>
    ERROR_OUT_OF_MEMORY = 0, // <枚举名同类名,大写开头单词>
    ERROR_MALFORMED_INPUT,  // <枚举值2空格缩进,全大写下划线>
  };
  explicit EventLoop(const int xx); // <explicit修饰单参数构造函数防止隐式转换;若定义了成员变量无构造函数,要定义一个默认构造函数>

  void Add(const std::string& input, Channel* output);// <普通函数命名大写开头单词,输入参数在前为const引用,输出参数在后为指针,不为参数设置缺省值>

  int num_entries() const {return num_entries_; } // <存取函数命名,取函数:同变量名;存函数:命名为set_varname>
  void set_num_entries(int num_entries) { num_entries_ = num_entries; } // <短小的存取函数可以使用inline>

 private:
  DISALLOW_COPY_AND_ASSIGN(EventLoop);// <仅在需要拷贝对象时i使用拷贝构造函数,不需要拷贝时在private里使用DISALLOW_COPY_AND_ASSIGN宏>

  const int kDaysInWeek = 7; // <变量使用描述性名称不要节约空间,让别人理解你的代码更重要> <const变量一律使用k开头后跟大写开头单词>
  int num_entries_; // <变量命名全小写,有意义的单词和下划线>
  int num_complated_connections_; // <类成员变量下划线结尾>

  Channel* channel_; // <头文件中只用了指针/引用,则前向声明而非引入头文件>
};

} // namespace mynamespace

#endif // PROJECT_EVENTLOOP <保护宏加注释>