#ifndef linearArrayNearbyDuplicatesHashSet_
#define linearArrayNearbyDuplicatesHashSet_
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class linearArrayNearbyDuplicatesHashSet{
    public:
        bool nearbyDuplicates(vector<int> &nums,int k){
            unordered_set<int> s;
            int length = nums.size();
            for (int i = 0; i < length; i++) {
                if (i > k) { // 如果 i>k，则下标 i−k−1 处的元素被移出滑动窗口，因此将 nums[i−k−1] 从哈希集合中删除
                    s.erase(nums[i - k - 1]);
                }
                if (s.count(nums[i])) { // 判断 nums[i] 是否在哈希集合中
                    return true; // 在哈希集合中则在同一个滑动窗口中有重复元素
                }
                s.emplace(nums[i]); // 不在哈希集合中则将其加入哈希集合
            }
            return false;
        }
};
void _linearArray_nearbyDuplicates_hashSet(){
    linearArrayNearbyDuplicatesHashSet solution;
    vector<int> nums = {0,1,3,1,6,7,1};
    cout<<"exist duplicate's idx mnius < 1? "<<(solution.nearbyDuplicates(nums,1)?"true" : "false")<<endl;
    cout<<"exist duplicate's idx mnius < 2? "<<(solution.nearbyDuplicates(nums,2)?"true" : "false")<<endl;
}
#endif // !linearArrayNearbyDuplicatesHashSet_