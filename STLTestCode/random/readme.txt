cd STLTestCode\\random\\source
这个文件夹提到的函数不一定只是头文件<random>的
凡是与随机数相关的都会被搜罗进去，包括随机种子、随机打乱、随机分布以及随机引擎等
/*
g++ -o ..\output\m m.cpp
..\output\m.exe
cl /Fo"..\output\m" /Fe"..\output\m.exe" /std:c++latest ".\m.cpp"
..\output\m.exe
*/
#include <iostream>
#include <vector>
#include <random>
#include <iterator>
using namespace std;
int main()
{
    /*

    */
    return 0;
}

随机数引擎和引擎适配器在c++11下有6种：
1.linear_congruential_engine 是基于线性同余生成器 (LCG) 的随机数引擎
    template<class UIntType,UIntType a,UIntType c,UIntType m>，基于LCG算法xi+1 ← (axi+c) mod m
    default_random_engine,本质上是std::minstd_rand0的别名,可以传入随机种子,来源于std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>
    它还有1个标准是1993年发现的,即minstd_rand=linear_congruential_engine<std::uint_fast32_t, 48271, 0, 2147483647>
2.mersenne_twister_engine是基于梅森缠绕器算法的随机数生成器,产生高质量 UIntType 类型的区间 [0, 2^w-1] 上的无符号整数随机数
    template<class UIntType,size_t w, size_t n, size_t m, size_t r,UIntType a, size_t u, UIntType d, size_t s,UIntType b, size_t t,UIntType c, size_t l, UIntType f>
    它也有2个常用的随即引擎,即mt19937和mt19937_64,这2个引擎的传入参数是随机种子
3.subtract_with_carry_engine 是使用带进位减法算法的随机数引擎，类似的2个引擎为ranlux24_base和ranlux48_base
    template<class UIntType,size_t w, size_t s, size_t r>
4.independent_bits_engine 是随机数引擎适配器，它产生位数与被包装引擎所产生者不同的随机数
    template<class Engine,std::size_t W,class UIntType>
    W指定生成数字应有的位数,大于0且不大于std::numeric_limits<UIntType>::digits;
    UIntTyp生成的随机数类型,类型必须是无符号整数类型
5.discard_block_engine是伪随机数生成器适配器，它忽略基础引擎所产生的一定量数据
    template<class Engine,size_t P, size_t R>
    生成器只从基础引擎生成的每个 P 大小的块保留 R 个数，舍弃剩余的数
    P是块大小。必须大于 0；R是每块用的数字数，必须大于 0 且不大于 P 
6.shuffle_order_engine是随机数引擎适配器,它打乱基础引擎生成的随机数
    template<class Engine,std::size_t K>，k为内部表大小，必须大于 0
    它维护一个大小为 K 的表，并在请求时随机地从该表派送被选择数，将它替换为基础引擎生成的数
    内部定义了一个常用引擎knuth_b，即std::shuffle_order_engine<std::minstd_rand0, 256>
模板参数Engine包装的引擎类型,必须满足随机数引擎 (RandomNumberEngine) 的要求

RandomNumberEngine(参数集,c++11)：
    随机数引擎是函数对象，返回无符号整数值，它使得可能结果范围中的每个值拥有（理想的）相等概率
    任何随机数引擎亦为均匀随机位生成器 (UniformRandomBitGenerator) ，从而可能插入任何随机数分布，以获得随机数
    以上的6种随机数生成器都是继承自RandomNumberEngine的派生类，均满足随机数引擎 RandomNumberEngine
    具体可见文档说明https://www.apiref.com/cpp-zh/cpp/named_req/RandomNumberEngine.html

UniformRandomBitGenerator(参数集,c++20)：
    均匀随机位生成器是返回无符号整数值的函数对象，可能结果范围中的每个值都（理想情况）拥有等概率
    均匀随机未生成器不是有意用做随机数生成器的：它们被用作随机位的源（为效率大量生成）
    任何均匀随机位生成器均可被插入任何随机数分布，以获得随机数（正式而言是随机变量）
    所有随机数引擎 (RandomNumberEngine) 均满足此概念,所以UniformRandomBitGenerator是兼容RandomNumberEngine的
    期望UniformRandomBitGenerator作为参数传入的主要有5个函数
        1.random_shuffle和shuffle函数,重排序给定范围 [first, last) 中的元素，使得这些元素的每个排列拥有相等的出现概率
            其中random_shuffle函数在C++14中被弃用,c++17中被替换为shuffle
            void shuffle( RandomIt first, RandomIt last, URBG&& g );
            void random_shuffle( RandomIt first, RandomIt last, RandomFunc&& r );
        2.generate_canonical生成范围 [0, 1) 中的随机浮点值，RealType generate_canonical( Generator& g )
        3.uniform_int_distribution，生成随机整数值 i ，均匀分布于闭区间 [a, b],按照离散概率P(i/a,b)=1/(b-a+1)
        4.uniform_real_distribution,产生均匀分布在区间 [a, b) 上的随机浮点值 i ，分布按照概率密度函数P(i/a,b)=1/(b-a)
        特别说明的是2、3、4均属于均匀分布
    与之相关的C++20定义的函数为uniform_random_bit_generator，可见https://www.apiref.com/cpp-zh/cpp/numeric/random/uniform_random_bit_generator.html

random_device：
    满足均匀随机位生成器 (UniformRandomBitGenerator) 但不满足随机数引擎 (随机数引擎 (RandomNumberEngine) )
    std::random_device 是生成非确定随机数的均匀分布[整数]随机数生成器，[属于非确定性生成器]

seed seq(C++11)：种子序列

随机数的几种分布：
1、均匀分布
uniform_int_distribution(C++11)
uniform_real_distribution(C++11)
generate_canonical(C++11)
2、伯努利分布
bernoulli_distribution(C++11)
binomial_distribution(C++11)
negative_binomial_distribution(C++11)
geometric_distribution(C++11)
3、泊松分布
poisson_distribution(C++11)
exponential_distribution(C++11)
gamma_distribution(C++11)
weibull_distribution(C++11)
extreme_value_distribution(C++11)
4、正态分布
normal_distribution(C++11)
lognormal_distribution(C++11)
chi_squared_distribution(C++11)
cauchy_distribution(C++11)
fisher_f_distribution(C++11)
student_t_distribution(C++11)
5、采样分布
discrete_distribution(C++11)
piecewise_constant_distribution(C++11)
piecewise_linear_distribution(C++11)




