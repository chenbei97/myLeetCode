/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:56:02
 * @LastEditTime: 2022-04-25 08:59:51
 * @Description: test partial_sort.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\partial_sort.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\partial_sort partial_sort.cpp
..\output\partial_sort.exe
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    // 部分排序,前边的排序好
    vector<int> src = {1,8,9,7,10,6,11,5,12,4,2,20,3};
    partial_sort(src.begin(),src.begin()+6,src.end());
    ostream_iterator<int> out(cout," ");
    for (auto &i : src) cout<<i<<" ";
    cout<<endl; // 1 2 3 4 5 6 11 10 12 9 8 20 7
    return 0;
}