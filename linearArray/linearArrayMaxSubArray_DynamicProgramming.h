#ifndef linearArrayMaxSubArrayDynamicProgramming_
#define linearArrayMaxSubArrayDynamicProgramming_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayMaxSubArrayDynamicProgramming{
    public:
        int maxSubArray(vector<int>&nums){
            int pre = 0, maxAns = nums[0];
            for (const auto &num: nums) {
                cout<<"before: num = "<<num<<" pre = "<<pre<<" maxAns = "<<maxAns<<endl;
                pre = max(pre + num, num); // f(i) = max(f(i-1)+nums[i],nums[i])
                maxAns = max(maxAns, pre);// maxAns=max(maxAns,f(i)),每次都和新计算得到的f(i)比较然后更新maxAns
                cout<<"after: num = "<<num<<" pre = "<<pre<<" maxAns = "<<maxAns<<endl;
            }
            return maxAns;
        }
};
void _linearArray_maxSubArray_dynamicProgramming(){
    linearArrayMaxSubArrayDynamicProgramming solution;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    auto ans = solution.maxSubArray(nums);
    cout<<"dynamicProgramming=> the max subArray sum is "<<ans<<"\n";
}
#endif // !linearArrayMaxSubArrayDynamicProgramming_