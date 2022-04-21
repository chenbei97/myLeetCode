/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:48:47
 * @LastEditTime: 2022-04-21 10:50:55
 * @Description: test set_union.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\set_union.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\set_union set_union.cpp
..\output\set_union.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 把相同元素的集合合并成一个集合
    vector<int> src1 = {0,1,2,2,4,4,5};
    vector<int> src2 = {1,2,3,4,5,6,7};
    vector<int> dst;
    set_union(src1.begin(), src1.end(), src2.begin(), src2.end(), back_inserter(dst));
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out);
    cout <<endl; // 0 1 2 2 3 4 4 5 6 7
    return 0;
}