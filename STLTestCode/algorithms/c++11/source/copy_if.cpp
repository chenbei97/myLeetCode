/*
 * @Author: chenbei
 * @Date: 2022-04-16 09:14:02
 * @LastEditTime: 2022-04-16 09:23:59
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\copy_if.cpp
 * @Description: test copy_if.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 满足某个条件时返回原数组子集
    vector<int> src = {1,2,3,4,5};
    vector<int> dst1(src.size()); // 必须提供容量
    copy_if(src.begin(),src.end(),dst1.begin(),[](int i){return i > 3;});
    ostream_iterator<int> out(cout," ");
    copy(dst1.begin(),dst1.end(),out);
    cout<<"\n";
    return 0;
}