'''
Author: chenbei
Date: 2022-04-12 16:02:36
LastEditTime: 2022-04-12 16:05:05
Description: linearArrayDailyTemperature_Stack.py
FilePath: \myLeetCode\linearArray\linearArrayDailyTemperature_Stack.py
Signature: A boy without dreams
'''
from typing import List
class linearArrayDailyTemperatureStack:
    def dailyTemperature(self,nums:List[int])->List[int]:
        length = len(nums)
        ans = [0] * length
        stack = []
        for i in range(length):
            temperature = nums[i]
            # 栈不为空且当前温度比栈顶温度大就把栈顶温度出栈
            while stack and temperature > nums[stack[-1]]:
                # 栈维护的是温度索引,栈顶温度总是表示要计算的那个温度
                prev_index = stack.pop() # 后面有温度比它大就得到了栈顶温度将有几天变成这个温度
                # 当前温度索引日比上次要计算的栈顶温度大了,就可计算索引差表示相差几天
                ans[prev_index] = i - prev_index # 那个栈顶元素计算过了就将其出栈,准备计算下1个温度
            stack.append(i)
        return ans
if __name__ == '__main__':
    nums = [73,74,75,71,69,72,76,73]
    solution = linearArrayDailyTemperatureStack()
    ans = solution.dailyTemperature(nums)
    print(ans)