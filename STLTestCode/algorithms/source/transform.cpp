/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:05:20
 * @LastEditTime: 2022-04-24 14:59:44
 * @Description: test transform.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\transform.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\transform transform.cpp
..\output\transform.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst;
    // 返回元素的平方
    transform(src.begin(), src.end(), back_inserter(dst), [](int x){return x*x;});
    for (auto i : dst)
    {
        cout << i << " "; // 1,4,9,16,25,36,49,64,81,100
    }
    cout << endl;

    // 也可以返回/2
    dst.clear();
    transform(src.begin(), src.end(), back_inserter(dst), [](int i){return i/2;});
    for (auto i : dst)
    {
        cout << i << " "; // 1,3,6,10,15,21,28,36,45,55
    }
    cout << endl;

    // 允许双参数,与第二者交互
    vector<int> src2 = {10,9,8,7,6,5,4,3,2,1};
    dst.clear();
    transform(src.begin(), src.end(), src2.begin(), back_inserter(dst), [](int x, int y){return x+y;});
    for (auto i : dst)
    {
        cout << i << " "; // 11,11,11,11,11,11,11,11,11,11
    }
    cout << endl;
    return 0;
}
