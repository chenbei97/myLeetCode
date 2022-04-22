/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:44:05
 * @LastEditTime: 2022-04-22 16:45:24
 * @Description: test prev_permutation.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\prev_permutation.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\prev_permutation prev_permutation.cpp
..\output\prev_permutation.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到指定序列的上一个排列
    vector<int> src = {1,2,3,4,5};
    vector<int> dst(5);
    prev_permutation(src.begin(), src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 5 4 3 2 1
    cout<<endl;
    return 0;
}