#ifndef linearArrayNonRepeatingSubsetRecursion_
#define linearArrayNonRepeatingSubsetRecursion_
#include <iostream>
#include <vector>
using namespace std;
class linearArrayNonRepeatingSubsetRecursion{
    public:
        vector<vector<int>> subsets(vector<int>& nums){
            vector<vector<int>> ans;
            int n = nums.size();
            return ans;
        }
    protected:
        vector<int> t;


};
void _linearArray_nonRepeatingSubset_recursion(){
    linearArrayNonRepeatingSubsetRecursion solution;
    vector<int> nums={1,2,3};
    auto ans = solution.subsets(nums);
    cout<<"recursion=>\n";
    for(auto vec:ans){
        for(int x=0;x<vec.size();x++){
            cout<<vec[x]<<" ";
        }
        cout<<"\n";
    }

}
#endif // !linearArrayNonRepeatingSubsetRecursion_