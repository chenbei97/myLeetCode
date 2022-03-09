#ifndef linearArrayNonRepeatingSubsetRecursion_
#define linearArrayNonRepeatingSubsetRecursion_
#include <iostream>
#include <vector>
using namespace std;
class linearArrayNonRepeatingSubsetRecursion{
    public:
        vector<vector<int>> subsets(vector<int>& nums){
            dfs(0, nums);
            return ans;
        }
        void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) { //cur进入下次递归之前,[0,cur-1]的位置状态是确定的
            ans.push_back(t); // 所有状态确定好后就会记录答案返回
            return;
        }
        t.push_back(nums[cur]); // 选择这个位置的元素
        dfs(cur + 1, nums);// 最开始会1路到底,元素全部选择
        t.pop_back(); // 从全1开始退栈,1个1个的放弃,放弃1个元素的时候可以放弃任意一个,都是1个可能
        dfs(cur + 1, nums); // 故最终递归时间复杂度O(2^n)
    }
    protected:
        vector<vector<int>> ans;
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