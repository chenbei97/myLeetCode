/*
 * @Author: chenbei
 * @Date: 2022-04-16 12:20:17
 * @LastEditTime: 2022-04-16 12:29:04
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\equal_range.cpp
 * @Description: test equal_range.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 返回指定的值范围迭代器,如果下边例子数字0后边再出现2个3,则second结果是不对的
    // 一般在set容器搜寻
    vector<int> src = {1,2,3,3,3,3,5,4,0};
    typedef vector<int> :: iterator vIter;
    pair<vIter,vIter> p = equal_range(src.begin(),src.end(),3);
    cout<<"first: "<<*p.first<<endl; // 3
    cout<<"second: "<<*p.second<<endl; // 5

    set<char> s = {'a','b','c','d','e','f','g','h','i','j'};
    pair<set<char>::iterator,set<char>::iterator> p1 = equal_range(s.begin(),s.end(),'f');
    cout<<"first: "<<*p1.first<<endl; // 'f'
    cout<<"second: "<<*p1.second<<endl;// 'g'

    auto ret = s.equal_range('i');
    cout<<"first: "<<*ret.first<<endl; // 'i'
    cout<<"second: "<<*ret.second<<endl; // 'j'
    return 0;
}