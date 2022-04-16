/*
 * @Author: chenbei
 * @Date: 2022-04-16 12:30:18
 * @LastEditTime: 2022-04-16 12:50:38
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\mismatch.cpp
 * @Description: test mismatch.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // mismatch返回匹配的范围
    auto seq1 = { 0, 1, 2 }; // 列表初始化
    auto seq2 = { 0, 1, 2, 3, 4 };
    pair<const int*,const int*> p = mismatch ( seq1.begin (), seq1.end (), seq2.begin ());
    cout<<"first: "<<*p.first<<endl; // 0
    cout<<"second: "<<*p.second<<endl; // 3

    auto p1 = mismatch ( seq2.begin (), seq2.end (), seq1.begin ()); //反过来会导致不确定的行为
    cout << "first: " << *p1.first << endl; // 3
    cout << "second: " << *p1.second << endl; // 0

    auto p2 = mismatch ( seq1.begin (), seq1.end (), seq2.begin (), seq2.end ());
    cout << "first: " << *p2.first << endl; // 0
    cout << "second: " << *p2.second << endl; // 3 和p的结果一样,可以使用4个参数

    auto v1 = {3,7,13,12};
    auto v2 = {8,3,-3,0};
    auto v3 = {8,3,-4,7,-5,2};
    auto v4 = {8,7,-4,2,13,12};
    // 判断相加大于10是否满足,存在不满足的给出范围
    auto p3 = mismatch ( v1.begin (), v1.end (), v2.begin (), v2.end (), [](int a, int b){return a+b>=10;});
    auto p4 = mismatch ( v3.begin (), v3.end (), v4.begin (), v4.end (), [](int a, int b){return a+b>=10;});
    // v1,v2都满足相加>=10,所以没有这样的范围,指向8
    cout << "first: " << *p3.first << endl; // 8
    cout << "second: " << *p3.second << endl; // 8
    // v3,v4的[-4,7]和[-4,2]不满足,指向-4
    cout << "first: " << *p4.first << endl; // -4
    cout << "second: " << *p4.second << endl; // -4
    auto v5 = {11,12,13,14,15};
    auto v6 = {19,18,17,16,15};
    // 所有都不满足,v5指向11,v6指向19
    auto p5 = mismatch ( v5.begin (), v5.end (), v6.begin (), v6.end (), [](int a, int b){return a+b<30;});
    cout<<"first: "<<*p5.first<<endl; // 11
    cout<<"second: "<<*p5.second<<endl; // 19
    return 0;
}