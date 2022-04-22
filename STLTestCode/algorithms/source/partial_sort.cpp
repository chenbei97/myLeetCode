/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:27:20
 * @LastEditTime: 2022-04-22 16:29:00
 * @Description: test partial_sort.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\partial_sort.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\partial_sort partial_sort.cpp
..\output\partial_sort.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 部分排序,原地排序,指定好范围就进行排序
    vector<int> src = {1,-3,4,3,2,5,2,6,8,0};
    // 只对[begin,begin+5]进行排序
    partial_sort(src.begin(), src.begin()+5, src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // -3 0 1 2 2 5 4 6 8 3 
    cout << endl;
    return 0;
}