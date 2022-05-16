/*** 
 * @Author: chenbei
 * @Date: 2022-05-16 11:26:58
 * @LastEditTime: 2022-05-16 11:54:56
 * @Description: 九号公司的一些面试题
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\nine.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode\\yushiqi
g++ -o nine nine.cpp
./nine
*/
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <iterator>
using namespace std;
// 写一个类要求可复制和可赋值
class Test{
    public:
        Test(int id, string* str):id_(id),str_(str){}
        // Test& operator=(const Test& t){
        //     if (this == &t)
        //         return *this;
        //     //delete this->str_;
        //     this->str_ = t.str_; // 浅拷贝的写法
        //     this->id_ = t.id_;
        //     return *this;
        // }
        Test& operator=(const Test& t){
            if (this == &t)
                return *this;
            this->id_ = t.id_;
            delete this->str_;
            this->str_ = new string(*t.str_); // 深拷贝的写法
            return *this;
        }
        ~Test(){
            if (str_ != nullptr)
                delete str_;
        }
        void getId(){
            cout << "id_addr = "<<&this->id_ ;
            cout << "  id = "<<this->id_ << endl;
        };
        void getStr(){
            cout << "str_addr = "<<this->str_;
            cout << "  str = "<<*this->str_ << endl;
        };
    private:
        int id_;
        string * str_;
};
void test_vector(){
    // 外部2次运行test_vector()函数
    vector<int> a; // 存储在栈上,运行结束会被销毁
    static vector<int> b; // 存储在静态存储区,运行结束不会被销毁
    cout<<"&a = "<<&a<<endl; // 地址会改变
    cout<<"&b = "<<&b<<endl; // 地址不变
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
int main()
{
    const char * a = "abc"; // 
    const char* b = "abc";
    cout <<"&a = " << &a << endl; // 0x58901ff8a0 地址不同
    cout <<"&b = " << &b << endl; // 0x58901ff898

    Test t1(1, new string("abc"));
    cout<<"t1:\n";
    t1.getId(); // id_addr = 0x15f7bffcc0  id = 1
    t1.getStr(); // str_addr = 0x1921bf46240  str = abc
    Test t2(2, new string("def"));
    cout<<"t2:\n";
    t2.getId(); // id_addr = 0x15f7bffcb0  id = 2
    t2.getStr(); // str_addr = 0x1921bf465b0  str = def

    cout<<"after t2 = t1:\n";
    t2 = t1;
    cout<<"t2:\n";
    t2.getId(); // id_addr = 0x15f7bffcb0  id = 1
    t2.getStr(); // str_addr = 0x1921bf46240  str = abc
    cout<<"t1:\n";
    t1.getId(); // id_addr = 0x15f7bffcc0  id = 1
    t1.getStr(); // str_addr = 0x1921bf46240  str = abc
    // 这里会发现，operator实际上是浅拷贝,2个string*指向同一个地址

    // 如果使用深拷贝的写法就可以解决这个问题,防止释放内存出错

    // vector<int> a在局部函数中存储在栈中，在函数结束后自动释放
    // 但是如果存储了元素,这个元素是在堆区申请内存的
    test_vector();
    test_vector();
    test_vector();
    /*
        &a = 0xfde3dff710
        &b = 0x7ff7472c9050
        1 2
        3 4

        &a = 0xfde3dff710 // 只是恰好改变了a的地址
        &b = 0x7ff7472c9050 // 地址不变
        1 2
        3 4 3 4

        &a = 0xb44c7ffbf0 // 其实这个地址是可以改变的
        &b = 0x7ff643569050
        1 2
        3 4 3 4 3 4
    */
    return 0;
}