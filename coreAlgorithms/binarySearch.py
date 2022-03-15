'''
Author: chenbei
Date: 2022-03-15 09:04:38
LastEditTime: 2022-03-15 10:00:10
Description: binary search
FilePath: \myLeetCode\coreAlgorithms\binarySearch.py
A boy without dreams
'''
from typing import Any, List
class binarySearch:
    def __init__(self,nums:List[int or float],target:int or float) -> Any:
        self.nums = nums
        self.nums.sort()
        self.target = target
    def search(self) -> int:
        left,right = 0,len(self.nums)-1
        while left<=right:
            mid = (left+right) // 2
            if self.nums[mid] == self.target:
                return mid
            if self.nums[mid] < self.target: # target∈[mid+1,right]
                left = mid + 1
            if self.nums[mid] > self.target: # target∈[left,mid-1]
                right = mid - 1
        return -1
    def sorted(self,reverse=False)->List[int or float]:
        if reverse:
            self.nums.sort(reverse=True)
        return self.nums
if __name__ == '__main__':
    solution1 = binarySearch([1.5,2,3.1,4.5,6.7,9.4,-12,-5.2],9.4)
    ans = solution1.sorted()
    print(ans)
    print("9.4's idx in sorted nums is ",solution1.search())
    solution2 = binarySearch([1.5,2,3.1,4.5,6.7,9.4,-12,-5.2],9.3)
    print("9.3's idx in sorted is ",solution2.search())