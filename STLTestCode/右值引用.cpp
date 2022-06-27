/*
 * @Author: chenbei
 * @Date: 2022-06-27 11:46:53
 * @LastEditTime: 2022-06-27 11:46:53
 * @FilePath: \\myLeetCode\\STLTestCode\\右值引用.cpp
 * @Description: 右值引用的测试问题
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
using namespace std;
void left_ref(int& val) {printf("左值非常量引用\n");}
void left_const_ref(const int& val) {printf("左值常量引用\n");}
void right_ref(int&& val) {printf("右值非常量引用\n");}
void right_const_ref(const int&& val) {printf("右值常量引用\n");}
class A {};
void left_ref_A(A& a) {};
void left_const_ref_A(const A& a) {};
void right_ref_A(A&& a) {};
void right_const_ref_A(const A&& a) {};
// 1. 测试非常量左值
void test_non_const_left_variable() {
    // 1. 普通数据类型
    int val = 10; // 【非常量左值】
    left_ref(val); // 可以传递给【非常量左引用】
    left_const_ref(val); // 可以传递给【常量左引用】
    // right_ref(val); // 不能传递给【非常量右引用】
    // right_const_ref(val); // 不能传递给【常量右引用】

    int& ref = val; // 【非常量左值的非常量左引用】
    left_ref(ref); // 可以传递给【非常量左引用】
    left_const_ref(ref); // 可以传递给【常量左引用】
    // right_ref(ref); // 不能传递给【非常量右引用】
    // right_const_ref(ref); // 不能传递给【常量右引用】

    const int& const_ref = val; // 【非常量左值的常量左引用】
    // left_ref(const_ref); // 不能传递给【非常量左引用】
    left_const_ref(const_ref); // 可以传递给【常量左引用】
    // right_ref(const_ref); // 不能传递给【非常量右引用】
    // right_const_ref(const_ref); // 不能传递给【常量右引用】

    // int&& rref = val; 不能对非常量左值进行【非常量右引用】
    // const int&& const_rref = val; 不能对非常量左值进行【常量右引用】

    // 2.自定义数据类型,规律和普通数据类型完全一致
    A a;
    left_ref_A(a);
    left_const_ref_A(a);
    // right_ref_A(a);
    // right_const_ref_A(a);

    A& ref_a = a;
    left_ref_A(ref_a);
    left_const_ref_A(ref_a);
    // right_ref_A(ref_a);
    // right_const_ref_A(ref_a);

    const int& const_ref_a = val; 
    // left_ref(const_ref_a);
    left_const_ref(const_ref_a); 
     // right_ref(const_ref_a); 
     // right_const_ref(const_ref_a);

    // A&& rref_a = a;
    // const A&& const_rred_a = a;
}
// 2. 测试常量左值
void test_const_left_variable() {
    // 1. 基本类型INT
    const int val = 10; // 【常量左值】
    // left_ref(val); // 不能传递给【非常量左引用】
    left_const_ref(val); // 可以传递给【常量左引用】
    // right_ref(val); // 不能传递给【非常量右引用】
    // right_const_ref(val); // 不能传递给【常量右引用】

    // int& ref = val; // 不能对常量左值进行【非常量左引用】

    const int& const_ref = val; // 【常量左值的常量左引用】
    // left_ref(a_const_ref); // 不能传递给【非常量左引用】
    left_const_ref(const_ref); // 可以传递给【常量左引用】
    // right_ref(const_ref); // 不能传递给【非常量右引用】
    // right_const_ref(const_ref); // 不能传递给【常量右引用】

    // int&& rref = val; 不能对常量左值进行【非常量右引用】
     // const int&& const_rref = val; 不能对常量左值进行【常量右引用】

    // 2.自定义数据类型A,规律一致
    const A a; // 【常量左值】
    // left_ref_A(a); 
    left_const_ref_A(a); 
    // right_ref_A(a); 
    // right_const_ref_A(a); 

     // A& ref_a = a; 

    const A& const_ref_a = a; 
    // left_ref_A(const_ref_a); 
    left_const_ref_A(const_ref_a);
    // right_ref_A(const_ref_a); 
    // right_const_ref_A(const_ref_a); 

     //A&& rref_a = a; 
     //const A&& const_rref_a = a; 
}
// 3. 测试非常量右值,这里测试了普通类型和自定义类型
int func1() { return 5; } 
const int func2() { return 5; }
void test_non_const_right_variable_INT() {
    // 普通类型无论是10还是func1()还是func2(),都是非常量右值,没有地址
    // left_ref(10); // 不能传递给【非常量左引用】
    // left_ref(func1());left_ref(func2());
    left_const_ref(10); // 可以传递给【常量左引用】
    left_const_ref(func1());left_const_ref(func2());
    right_ref(10); // 可以传递给【非常量右引用】
    right_ref(func1()); right_ref(func2());
    right_const_ref(10); // 可以传递给【常量右引用】
    right_const_ref(func1()); right_const_ref(func2());

    int&& ref = 10; // 【非常量右值的非常量右引用】
    int&& ref1 = func1(); int&& ref2 = func2();
    left_ref(ref); // 可以传递给【非常量左引用】
    left_ref(ref1); left_ref(ref2);
    left_const_ref(ref); // 可以传递给【常量左引用】
    left_const_ref(ref1); left_const_ref(ref2);
    // right_ref(ref);  不能传递给【非常量右引用】
    // right_ref(ref1);right_ref(ref2);
    // right_const_ref(ref); 不能传递给【常量右引用】
    // right_const_ref(ref1);right_const_ref(ref2);

    const int&& const_ref = 10; // 【非常量右值的常量右引用】
    const int&& const_ref1 = func1(); const int&& const_ref2 = func2();
    // left_ref(a_const_ref); // 不能传递给【非常量左引用】
    // left_ref(a_const_ref1);left_ref(a_const_ref2);
    left_const_ref(const_ref); // 可以传递给【常量左引用】
    left_const_ref(const_ref1); left_const_ref(const_ref2);
    // right_ref(const_ref); // 不能传递给【非常量右引用】
    // right_ref(const_ref1); right_ref(const_ref2); 
    // right_const_ref(const_ref); // 不能传递给【常量右引用】
   //  right_const_ref(const_ref1);right_const_ref(const_ref2);
}
A func3() { A a; return a; }; // 非常量右值
void test_non_const_right_variable_A() {
    //  自定义类型非常量右值,规律一致
    // A a = func3(); // 变成了左值,所以不要把a传进去,直接传func3()
    // left_ref_A(func3()); 
    left_const_ref_A(func3());
    right_ref_A(func3());
    right_const_ref_A(func3());

    A&& ref = func3();
    left_ref_A(ref); 
    left_const_ref_A(ref);
    // right_ref_A(ref);
    // right_const_ref_A(ref);

    const A&& const_ref = func3();
   // left_ref_A(const_ref;
   left_const_ref_A(const_ref);
   // right_ref_A(const_ref);
   // right_const_ref_A(const_ref);
}
// 4. 常量右值只能在自定义类型里边可以涉及
const A func4() { A a; return a; }; // 常量右值
void test_const_right_variable_A() {
    // 自定义类型常量右值
    // left_ref_A(func4());  不能传递给【非常量左引用】
    left_const_ref_A(func4()); //  可以传递给【常量左引用】
    // right_ref_A(func4()); 不能传递给【非常量右引用】
    right_const_ref_A(func4()); //  可以传递给【常量右引用】

    // A&& ref = func4(); // 不能用【非常量右引用】接收【常量右引用】

    const A&& const_ref = func4(); // 可以用【常量右引用】接收【常量右引用】
    // left_ref_A(const_ref);不能传递给【非常量左引用】
    left_const_ref_A(const_ref); // 可以传递给【常量左引用】
    // right_ref_A(const_ref); 不能传递给【非常量右引用】
    // right_const_ref_A(const_ref); 不能传递给【常量右引用】
}
int main()
{
    // 1. 非常量左值测试4个函数
    test_non_const_left_variable;
    // 2.常量左值测试4个函数
    test_const_left_variable;
    // 3. 非常量右值测试4个函数
    test_non_const_right_variable_INT();
    test_non_const_right_variable_A();
    // 4. 常量右值测试4个函数
    test_const_right_variable_A();
    return 0;
}