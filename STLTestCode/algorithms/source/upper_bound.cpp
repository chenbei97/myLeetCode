/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:56:03
 * @LastEditTime: 2022-04-21 10:58:22
 * @Description: test upper_bound.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\upper_bound.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\upper_bound upper_bound.cpp
..\output\upper_bound.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 必须是有序序列,然后找到指定数的上边界,就是value的下一个迭代器
    vector<int> src = {0,1,2,3,4,5,6,7,8,9};
    int value = 5;
    auto it = upper_bound(src.begin(), src.end(), value);
    if (it != src.end())
    {
        cout << *it << endl; // 6
    }
    else
    {
        cout << "not found" << endl;
    }

    int val  = 10;
    it = upper_bound(src.begin(), src.end(), val);
    if (it != src.end())
    {
        cout << *it << endl; 
    }
    else
    {
        cout << "not found" << endl; // 执行
    }
    return 0;
}