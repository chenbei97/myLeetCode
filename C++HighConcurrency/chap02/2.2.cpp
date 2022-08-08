/*
 * @Author: chenbei
 * @Date: 2022-08-08 09:46:34
 * @LastEditTime: 2022-08-08 10:31:09
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap02\\2.2.cpp
 * @Description: 线程函数传递参数
 * @Signature: A boy without dreams
 */
// 线程传递参数时一律是复制原有数据类型到线程的起始函数处，不会发生隐式转换，也不会知道是否为引用参数
// 传递的参数都当成临时变量，形成一个右值方式传递给线程起始函数
#include <string>
#include <thread>

void f(int i, const std::string& s);
std::thread t(f,3,"hello");

// 这里复制参数3和"hello"给f,进入新线程的上下文环境后才会转换为string类型
void oops(int param)
{
    char buffer[1024];
    sprintf(buffer,"%i",param);
    std::thread t(f,3,buffer);
    t.detach();
}
// 原本设想buffer对象会在新线程内换换成std::string对象
// 但是完成之前oops函数极有可能已经退出
// 导致局部变量buffer被销毁引发未定义行为
// 原因是thread构造函数原样复制值但是没有转换为预期的参数类型，解决方法是buffer传入之前先转换为string对象
void oops_(int param)
{
    char buffer[1024];
    sprintf(buffer,"%i",param);
    std::thread t(f,3,std::string(buffer));
    t.detach();
}
// 另外如果想传入的是非const左引用(右值不能隐式转换为非const左引用)就会导致编译错误
class ID{};
class DATA{};
void update(ID id, DATA &data);//非const左值引用
void display_status();
void process_data(DATA data);
void oops(ID id)
{
    DATA  data;
    // std::thread t(update,id,data); // 传递的实际上是右值不能通过编译
    std::thread t(update,id,std::ref(data));//必须借助std::ref才能传递引用参数
    display_status();
    t.join();
    process_data(data);
}

// 传递参数还可以使用类的成员函数，需要使用&运算符，绑定具体的对象
class X
{
public:
    void do_work();
};
X myx;
std::thread t(&X::do_work,&myx); // 使用&

// 传递参数还可以使用std::move,对于右值(临时不具名对象会自动发生,具名对象需要显示使用move函数)
class big_object{};
void process_big_object(std::unique_ptr<big_object>);
std::unique_ptr<big_object> p (new big_object);
std::thread t(process_big_object,std::move(p)); // 独占指针需要显式使用std::move进行传递否则会直接复制

// 对于thread本身，和unique_ptr类似，每个thread实例掌控1个线程，故不能发生复制，而只能移动
// 所以thread的归属权可以在实例之间进行转移，保证了任一特定的执行线程，任何时候都只有唯一的std::thread对象与之关联