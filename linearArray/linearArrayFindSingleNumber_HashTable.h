#ifndef linearArrayFindSingleNumberHashTable_
#define linearArrayFindSingleNumberHashTable_
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class linearArrayFindSingleNumberHashTable{
    public:
        int singleNumber(vector<int>& nums){
            // 用哈希表存储每个数字,键为数字,值为个数
            unordered_map<int, int> freq;
            for (int num: nums) 
                freq[num]++;//重复遇见num就增1
            for (auto [num, count]: freq) { // 类似于python的enumerate语法
                if (count == 1) { // 只出现1次的数据返回键即可
                    return num;
                }
            }
            return 0; // 默认返回0
        }
};
void _linearArray_findSingleNumber_hashTable(){
    linearArrayFindSingleNumberHashTable solution;
    vector<int> nums={3,2,3,5,5,3,2,5,2,-1};
    int ans = solution.singleNumber(nums);
    cout<<"hashTable=> the single number is "<<ans<<endl;
}
#endif // !linearArrayFindSingleNumberHashTable_