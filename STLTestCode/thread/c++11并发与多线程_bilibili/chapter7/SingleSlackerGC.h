/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 15:56:15
 * @LastEditTime: 2022-05-26 16:17:49
 * @Description: SingleSlackerGC.h 借助了嵌套类实现资源的释放
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\SingleSlackerGC.h
 * @Signature: A boy without dreams
 */
#ifndef __SINGLESLACKERGC__
#define __SINGLESLACKERGC__
// 1.2 b站提供的另一种懒汉式的写法,静态对象生成在堆中可以借助GC释放资源
// 是对懒汉式写法的一种改进
// https://www.bilibili.com/video/BV1Yb411L7ak?p=9
class SingleSlackerGC{
    protected:
        SingleSlackerGC(){}; 
        static SingleSlackerGC* instance; // 定义一个静态成员变量
    private: // 定义嵌套类用于释放资源
        class Garbage{
            public:
                ~Garbage(){
                    if (SingleSlackerGC::instance != nullptr){
                        delete SingleSlackerGC::instance;
                        SingleSlackerGC::instance = nullptr;
                    }
                }
        };
    public:
        ~SingleSlackerGC(){};
        SingleSlackerGC(const SingleSlackerGC&) = delete;
        SingleSlackerGC& operator=(const SingleSlackerGC&) = delete;
        static SingleSlackerGC* getInstance();
};
#endif // !__SINGLESLACKERGC__