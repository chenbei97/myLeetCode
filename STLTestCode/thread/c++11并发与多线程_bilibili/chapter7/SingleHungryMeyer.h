/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 16:07:57
 * @LastEditTime: 2022-05-26 16:18:49
 * @Description: SingleHungryMeyer.h Meyer在Effective提出的写法
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleHungryMeyer.h
 * @Signature: A boy without dreams
 */
// 2.1 饿汉式写法: Meyer在EffectiveC++中提出的单例模式写法,利用局部静态对象
#ifndef __SINGLEHUNGRYMETER__
#define __SINGLEHUNGRYMETER__
class SignleHungryMeyer{
    public:
        ~SignleHungryMeyer(){};
        SignleHungryMeyer(const SignleHungryMeyer&) = delete;
        SignleHungryMeyer& operator=(const SignleHungryMeyer&) = delete;
        static SignleHungryMeyer& getInstance();
    protected:
        SignleHungryMeyer(){};
};
#endif // ! __SINGLEHUNGRYMETER__