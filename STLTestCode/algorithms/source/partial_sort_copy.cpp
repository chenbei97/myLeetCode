/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:30:26
 * @LastEditTime: 2022-04-22 16:31:33
 * @Description: test partial_sort_copy.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\partial_sort_copy.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\partial_sort_copy partial_sort_copy.cpp
..\output\partial_sort_copy.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 相比于partial_sort，partial_sort_copy不是原地排序
    vector<int> src = {1,-3,4,3,2,5,2,6,8,0};
    vector<int> dst(10);
    partial_sort_copy(src.begin(), src.begin()+5, dst.begin(), dst.end());
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out); // -3 1 2 3 4 0 0 0 0 0
    cout << endl;
    return 0;
}