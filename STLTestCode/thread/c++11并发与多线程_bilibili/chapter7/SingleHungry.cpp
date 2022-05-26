/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 16:05:29
 * @LastEditTime: 2022-05-26 16:06:42
 * @Description: SingleHungry.cpp 饿汉式静态成员直接实例化单例的定义文件
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleHungry.cpp
 * @Signature: A boy without dreams
 */
#include "SingleHungry.h"
SingleHungry SingleHungry::instance; // 初始化单例的定义
SingleHungry* SingleHungry::getInstance(){ // 类外实现,注意返回的是指针,所以取地址
    return &instance;
}