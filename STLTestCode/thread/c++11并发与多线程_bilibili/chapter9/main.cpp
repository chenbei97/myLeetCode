/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:35:22
 * @LastEditTime: 2022-05-27 11:12:12
 * @Description: /chapter9/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter9\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <condition_variable>
#include <future>
using namespace std;
int mythread(){
    cout<<"mythread() is called, thread_id = "<<this_thread::get_id()<<endl;
    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);
    cout<<"mythread() is end, thread_id = "<<this_thread::get_id()<<endl;
    return 5;
}
void test_my_thread(){
    cout<<"main thread id = "<<this_thread::get_id()<<endl;
    // 绑定关系, 创建线程对象, 并且调用线程函数,这里不会卡住
    // async的默认枚举值是launch::async
    std::future<int> result = std::async(std::launch::async,mythread); // std::async(mythread)也可以
    cout<<"continue...!"<<endl;
    int def;
    def = result.get(); // 拿到线程结束后的返回值,在这里会卡住,直到拿到结果为止
    cout<<"result.get() = "<<def<<endl;
}
class A{
    public:
        int my_thread(int a){
            cout<<"value = "<<a<<endl;
            cout<<"mythread() is called, thread_id = "<<this_thread::get_id()<<endl;
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);
            cout<<"mythread() is end, thread_id = "<<this_thread::get_id()<<endl;
            return a;
        }
};
void test_class_member_function_async(){
    cout<<"main thread id = "<<this_thread::get_id()<<endl;
    A a;
    std::future<int> result = std::async(std::launch::async,&A::my_thread,std::ref(a),25);// cl.exe这里必须要对A::my_thread取引用否则编译不通过
    cout<<"continue...!"<<endl;
    int def;
    def = result.get(); // 拿到线程结束后的返回值,在这里会卡住,直到拿到结果为止
    cout<<"result.get() = "<<def<<endl;
    /*
        没调用get的输出结果:
        main thread id = 1
        continue...!mythread() is called, thread_id = 2
        mythread() is end, thread_id = 2
        result.get() = 5
        main thread id = 1
        continue...!
        value = 25
        mythread() is called, thread_id = 3
        mythread() is end, thread_id = 3

        调用get的输出结果: 而且能感觉到执行时会在get()这里卡顿
        main thread id = 1
        continue...!
        mythread() is called, thread_id = 2
        mythread() is end, thread_id = 2
        result.get() = 5
        main thread id = 1
        continue...!
        value = 25
        mythread() is called, thread_id = 3
        mythread() is end, thread_id = 3
        result.get() = 25 // 唯一的区别
    */
}
void test_class_member_function_deferred(){
    cout<<"main thread id = "<<this_thread::get_id()<<endl;
    A a;
    std::future<int> result = std::async(std::launch::deferred,&A::my_thread,std::ref(a),25); // cl.exe这里必须要对A::my_thread取引用否则编译不通过
    cout<<"continue...!"<<endl;
    int def;
    // result.wait(); // 在这里会卡住,直到拿到结果为止
    // def = result.get(); // 拿到线程结束后的返回值,在这里会卡住,直到拿到结果为止
    // cout<<"result.get() = "<<def<<endl;
    // 这里会发现如果没用调用gett()的话,实际线程没有执行,也就是延迟调用,而async是创建了新线程
    // 输出结果只有2句,而A::my_thread函数实际没被调用
    // 这和async作为枚举值参数不同,无论get不get起码是执行的,区别是有没有打印result.get() = 25而已
    // main thread id = 1
    // continue...!
}
int myprint(int async){
    cout<<"async = "<<async<<endl;
    cout<<"myprint() is called, thread_id = "<<this_thread::get_id()<<endl;
    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);
    cout<<"myprint() is end, thread_id = "<<this_thread::get_id()<<endl;    return async;
}
void test_packaged_task(){
    // 这段代码写成成员函数也是一样的没区别
    int async = 255;
    cout<<"main thread id = "<<this_thread::get_id()<<endl;
    std::packaged_task<int(int)> task(myprint);//将函数mythread绑定到task
    thread t(std::ref(task),async);//创建线程,以打包的方式调用myprint
    t.join();//等待线程结束
    std::future<int> result = task.get_future();//获取打包任务的返回值
    cout<<"test_packaged_task => result.get() = "<<result.get()<<endl;//获取任务的返回值

    vector<std::packaged_task<int(int)>> mytasks;
    // 可以使用移动将task移动到mytasks中
    mytasks.push_back(std::move(task));
    auto iter = mytasks.begin();
    std::packaged_task<int(int)>& task2 = *iter; // &表示移动语义,或者使用std::move(*iter)也可以
    mytasks.erase(iter); // 删除移动的task
    std::packaged_task<int(int)> task3 = std::move(task2); // 此时*iter已经失效，只能使用task2
    
    // cout<<"4.------------------------------------"<<endl;
    // 直接调用参数,就像使用myprint一样
    // task3(async);
    // std::future<int> result = task3.get_future(); // 不能再调用
    // cout<<"result.get() = "<<result.get()<<endl;
}
void mypromise(std::promise<int> &p , int async){
    // 注意第1个参数必须是std::promise<int>&,不能是std::promise<int>
    // 可以在线程中运算被其他线程获取到
    cout<<"mypromise() is called, async = "<<async<<endl;
    cout<<"mypromise() is called, thread_id = "<<this_thread::get_id()<<endl;
    // 一些运算...
    async += 10;
    async * 2;
    std::chrono::milliseconds dura(1000);
    std::this_thread::sleep_for(dura);
    cout<<"mypromise() is end, thread_id = "<<this_thread::get_id()<<endl;
    cout<<"after operation, async = "<<async<<endl;
    int result = async;
    p.set_value(result); // 把计算结果放入promise中
}
void mypromise1(std::future<int> &fut){
    // 这是用于第2个线程的入口函数,为了获得第1个线程的结果即mypromise()函数的返回值
    cout<<"mypromise1() is called, thread_id = "<<this_thread::get_id()<<endl;
    auto result = fut.get(); // 获取future的返回值
    cout<<"mypromise1() get this result = "<<result<<endl;
}
void test_promise(){
    // 第1个线程用于计算
    int async = 25;
    std::promise<int> p;
    std::thread t(mypromise,std::ref(p),async);
    t.join();
    // 获取结果值可以在这里(主线程)
    std::future<int> result = p.get_future();
    // cout<<"test_promise=> result.get() = "<<result.get()<<endl;

    /*
        mypromise() is called, async = 25
        mypromise() is called, thread_id = 5
        mypromise() is end, thread_id = 5
        after operation, async = 35
        test_promise=> result.get() = 35
    */
    // 也可以在第2个线程用于获取结果(子线程)
    // 但是要住于因为子线程也调用了get所以上边那条调用get的语句注释掉否则报错
    std::thread t2(mypromise1,std::ref(result));
    t2.join();
    /*
        mypromise1() is called, thread_id = 6
        mypromise1() get this result = 35
    */
}
int main(){
    /*
        (1) std::async、std::future创建后台任务并返回值
            希望线程返回一个结果，是个函数模板，可以启动一个异步任务
            返回一个std::future<T>对象，可以获取异步任务的结果
            启动异步任务：自动创建1个线程并开始执行对应的线程入口函数
            std::future<T>函数里边含有线程入口函数返回的结果,使用get()获取结果
            就是说可能结果不能马上拿到，但是线程结束后可以拿到结果
            get()只能获取一次，如果再次调用get()，会抛出异常
            (1.1) std::launch类型可以作为async的参数,launch是枚举类型
                例如std::launch::deferred,表示线程函数的返回值不会立即被拿到,即get()或者wait()函数调用后才会拿到结果
                enum class launch
                {
                    async = 1, // 会创建一个新线程,并且立即执行线程入口函数
                    deferred = 2 // 延迟调用,线程入口函数不会立即执行,只有在get()或者wait()调用后才会执行
                };
                如果是std::launch::async,那么线程函数的返回值会立即被拿到,即get()或者wait()函数调用后就会拿到结果
        (2) std::packaged_task
            打包任务,是个类模板,模板参数是各种可调用对象,可以是函数,可以是函数对象,可以是lambda表达式
            也就是把各种可调用对象包装起来方便作为线程入口函数被调用
            然后它自身也是可调用对象,可以通过get_future()获取打包函数的返回值result
            然后再用result.get()获取结果
        (3) std::promise
            能在某个线程中赋值,然后在其它线程拿到这个结果
    */
    // 普通函数作为线程函数
    test_my_thread();
    // 类成员函数作为线程函数
    cout<<"1.------------------"<<endl;
    test_class_member_function_async(); // 枚举值是async
    cout<<"2.------------------"<<endl;
    test_class_member_function_deferred(); // 枚举值是deferred
    cout<<"3.------------------"<<endl;
    // 测试std::packaged_task
    test_packaged_task(); // 写成成员函数也可以,这里不再赘述
    cout<<"5.------------------"<<endl;
    // 测试std::promise
    test_promise();
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/