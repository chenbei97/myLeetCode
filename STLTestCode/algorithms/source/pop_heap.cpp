/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:52:50
 * @LastEditTime: 2022-04-22 16:55:31
 * @Description: test pop_heap.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\pop_heap.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\pop_heap pop_heap.cpp
..\output\pop_heap.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {1,6,4,2,9,7,8};
    make_heap(src.begin(), src.end());
    cout << "src: \n";
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 9 6 8 2 1 7 4
    cout<<endl;
    // 弹出堆顶元素
    cout << "pop_heap: \n";
    pop_heap(src.begin(), src.end());
    copy(src.begin(), src.end(), out); // 8 6 7 2 1 4 9
    cout<<endl;
    src.pop_back();//删除就能得到想要的结果
    copy(src.begin(), src.end(), out); // 8 6 7 2 1 4
    cout<<endl;
    return 0;
}