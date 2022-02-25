#ifndef linearArrayThreeSumIteration_
#define linearArrayThreeSumIteration_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class linearArrayThreeSumIteration{
    public:
        vector<vector<int>> threeSum(vector<int> & nums){
            if (nums.size() < 3) return{{}};
            vector<vector<int>> ans; // (a,b,c)
            sort(nums.begin(),nums.end()); // 数组已经有序
            for (int first = 0 ; first < nums.size(); first++){
                if (first > 0 && nums[first] == nums[first-1]) // 要求后1个大于前1个以减少重复
                    continue; // 连续的2个a相等说明会有重复,直接跳过,first>0是为了防止越界
                for(int second = first+1; second < nums.size() ; second++){ 
                    // first=nums.size()-1时本循环不执行
                    if (second > first+1 && nums[second] == nums[second-1]) // second>first+1是避免second-1<first但可以等于
                        continue; // 固定a,连续的2个b有重复元素则跳过
                    for(int third = second+1 ; third < nums.size() ; third++){ 
                        // first=nums.size()-1或 first=nums.size()-2(即second=nums.size()-1)本循环不执行
                        if(third > second+1 && nums[third] == nums[third-1]) // third>second+1避免third-1<second但可以等于
                            continue; // 固定a,b,连续的2个c重复则跳过
                        if (nums[first]+nums[second]+nums[third] == 0) // 所有不重复的(a,b,c)满足a+b+c=0的添加
                            ans.push_back({nums[first],nums[second],nums[third]});
                    }
                }
            }
            return ans;
        }
};
void _linearArray_threeSum_iteration(){
    linearArrayThreeSumIteration solution;
    vector<int> nums = {-2,5,-3,-1,-4,7,4,0,8};
    auto ans = solution.threeSum(nums);
    for(int i =0 ;i<ans.size();i++){
        for(int j =0; j <ans[i].size();j++){
            cout << ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
#endif // !linearArrayThreeSumIteration_