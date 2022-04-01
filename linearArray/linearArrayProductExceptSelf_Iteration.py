'''
Author: chenbei
Date: 2022-03-31 16:32:13
LastEditTime: 2022-03-31 16:47:21
Description: linearArrayProductExceptSelf_Iteration.py
FilePath: \myLeetCode\linearArray\linearArrayProductExceptSelf_Iteration.py
A boy without dreams
'''
from typing import List
class linearArrayProductExceptSelfIteration:
    def productExceptSelf(self,nums:List[int])->List[int]:
        # 双数组的写法不在给出,参考c++的写法
        n = len(nums)
        ans = [1 for _ in range(n)]
        left = right = 1
        # for i in range(n): # ans先存储每个nums[i]的左边元素乘积
        #     ans[i] = left # ans[0]=1,left初始化为1的原因,left计算完用于下一次的left计算,即left=left*nums[0]
        #     left *= nums[i] # left是nums[0]..nums[n-1]的动态乘积,nums[0]用于下一次的left计算
        # for i in range(n - 1, -1, -1):# ans再依次和右边元素的乘积相乘计算,但是倒序计算
        #     ans[i] *= right # ans[n-1]=1,因为nums[n-1]右边没有元素,right初始化为1的意义
        #     right *= nums[i] # right是nums[n-1]...nums[0]的动态乘积,nums[n-1]是用于right=nums[n-1]*right的下一次计算
        for i in range(1,n):
            left *= nums[i-1] # left取nums[0]...nums[n-1]的动态乘积
            right *= nums[n-i] # right取nums[n-1]...nums[1]的动态乘积
            ans[i] *= left # 同时更新ans的头部和尾部,等left到右边时右边已恭候多时ans[left]早就是那个元素后边的乘积了,left是左边元素乘积
            ans[n-1-i] *= right # right到左边时,ans[right]早就存储了元素之前的乘积,right是该元素右边的乘积
        return ans
if __name__ == '__main__':
    nums = [1,2,3,4]
    solution = linearArrayProductExceptSelfIteration()
    ans = solution.productExceptSelf(nums)
    print(ans) # [24,12,8,6]