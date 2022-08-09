/*
 * @Author: chenbei
 * @Date: 2022-08-09 10:59:19
 * @LastEditTime: 2022-08-09 13:52:44
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap03\\3.4.cpp
 * @Description: 给出解决接口固有竞争的方法
 * @Signature: A boy without dreams
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// （1）传入引用
// 借助一个外部变量接收栈容器弹出的元素,并将指向元素的引用通过参数传入pop调用
class myStack
{
public:
    void pop(vector<int>& v){
        //...
    };
// ....
};
void f1()
{
    myStack some_stack;
    vector<int> result; // 外部变量
    some_stack.pop(result); // 想要调用这样的pop,必须构造好myStack这样的类,依据栈容器的元素类型构造实例some_stack
    // 不过某些时候构造这样的实例some_stack时间代价较大,不不太实用
    // 而且要求栈容器存储的元素类型是可赋值的,该限制不可忽略,许多用户自定义的型别不支持赋值
    // 尽管它们支持移动构造或者拷贝构造,即允许pop()按值返回
}


// （2）提供不抛出异常的拷贝构造函数或者不抛出异常的移动构造函数
// 假设pop按值返回,若抛出异常牵涉的异常安全问题只会在这里出现,所以限定用途保证按值返回且不抛异常是安全的
// 不过效果不理想，因为很多时候自定义的数据类型会包含抛出异常的拷贝构造函数却不含移动构造函数
// 虽然随着C++11右值引用的普及这一问题会环节但是现在显然是不好用的

// （3）返回指针，指向弹出的元素
// 不是返回值而是返回指向值的指针，优点是指针可以自由复制一定不发生异常
// 缺点是指针并不安全,可能需要shared_ptr进行自动内存管理

// （4）结合方法1和2，或结合方法1和3
// 没有一种方法能彻底解决问题，全部提供可以让用户自己选择风险最小的方法

// 一个线程安全的栈容器类如下所示
#include <exception>
#include <memory>
#include <mutex>
struct empty_stack: std::exception
{
    const char* what() const throw()
    {
        return "empty stack";
    }
};

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> data; // 内部数据
    mutable std::mutex m;
public:
    threadsafe_stack(){}
    threadsafe_stack(const threadsafe_stack& other) {// 定义拷贝构造
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data; // 安全的复制数据
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete; // 删除赋值运算符函数

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value); // 安全的添加数据
    }
    std::shared_ptr<T> pop()// 使用shared_ptr管理弹出的指向元素的指针
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack(); // 栈空抛出异常
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));//以栈顶元素构造一个智能指针
        data.pop(); // 再删除栈顶元素
        return res; // 返回这个元素的智能指针
    }
    void pop(T& value)// 也可以按值返回,多方法提供
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top(); // 先获取这个值再pop,有异常并不会执行后边的pop
        data.pop();
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    threadsafe_stack<int> si;
    si.push(5);
    si.pop();
    if(!si.empty())
    {
        int x;
        si.pop(x);
    }  
}
/*n
cd C++HighConcurrency/chap03
g++ 3.4.cpp -o 3.4.exe
.\3.4
*/