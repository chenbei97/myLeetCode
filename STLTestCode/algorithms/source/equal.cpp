/*
 * @Author: chenbei
 * @Date: 2022-04-16 11:50:09
 * @LastEditTime: 2022-04-16 12:10:38
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
        <<equal(src1.begin(),src1.end(),src2.begin())<<endl; //false

    vector<int> src3 = {1,2,3,4,5};
    cout<<boolalpha<<"equal({1,2,3,4,5},{1,2,3,4,5}) = "
        <<equal(src1.begin(),src1.end(),src3.begin())<<endl;// true
    
    vector<int> src4 = {3,4,5,6,7};
    cout<<boolalpha<<"equal({1,2,3,4,5}[2,5),{3,4,5,6,7}[0,3)) = "
        <<equal(src1.begin()+2,src1.end(),src4.begin(),src4.end()-2)<<endl; // true

    vector<int> src5 = {5,4,3,6,7};
    cout<<boolalpha<<"equal({1,2,3,4,5}[2,5),{5,4,3,6,7}[0,3),less<int>) = "
        <<equal(src1.begin()+2,src1.end(),src5.begin(),src5.end()-2,less<int>())<<endl; //false
    cout<<boolalpha<<"equal({1,2,3,4,5}[2,5),{5,4,3,6,7}[0,3),greater<int>) = "
        <<equal(src1.begin()+2,src1.end(),src5.begin(),src5.end()-2,greater<int>())<<endl;//false
    
    cout<<boolalpha<<"equal({1,2,3},{5,6,7},less<int>) = "
        <<equal(src3.begin(),src3.begin()+3,src4.begin()+2,src4.end(),less<int>())<<endl; //true
    
    cout<<boolalpha<<"equal({1,2,3},{5,6,7},greater<int>) = "
        <<equal(src3.begin(),src3.begin()+3,src4.begin()+2,src4.end(),greater<int>())<<endl;//false
    
    cout<<boolalpha<<"equal({1,2,3},{5,6,7}[0,2),less<int>) = "//这里原因是元素个数不相等必定有问题
        <<equal(src3.begin(),src3.begin()+3,src4.begin()+2,src4.end()-1,less<int>())<<endl;//false
    return 0;
}