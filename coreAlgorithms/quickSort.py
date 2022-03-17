'''
Author: chenbei
Date: 2022-03-17 14:07:01
LastEditTime: 2022-03-17 14:40:17
Description: quickSort.py
FilePath: \myLeetCode\coreAlgorithms\quickSort.py
A boy without dreams
'''
from typing import List,Any
class quickSort:
    def __init__(self,nums:List[int or float],reverse=False) -> None:
        self.nums = nums
        self.reverse = reverse
    def quick_sort(self,low:int,high:int)->Any:
        if low<high: # 递归终止条件
            pivotIdx = self.partition_new(low,high)
            self.quick_sort(low,pivotIdx-1)
            self.quick_sort(pivotIdx+1,high)
    def partition(self,low:int,high:int)->int:
        pivot = self.nums[low]
        while low < high:
            # 从后往前捋,找到右边不符合降序/升序条件的元素移动到基准值左边
            while low<high and (self.nums[high]<=pivot if self.reverse else self.nums[high]>=pivot):
                high -= 1 # high前移,降序时是后面的元素确实小于前面的元素才会前移,升序时反之
            self.nums[low] = self.nums[high] # 把不符合条件的元素挪到基准值及其前边使之符合条件
            # 从前往后捋,找到左边不符合降序/升序条件的元素移动到基准值右边
            while low<high and (self.nums[low]>=pivot if self.reverse else self.nums[low]<=pivot):
                low += 1
            self.nums[high] = self.nums[low]# 把不符合条件的元素挪到基准值及其后边使之符合条件
        self.nums[low] = pivot # 此时low位置左边和右边的所有元素都满足了降序/升序要求
        return low
    def partition_new(self,low:int,high:int)->int:
        pivot = self.nums[low]
        behindPivotIdx = low + 1
        i = low + 1
        while i <= high:
            if self.nums[i]>=pivot if self.reverse else self.nums[i]<=pivot:
                # 目的是把满足升序/降序条件的元素移动到当前基准值位置low的后面
                self.nums[i],self.nums[behindPivotIdx]=self.nums[behindPivotIdx],self.nums[i]
                behindPivotIdx += 1 
            i += 1 # 元素不满足条件就在原地,无需移动
        # 把临界点behindPivotIdx的元素和基准值交换,此时基准值新位置前与后的元素都满足比基准值大或小
        self.nums[low],self.nums[behindPivotIdx-1]=self.nums[behindPivotIdx-1],self.nums[low]
        return behindPivotIdx-1    
    def setReverse(self,reverse=False)->None:
        self.reverse = reverse
if __name__ == '__main__':
    nums = [2,6,10,4,8,12,-1,3]
    solution = quickSort(nums,False)
    solution.quick_sort(0,7)
    print(nums)
    solution.setReverse(True)
    solution.quick_sort(0,7)
    print(nums)