/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 11:45:40
 * @LastEditTime: 2022-05-19 13:40:45
 * @Description: auto_decltype.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\auto_decltype.hpp
 * @Signature: A boy without dreams
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int add_ad(auto x, auto y) { // c++20
    return x+y;
}
template<typename R, typename T, typename U>
R add_rtu(T x, U y) {
    // 程序员在使用这个模板函数的时候，必须明确指出返回类型
    // 但事实上我们并不知道这个函数会做什么样的操作，以及获得一个什么样的返回类型
    return x+y;
}
// template<typename T, typename U> 这样的写法其实不能通过编译
// decltype(x+y) add_tu(T x, U y); 因为在编译器读到decltype(x+y)时,x和y尚未被定义
template<typename T, typename U>
auto add_tu(T x, U y) -> decltype(x+y){
    return x + y;
}
template<typename T, typename U> // c++14以后没有后置类型强调也具备推导能力
auto add_tu_without_decltype(T x, U y){
    return x + y;
}

// c++14之后支持decltype(auto),用于对转发函数或封装的返回类型进行推导
//     使我们无需显式的指定 decltype 的参数表达式
std::string  lookup1(){
    std::cout<<"it's loopkp1 is called"<<std::endl;
     return "lookup1";
};
std::string&  lookup2(){
    std::cout<<"it's lookup2 is called"<<std::endl;
    static string lookup_2 = "lookup2";
    return lookup_2;
}
// 如果是c++11对这2个函数进行转发操作需要这样做:
std::string transmit_lookup1(){
    return lookup1();
}
std::string& transmit_lookup2(){
    return lookup2();
}
// c++14之后只需要这样
decltype(auto) look_up_a_string_1() {
    return transmit_lookup1(); // 甚至多层嵌套都是ok的
}
decltype(auto) look_up_a_string_2() {
    return lookup2();
}
void test_auto_deltype(){
    vector<int> vec = {1,2,3,4,5};
    for (auto it = vec.cbegin(); it != vec.cend(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    auto i = 5;
    auto arr = new auto(10);

    auto j = 6; // 被推导为 int
    std::cout << add_ad(i, j) << std::endl;

    // 计算某个表达式的类型
    auto x = 1;
    auto y = 2;
    decltype(x+y) z; 
    // std::is_same<T, U> 用于判断 T 和 U 这两个类型是否相等
    if (std::is_same<decltype(x), int>::value)
    std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
        std::cout << "type x == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type z == type x" << std::endl;

    unsigned char k = 'k';
    float f = 3.14f;
    // auto d = add_rtu(k, f); // 会报错couldn't deduce template parameter 'R'
    auto d = add_tu(k, f); // 不会报错,d的类型是decltype(k+f)->float,兼容型
    std::cout<<"d = "<<d<<std::endl; // 110.14
    auto d1 = add_tu_without_decltype(k,f); // it's also ok
    std::cout<<"d1 = "<<d1<<std::endl; // 110.14

    // decltype(auto)的用法,用于转发函数
    look_up_a_string_1();
    look_up_a_string_2();
}
