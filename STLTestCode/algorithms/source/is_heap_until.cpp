/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 08:43:42
 * @LastEditTime: 2022-04-22 08:45:08
 * @Description: test is_heap_until.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\is_heap_until.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\is_heap_until is_heap_until.cpp
..\output\is_heap_until.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 判断到某个元素位置是否为堆,存在就返回堆末尾,否则返回end
    vector<int> src = {9,7,8,6,8,1,4};
    auto it = is_heap_until(src.begin(), src.end());
    if(it != src.end())
    {
        cout << "is heap" << endl;
        cout << "*it = " << *it << endl;
    }
    else
    {
        cout << "not heap" << endl;
    }
    return 0;
}