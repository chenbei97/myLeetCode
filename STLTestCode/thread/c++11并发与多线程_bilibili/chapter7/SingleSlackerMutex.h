/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 16:47:51
 * @LastEditTime: 2022-05-26 17:00:34
 * @Description: SingleSlackerMutex.h 带锁的懒汉式写法
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlackerMutex.h
 * @Signature: A boy without dreams
 */
// 1.3 带锁的懒汉式写法,线程安全
#ifndef __SINGLESLACKERMUTEX__
#define __SINGLESLACKERMUTEX__
#include <mutex>
class SingleSlackerMutex{
    public:
        ~SingleSlackerMutex(){};
        SingleSlackerMutex(const SingleSlackerMutex&) = delete;
        SingleSlackerMutex& operator=(const SingleSlackerMutex&) = delete;
        static SingleSlackerMutex*getInstance();
        static void release();//需要手动释放内存
    protected:
        SingleSlackerMutex(){};
        static SingleSlackerMutex* instance;
        static std::mutex mtx;
};
#endif // !__SINGLESLACKERMUTEX__