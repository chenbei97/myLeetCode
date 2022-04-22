/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:57:29
 * @LastEditTime: 2022-04-22 16:58:34
 * @Description: test sort_heap.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\sort_heap.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\sort_heap sort_heap.cpp
..\output\sort_heap.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 对堆调整为有序
    vector<int> src = {9,6,8,2,1,7,4};
    sort_heap(src.begin(), src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 1 2 4 6 7 8 9
    cout << endl;
    return 0;
}