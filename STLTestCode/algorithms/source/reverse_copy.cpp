/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:19:58
 * @LastEditTime: 2022-04-22 16:21:10
 * @Description: test reverse_copy.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\reverse_copy.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\reverse_copy reverse_copy.cpp
..\output\reverse_copy.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 相比reverse，reverse_copy不是原地反转
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst(10);
    // 反转前
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // 反转后
    reverse_copy(src.begin(), src.end(), dst.begin());
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out);
    cout << endl;
    return 0;
}