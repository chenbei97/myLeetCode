/*
 * @Author: chenbei
 * @Date: 2022-04-16 09:24:09
 * @LastEditTime: 2022-04-16 09:27:17
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\copy_n.cpp
 * @Description: test copy_n.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 把src的[begin,begin+n)个元素复制到dst的[begin,begin+n)
    vector<int> src = {4,5,6,7,8};
    int size = 3; // 前3个
    ostream_iterator<int> out(cout," ");
    copy_n(src.begin(),size,out); // 这里直接复制到终端
    return 0;
}