'''
Author: chenbei
Date: 2022-03-15 10:33:01
LastEditTime: 2022-03-15 11:03:56
Description: bubbleSort.py
FilePath: \myLeetCode\coreAlgorithms\bubbleSort.py
A boy without dreams
'''
from typing import Any, List
class bubbleSort:
    def __init__(self,nums:List[int or float],reverse:False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def bubble_sort(self)->List[int or float]:# reverse=false:依次比较后n,n-1,n-2,..2个元素,总是把小的放在前边
        for i in range(self.n-1):
            for j in range(i+1,self.n):
                if self.nums[i]<self.nums[j] if self.reverse else self.nums[j]>self.nums[i]:
                    self.nums[i],self.nums[j]=self.nums[j],self.nums[i]
        return self.nums
    def _bubble_sort(self, arr):# 另一种写法
        for i in range(len(arr)):
            for j in range(len(arr) - i - 1): # reverse=false:这是依次比较前n,n-1,..2个元素,总是把最大的放在后面
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr
if __name__ == '__main__':
    solution = bubbleSort([5,4,3,2,1,9],True)
    print(solution.bubble_sort())