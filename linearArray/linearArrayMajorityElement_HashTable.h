#ifndef linearArrayMajorityElementHashTable_
#define linearArrayMajorityElementHashTable_
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class linearArrayMajorityElementHashTable{
    public:
        int majorityElement(vector<int>&nums){
            unordered_map<int,int> m;
            for (auto num : nums){
                m[num]++; // 每个num作为关键字去统计数量
            }
            int maxVal=0,maxKey=nums[0];
            for (auto [key,val]:m){
                if (val>maxVal){ // 找到数量最大的关键字返回
                    maxVal = val;
                    maxKey = key;
                }
            }
            return maxKey;
        }
};
void _linearArray_majorityElement_hashTable(){
    linearArrayMajorityElementHashTable solution;
    vector<int> nums={5,2,5,5,5,3,2,5,2,5,7,8,5,5};
    auto ans = solution.majorityElement(nums);
    cout<<"hashTable=> the majority element is "<<ans<<"\n";
}
#endif // !linearArrayMajorityElementHashTable_