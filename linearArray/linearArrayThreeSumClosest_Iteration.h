#ifndef linearArrayThreeSumClosestIteration_
#define linearArrayThreeSumClosestIteration_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class linearArrayThreeSumClosestIteration{
    public : 
        int threeSumClosest(vector<int>& nums, int target){
            int ans = 1e7; // 记录目前最接近target的值
            sort(nums.begin(),nums.end());
            for(int i = 0; i<nums.size();i++){
                if (i>0 && nums[i] == nums[i-1])
                    continue;
                for(int j = i+1; j<nums.size(); j++){
                    if (j>i+1 && nums[j-1] == nums[j])
                        continue;
                    for (int k = j+1; k<nums.size(); k++){
                        if(k>j+1 && nums[k-1] == nums[k])
                            continue;
                        // 跳过所有的重复值后剩下的
                        int delta = abs(nums[i]+nums[j]+nums[k]-target);
                        if (delta == 0)
                            return target;
                        else {
                            if (delta < abs(target-ans)){
                                ans = nums[i]+nums[j]+nums[k];
                            }
                        }
                    } 
                }
            }
            return ans;
        }
};
void _linearArray_threeSumClosest_iteration(){
    linearArrayThreeSumClosestIteration solution;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int ans = solution.threeSumClosest(nums,target);
    cout << "the ans is "<<ans<<endl;
    vector<int> k(100);
    for(int i = 0 ;i<100;i++)
        k.push_back(i+1);
    target = 100+99+98+1; //297+1
    ans = solution.threeSumClosest(k,target);
    cout << "the ans is "<<ans<<endl; // 最接近298的是297唯一的答案
}
#endif // !linearArrayThreeSumClosestIteration_