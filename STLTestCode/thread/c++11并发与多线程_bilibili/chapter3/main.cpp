/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 09:54:53
 * @LastEditTime: 2022-05-25 15:24:54
 * @Description: /chapter3/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter3\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <string>
#include <windows.h> // sleep
using namespace std;
void myprint1(const int &id, char * buf){
    cout <<"const int& is copy, char * not copy! : &id = "<<&id<<" &buf = "<<(void*)buf<<endl;
}
void myprint2(const int &id, const string & buf){
    cout <<"const int& and string& is copy! : &id = "<<&id<<" &buf = "<< &buf<<endl;
}
void normal_version(const int &id, char * buf){
    cout <<"normal_version keep same! : &id = "<<&id<<" &buf = "<<(void*)buf<<endl;
    thread t(myprint1, id, buf);
    t.join();
    cout<<"---------------------------------------->"<<endl;
}
void trap1_version(const int &id, char * buf){
    // 如果使用的是detach,由于存在指针参数就可能会造成问题
    cout <<"trap1_version keep same! : &id = "<<&id<<" &buf = "<<(void*)buf<<endl;
    thread t(myprint1, id, buf); // 首先要注意这里传递给myprint1的id并不是外部变量id,而是复制
    t.detach();
    cout<<"---------------------------------------->"<<endl; 
}
void trap1_version_improve(const int &id, const string& buf){
    // 如果使用的是detach,由于存在指针参数就可能会造成问题
    // 解决方案是改用string&代替char*,不过要注意这里因为存在隐式转换
    // 所以进来的buf地址和外部的不同了,然后进入myprint2进一步被值传递,buf又是不同的,相当于有3个地址
    cout <<"trap1_version_improve: id is same, buf not same! : &id = "<<&id<<" &buf = "<< &buf<<endl;
    thread t(myprint2, id, buf); // 使用改进版本
    t.detach();
    cout<<"---------------------------------------->"<<endl; 
}
class TA{
    public:
        int value;
        TA(int v):value(v){cout<<"TA's default constructor"<<endl;}
        TA(const TA& t):value(t.value){cout<<"TA's copy constructor"<<endl;}
        ~TA(){cout<<"TA's destructor"<<endl;}
        void printValue(int num){
            this->value = num;
            cout<<"print TA's value = "<<value<<endl;
        }
        void operator()(int num){
            this->printValue(num);
        }
};
void myprint3(const TA& ta){
    // (3.1) 传递类对象
    cout<<"&ta = "<<&ta<<" ta.value = "<<ta.value<<endl;
}
void myprint4(const unique_ptr<int> &up){
    // (3.2) 传递unique_ptr
    cout<<"&up = "<<&up<<" up.get() = "<<up.get()<<endl;
}
int main(){
    /*
        (1) 传递临时对象作为线程参数
            (1.1) 避免的陷阱 解释1
                如果使用的是detach(),且子线程存在引用或指针,可能运行的结果不同
                首先第1个问题,外部变量如果是普通表变量即使作为引用参数被传入thread,也是复制拷贝,所以不会造成问题
                但是如果传递的是指针,会发现外部变量的指针地址和子线程的地址完全一样,这样其实是不安全的会产生问题
                解决方法是myprint1不要传递char*,改用string&,这样可以隐式转换也就是myprint2,这样都是值传递了
            (1.2) 避免的陷阱 解释2
                char*在什么时候被转为string&的?因为可能主线程执行完了,char*都被销毁了,再转为string&时可能会导致错误
                所以为了保证稳定,可以不隐式转换,而是传递给thred(myprint2)时就先显示转换
            以上2条总结来说：就是推荐值传递，不要传递指针给线程，并一定要在主线程结束之前就将对象提前复制给线程,这样不会出错
            如果是内置类型,一律使用值传递,不要使用引用以免节外生枝;如果传递类对象,避免隐式类型转换;全部在创建线程这一行就构建出临时对象
            然后在类的构造参数里一定要用引用参数来接,否则系统还会多构造一次对象
            终极结论就是不要使用detach,使用join就没有这些问题
        (2) 临时对象作为线程参数继续讲
            (2.1) 线程id概念
                可以使用this_thread::get_id()获取线程id
            (2.2) 临时对象构造时机抓捕
                这里其实已经实现过了,就是将亡值由于右值引用的原因延长生命周期,在主线程中就已经构造了,所以在子线程中就不会再构造了
        (3) 传递类对象、智能指针作为线程参数
            std::ref函数：可以在线程中真正传递引用而不是值拷贝,或者直接取类对象的地址传递也可以
            但是要注意是以join加入的,不然detach使用引用可能会有错误
            (3.1) 传递类对象
            (3.2) 传递智能指针,例如unique_ptr
                独占式智能指针,禁止拷贝和赋值,所以传入thread时必须使用move函数转为右值才能传递引用
                同样智能指针也要使用join,否则容易造成成员泄露
        (4) 使用成员函数指针作为线程函数
            同样只能使用join()
            如果是普通函数,指明成员函数需要使用作用域符号::,并取地址thread(&类::成员函数,类对象,成员函数参数)
                如果传递引用可以使用std::ref和&,这里&相当于取this指针所以允许
            如果是operator()函数,只需要thread(类对象,operator()的参数)
                如果传递引用必须使用std::ref,不可以使用&,因为当作一个函数对象使用
    */
    int id = 1;
    int &id_ref = id;
    char buf[] = "hello";
    // 打印id,和id_ref的地址,是相同
    cout<<"external: &id = "<<&id<<" &id_ref = "<<&id_ref<<" &buf = "<<(void*)&buf<<endl;
    // (1) 传递临时对象作为线程参数
    normal_version(id_ref, buf);
    // (1.1) 避免的陷阱 解释1
    trap1_version(id_ref, buf);
    // 可以看出来,传递给调用的函数xx_version_xx的id地址还是和外部地址相同的
    // 如果是正常版本和trap1版本,buf也都是相同的,trap1_improve版本buf不同(隐式转换原因)
    // 对于myprint1,进入的id地址是不同的,因为myprint1的id是复制的
    // 而char*地址是相同的,这里实际是地址传递给thread,buf在myprint1的地址和外部的是一样的

    // 改用string&代替char*,会发现trap1_version_improve的buf和外部的不同(隐式转换产生新局部变量的原因)
    // 以及myprint2的id和buf和外部均不同(值传递的原因)
    trap1_version_improve(id_ref, buf); 
    /*
        某次运行结果:
        external: &id = 0x5e8bfffd4c &id_ref = 0x5e8bfffd4c &buf = 0x5e8bfffd46
        normal_version keep same! : &id = 0x5e8bfffd4c &buf = 0x5e8bfffd46
        const int& is copy, char * not copy! : &id = 0x214c83262a0 &buf = 0x5e8bfffd46
        ---------------------------------------->
        trap1_version keep same! : &id = 0x5e8bfffd4c &buf = 0x5e8bfffd46
        ---------------------------------------->
        trap1_version_improve: id is same, buf not same! : &id = 0x5e8bfffd4c &buf = 0x5e8bfffd50
        const int& is copy, char * not copy! : &id = 0x214c83262a0 &buf = 0x5e8bfffd46
        const int& and string& is copy! : &id = 0x214c8326df8 &buf = 0x214c8326dd8
        ---------------------------------------->
    */

    // 然而上边的写法可能依然是不稳定的
    // 因为可能主线程执行完了,char*都被销毁了,再转为string&时可能会导致错误
    // 这里是因为借助了trap1_version_improve本身函数参数有个隐式转换,所以内部到达thread时buf已经是string&类型
    // 如果trap1_version_improve的这些代码直接写在主程序应当这样写
    thread t(myprint2, id, string(buf)); // 应当显示转换这样会更加稳定,主线程结束之前就将char*转换为string&
    t.detach();
    cout<<"1.---------------------------------------->"<<endl; 
    // (2.1) 获取线程id (2.2) 临时对象构造时机抓捕,也就是上边说的传入thread之前先使用string进行显示转换
    cout<<"main thread's id is "<<this_thread::get_id()<<endl; // 1
    cout<<"2.---------------------------------------->"<<endl; 
    
    // (3) 传递类对象、智能指针作为线程参数 ：借助std::ref传递引用
    // 但是要注意是以join加入的,不然detach使用引用可能会有错误
    // (3.1) 传递类对象 
    TA ta(10); // TA's default constructor
    cout<<"&ta = "<<&ta<<endl; // &ta = 0x5b52bff7e4
    thread t2(myprint3,ta);// TA's copy constructor 
    t2.join(); // &ta = 0x5b52bff7e4 ta.value = 10 这里可以发现不是std::ref就是值传递
    thread t3(myprint3,std::ref(ta)); // &ta = 0x252b9626a08 ta.value = 10 使用了std::ref是引用传递
    t3.join(); // TA's destructor × 2
    cout<<"3.---------------------------------------->"<<endl; 
    // (3.2) 传递智能指针
    auto *p = new int(100); // int *
    cout<<"p's address is "<<p<<endl; // p's address is 0x1cac49e6290
    unique_ptr<int> up(p); // 独占式智能指针,禁止拷贝和赋值,所以传入thread时必须使用move函数转为右值才能传递引用
    thread t4(myprint4,std::move(up)); // 独占式智能指针的拷贝构造,不使用move会报错
    t4.join(); // &up = 0x1cac49e62b8 up.get() = 0x1cac49e6290
    cout<<"4.---------------------------------------->"<<endl; 
    // (4) 使用成员函数指针作为线程函数
    TA ba(5); // TA's default constructor
    thread t5(&TA::printValue,ba,15);// TA's copy constructor,print TA's value = 15
    t5.join(); // 最好使用join,但是因为这里ba是值传递,所以使用detach似乎也无大碍
    // 当然也可以既使用成员函数也可以同时使用std::ref
    cout<<"5.---------------------------------------->"<<endl; 
    thread t6(&TA::printValue,std::ref(ba),15); // 这里会发现没有调用拷贝构造
    t6.join();
    cout<<"6.---------------------------------------->"<<endl; 
    // 使用&代替std::ref也是ok的
    thread t7(&TA::printValue,&ba,15);
    t7.join();
    cout<<"7.---------------------------------------->"<<endl; 
    // 上边的成员函数使用的是一个普通函数,接下来测试operator()可调用对象
    // 这里要注意如果传递引用必须使用std::ref,不可以使用&,因为当作一个函数对象使用
    thread t8(std::ref(ba),15); // 这样的无需显示给出成员函数指针,直接传递类对象也是ok的
    t8.join(); 
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/