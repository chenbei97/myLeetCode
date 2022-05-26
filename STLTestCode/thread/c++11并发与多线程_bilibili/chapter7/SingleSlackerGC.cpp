/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 15:58:12
 * @LastEditTime: 2022-05-26 17:45:38
 * @Description: SingleSlackerGC.cpp 懒汉式单例带资源管理的实现
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlackerGC.cpp
 * @Signature: A boy without dreams
 */
#include "SingleSlackerGC.h"
#include <mutex>
std::mutex resource_mtx; // 进一步改进方法
// std::once_flag resource_flag; // 作为call_once的标记,可以进一步改进提高效率,这个写法可见SingleSlackerCallOnce.h
SingleSlackerGC * SingleSlackerGC::instance = nullptr; // // 初始化单例对象为空指针
SingleSlackerGC* SingleSlackerGC::getInstance(){
    if(instance == nullptr){ // 不代表instance没被new过(可能是另1个线程new的),但是!=nullptr时说明肯定被new过
    // 如果不为nullptr时就不需要再加锁,只需要初始化时才加锁,双重判断提高效率
        std::unique_lock<std::mutex> lck(resource_mtx); // 自动上锁,线程竞争时避免出错
        if (instance == nullptr){
            instance = new SingleSlackerGC();
            static Garbage gar; // 程序结束时会调用gar的析构函数从而释放new的实例
        }
    }
    return instance;
}
