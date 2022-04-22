/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:21:58
 * @LastEditTime: 2022-04-22 16:23:42
 * @Description: test rotate_copy.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\rotate_copy.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\rotate_copy rotate_copy.cpp
..\output\rotate_copy.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 相比rotate,rotate_copy不是原地旋转
    // 需要提供3个位置,first,middle,last
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst(10);
    // 旋转前
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // 旋转后
    rotate_copy(src.begin(), src.begin()+3, src.end(), dst.begin()); // 从位置3开始旋转
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out);
    cout << endl;
    return 0;
}