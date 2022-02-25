#ifndef linearArrayTwoSumIteration_
#define linearArrayTwoSumIteration_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayTwoSumIteration{
    public:
        vector<int> twoSum(vector<int>&nums,int target){ // 168 ms
            if (nums.size() < 2) return {-1,-1};
            vector<int> ans;
            auto itBegin = nums.begin();
            auto itEnd = nums.end();
            int idx1 = 0;
            while (itBegin != itEnd)
            {
                // cout<<"idx1 = "<<idx1<<endl;
                ans.push_back(idx1);
                int idx2 = idx1+1;
                // cout<<"idx2 = "<<idx2<<endl;
                auto it1Begin = itBegin + 1;
                while (it1Begin != itEnd )
                {
                    if ( *it1Begin == target - * itBegin){
                        ans.push_back(idx2);
                        return ans;
                    }
                    it1Begin++;
                    idx2++;
                }
                if (it1Begin == itEnd){
                    ans.clear();
                }
                
                idx1++;
                itBegin++;
            }
            if (ans.empty()) return {-1,-1};
            return ans;
        }
        vector<int> twoSumSimple(vector<int>&nums,int target){ // 304 ms
            if (nums.size() < 2) return {-1,-1};
            for(int i = 0 ; i <nums.size(); i++){
                if (i == nums.size()-1) return {-1,-1};//最后1个元素一定没有了
                for (int j = i+1 ; j <nums.size() ; j++){
                    if (nums[i]+nums[j] == target)
                        return {i,j};
                }
            }
            return {-1,-1};
        }
};
void _linearArray_twoSum_iteration(){
    linearArrayTwoSumIteration solution;
    vector<int> nums = {2,7,13,21,4,9,23,44};
    for (size_t i = 0; i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
    int target = 67;
    vector<int> ans = solution.twoSum(nums,target);
    cout<<"two sum by iterator:\n";
    for (size_t i = 0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    ans = solution.twoSumSimple(nums,target);
    cout<<"two sum by array:\n";
    for (size_t i = 0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
#endif // !linearArrayTwoSumIteration_