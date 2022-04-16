/*
 * @Author: chenbei
 * @Date: 2022-04-16 11:50:09
 * @LastEditTime: 2022-04-16 11:58:49
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\equal.cpp
 * @Description: test equal.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // equal按顺序比较2个数组
    vector<int> src1 = {1,2,3,4,5};
    vector<int> src2 = {5,4,3,2,1};
    cout<<boolalpha<<"equal({1,2,3,4,5},{5,4,3,2,1}) = "
        <<equal(src1.begin(),src1.end(),src2.begin())<<endl;

    vector<int> src3 = {1,2,3,4,5};
    cout<<boolalpha<<"equal({1,2,3,4,5},{1,2,3,4,5}) = "
        <<equal(src1.begin(),src1.end(),src3.begin())<<endl;
    
    vector<int> src4 = {3,4,5,6,7};
    cout<<boolalpha<<"equal({1,2,3,4,5}[2,5),{3,4,5,6,7}[0,3)) = "
        <<equal(src1.begin()+2,src1.end(),src4.begin(),src4.end()-2)<<endl;
    return 0;
}