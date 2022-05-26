/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 17:33:25
 * @LastEditTime: 2022-05-26 17:43:02
 * @Description: SingleSlackerCallOnce.cpp 使用callonce的定义文件
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlackerCallOnce.cpp
 * @Signature: A boy without dreams
 */
#include "SingleSlackerCallOnce.h"
#include <thread>
#include <chrono>
std::once_flag resource_flag; // 作为call_once的标记,可以进一步改进提高效率
SingleSlackerCallOnce * SingleSlackerCallOnce::instance = nullptr; // // 初始化单例对象为空指针
SingleSlackerCallOnce* SingleSlackerCallOnce::getInstance(){
    std::call_once(resource_flag,createInstance); // 可以保证线程竞争中,实例化只被执行1次
    return instance;
}
void SingleSlackerCallOnce::createInstance(){
    std::chrono::milliseconds dura(2000); // 2s
    std::this_thread::sleep_for(dura); // test it
    instance = new SingleSlackerCallOnce();
    static Garbage gar;
}