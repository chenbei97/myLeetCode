#ifndef linearArraySortedSquareIteration_
#define linearArraySortedSquareIteration_
#include <vector>
#include <algorithm>
using namespace std;
class linearArraySortedSquareIteration{
    public:
        vector<int> sortedSquares(vector<int>&nums){
            vector<int> ans;
            for(auto num : nums){
                ans.push_back(num*num);
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
};
void _linearArray_sortedSquare_iteration(){
    linearArraySortedSquareIteration solution;
    vector<int> nums={-9,-5,-1,2,3,7};
    auto ans = solution.sortedSquares(nums);
    cout<<"iteration =>\n";
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<"\n";
}
#endif // !linearArraySortedSquareIteration