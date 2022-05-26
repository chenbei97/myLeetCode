/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 16:51:32
 * @LastEditTime: 2022-05-26 17:03:27
 * @Description: SingleSlackerMutex 带锁的懒汉式单例模式
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlackerMutex.cpp
 * @Signature: A boy without dreams
 */
#include "SingleSlackerMutex.h"
// 1.3 带锁的懒汉单例模式
SingleSlackerMutex* SingleSlackerMutex::instance = nullptr;
std::mutex SingleSlackerMutex::mtx;
SingleSlackerMutex* SingleSlackerMutex::getInstance(){
    if (instance == nullptr){
        mtx.lock();//上锁
        if (instance == nullptr){
            instance = new SingleSlackerMutex();
        }
        mtx.unlock(); // 去锁
    }
    return instance;
}

void SingleSlackerMutex::release(){
    if (instance!= nullptr){
        mtx.lock();
        if (instance != nullptr){
            delete instance;
            instance = nullptr;
        }
        mtx.unlock();
    }
}