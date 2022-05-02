/*
 * @Author: chenbei
 * @Date: 2022-05-02 19:23:07
 * @LastEditTime: 2022-05-02 20:25:58
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\size_t.cpp
 * @Description: test size_t
 * @Signature: A boy without dreams
 */
/*
g++ -o size_t size_t.cpp
./size_t
*/
#include <iostream>
using namespace std;
int main()
{
    // sizeof返回的必定是无符号整形,在标准c中通过 typedef 将返回值类型定义为size_t
    // size_t目的是为了可移植性,可以在不同平台上使用同一个程序
    // 在c++中size_t是一个类型,可以用来表示一个类型的大小

    // size_t与sizeof的关系示意如下:
    // size_t是一个类型,sizeof是一个操作符但不是一个函数
    auto st1 = sizeof(int); // st1推断为unsigned long long
    std::cout << "sizeof(int) = " << st1 <<std::endl; // 4
    auto st2 = sizeof(unsigned int); // st2推断为unsigned long long
    std::cout << "sizeof(unsigned int) = " << st2 << std::endl; // 4
    auto st3 = sizeof(long); // st3推断为unsigned long long
    std::cout << "sizeof(long) = " << st3 << std::endl; // 4
    auto st4 = sizeof(unsigned long); // st4推断为unsigned long long
    std::cout << "sizeof(unsigned long) = " << st4 << std::endl; // 4
    auto st5 = sizeof(long long); // st5推断为unsigned long long
    std::cout << "sizeof(long long) = " << st5 << std::endl; // 8
    auto st6 = sizeof(unsigned long long); // st6推断为unsigned long long
    std::cout << "sizeof(unsigned long long) = " << st6 << endl; // 8
    auto st7 = sizeof(size_t); // st7推断为unsigned long long
    std::cout << "sizeof(size_t) = " << st7 << std::endl; // 8
    // 从以上可以看出,size_t一定是无符号的,而且是最大的类型
    // sizeof(xxx)得到的其实就是size_t,都推断为unsigned long long是因为size_t是最大的类型
    // 而本台机器是64位的,所以size_t的大小是8字节,而sizeof(xxx)得到的是4字节或者8字节
    // 如果移植到32位机器,size_t是最大的类型即4子节,而sizeof(xxx)得到的是4字节

    // 因为size_t类型的数据其实是保存了一个整数
    // 所以它也可以做加减乘除，也可以转化为int并赋值给int类型的变量
    int a = (int)st1;
    std::cout << "a = " << a << std::endl; // 4
    int b = (int)st7;
    std::cout << "b = " << b << std::endl; // 8

    // 如果size_t的值超过了int的范围,那么它就会自动转化为long long
    // 使用size_t在while循环可能出错的示例
    // 如果使用int
    int m = 5;
    while(m>=0)
    {
        std::cout << "m = " << m << std::endl;
        m--;
    }
    std::cout <<std::endl; // 不会有任何问题,5,4,3,2,1,0

    // 使用size_t就会出错,因为size_t是无符号的,最小为0
    // 所以size_t的0一旦递减就反而成为最大值18446744073709551615了
    size_t sm = 5;
    int i = 0;
    while(sm>=0)
    {
        std::cout << "before sm = " << sm << std::endl; // 这里sm=5,4,3,2,1,0都没问题
        sm--; // 当sm=0时再--,就会出错,因为是无符号类型,0--得到的是18446744073709551615
        std::cout << "after sm = " << sm << std::endl;
        i++; // 之后循环就等于sm=18446744073709551615开始循环递减了
        if (i>8) break; // 这是为了终止死循环,但是还能保证打印有效的信息查出问题
    }
}