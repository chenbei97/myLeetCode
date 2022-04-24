/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 15:05:42
 * @LastEditTime: 2022-04-24 15:07:23
 * @Description: test set_difference.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\set_difference.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\set_difference set_difference.cpp
..\output\set_difference.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 取去除第2个集合后第1个集合剩下的,和set_union,set_intersection一样,事先必须有序
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst = {1,2,3,4,5,6,-1};
    vector<int> result;
    set_difference(src.begin(), src.end(), dst.begin(), dst.end(), back_inserter(result));
    ostream_iterator<int> out(cout," ");
    copy(result.begin(), result.end(), out); // 7,8,9,10
    cout << endl;
    return 0;
}