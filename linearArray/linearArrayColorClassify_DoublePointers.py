'''
Author: chenbei
Date: 2022-04-01 16:06:27
LastEditTime: 2022-04-01 16:42:38
Description: linearArrayColorClassify_DoublePointers.py
FilePath: \myLeetCode\linearArray\linearArrayColorClassify_DoublePointers.py
A boy without dreams
'''
from typing import List
class linearArrayColorClassifyDoublePointers:
    def sortColors(self,nums:List[int])->None:
        n = len(nums)
        p1,p2 = 0,0
        for i in range(n):
            if nums[i] == 1:
                nums[i],nums[p2] = nums[p2],nums[i]
                p2 +=1
            elif nums[i] == 0:
                nums[i],nums[p1] = nums[p1],nums[i]
                if p1<p2:
                    nums[p2],nums[i] = nums[i],nums[p2]
                p1 += 1
                p2 += 1
if __name__ == '__main__':
    nums = [2,0,2,1,1,0,2,0,1,2,0,0,2]
    solution = linearArrayColorClassifyDoublePointers()
    solution.sortColors(nums)
    print(nums)