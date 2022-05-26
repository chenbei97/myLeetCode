/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 16:03:47
 * @LastEditTime: 2022-05-26 16:19:03
 * @Description: SingleHungry.h 饿汉式的写法,直接作为静态成员变量实例
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleHungry.h
 * @Signature: A boy without dreams
 */
// 2.饿汉式写法:第一时间创建实例,执行效率比懒汉高,但是类加载时就初始化浪费内存
// 2.1 这里是静态成员对象的写法,即instance是静态成员
#ifndef __SINGLEHUNGRY__
#define __SINGLEHUNGRY__
class SingleHungry{
    protected:
        SingleHungry(){}; // 让构造函数成为私有,外部就不能直接创建对象了
        static SingleHungry instance; // 作为静态成员对象,直接实例化
    public:
        ~SingleHungry(){};
        SingleHungry(const SingleHungry&) = delete;
        SingleHungry& operator=(const SingleHungry) = delete;
        static SingleHungry* getInstance();
};
#endif // !__SINGLEHUNGRY__