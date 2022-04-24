/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 15:02:34
 * @LastEditTime: 2022-04-24 15:03:37
 * @Description: test set_intersection.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\set_intersection.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\set_intersection set_intersection.cpp
..\output\set_intersection.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 取交集
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst = {1,2,3,4,5,6};
    vector<int> result;
    set_intersection(src.begin(), src.end(), dst.begin(), dst.end(), back_inserter(result));
    ostream_iterator<int> out(cout," ");
    copy(result.begin(), result.end(), out); // 1,2,3,4,5,6
    cout << endl;
    return 0;
}