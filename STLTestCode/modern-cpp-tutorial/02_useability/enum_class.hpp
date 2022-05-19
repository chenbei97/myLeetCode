/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 14:55:03
 * @LastEditTime: 2022-05-19 15:06:11
 * @Description: enum_class.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\enum_class.hpp
 * @Signature: A boy without dreams
 */
// 传统 C++中，枚举类型并非类型安全，枚举类型会被视作整数
// 则会让两种完全不同的枚举类型可以进行直接的比较
// 同时甚至同一个命名空间中的不同枚举类型的枚举值名字不能相同，这通常不是我们希望看到的结果
// C++11 引入了枚举类（enumeration class）
// 这样定义的枚举实现了类型安全，首先他不能够被隐式的转换为整数
// 同时也不能够将其与整数数字进行比较,更不可能对不同的枚举类型的枚举值进行比较
// 但相同枚举值之间如果指定的值相同，那么可以进行比较
#include <iostream>
using namespace std;
enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};
// 希望获得枚举值的值时，将必须显式的进行类型转换
// 不过我们可以通过重载 << 这个算符来进行输出，可以收藏下面这个代码段
// 这时代码std::cout << new_enum::value3 << std::endl将能够被编译
template<typename T>
std::ostream& operator<<(
    typename std::enable_if<std::is_enum<T>::value, // 如果是枚举值
        std::ostream>::type& stream, const T& e) // 则输出枚举值
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}
void test_enum_class(){
    if (new_enum::value3 == new_enum::value4) // 枚举类型后面使用了冒号及类型关键字来指定枚举中枚举值的类型
    // 这使得我们能够为枚举赋值(未指定时将默认使用 int )
        std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    std::cout << new_enum::value1 << std::endl; // 0
};