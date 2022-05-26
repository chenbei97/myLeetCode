/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 17:30:26
 * @LastEditTime: 2022-05-26 17:36:59
 * @Description: SingleSlackerCallOnce.h 使用call_once实现1次调用
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlackerCallOnce.h
 * @Signature: A boy without dreams
 */
#ifndef __SINGLESLACKERCALLONCE__
#define __SINGLESLACKERCALLONCE__
#include <mutex>
class SingleSlackerCallOnce{
     protected:
        SingleSlackerCallOnce(){}; 
        static SingleSlackerCallOnce* instance; // 定义一个静态成员变量
    private: // 定义嵌套类用于释放资源
        static void createInstance();
        class Garbage{
            public:
                ~Garbage(){
                    if (SingleSlackerCallOnce::instance != nullptr){
                        delete SingleSlackerCallOnce::instance;
                        SingleSlackerCallOnce::instance = nullptr;
                    }
                }
        };
    public:
        ~SingleSlackerCallOnce(){};
        SingleSlackerCallOnce(const SingleSlackerCallOnce&) = delete;
        SingleSlackerCallOnce& operator=(const SingleSlackerCallOnce&) = delete;
        static SingleSlackerCallOnce* getInstance();
};
#endif // !__SINGLESLACKERCALLONCE__
