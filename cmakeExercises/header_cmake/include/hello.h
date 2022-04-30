/*
 * @Author: chenbei
 * @Date: 2022-04-30 20:39:01
 * @LastEditTime: 2022-04-30 20:46:22
 * @FilePath: \myLeetCode\cmakeExercises\header_cmake\include\hello.h
 * @Description: header_cmake's hello.h
 * @Signature: A boy without dreams
 */
#ifndef __HELLO_H__
#define __HELLO_H__
void test_for_headerCmake(); // 包含了一个函数的声明,定义在test.cpp
class Hello // 包含了一个类的声明,定义在hello.cpp
{
public:
    void print();
};
#endif