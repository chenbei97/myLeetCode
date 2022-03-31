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
        n = len(nums)
        ans = [1 for _ in range(n)]
        left = right = 1
        for i in range(n):
            ans[i] = left
            left *= nums[i]
        for i in range(n - 1, -1, -1):
            ans[i] *= right
            right *= nums[i]
        return ans
if __name__ == '__main__':
    nums = [1,2,3,4]
    solution = linearArrayProductExceptSelfIteration()
    ans = solution.productExceptSelf(nums)
    print(ans) # [24,12,8,6]