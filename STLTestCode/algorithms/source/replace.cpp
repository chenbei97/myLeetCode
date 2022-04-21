/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:24:59
 * @LastEditTime: 2022-04-21 11:26:29
 * @Description: test replace.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\replace.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\replace replace.cpp
..\output\replace.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 旧值2被替换成5
    vector<int> src = {1,2,1,2,1,2,1,2};
    replace(src.begin(), src.end(), 1, 5);
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout << endl;
    return 0;
}