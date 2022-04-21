/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:18:55
 * @LastEditTime: 2022-04-21 10:25:43
 * @Description: test rotate.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\rotate.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o rotate rotate.cpp
.\rotate.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 在指定的位置旋转,前边的元素会整体挪到后面,从右向左填充但不改变相对次序
    // 剩下的元素按照相对次序不变移动到起点开始
    vector<int> src = {1,2,3,4,5,6,7,8,9};
    rotate(src.begin(), src.begin()+3, src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl; // 4 5 6 7 8 9 [1 2 3]

    vector<int> src2 = {-1,0,1,5,5,5,4,3,2};
    rotate(src2.begin(), src2.begin()+4, src2.end());
    copy(src2.begin(), src2.end(), out);
    cout <<endl; // 5 5 4 3 2 [-1 0 1 5]
    return 0;
}