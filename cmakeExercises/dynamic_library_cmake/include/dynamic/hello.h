#ifndef __HELLO_H__
#define __HELLO_H__
// 方法1：class __declspec(dllexport) Hello 只需要+此句限定即可

// 方法2头文件使用宏定义
// #ifdef __HELLO_DLL__
// #define __HELLO_DLL__ __declspec(dllexport)
// #else
// #define __HELLO_DLL__ __declspec(dllimport)
// #endif
// class __HELLO_DLL__ Hello

// 方法3以头文件形式包含宏
#include "dynamic\my_hello_export.h"
class MY_LIB_API Hello
{
public:
    void print();
};
#endif