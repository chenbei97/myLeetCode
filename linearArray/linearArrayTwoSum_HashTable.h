#ifndef linearArrayTwoSumHashTable_
#define linearArrayTwoSumHashTable_
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class linearArrayTwoSumHashTable{
    public:
        vector<int> twoSum(vector<int>&nums,int target){ // 12 ms
            if (nums.size() <2) return {-1,-1};
            unordered_map<int,int> m;
            for (int i = 0; i<nums.size() ; i++){
                m[nums[i]] = i; // 注,因为目标是返回索引,所以索引作为数据而值作为关键字
            }
            int idx = 0;
            for (vector<int>::const_iterator it = nums.begin();
                it!=nums.end(); it++){
                    auto ans = m.find(target-*(it));
                    if (ans!= m.end() && ans->second != idx)
                        return {idx,ans->second};
                    // if (m.contains(target-*(it)) && ans->second !=idx)
                    //     return {idx,ans->second};
                    idx++;
            }
            return {-1,-1};
        }
        vector<int> twoSumSimple(vector<int>&nums,int target){ // 12ms
            if (nums.size() <2) return {-1,-1};
            unordered_map<int,int> m;
            for (int i = 0; i<nums.size() ; i++){
                m[nums[i]] = i; // 注,因为目标是返回索引,所以索引作为数据而值作为关键字
            }
            for (int i =0; i<nums.size();i++){
                if (m.count(target - nums[i]) != 0 && m[target-nums[i]] != i )
                    return {i,m[target-nums[i]]};
            }
            return {-1,-1};
        }
        
};
void _linearArray_twoSum_hashTable(){
    linearArrayTwoSumHashTable solution;
    vector<int> nums = {2,7,13,21,4,9,23,44};
    auto ans = solution.twoSum(nums,67);
    cout<<"two sum by hashTable:\n";
    for (size_t i = 0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\ntwo sum by hashTableSimple:\n";
    ans = solution.twoSumSimple(nums,67);
    for (size_t i = 0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
#endif // !linearArrayTwoSumHashTable_