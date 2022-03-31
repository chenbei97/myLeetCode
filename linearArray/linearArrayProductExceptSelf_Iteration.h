/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 16:31:58
 * @LastEditTime: 2022-03-31 16:59:31
 * @Description: linearArrayProductExceptSelf_Iteration.h
 * @FilePath: \myLeetCode\linearArray\linearArrayProductExceptSelf_Iteration.h
 * @A boy without dreams
 */
#ifndef linearArrayProductExceptSelfIteration_
#define linearArrayProductExceptSelfIteration_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class linearArrayProductExceptSelfIteration{
    public:
        vector<int> roductExceptSelf(vector<int>&nums){
            // 创建两个数组,一个用于记录某元素前元素的乘积
            // 一个用于记录某元素后元素的乘积,最后用两个元素进行逐元素相乘即可
                ostream_iterator<int> os(cout," ");
                int n = nums.size();
                vector<int> left(n, 1); // 初始化为1是为了方便相乘
                vector<int> right(n, 1);
                vector<int> res(n, 1);
                for(int i = 1; i < nums.size(); i++) 
                    left[i] = left[i-1] * nums[i-1]; 
                for(int j = nums.size()-2; j>=0; j--)
                    right[j] = right[j+1] * nums[j+1];//
                for(int i = 0; i<nums.size(); i++)
                    res[i] = left[i] * right[i];
                copy(left.begin(),left.end(),os);
                cout<<"\n";// 1 1 2 6 =[1,1*1,1*2,2*3]=[1,left[0]*nums[0],left[1]*nums[1],left[2]*nums[2]]
                copy(right.begin(),right.end(),os);
                cout<<"\n";// 24 12 4 1 = [right[3]*nums[3],right[2]*nums[2],right[3]*nums[3],1]
                return res;
            
            // int n = nums.size();
            // vector<int> ans(n,1);
            // int left=1,right=1;
            // for(int i=0;i<n;++i){
            //     ans[i] = left;
            //     left *= nums[i];
            // }
            // for (int i=n-1;i>=0;--i){
            //     ans[i] *= right;
            //     right *= nums[i];
            // }
            // return ans;
        }
};
void _linearArray_productExceptSelf_iteration(){
    linearArrayProductExceptSelfIteration solution;
    vector<int> nums = {1,2,3,4};
    auto ans = solution.roductExceptSelf(nums);
    ostream_iterator<int> os(cout," ");
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!linearArrayProductExceptSelfIteration_