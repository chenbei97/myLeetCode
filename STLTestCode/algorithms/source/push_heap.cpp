/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:48:16
 * @LastEditTime: 2022-04-22 16:51:51
 * @Description: test push_heap.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\push_heap.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\push_heap push_heap.cpp
..\output\push_heap.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {8,6,7,2,1,4};
    make_heap(src.begin(), src.end());
    // 调整堆之前
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 8 6 7 2 1 4 
    cout<<endl;
    // 调整堆之后,变成小根堆
    push_heap(src.begin(), src.end(), [](int x, int y){return x>y;});
    copy(src.begin(), src.end(), out); // 4 6 8 2 1 7
    cout<<endl;
    return 0;
}
