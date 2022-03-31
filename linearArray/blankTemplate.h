/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 10:02:49
 * @LastEditTime: 2022-03-31 10:09:39
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
#include <iterator>
using namespace std;
class A{
    public:
        void func(vector<int>&nums){
            
        }
};
void _linearArray_a_b(){
    A solution;
    vector<int> nums = {};
    solution.func(nums);
    ostream_iterator<int> os(cout," ");
    cout<<" as follows\n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif//!_