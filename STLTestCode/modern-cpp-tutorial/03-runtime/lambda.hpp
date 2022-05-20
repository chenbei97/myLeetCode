/*** 
 * @Author: chenbei
 * @Date: 2022-05-20 16:11:10
 * @LastEditTime: 2022-05-20 16:33:44
 * @Description: lambda.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\03-runtime\lambda.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <memory>  // std::make_unique
#include <utility> // std::move
using namespace std;
void lambda_value_capture() { // 按值捕获
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 1, 而 value == 100.
    // 因为 copy_value 在创建时就保存了一份 value 的拷贝
    // 即使外部变量后来发生了变化, copy_value 也不会变
}
void lambda_reference_capture() { // 按引用捕获
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 100, value == 100.
    // 因为 copy_value 保存的是引用
}
// 手动书写捕获列表有时候是非常复杂的,这种机械性的工作可以交给编译器来处理
// 这时候可以在捕获列表中写一个& 或 = 向编译器声明采用引用捕获或者值捕获
// 总结一下,捕获列表的最常用的四种形式可以是
// [] 空捕获列表
// [name1, name2, ...] 捕获一系列变量
// [&] 引用捕获, 让编译器自行推导引用列表
// [=] 值捕获, 让编译器自行推导值捕获列表

// 上面提到的值捕获、引用捕获都是已经在外层作用域声明的变量
// 因此这些捕获方式捕获的均为左值，而不能捕获右值
// c++14允许捕获的成员用任意的表达式进行初始化,这就允许了右值的捕获
void lambda_expression_capture() { // 捕获表达式
    auto important = std::make_unique<int>(1); // important是一个独占指针不能够被"=" 值捕获,可用move转移为右值
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x+y+v1+(*v2); // v1=1就是右值,临时创建的变量;v2捕获的是move变量,为右值
    };
    std::cout << add(3,4) << std::endl; // = 3+4+1+1 = 9
}

// 泛型 Lambda
// auto 关键字不能够用在lambda参数表里,这是因为这样的写法会与模板的功能产生冲突
// 从 C++14 开始,Lambda 函数的形式参数可以使用 auto 关键字来产生意义上的泛型
auto add_lambda_by_auto = [](auto x, auto y) {
    return x+y;
};
void test_lambda(){
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_capture();
    cout <<"add_lambda_by_auto(3,4) = " << add_lambda_by_auto(3,4) << endl; // 7
    cout <<"add_lambda_by_auto(3.2f,4.0) = " << add_lambda_by_auto(3.2f,4.0) << endl; // 7.3
    cout <<"add_lambda_by_auto(3,'h') = " << add_lambda_by_auto(3,'h') << endl; // 107
}