/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 08:41:36
 * @LastEditTime: 2022-04-22 08:42:51
 * @Description: is_heap.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\is_heap.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\is_heap is_heap.cpp
..\output\is_heap.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 判断是否为堆,默认判断大根堆
    vector<int> src = {9,7,8,6,2,1,4};
    auto it = is_heap(src.begin(), src.end());
    if(it)
    {
        cout << "is heap" << endl;
    }
    else
    {
        cout << "not heap" << endl;
    }
    return 0;
}