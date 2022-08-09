/*
 * @Author: chenbei
 * @Date: 2022-08-09 09:37:13
 * @LastEditTime: 2022-08-09 10:16:28
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap03\\3.2.cpp
 * @Description: 使用互斥量保护数据时不要给互斥锁所在的作用域以外传递指针或引用
 * @Signature: A boy without dreams
 */
#include <mutex>
#include <iostream>

class some_data // 数据存放的类
{
    int a;
    std::string b;
public:
    void do_something()
    {std::cout<<"do_something\n";}
};

class data_wrapper // 封装数据的类
{
private:
    some_data data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func) // 成员模板函数,本意是外部传入1个函数处理数据的时候可以提供保护
    {
        std::lock_guard<std::mutex> lock(m);
        func(data); // func是使用者提供的函数
    }
};

some_data* unprotected;

void malicious_function(some_data& protected_data) // 使用者提供的函数
{
    unprotected=&protected_data; // 使用者本应该直接在这里调用protected_data.do_something()即可
    // 但是使用者没有这么做,而是把共享数据的引用传递给了外部变量,然后在另一个函数处理外部变量,它不再受保护
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function); // 使用者传入函数拿到了共享数据的指针
    unprotected->do_something();// 绕过保护调用了本该受保护的代码
}

int main()
{
    foo();
}

/*
cd C++HighConcurrency/chap03
g++ 3.2.cpp -o 3.2.exe
.\3.2
*/