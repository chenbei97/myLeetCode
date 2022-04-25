/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:37:28
 * @LastEditTime: 2022-04-25 08:40:12
 * @Description: test adjacent_difference.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\adjacent_difference.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\adjacent_difference adjacent_difference.cpp
..\output\adjacent_difference.exe
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;
int main()
{
    // 找到元素的差分
    vector<int> src = {1,2,4,7,11,16,22,29,37,46};
    vector<int> dst;
    adjacent_difference(src.begin(), src.end(), back_inserter(dst));
    for (auto i : dst) cout << i << " ";
    cout << endl;// 1 1 2 3 4 5 6 7 8 9
    return 0;
}