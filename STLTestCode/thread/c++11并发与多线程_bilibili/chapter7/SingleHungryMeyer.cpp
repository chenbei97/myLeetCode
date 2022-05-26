/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 16:11:23
 * @LastEditTime: 2022-05-26 16:13:06
 * @Description: SingleHungryMeyer.cpp 定义文件
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleHungryMeyer.cpp
 * @Signature: A boy without dreams
 */
#include "SingleHungryMeyer.h"
// 2.1  局部静态对象写法
SignleHungryMeyer& SignleHungryMeyer::getInstance(){
    static SignleHungryMeyer instance;
    return instance;
}