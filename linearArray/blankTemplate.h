/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 10:02:49
 * @LastEditTime: 2022-04-01 14:50:00
 * @Description: blankTemplate.h
 * @FilePath: \myLeetCode\linearArray\blankTemplate.h
 * @A boy without dreams
 */
#ifndef _
#define _
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;
class A{
    public:
        vector<int> func(vector<int>&nums){
            
        }
};
void _linearArray_a_b(){
    A solution;
    vector<int> nums = {};
    auto ans = solution.func(nums);
    ostream_iterator<int> os(cout," ");
    cout<<" as follows\n";
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!_