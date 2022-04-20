/*** 
 * @Author: chenbei
 * @Date: 2022-04-20 11:00:46
 * @LastEditTime: 2022-04-20 11:32:05
 * @Description: lexicographical_compare_three_way.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\lexicographical_compare_three_way.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o lexicographical_compare lexicographical_compare_three_way.cpp
.\lexicographical_compare_three_way.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <c++/11.2.0/bits/stl_algobase.h>
using namespace std;
int main()
{
    vector<string> v1 = {"abc", "abd", "abe"};
    vector<string> v2 = {"abd", "abd", "abe"};
    // C++20新特性,比较的强弱语义,strong_ordering
    // 返回1,0,-1,表示3种意思
    auto it = std::lexicographical_compare_three_way(begin(v1),end(v1),begin(v2),end(v2));
    if (it < 0) cout<<"{abc,abd,abe} less than {abd,abd,abe}"<<endl;
    else if (it > 0) cout<<"{abd,abd,abe} less than {abc,abd,abe}"<<endl;
    else cout<<"{abc,abd,abe} equal to {abd,abd,abe}"<<endl;
    return 0;
}