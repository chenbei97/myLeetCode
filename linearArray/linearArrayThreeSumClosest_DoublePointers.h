#ifndef linearArrayThreeSumClosestDoublePointers_
#define linearArrayThreeSumClosestDoublePointers_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayThreeSumClosestDoublePointers{
    public : 
        int threeSumClosest(vector<int>& nums, int target){
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int ans = 1e7;
            for(int i = 0; i<n;i++)
            {
                if (i>0 && nums[i] == nums[i-1])
                    continue;
                int j = i+1 ,k = n-1 ; // nums[j]和nums[k]之间的数指针
                while (j < k)
                { // 相等意味着索引同1个坐标,不允许
                    int s = nums[i]+nums[j]+nums[k];
                    if (s-target == 0)
                        return target;
                    if (abs(s-target) < abs(ans-target))
                        ans = s;
                    if (s-target > 0)
                    { // k>j,只可能向左移动k才会让s变小
                        k--;
                    }
                    if (s-target < 0)
                    { // 只可能向右移动j才会让s变大
                        j++;
                    }
                }
            }
            return ans;
        }
};
void _linearArray_threeSumClosest_doublePointers(){
    linearArrayThreeSumClosestDoublePointers solution;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int ans = solution.threeSumClosest(nums,target);
    cout << "the ans is "<<ans<<endl;
    vector<int> k(100);
    for(int i = 0 ;i<100;i++)
        k.push_back(i+1);
    target = 100+99+98+1; //297+1
    ans = solution.threeSumClosest(k,target);
    cout << "the ans is "<<ans<<endl; // 最接近298的是297唯一的答案
}
#endif // !linearArrayThreeSumClosestDoublePointers_