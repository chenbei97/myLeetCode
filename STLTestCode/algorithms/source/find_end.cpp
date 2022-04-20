/*** 
 * @Author: chenbei
 * @Date: 2022-04-20 08:00:42
 * @LastEditTime: 2022-04-20 08:05:36
 * @Description: test find_end.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\find_end.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o find_end find_end.cpp
.\find_end.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 和search的区别是search会从前往后找到第1个重复的
    vector<int> src = {1,2,3,4,5,6,3,4,5,7,8,9};
    vector<int> which = {3,4,5};
    auto it = find_end(src.begin(),src.end(),which.begin(),which.end());
    if (it == src.end())
        cout << "not found" << endl; // 6,第2个(3,4,5)3的位置
    else
        cout << *(it-1) << endl;
    auto it1 = search(src.begin(),src.end(),which.begin(),which.end());
    if (it1 == src.end())
        cout << "not found" << endl;
    else
        cout << *(it1-1) << endl; // 2,第1个(3,4,5)3的位置
    return 0;
}