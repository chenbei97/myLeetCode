#ifndef linearArrayMajorityElementSort_
#define linearArrayMajorityElementSort_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class linearArrayMajorityElementSort{
    public:
        int majorityElement(vector<int>&nums){
            sort(nums.begin(),nums.end());
            return (nums[nums.size()/2]); // 众数一定在排序后的数组中间,无论奇数还是偶数
        }
};
void _linearArray_majorityElement_sort(){
    linearArrayMajorityElementSort solution;
    vector<int> nums={5,2,5,5,5,3,2,5,2,5,7,8,5,5};
    auto ans = solution.majorityElement(nums);
    cout<<"sort=> the majority element is "<<ans<<"\n";
}
#endif // !linearArrayMajorityElementSort_