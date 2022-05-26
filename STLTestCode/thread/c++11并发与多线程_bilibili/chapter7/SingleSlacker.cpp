/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 15:50:26
 * @LastEditTime: 2022-05-26 15:51:40
 * @Description: SingleSlacker的定义文件
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlacker.cpp
 * @Signature: A boy without dreams
 */
#include "SingleSlacker.h"
SingleSlacker * SingleSlacker::instance = nullptr; // 初始化单例对象为空指针

void SingleSlacker::deleteInstance(){ // 无需再声明static
    if (instance != nullptr){
        delete instance;
        instance = nullptr;
    }
}

SingleSlacker* SingleSlacker::getInstance(){
    if (instance == nullptr){
        instance = new SingleSlacker(); 
    }
    return instance;
}