#ifndef linearArrayThreeSumDoublePointers_
#define linearArrayThreeSumDoublePointers_
#include <vector>
#include <iostream>
#include <algorithm>
class linearArrayThreeSumDoublePointers{
    public:
        vector<vector<int>> threeSum(vector<int> & nums)
        {
            if (nums.size() < 3) return{{}};
            vector<vector<int>> ans; 
            sort(nums.begin(),nums.end());
            for (int first = 0 ; first < nums.size(); first++)
            {
                if (first > 0 && nums[first] == nums[first-1]) 
                {
                    continue; 
                }
                    
                int third = nums.size() - 1;
                for(int second = first + 1;second < nums.size() ; second++)
                { 
                    if (second > first+1 && nums[second] == nums[second-1]) 
                    {
                        continue; 
                    }
                        
                    while (second < third && (nums[first]+nums[second]+nums[third] > 0))
                    {
                        third--;
                    }
                        
                    if (second == third) 
                    {
                        break;
                    }
                        
                    if (nums[second] + nums[third] + nums[first] == 0) 
                    {
                        ans.push_back({nums[first],nums[second],nums[third]});
                    }
                }

            }
            return ans;
        }
};
void _linearArray_threeSum_doublePointers(){
    linearArrayThreeSumDoublePointers solution;
    vector<int> nums = {-1,0,1,2,-1,-4};// -2,5,-3,-1,-4,7,4,0,8
    auto ans = solution.threeSum(nums);
    for(int i =0 ;i<ans.size();i++){
        for(int j =0; j <ans[i].size();j++){
            cout << ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
#endif // !linearArrayThreeSumDoublePointers_