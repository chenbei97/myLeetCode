/*** 
 * @Author: chenbei
 * @Date: 2022-05-24 14:34:04
 * @LastEditTime: 2022-05-24 14:53:31
 * @Description: seed_seq.cpp
 * @FilePath: \myLeetCode\STLTestCode\random\source\seed_seq.cpp
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
        std::seed_seq 消耗整数值数列，并基于消耗的数据生成请求数量的无符号整数值 i
        i处于[0,2^32)之间,它的成员类型为result_type	std::uint_least32_t
        operator=函数被删除不可被赋值,有generate,param和size三个成员函数
        此函数满足种子序列SeedSequence的要求,可见https://www.apiref.com/cpp-zh/cpp/named_req/SeedSequence.html
    */
    // 示例
    std::seed_seq ss{1, 2, 3, 4, 5};
    std::vector<int> v2(10+1);
    std::fill(v2.begin(), v2.end(), 0);
    // 可以使用seed_seq的generate函数
    ss.generate(v2.begin()+1, v2.end());
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // 测试size函数
    cout << "size: " << ss.size() << endl; // 5
    // 测试param函数
    cout << "param: ";
    // 设置目标迭代器
    vector<int>::iterator it = v2.begin(); 
    ss.param(it);// 把param函数的返回值赋值给it,从这个迭代器位置往后覆盖
    cout<<"*it: "<<*it<<endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // 0 -89969659 -48433430 1856049002 1129615051 690460811 1075771511 46783058 -390858218 1534123438 1495905678
    // 1 2 3 4 5 690460811 1075771511 46783058 -390858218 1534123438 1495905678
    return 0;
}
/*
g++ -o ..\output\seed_seq_g++ seed_seq.cpp
..\output\seed_seq_g++.exe
cl /Fo"..\output\seed_seq_cl" /Fe"..\output\seed_seq_cl.exe" /std:c++latest ".\seed_seq.cpp"
..\output\seed_seq_cl.exe
*/