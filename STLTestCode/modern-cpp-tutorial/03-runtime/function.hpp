/*** 
 * @Author: chenbei
 * @Date: 2022-05-20 16:32:28
 * @LastEditTime: 2022-05-20 16:59:54
 * @Description: function.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\03-runtime\function.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include<functional> // std::function
#include <memory>  // std::make_unique
#include <utility> // std::move
using namespace std;
// 1. Lambda 表达式的本质是一个和函数对象类型相似的闭包对象
// Lambda 表达式的捕获列表为空时，闭包对象还能够转换为函数指针值进行传递
using foo = void(int); // 定义函数类型, using 的使用类似于typedef,是一种增强
void with_foo(foo f) { // 定义在参数列表中的函数类型 foo 被视为退化后的函数指针类型 foo*
    f(1); // 通过函数指针调用函数
}
void test_foo(){
    auto f = [](int value) {
        std::cout << "value = "<<value << std::endl;
    };
    f(1); // 直接调用 =1
    with_foo(f); // 传递闭包对象,f隐式转换为foo*类型的函数指针值,functional(f)调用函数指针f也得到1
}
// 2. 代码给出了两种不同的调用形式,一种是将Lambda 作为函数类型传递进行调用
// 另一种则是直接调用 Lambda 表达式,在 C++11 中,统一了这些概念
// 将能够被调用的对象的类型统一称之为可调用类型,这种类型通过std::function引入
// std::function是一种通用、多态的函数封装,它的实例可以对任何可以调用的目标实体进行存储、复制和调用操作
// 也是对 C++中现有的可调用实体的一种类型安全的包裹（相对来说，函数指针的调用不是类型安全的）
// 换句话说，就是函数的容器,能够更加方便的将函数、函数指针作为对象进行处理
int get_para(int para) {
    return para;
}
void test_get_para(){
    // std::function 包装了一个返回值为 int, 参数为 int 的函数
    std::function<int(int)> func1 = get_para; // 使用func1比使用get_para更加安全
    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
        return 1+value+important; // lambda表达式也可以被封装,func2比lambda更加安全
    };
    important = 20;
    std::cout << "func1(10) = "<<func1(10) << std::endl; // return 10
    std::cout << "func2(10) = "<<func2(10) << std::endl; // return 1+20+10 = 31
}


// 3. 使用std::bind来事先绑定函数的某些参数,另外的参数是不知道的
// 那么就可以使用std::placeholder来事先占位,这样完成参数绑定以后只需要提供不知道的参数即可
// 例如一个人已知姓名,性别但是年龄不知道,可以使用std::placeholder来占位
void print_age_sex_name(int age, bool boy, const char* name) {
    printf("age = %d boy? %d name = %s",age,boy,name);
}
void test_bind_placeholder(){
    // 将参数boy,name绑定到函数上，但是使用 std::placeholders::_1 来对第一个参数进行占位
    // 使用auto可以规避不太熟悉一个函数的返回值类型这一问题
    auto bindFoo = std::bind(print_age_sex_name, std::placeholders::_1, true,"chenbei");
    // 这时调用 bindFoo 时,只需要提供第一个参数即可
    // 就像void print_age_sex_name(int age, bool boy = true, const char* name = "chenbei");版本一样
    bindFoo(25);
}
void test_function(){
    test_foo();
    test_get_para();
    test_bind_placeholder();
}