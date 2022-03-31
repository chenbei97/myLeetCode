/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 15:41:28
 * @LastEditTime: 2022-03-31 16:27:57
 * @Description: linearArrayFourSum_DoublePointers.h
 * @FilePath: \myLeetCode\linearArray\linearArrayFourSum_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linearArrayFourSumDoublePointers_
#define linearArrayFourSumDoublePointers_
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
using namespace std;
class linearArrayFourSumDoublePointers{
    public:
        vector<vector<int>> fourSum(vector<int>&nums,int target){
            int n = nums.size();
            if (n<4) {return {{}};}
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            // 首先固定第一个元素，要求first+3<=len(nums)-1,故first<=len(nums)-4
            for (int first=0;first<n-3;++first){ // first取到len(nums-4)对应(len(nums)-3)
                if (first>0 && nums[first-1]==nums[first]) // first不能为0,因为nums[first-1]要使用
                    continue; //连续的2个值相等说明重复
                //固定第2个元素second,同理second+2<=len(nums)-1,故second<=len(nums)-3    
                for(int second=first+1;second<n-2;++second){
                    if(second>first+1 && nums[second-1]==nums[second])
                        continue;//  同样连续的2个第二元素相同就跳过
                    int third=second+1,fourth=n-1; // 双指针确定第3,4个元素
                    while (third<fourth){
                        if (nums[first]+nums[second]+nums[third]+nums[fourth]>target)
                            --fourth; // 偏大需要让fourth前移,因为数组有序,可保证target缩小一些
                        else if (nums[first]+nums[second]+nums[third]+nums[fourth]<target)
                            ++third; // 偏小让third前移,可以变大
                        else { // 相等时,因为有third和fourth2个变量,所以可能存在多种相等情况还要继续考虑前移或后移
                            ans.push_back({nums[first],nums[second],nums[third],nums[fourth]});
                            while (third<fourth and nums[third]==nums[third+1])
                                    ++third; // 右移指针，确保跳过重复元素
                            while (third<fourth and nums[fourth]==nums[fourth-1])
                                    --fourth;// 左移指针，确保跳过重复元素
                            ++third; // 正常也应该尝试前移和后移
                            --fourth;
                        }
                    }
                }
            }
            return ans;
        }
};
void _linearArray_fourSum_doublePointers(){
    linearArrayFourSumDoublePointers solution;
    vector<int> nums = {1,0,-1,0,-2,2};
    auto ans = solution.fourSum(nums,0);
    ostream_iterator<int> os(cout," ");
    for (auto vec : ans){
        copy(vec.begin(),vec.end(),os);
        cout<<"\n";
    }
}
#endif//!linearArrayFourSumDoublePointers_