#ifndef linearArrayThreeSumClosestIteration_
#define linearArrayThreeSumClosestIteration_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayThreeSumClosestIteration{
    public : 
        int threeSumClosest(vector<int>& nums, int target){

        }
};
void _linearArray_threeSumClosest_iteration(){
    linearArrayThreeSumClosestIteration solution;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int ans = solution.threeSumClosest(nums,target);
    cout << "the ans is "<<ans<<endl;
}
#endif // !linearArrayThreeSumClosestIteration_