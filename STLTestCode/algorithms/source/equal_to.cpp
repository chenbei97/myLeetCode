/*
 * @Author: chenbei
 * @Date: 2022-04-16 11:59:12
 * @LastEditTime: 2022-04-16 12:18:13
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\equal_to.cpp
 * @Description: test equal_to.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src1 = {2,4,6,8};
    vector<int> src2 = {-2,-4,-6,8};
    equal_to<int> eq;
    cout<<boolalpha<<"2 == 4? "<<eq(2,4)<<endl;//false
    cout<<boolalpha<<"2 == -2? "<<eq(2,-2)<<endl;//false
    cout<<boolalpha<<"2 == 2? "<<eq(2,2)<<endl;//true
    cout<<boolalpha<<eq(*src1.begin(),*src2.begin())<<endl; //false
    cout<<boolalpha<<eq(*(src1.end()-1),*(src2.end()-1))<<endl;//true
    return 0;
}