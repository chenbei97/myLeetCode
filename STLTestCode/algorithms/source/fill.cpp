/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 14:34:46
 * @LastEditTime: 2022-04-24 14:36:34
 * @Description: test fill.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\fill.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\fill fill.cpp
..\output\fill.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 填充指定的值
    vector<int> src(10);
    fill(src.begin(), src.end(), 1);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}