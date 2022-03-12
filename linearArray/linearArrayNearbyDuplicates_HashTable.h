#ifndef linearArrayNearbyDuplicatesHashTable_
#define linearArrayNearbyDuplicatesHashTable_
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class linearArrayNearbyDuplicatesHashTable{
    public:
        bool nearbyDuplicates(vector<int> &nums,int k){
            unordered_map<int, int> dictionary;
            int length = nums.size();
            for (int i = 0; i < length; i++) {//遍历每个元素
                int num = nums[i]; // 当前元素
                if (dictionary.count(num) &&  // 如果当前元素在字典里
                    i - dictionary[num] <= k) { // 且满足当前索引值i与字典中num目前最大的索引值的差值<=k
                    return true; // 返回true
                }
                dictionary[num] = i; // 不在字典或者索引值不满足就更新字典的值
            }
            return false; // 遍历结束还没有就说明不存在
        }
};
void _linearArray_nearbyDuplicates_hashTable(){
    linearArrayNearbyDuplicatesHashTable solution;
    vector<int> nums = {0,1,3,1,6,7,1};
    cout<<"exist duplicate's idx mnius < 1? "<<(solution.nearbyDuplicates(nums,1)?"true" : "false")<<endl;
    cout<<"exist duplicate's idx mnius < 2? "<<(solution.nearbyDuplicates(nums,2)?"true" : "false")<<endl;
}
#endif // !linearArrayNearbyDuplicatesHashTable