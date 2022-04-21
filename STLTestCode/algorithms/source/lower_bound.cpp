/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:59:48
 * @LastEditTime: 2022-04-21 11:01:03
 * @Description: test lower_bound.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\lower_bound.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\lower_bound lower_bound.cpp
..\output\lower_bound.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到指定值的下边界,其实就是指向value的迭代器
    vector<int> src = {0,1,2,3,4,5,6,7,8,9};
    auto it = lower_bound(src.begin(), src.end(), 5);
    cout << *it << endl; // 5

    auto it2 = lower_bound(src.begin(), src.end(), 10);
    if (it2 != src.end())
    {
        cout << *it2 << endl;
    }
    else
    {
        cout << "not found" << endl; // 执行
    }
    return 0;
}