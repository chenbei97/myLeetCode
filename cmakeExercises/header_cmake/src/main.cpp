/*
 * @Author: chenbei
 * @Date: 2022-04-30 20:46:04
 * @LastEditTime: 2022-04-30 20:49:11
 * @FilePath: \myLeetCode\cmakeExercises\header_cmake\src\main.cpp
 * @Description: header_cmake's main.cpp
 * @Signature: A boy without dreams
 */
#include "hello.h"
#include <iostream>
using namespace std;
int main()
{
    cout <<"first => test for function\n";
    test_for_headerCmake();

    cout <<"second => test for class\n";
    Hello hi;
    hi.print();
    return 0;
}