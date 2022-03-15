'''
Author: chenbei
Date: 2022-03-15 11:40:12
LastEditTime: 2022-03-15 15:05:04
Description: selectSort.py
FilePath: \myLeetCode\coreAlgorithms\selectSort.py
A boy without dreams
'''
from typing import List,Any
class selectSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def select_sort(self)->List[int or float]:
        for i in range(self.n-1):
            idx = i # 记录当前未分类的第1个元素
            for j in range(i+1,self.n):
                if self.nums[i]<self.nums[j] if self.reverse \
                    else self.nums[i]>self.nums[j]:# reverse=False是有更小的元素交换
                    idx = j
            if idx != i:
                self.nums[idx],self.nums[i]=self.nums[i],self.nums[idx]
        return self.nums
if __name__ == '__main__':
    solution = selectSort([5,4,3,2,1,9],True)
    print(solution.select_sort())