/*** 
 * @Author: chenbei
 * @Date: 2022-04-12 15:32:02
 * @LastEditTime: 2022-04-12 16:01:04
 * @Description: linearArrayDailyTemperature_Stack.h
 * @FilePath: \myLeetCode\linearArray\linearArrayDailyTemperature_Stack.h
 * @Signature: A boy without dreams
 */
#ifndef linearArrayDailyTemperatureStack_
#define linearArrayDailyTemperatureStack_
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
class linearArrayDailyTemperatureStack{
    public:
        vector<int> dailyTemperature(const vector<int>&nums){
            int n = nums.size();
            vector<int> ans(n);
            stack<int> s;
            for (int i = 0; i < n; ++i) {
                while (!s.empty() && nums[i] > nums[s.top()]) { //栈不为空且当前温度比栈顶温度大就把栈顶温度出栈
                    int previousIndex = s.top();//栈维护的是温度索引,栈顶温度总是表示要计算的那个温度,后面有温度比它大就得到了栈顶温度将有几天变成这个温度
                    ans[previousIndex] = i - previousIndex; // 当前温度索引日比上次要计算的栈顶温度大了,就可计算索引差表示相差几天
                    s.pop(); // 那个栈顶元素计算过了就将其出栈,准备计算下1个温度
                }
                s.push(i);
            }
            return ans;
        }
};
void _linearArray_dailyTemperature_statck(){
    linearArrayDailyTemperatureStack solution;
    vector<int> nums = {73,74,75,71,69,72,76,73};
    auto ans = solution.dailyTemperature(nums);
    ostream_iterator<int> os(cout," ");
    cout<<"daily temperature by stack as follows\n";
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!linearArrayDailyTemperatureStack_