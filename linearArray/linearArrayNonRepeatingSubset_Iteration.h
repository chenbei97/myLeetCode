#ifndef linearArrayNonRepeatingSubsetIteration_
#define linearArrayNonRepeatingSubsetIteration_
#include <iostream>
#include <vector>
using namespace std;
class linearArrayNonRepeatingSubsetIteration{
    public:
        vector<vector<int>> subsets(vector<int>& nums){
            // 因为nums元素不重复,所有集合的数量是2^n个
            vector<vector<int>> ans;
            int n = nums.size();
            for(int mask=0;mask<(1<<n);mask++){ //2^n个集合的某个,位为1的说明那个位置数字在集合中
                t.clear();
                for(int i=0;i<n;i++){ // i=0,1,2
                    if (mask& (1<<i)){ // 每个可能和1,10,100,...去与运算
                    // 其实就是依次检测mask的低位到高位是否为0
                    // 不为0说明位置i的元素在集合中
                        t.push_back(nums[i]);
                    }
                }
                ans.push_back(t);
            }
            return ans;
        }
    protected:
        vector<int> t;


};
void _linearArray_nonRepeatingSubset_iteration(){
    linearArrayNonRepeatingSubsetIteration solution;
    vector<int> nums={1,2,3};
    // for(int i =0;i<8;i++){
    //     for(int j =0;j<3;j++){
    //         cout<<"("<<i<<"&"<<(1<<j)<<") = "<<(i&j)<<" ";
    //     }
    //     cout<<"\n";
    // }
    auto ans = solution.subsets(nums);
    cout<<"iteration(bit)=>\n";
    for(auto vec:ans){
        for(int x=0;x<vec.size();x++){
            cout<<vec[x]<<" ";
        }
        cout<<"\n";
    }

}
#endif // !linearArrayNonRepeatingSubsetIteration_