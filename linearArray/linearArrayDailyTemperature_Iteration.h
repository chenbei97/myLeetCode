/*** 
 * @Author: chenbei
 * @Date: 2022-04-12 16:05:26
 * @LastEditTime: 2022-04-12 16:27:30
 * @Description: linearArrayDailyTemperature_Iteration.h
 * @FilePath: \myLeetCode\linearArray\linearArrayDailyTemperature_Iteration.h
 * @Signature: A boy without dreams
 */
#ifndef linearArrayDailyTemperatureIteration_
#define linearArrayDailyTemperatureIteration_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class linearArrayDailyTemperatureIteration{
    public:
        vector<int> dailyTemperature(const vector<int>&nums){
            int n = nums.size(); //数组长度
            vector<int> ans(n), next(101, INT_MAX); // next是元组
            for (int i = n - 1; i >= 0; --i) { // 倒序遍历每个温度nums[i]
                int warmerIndex = INT_MAX; // 目前最大的温度所在索引还是无穷大未知
                for (int t = nums[i] + 1; t <= 100; ++t) {//nums[i]表示的温度开始一直到100°找比nums[i]的最小索引
                    warmerIndex = min(warmerIndex, next[t]); // 总是找到当前最小warmerIndex和下1个值中更小的那个
                }
                // 结果warmerIndex可以找到也可以没找到,首次时next全都是INT_MAX
                // 那么if语句不会执行,然后让next在当前温度nums[i]的位置存放坐标i
                // 下1次warmerIndex就可能找到了,如果nums[i-1]比nums[i]要小,比小是因为对温度倒序的
                // 则上边的for循环范围num[i-1]的搜索范围大于num[i],那么必定会找到那个更新过不为INT_MAX的值
                if (warmerIndex != INT_MAX) {
                    ans[i] = warmerIndex - i; // 倒数第2个温度比倒数第1个温度要小的时候,自然倒数第2个温度后边首次比它大的温度自然是最后1个了
                }
                next[nums[i]] = i; // 这一步是后边的温度比前边的温度小,则正常更新next即可
            }
            return ans;
        }
};
void _linearArray_dailyTemperature_iteration(){
    linearArrayDailyTemperatureIteration solution;
    vector<int> nums = {73,74,75,71,69,72,76,73};
    auto ans = solution.dailyTemperature(nums);
    ostream_iterator<int> os(cout," ");
    cout<<"daily temperature by iteration as follows\n";
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!linearArrayDailyTemperatureIteration_