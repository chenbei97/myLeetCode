/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:42:32
 * @LastEditTime: 2022-04-22 16:42:32
 * @Description: test next_permutation.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\next_permutation.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\next_permutation next_permutation.cpp
..\output\next_permutation.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到指定序列的下一个排列
    vector<int> src = {5,4,3,2,1};
    vector<int> dst(5);
    next_permutation(src.begin(), src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 1 2 3 4 5
    return 0;
}