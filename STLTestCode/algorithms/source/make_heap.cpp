/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:46:10
 * @LastEditTime: 2022-04-22 16:47:17
 * @Description: test make_heap.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\make_heap.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\make_heap make_heap.cpp
..\output\make_heap.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 默认制造大根堆,原地制造
    vector<int> src = {1,6,4,2,9,7,8};
    make_heap(src.begin(), src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 9 6 8 2 1 7 4 
    cout<<endl;
    return 0;
}