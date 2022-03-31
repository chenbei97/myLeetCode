'''
Author: chenbei
Date: 2022-03-31 09:58:01
LastEditTime: 2022-03-31 10:24:15
Description: linearArrayMoveZerosToEnd_DoublePointers.py
FilePath: \myLeetCode\linearArray\linearArrayMoveZerosToEnd_DoublePointers.py
A boy without dreams
'''
from typing import List
class linearArrayMoveZerosToEndDoublePointers:
    def moveZeros(self,nums:List[int]):
        left,n = 0,len(nums)
        for right in range(n):
            if nums[right]!=0:
                nums[left],nums[right]=nums[right],nums[left]
                left += 1
if __name__ == '__main__':
    nums = [0,1,3,0,5,6,0,-2,-5,0,10]
    solution = linearArrayMoveZerosToEndDoublePointers()
    solution.moveZeros(nums)
    print(nums)