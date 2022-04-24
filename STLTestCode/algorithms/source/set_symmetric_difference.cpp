/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 15:08:12
 * @LastEditTime: 2022-04-24 15:09:42
 * @Description: test set_symmetric_difference.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\set_symmetric_difference.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\set_symmetric_difference set_symmetric_difference.cpp
..\output\set_symmetric_difference.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 和set_difference不同在于,去除了第2个集合后,第2个集合剩下的也会合并到集合1中
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst = {1,2,3,4,5,6,-1};
    vector<int> result;
    set_symmetric_difference(src.begin(), src.end(), dst.begin(), dst.end(), back_inserter(result));
    ostream_iterator<int> out(cout," ");
    copy(result.begin(), result.end(), out); // -1,7,8,9,10
    cout << endl;
    return 0;
}
