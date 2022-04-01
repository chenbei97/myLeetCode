/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 16:31:58
 * @LastEditTime: 2022-04-01 08:04:14
 * @Description: linearArrayProductExceptSelf_Iteration.h
 * @FilePath: \myLeetCode\linearArray\linearArrayProductExceptSelf_Iteration.h
 * @A boy without dreams
 */
#ifndef linearArrayProductExceptSelfIteration_
#define linearArrayProductExceptSelfIteration_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class linearArrayProductExceptSelfIteration{
    public:
        vector<int> roductExceptSelf(vector<int>&nums){
            // 创建两个数组,一个用于记录某元素前所有元素的乘积
            // 一个用于记录某元素后所有元素的乘积
            // 最后两个数组的元素进行逐元素相乘即可其实就得到nums每个元素以外的所有元素乘积
            /*
                ostream_iterator<int> os(cout," ");
                int n = nums.size();
                vector<int> left(n, 1); // 初始化为1是为了方便相乘
                vector<int> right(n, 1);
                vector<int> res(n, 1);
                // for(int i = 1; i < nums.size(); i++) 
                //     //从left[i]i≥1,开始总是存储nums[i]之前的元素乘积,i=1开始,left[0]=1已初始化
                //     left[i] = left[i-1] * nums[i-1]; 
                // for(int j = nums.size()-2; j>=0; j--)
                //     //从right[j]j<=n-2,开始总是存储nums[j]之后的元素乘积,j=n-2开始,left[n-1]=1已初始化
                //     right[j] = right[j+1] * nums[j+1];
                for(int i =1;i<nums.size();++i){
                    // 上述2个for循环写成1个也对
                    left[i] = left[i-1] * nums[i-1];
                    right[n-1-i] = right[n-i] * nums[n-i]; 
                }
                for(int i = 0; i<nums.size(); i++)
                    res[i] = left[i] * right[i];
                copy(left.begin(),left.end(),os);
                cout<<"\n";// 1 1 2 6 =[1,1*1,1*2,2*3]=[1,left[0]*nums[0],left[1]*nums[1],left[2]*nums[2]]
                copy(right.begin(),right.end(),os);
                cout<<"\n";// 24 12 4 1 = [right[3]*nums[3],right[2]*nums[2],right[3]*nums[3],1]
                return res;
            */
            
            // 优化的写法,不再使用2个数组,只需要2个数动态的等于nums[i]之前和之后的乘积即可
            int n = nums.size();
            vector<int> ans(n);
            int left=1,right=1;
            for(int i=0;i<n;++i){//ans先存储每个nums[i]的左边元素乘积
                ans[i] = left; // ans[0]=1,left初始化为1的原因,left计算完用于下一次的left计算,即left=left*nums[0]
                left *= nums[i];//left是nums[0]..nums[n-1]的动态乘积,nums[0]用于下一次的left计算
            }
            for (int i=n-1;i>=0;--i){ //ans再依次和右边元素的乘积相乘计算,但是倒序计算
                ans[i] *= right;// ans[n-1]=1,因为nums[n-1]右边没有元素,right初始化为1的意义
                right *= nums[i]; // right是nums[n-1]...nums[0]的动态乘积,nums[n-1]是用于right=nums[n-1]*right的下一次计算
            }
            // 也是合并2个for的写法
            // for(int i =1;i<nums.size();++i){
            //     left *= nums[i-1]; // left取nums[0]...nums[n-1]的动态乘积
            //     right *= nums[nums.size()-i];//right取nums[n-1]...nums[1]的动态乘积
            //     ans[i] *= left; // 同时更新ans的头部和尾部,等left到右边时右边已恭候多时ans[left]早就是那个元素后边的乘积了,left是左边元素乘积
            //     ans[nums.size()-1-i] *= right;// right到左边时,ans[right]早就存储了元素之前的乘积,right是该元素右边的乘积
            // }
            return ans;
        }
};
void _linearArray_productExceptSelf_iteration(){
    linearArrayProductExceptSelfIteration solution;
    vector<int> nums = {1,2,3,4};
    auto ans = solution.roductExceptSelf(nums);
    ostream_iterator<int> os(cout," ");
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!linearArrayProductExceptSelfIteration_