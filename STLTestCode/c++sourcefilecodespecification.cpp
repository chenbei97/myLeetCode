/*
 * @Author: chenbei
 * @Date: 2022-07-23 19:58:15
 * @LastEditTime: 2022-07-23 20:25:20
 * @FilePath: \\myLeetCode\\STLTestCode\\c++sourcefilecodespecification.cpp
 * @Description: C++源文件的代码规范示例
 * @Signature: A boy without dreams
 */

 /************************************************************
关于代码规范的注意点都使用尖括号<>注明
1. 头文件扩展名.h 文件名全小写,可包含下划线或者短线
2. 尽量不使用宏
3. 禁止使用RTTI
4. 使用printf之类的代替流
5. 除位饫不使用无符号数字
6. 除特定环境不使用操作符重载
7. 使用4种类型转换cast运算符替代C风格转换
8. 禁止使用Class类型全局变量
9. 使用sizeof(var)来代替sizeof(type)
10. scoped_ptr可以胜任智能指针
11. 特殊情况下可用shared_ptr,任何时候都不使用auto_ptr
************************************************************/

// CopyRight 2022 Googlw Inc. <版权声明>
// License(BSD/GPL/...) <许可证声明>
// Author: chenbei <作者>
// This is ... <文件内容简短说明>

#include "c++headerfilecodespecification.h" // <包含次序标准化避免隐藏依赖>
#include <sys/types.h> // <1. 本类的声明(第一个包含本类h文件,有效减少依赖)>
#include <vector> // <2. C系统文件> <3. C++系统文件>
#include "base/basictypes.h"// <4. 其它库头文件>
#include "foo/public/bar.h" // <5. 本项目内头文件(避免使用UNIX文件路径"."和"..")>

using std::string; // <禁止使用using namespace xx污染命名空间>

namespace mynamespace{
    : _num_entries_(10), // <多行初始化列表,":"之前4个空格.以","结尾>
      _num_complated_connections_(false) { // <多个变量折行对齐>
//...    // <单行初始化列表 Class:Class() : _var(xx) { >  <构造函数中只进行那些没有实际意义的初始化>
 }

 ReturnType ClassName::ReallyLongFunctionName(const Type& par_name1,
                                              Type* par_name2) {
    bool retval = DoSomething(averyveryverylongargument1, // <参数过多时","结尾,每行1个变量对齐>
                              argument2, argument3);
    if (condition) { // <条件括号内无空格,左右空1格, if执行2空格缩进>
      for (int i = 0; i < kSomeNumber; ++i) { // <使用前置++运算>
        if (this_one_thing > this_other_thing &&
            a_third_thing == a_fourth_thing) {
                // TODO(name&abc.com): xxx 临时方案使用TODO(大写)注释,后边括号里加上你的大名、邮件地址等
        }
      }
    } else {
        int j  = g(); // <大括号与else同行,else左右1格空格,尽量使用初始化时声明>
    }
    switch (var) { // <var左右1格空格>
      case 0: { // <case相对switch 2空格缩进>
        //... <执行体相对switch 4空格缩进>
        break;
      }
      default: {
        assert(false); // <若default永不执行可使用assert>
      }
    }
    return x; // <返回值不需要加括号>
}

} // namespace mynamespace 命名空间结束注释