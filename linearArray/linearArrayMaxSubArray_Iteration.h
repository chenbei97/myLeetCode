#ifndef linearArrayMaxSubArrayIteration_
#define linearArrayMaxSubArrayIteration_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class linearArrayMaxSubArrayIteration{
    public:
        int maxSubArray(vector<int>&nums){
            int n = nums.size();
            vector<int> ans;
            for(int i =0;i<n;i++){
                int subArraySum = nums[i];
                ans.push_back(subArraySum);
                for(int j=i-1;j>=0;j--){
                    subArraySum += nums[j];
                    ans.push_back(subArraySum);
                }
            }
            return *max_element(ans.begin(),ans.end());
        }
};
void _linearArray_maxSubArray_iteration(){
    linearArrayMaxSubArrayIteration solution;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    auto ans = solution.maxSubArray(nums);
    cout<<"Iteration=> the max subArray sum is "<<ans<<"\n";
}
#endif // !linearArrayMaxSubArrayIteration_