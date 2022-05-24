/*** 
 * @Author: chenbei
 * @Date: 2022-05-24 10:41:40
 * @LastEditTime: 2022-05-24 11:07:04
 * @Description: generate_canonical.cpp
 * @FilePath: \myLeetCode\STLTestCode\random\source\generate_canonical.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <iterator>
using namespace std;
int main()
{
    /*
        属于均匀分布。
        template< class RealType, size_t bits, class Generator >
        RealType generate_canonical( Generator& g );
        生成范围 [0, 1) 中的随机浮点值,注意不能是int类型
        为生成足够的熵， generate_canonical() 将准确调用 g() k 次，其中 k = \text{Max}(1, ⌈ b / log2 R ⌉) 且
        b = std::min<std::size_t>(bits, std::numeric_limits<RealType>::digits)
        R = g.max() - g.min() + 1
        这个更多的作为函数对象使用,没有其它成员函数或者构造函数
    */
    // 示例,产生有10位随机性的随机数：这仅可能产生 k*R 个相异值
    std::random_device rd;
    std::mt19937 gen(rd());
    for(int n = 0; n < 10; ++n) {
        std::cout << std::generate_canonical<double, 10>(gen) << ' ';
    }
    std::cout << '\n';
	auto p1 = generate_canonical<double,10,mt19937> (gen); // 带上模板参数gen也可以
    cout << p1 << endl;
    
    // 但是不允许生成器是纯右值
	// std::mt19937 gen2(random_device()); // random_device没有实例化,一个纯右值
	// auto p2 = generate_canonical<double,10, mt19937> (gen2);

    return 0;
}
/*
g++ -o ..\output\generate_canonical_g++ generate_canonical.cpp
..\output\generate_canonical_g++.exe
cl /Fo"..\output\generate_canonical_cl" /Fe"..\output\generate_canonical_cl.exe" /std:c++latest ".\generate_canonical.cpp"
..\output\generate_canonical_cl.exe
*/