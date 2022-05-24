/*** 
 * @Author: chenbei
 * @Date: 2022-05-24 08:09:28
 * @LastEditTime: 2022-05-24 10:09:01
 * @Description: uniform_real_distribution.cpp
 * @FilePath: \myLeetCode\STLTestCode\random\source\uniform_real_distribution.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <functional> // bind
using namespace std;
int main()
{
    /*
        属于均匀分布。
        uniform_real_distribution<T>,T只允许double,float和long double,默认是double
        一、存在3个构造函数：
        uniform_real() : _Par(_Ty{0}, _Ty{1}) {}
        explicit uniform_real(_Ty _Min0, _Ty _Max0 = _Ty{1}) : _Par(_Min0, _Max0) {}
        explicit uniform_real(const param_type& _Par0) : _Par(_Par0) {}
        从源码可以看出支持默认、参数a,b以及使用param_type类型的构造函数
        1.uniform_real_distribution();
        2.uniform_real_distribution(T a, T b)
        参数a和b是两个参数，表示生成的随机数的范围，a<b,默认是0<1
        3.uniform_real_distribution(const param_type& param)
        二、存在几个成员函数：
        1.param_type param() const
        返回一个param_type类型的参数，包含a和b,可以使用a()和b()获取a和b
        2.result_type b() const返回b；result_type a() const返回a
        3.result_type min() const，返回一个result_type类型的参数，表示生成的随机数的最小值
            result_type max() const，返回一个result_type类型的参数，表示生成的随机数的最大值
        4.result_type operator() const;
            result_type operator()(_Engine& _Eng) const;
            result_type operator()(_Engine& _Eng, const param_type& _Par0) const;
            有2个重载版本,可以传入一个_Engine类型的参数，也可以传入一个param_type类型的参数
        5.void reset(),重置到默认值
    */
    // 测试构造函数
    uniform_real_distribution<double> u0; // 默认构造(0,1)
    uniform_real_distribution<double> u1(1.0, 2.0);
    uniform_real_distribution<double> u2(uniform_real_distribution<double>::param_type(2.0, 10.0));
    // 测试成员函数
    cout << "u1.param().a() = " << u1.param().a() << endl; // u1.param().a() = 1
    cout << "u2.b() = " << u2.b() << endl; // u2.b() = 10
    cout << "u1.min() = " << u1.min() << endl; // u1.min() = 1
    cout << "u2.max() = " << u2.max() << endl; // u2.max() = 10
    // 线性同余生成器常用参数引擎的别名,传入随机种子
    auto engine0 = default_random_engine{20}; // typedef std::minstd_rand0 std::default_random_engine
    cout << "u0(engine) = " << u0(engine0) << endl; // u0(engine) = 0.630756
    cout << "u0(engine,param_type) = " << u0(engine0, // u0(engine,param_type) = 101.73
        uniform_real_distribution<double>::param_type(100.0,110.0)) << endl; // 第2个版本可以指定param_type类型的参数
    // 使用reset()重置到默认值
    u0.reset();
    cout<<"u0.max() = "<<u0.max()<<endl; // u0.max() = 1

    // 除了使用线性同余生成器minstd_rand0,也可以使用minstd_rand
    auto engine1 = minstd_rand{10};
    // 还可以使用mersenne_twister_engine的2个引擎
    auto engine2 = mt19937{12};
    auto engine3 = mt19937_64{13};
    // subtract_with_carry_engine的2个引擎
    auto engine4 = ranlux24_base{14};
    auto engine5 = ranlux48_base{15};
    // shuffle_order_engine的1个引擎,种子除了可以直接指定数字以外也可以使用random_device
    random_device rd;
    auto engine6 = knuth_b{rd()};
    
    // 测试一下engine6
    uniform_real_distribution<double> u3(10.0,25.0);
    vector<double> v(10);
    generate(begin(v), end(v), bind(u3, engine6));
    copy(begin(v), end(v), ostream_iterator<double>(cout, " "));
    cout<<endl; // 14.0896 16.9349 21.7032 12.7862 15.9966 22.8588 14.6084 16.1722 14.7972 10.1518
    // 当然直接遍历每个元素也可以
    for(auto &i : v) i = u3(engine6);
    copy(begin(v), end(v), ostream_iterator<double>(cout, " "));
    cout<<endl; // 结果是一样的

    return 0;
}
/*
g++ -o ..\output\uniform_real_distribution_g++ uniform_real_distribution.cpp
..\output\uniform_real_distribution_g++.exe
cl /Fo"..\output\uniform_real_distribution_cl" /Fe"..\output\uniform_real_distribution_cl.exe" /std:c++latest ".\uniform_real_distribution.cpp"
..\output\uniform_real_distribution_cl.exe
*/