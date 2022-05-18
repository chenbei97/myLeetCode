/*** 
 * @Author: chenbei
 * @Date: 2022-05-18 17:33:04
 * @LastEditTime: 2022-05-18 17:50:10
 * @Description: linearArrayFullPermutation_Recursion.h
 * @FilePath: \myLeetCode\linearArray\linearArrayFullPermutation_Recursion.h
 * @Signature: A boy without dreams
 */
#ifndef linearArrayFullPermutationRecursion_
#define linearArrayFullPermutationRecursion_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class linearArrayFullPermutationRecursion{
    public:
        vector<vector<int>> res;
        int n ;
        vector<vector<int>> permute(vector<int>&nums){
            this->n = nums.size();
            backTrace(nums,0);
            return this->res;
        }
        void backTrace(vector<int>&nums,int first){
        if (first == this->n){
            res.emplace_back(nums); // 添加进答案
        }
        for(int i =first; i < this->n;++i){ // 对于每一个位置
            swap(nums[i],nums[first]); // 改变状态
            backTrace(nums,first+1); // 反复递归
            swap(nums[i],nums[first]);// 撤销状态
        }
    }
};
void _linearArray_fullPermutation_recursion(){
    /*
        i = 0,first = 0
        i = 1,first = 1 --> i = 2,first = 1 --> 1,3,2
        i = 2,first = 2--> 1,2,3

        i = 1,first = 0
        i = 1,first = 1 --> i = 2,first = 2 --> 2,3,1
        i = 2,first = 2-->2,1,3

        i = 2,first = 0
        i = 1,first = 1 --> i = 2,first = 2-->3,1,2
        i = 2,first = 2--> 3,2,1
    */
    linearArrayFullPermutationRecursion solution;
    vector<int> nums = {1,2,3};
    auto ans = solution.permute(nums);
    ostream_iterator<int> os(cout," ");
    cout<<"[1,2,3]'s full permutation as follows\n";
    for (auto &i : ans){
        copy(i.begin(),i.end(),os);
        cout<<"\n";
    }
}
#endif//!linearArrayFullPermutationRecursion_