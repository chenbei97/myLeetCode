#ifndef linearArraySortedSquareDoublePointers_
#define linearArraySortedSquareDoublePointers_
#include <vector>
#include <algorithm>
using namespace std;
class linearArraySortedSquareDoublePointers{
    public:
        vector<int> sortedSquares(vector<int>&nums){
            int n = nums.size();
            int negative = -1;//初始分界线
            for (int i = 0; i < n; ++i) {
                if (nums[i] < 0) {
                    negative = i; // 找到分界线
                } 
                else break;
            }
            vector<int> ans;
            int i = negative, j = negative + 1; // 2个指针指向负数的最大值和正数的最小值
            while (i >= 0 || j < n){//有一个指针没到达终点就继续执行
                if (i < 0) { // 如果负数指针先到达0再次进入i会<0

                    ans.push_back(nums[j] * nums[j]);//j剩余未到达的数统统直接添加即可
                    ++j;
                    if (j>n-1) break;
                }
                else if (j>n-1){ //整数指针先到达n-1,再次进入j就等于n
                    ans.push_back(nums[i]*nums[i]);
                    --i;
                    if (i<0) break;
                }
                else if (abs(nums[i]) < abs(nums[j])){
                    ans.push_back(nums[i]*nums[i]);
                    i--;
                }
                else{
                    ans.push_back(nums[j]*nums[j]);
                    j++;
                }
            }
            return ans;
        }
};
void _linearArray_sortedSquare_doublePointers(){
    linearArraySortedSquareIteration solution;
    vector<int> nums={-9,-5,-1,2,3,7,10};
    auto ans = solution.sortedSquares(nums);
    cout<<"doublePointers =>\n";
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<"\n";
}
#endif // !linearArraySortedSquareDoublePointers