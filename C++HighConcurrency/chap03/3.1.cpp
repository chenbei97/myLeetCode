/*
 * @Author: chenbei
 * @Date: 2022-08-09 09:00:53
 * @LastEditTime: 2022-08-09 10:35:38
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap03\\3.1.cpp
 * @Description: 使用互斥保护共享数据
 * @Signature: A boy without dreams
 */
#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>

std::list<int> mList;
std::mutex mtx;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(mtx);
    mList.push_back(new_value);
}
bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(mtx);
    return std::find(mList.begin(),mList.end(),value_to_find)
        != mList.end(); // 查找指定元素,如果没找到会返回end(),此时返回false
}

// c++17支持了简单模板参数推导,对于std::lock_guard<>模板参数列表可以省略
// 上述的std::lock_guard<std::mutex> guard(mtx); 都可以简化成std::lock_guard guard(mtx);
// 进一步的c++17还引入了std::scoped_lock,是增强版的lock_guard,也可以写成std::scoped_lock guard(mtx);

// 但是要住于大多数时候不使用全局变量而是使用类存放数据以及mutex，而2个函数则变成成员函数
// 这样那些代码需要访问哪些代码需要锁住互斥都很容易确定
// 不过只有一种情况使用互斥没有用，成员函数若返回指向共享数据的指针或引用就会破坏保护
// 所以使用互斥时要谨慎设计程序接口确保互斥先行锁定然后再对受保护的共享数据进行访问
int main()
{
    add_to_list(42);
    std::cout<<"contains(1)="<<list_contains(1)<<", contains(42)="<<list_contains(42)<<std::endl;

    for(int i = 1; i <= 200; ++i)
    {
        add_to_list(i);
        std::cout<<"contains(100) = "<<std::boolalpha<<list_contains(100)<<"\n"; //不会读写发生冲突
    }
}

/*
cd C++HighConcurrency/chap03
g++ 3.1.cpp -o 3.1.exe
.\3.1
*/