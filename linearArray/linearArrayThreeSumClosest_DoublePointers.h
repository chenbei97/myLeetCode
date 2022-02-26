#ifndef linearArrayThreeSumClosestDoublePointers_
#define linearArrayThreeSumClosestDoublePointers_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayThreeSumClosestDoublePointers{
    public : 
        int threeSumClosest(vector<int>& nums, int target){
            int ans;
            return ans;
        }
};
void _linearArray_threeSumClosest_doublePointers(){
    linearArrayThreeSumClosestDoublePointers solution;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int ans = solution.threeSumClosest(nums,target);
    cout << "the ans is "<<ans<<endl;
}
#endif // !linearArrayThreeSumClosestDoublePointers_