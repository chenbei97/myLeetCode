/*** 
 * @Author: chenbei
 * @Date: 2022-05-21 09:33:15
 * @LastEditTime: 2022-05-21 09:48:32
 * @Description: tuple_variant.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\04-containers\tuple_variant.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <variant>
#include <string>
#include <tuple>
#include <utility>
using namespace std;
template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i);
template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tpl, size_t i);
template <typename T0, typename ... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v);
// 获取元组长度
template <typename T>
auto tuple_len(T &tpl) {
    return std::tuple_size<T>::value;
}

auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>
    if (id == 0)
        return std::make_tuple(3.8, 'A', "zhangsan");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "lisi");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "wangwu");
    return std::make_tuple(0.0, 'D', "null");
    // 如果只写 0 会出现推断错误, 编译失败
}

void test_tuple(){
    auto student = get_student(0);
    std::cout << "ID: 0, "
    << "GPA: " << std::get<0>(student) << ", "
    << "Grade: " << std::get<1>(student) << ", "
    << "Name: " << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;

    // 元组进行拆包
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
    << "GPA: " << gpa << ", "
    << "Grade: " << grade << ", "
    << "Name: " << name << '\n';

    std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
    std::cout << std::get<std::string>(t) << std::endl; // 获取string类型的元素 123
    std::cout << std::get<3>(t) << std::endl; // 获取第四个元素 8
    // std::cout << std::get<double>(t) << std::endl; // 非法, 引发编译期错误

    // std::get<> 依赖一个编译期的常量，所以下面的方式是不合法的
    // int index = 1;
    // std::get<index>(t);
    // 可以通过variant解决这个问题
    int i = 1;
    std::cout << tuple_index(t, i) << std::endl; // 4.5

    // 元组合并与遍历,std::tuple_cat()
    auto new_tuple = std::tuple_cat(get_student(1), std::move(t));
    // 迭代
    for(int i = 0; i != tuple_len(new_tuple); ++i)
        std::cout << tuple_index(new_tuple, i) << " ";// 运行期索引 2.9 C lisi 123 4.5 6.7 8
    std::cout << std::endl;
}

void test_tuple_variant(){
    test_tuple();
}


template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i) {
    if constexpr (n >= sizeof...(T))
        throw std::out_of_range("越界.");
    if (i == n)
        return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl) };
    return _tuple_index<(n < sizeof...(T)-1 ? n+1 : 0)>(tpl, i);
}
template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tpl, size_t i) {
    return _tuple_index<0>(tpl, i);
}
template <typename T0, typename ... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v) { 
    std::visit([&](auto && x){ s << x;}, v); 
    return s;
}

