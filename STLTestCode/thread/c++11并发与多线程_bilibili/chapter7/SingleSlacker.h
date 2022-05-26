/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 15:48:18
 * @LastEditTime: 2022-05-26 16:18:21
 * @Description: 单例模式的懒汉式写法,线程不安全
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlacker.h
 * @Signature: A boy without dreams
 */
#ifndef __SINGLESLACKER__
#define __SINGLESLACKER__
// 1.懒汉式写法:实例用到时才创建,会有线程安全问题
// 因为new的单例对象没有时机去释放,会导致内存泄漏
// 1.1 没有资源管理的写法
class SingleSlacker{
    protected:
        SingleSlacker(){}; // 让构造函数成为私有,外部就不能直接创建对象了
        static SingleSlacker* instance; // 定义一个静态单例对象指针,是保护成员可以外部访问
    public:
        ~SingleSlacker(){};
        SingleSlacker(const SingleSlacker&) = delete;
        SingleSlacker& operator=(const SingleSlacker&) = delete;
        static SingleSlacker* getInstance();
        static void deleteInstance();
};
#endif // !__SINGLESLACKER__