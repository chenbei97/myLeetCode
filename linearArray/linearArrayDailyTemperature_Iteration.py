'''
Author: chenbei
Date: 2022-04-12 16:05:33
LastEditTime: 2022-04-12 16:05:33
Description: linearArrayDailyTemperature_Iteration.py
FilePath: \myLeetCode\linearArray\linearArrayDailyTemperature_Iteration.py
@Signature: A boy without dreams
'''
from typing import List
class linearArrayDailyTemperatureStack:
    def dailyTemperature(self,nums:List[int])->List[int]:
        n = len(nums)
        ans, nxt, big = [0] * n, dict(), 10**9
        for i in range(n - 1, -1, -1): # 倒序遍历温度数组
            warmer_index = min(nxt.get(t, big) for t in range(nums[i] + 1, 102)) # 找到比当前温度小的那个最小的温度
            if warmer_index != big:
                ans[i] = warmer_index - i
            nxt[nums[i]] = i 
        return ans
if __name__ == '__main__':
    nums = [73,74,75,71,69,72,76,73]
    solution = linearArrayDailyTemperatureStack()
    ans = solution.dailyTemperature(nums)
    print(ans)