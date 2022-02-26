#ifndef linearArrayRemoveDuplicatesDoublePointers_
#define linearArrayRemoveDuplicatesDoublePointers_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class linearArrayRemoveDuplicatesDoublePointers{
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() < 1) return 0;
            sort(nums.begin(),nums.end());
            int slow = 1; // 至少有1个元素nums[0]
            int fast = 1 ; // 初始时指向同1位置
            int n = nums.size();
            while (fast < n){
                if (nums[fast] != nums[fast-1]){
                    nums[slow] = nums[fast];
                    slow++; // 因为数组有序,fast无需再回到slow,继续向前即可
                }
                fast++; // 无论前后是否相等,fast都会前进
            }
            return slow;
        }
};
void _linearArray_removeDuplicates_doublePointers(){
    linearArrayRemoveDuplicatesDoublePointers solution;
    vector <int> nums;
    for (int i =0;i<100;i++)
    {
        nums.push_back(((i+1) % 5)+3);
    }
    for (int i = 0 ; i< nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
    int size = solution.removeDuplicates(nums);
    cout<<"The number of non repeating elements is "<<size<<endl;
    for (int i = 0 ; i< size; i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n"; 

}
#endif // !linearArrayRemoveDuplicatesDoublePointers_