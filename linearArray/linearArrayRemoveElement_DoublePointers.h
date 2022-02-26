#ifndef linearArrayRemoveElementDoublePointers_
#define linearArrayRemoveElementDoublePointers_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class linearArrayRemoveElementDoublePointers{
    public:
        int removeElement(vector<int>& nums, int val) {
            int left=0,right=0;
            int n = nums.size();
            while (right < n ){
                if (nums[right] != val){
                    nums[left] = nums[right];
                    left++;
                }
                right++;
            }
            return left;
        }
};
void _linearArray_removeElement_doublePointers(){
    linearArrayRemoveElementDoublePointers solution;
    vector<int> nums ={1,2,2,3,3,6,3,7,9,10,4,3,2,3};
    int size = solution.removeElement(nums,3);
    for (int i = 0 ; i< size; i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n"; 
}
#endif // !linearArrayRemoveElementDoublePointers_