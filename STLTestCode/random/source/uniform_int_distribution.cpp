/*** 
 * @Author: chenbei
 * @Date: 2022-05-24 10:19:09
 * @LastEditTime: 2022-05-24 10:41:10
 * @Description: uniform_int_distribution
 * @FilePath: \myLeetCode\STLTestCode\random\source\uniform_int_distribution.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <functional>
using namespace std;
int main()
{
    /*
        uniform_int_distribution本质上和uniform_real_distribution区别不大都属于随机分布
        前者是离散概率P(i/a,b)=1/(b-a+1),后者是概率密度函数P(i/a,b)=1/(b-a)
        且要求是int类型而不是实数类型,也就是非double,float和long double等类型
        模板参数除了是int还可以是short、long、long long、unsigned short、unsigned int、unsigned long或unsigned long long之一
        符合随机数分布 (RandomNumberDistribution) 的要求
        具备成员函数 min()、max()、operator()、param()、reset()、a()、b()
        构造函数也有3种,默认是[0,numeric_limits<_Ty>::max()],其次参数构造[a,b),最后以param_type构造
        operator()除了(engine),(engine,param_type)还有(engine,c),内部返回的是[0,c-1)进行构造
    */
    // 测试3个构造函数
    uniform_int_distribution<int> uid1;
    uniform_int_distribution<int> uid2(0, 10);
    uniform_int_distribution<int> uid3(uniform_int_distribution<int>::param_type(100, 110));
    // 测试成员函数
    cout<<"uid1.min() = "<<uid1.min()<<" uid1.max() = "<<uid1.max()<<endl;
    cout <<"uid1.a() = "<<uid1.a()<<" uid1.b() = "<<uid1.b()<<endl;
    cout<<"uid1.param().a() = "<<uid1.param().a()<<" uid1.param().b() = "<<uid1.param().b()<<endl;
    auto engine = std::mt19937(std::random_device{}()); // 随机数生成器
    // 测试operator()
    vector<int> vec1(10);
    generate(vec1.begin(), vec1.end(), bind(uid1, engine));
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    cout<<"uid3(engine) = "<<uid3(engine)<<endl; // 107
    cout<<"uid2(engine,param_type) = "<<uid2(engine,uniform_int_distribution<int>::param_type(50,100))<<endl; // 77
    //cout<<"uid1(engine,100) = "<<uid1(engine,3)<<endl; // 只可能出现0,1,2, cl.exe可以成功,g++无此构造函数
    return 0;
}
/*
g++ -o ..\output\uniform_int_distribution_g++ uniform_int_distribution.cpp
..\output\uniform_int_distribution_g++.exe
cl /Fo"..\output\uniform_int_distribution_cl" /Fe"..\output\uniform_int_distribution_cl.exe" /std:c++latest ".\uniform_int_distribution.cpp"
..\output\uniform_int_distribution_cl.exe
*/