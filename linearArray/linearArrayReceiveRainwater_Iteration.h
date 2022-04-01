/*** 
 * @Author: chenbei
 * @Date: 2022-04-01 13:35:46
 * @LastEditTime: 2022-04-01 14:54:27
 * @Description: linearArrayReceiveRainwater_Iteration.h
 * @FilePath: \myLeetCode\linearArray\linearArrayReceiveRainwater_Iteration.h
 * @A boy without dreams
 */
#ifndef linearArrayReceiveRainwaterIteration_
#define linearArrayReceiveRainwaterIteration_
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class linearArrayReceiveRainwaterIteration{
    public:
        int trap(vector<int>&nums){
            // 水有多高取决于这个点左侧和右侧墙壁的最大高度
            int n = nums.size();
            // 用于记录nums[i]左侧和右侧所有高度的最大值,在范围之外高度认为是0
            vector<int> rightMaxHeight(n),leftMaxHeight(n);
            for(int i=1;i<n;++i){
                // 最大高度总是依据当前高度和以往高度进行比较
                leftMaxHeight[i] = max(leftMaxHeight[i-1],nums[i-1]);
                // 初始时leftMaxHeight[0]=rightMaxHeight[n-1]=0
                rightMaxHeight[n-i-1] = max(rightMaxHeight[n-i],nums[n-i]);
            }
            // ostream_iterator<int> os(cout," ");
            // copy(leftMaxHeight.begin(),leftMaxHeight.end(),os); 
            // cout<<"\n"; // 0 0 1 1 2 2 2 2 3 3 3 3
            // copy(rightMaxHeight.begin(),rightMaxHeight.end(),os);
            // cout<<"\n"; // 3 3 3 3 3 3 3 2 2 2 1 0
            int water = 0;
            for(int i =1;i<n-1;++i){ // i=0,n-1的wallHeight-nums[i]必定是0无需再判断
                int wallHeight = min(rightMaxHeight[i],leftMaxHeight[i]);//木桶理论
                // 可能比当前i对应的高度小。所以level-height[i]可能是负数
                water += max(0,wallHeight-nums[i]); // 更小的那个墙壁高度减去当前地面高度
            }
            return water;
        }
};
void _linearArray_receiveRainwater_iteration(){
    linearArrayReceiveRainwaterIteration solution;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    auto ans = solution.trap(nums);
    cout<<"the water is "<<ans<<"\n";
}
#endif//!linearArrayReceiveRainwaterIteration_