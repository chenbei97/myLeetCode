'''
Author: chenbei
Date: 2022-04-01 16:17:23
LastEditTime: 2022-04-01 16:26:39
Description: linearArrayColorClassify_Iteration.py
FilePath: \myLeetCode\linearArray\linearArrayColorClassify_Iteration.py
A boy without dreams
'''
from typing import List
class linearArrayColorClassifyIteration:
    def sortColor(self,nums:List[int])->List[int]:
        n = len(nums)
        ptr = 0
        for i in range(n):
            if nums[i] == 0 :
                nums[i],nums[ptr]=nums[ptr],nums[i]
                ptr += 1
        for i in range(ptr,n):
            if nums[i] == 1:
                nums[i],nums[ptr]=nums[ptr],nums[i]
                ptr += 1
if __name__ == '__main__':
    nums = [2,0,2,1,1,0,2,0,1,2,0,0,2]
    solution = linearArrayColorClassifyIteration()
    solution.sortColor(nums)
    print(nums)