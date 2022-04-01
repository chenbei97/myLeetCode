/*** 
 * @Author: chenbei
 * @Date: 2022-04-01 09:46:33
 * @LastEditTime: 2022-04-01 11:48:49
 * @Description: linearArraySmallestDistancePairs_DoublePointers.h
 * @FilePath: \myLeetCode\linearArray\linearArraySmallestDistancePairs_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linearArraySmallestDistancePairsDoublePointers_
#define linearArraySmallestDistancePairsDoublePointers_
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class linearArraySmallestDistancePairsDoublePointers{
    public:
        int smallestKDistance(vector<int>&nums,int k){
            sort(nums.begin(),nums.end());
            int n = nums.size();
            int leftDist=0,rightDist=nums[n-1]-nums[0];
            while (leftDist<=rightDist){//符合条件就要继续寻找
                int midDist = (leftDist+rightDist)/2;
                if (numOfLessThanDistance(nums,midDist)<k)
                    leftDist = midDist + 1;// 说明第k小在[midDist+1,rightDist]之间
                else { // 即使umOfLessThanDistance(midDist)==k也不能说明midDist是最小距离
                    // 因为这个返回的是比midDist小的个数,k是比它大的应该继续计算
                    rightDist = midDist - 1;// 第k小在[leftDist,midDist-1]之间
                }
                cout<<"leftDist = "<<leftDist<<" rightDist = "<<rightDist<<endl;//[0,0,2,3,4]and[8,3,3,3,3]
            }
            return leftDist; //不返回midDist,直到leftDist>rightDist为止
        }
    private:
        int numOfLessThanDistance(const vector<int> &nums,int dist){
            int count=0;
            int left = 0;
            for(int right=0;right<nums.size();++right){ 
                while (nums[right]-nums[left]>dist)
                        ++ left;//只要存在后面的元素减去前面的元素大于这个距离就让left前移
                count += right-left; // [left,right-1]的数据才是小于dist的
            }
            return count;
        }
};
void _linearArray_smallestDistancePairs_doublePointers(){
    linearArraySmallestDistancePairsDoublePointers solution;
    vector<int> nums = {1,10,5,23,40,14,2};
    cout<<"the k smallest distance is "<<solution.smallestKDistance(nums,3)<<endl;//4=14-10
}
#endif//!linearArraySmallestDistancePairsDoublePointers_