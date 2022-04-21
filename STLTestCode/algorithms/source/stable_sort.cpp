/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 08:41:01
 * @LastEditTime: 2022-04-21 08:45:03
 * @Description: test stable_sort.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\stable_sort.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o stable_sort stable_sort.cpp
.\stable_sort.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 稳定性排序,不会影响相对次序
    vector<char> src = {'g','b','a','E','A','f','e','c'};
    stable_sort(src.begin()+1, src.end()-1);
    ostream_iterator<char> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl; // g A E a b e f c ,
    return 0;
}