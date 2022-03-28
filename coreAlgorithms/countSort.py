'''
Author: chenbei
Date: 2022-03-28 14:49:32
LastEditTime: 2022-03-28 16:23:24
Description: countSort.py
FilePath: \myLeetCode\coreAlgorithms\countSort.py
A boy without dreams
'''
from typing import Any, List
class countSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def count_sort(self)->List[int or float]:
        rank = [0 for i in range(self.n)] # zeros list
        for i in range(1,self.n):
            for j in range(i):#目的是两两不重复的比较元素
                if self.nums[j]>self.nums[i] \
                    if self.reverse else self.nums[j]<=self.nums[i]: #如果是升序,nums[j]<=nums[i],让数值大的排名高
                        rank[i] += 1 # 排名高的体现就是让i这个位置排名+1
                else: rank[j] += 1 # 降序就让数值小的时候提高排名
        if self.reverse:
            for i in reversed(range(self.n)): # 降序
                while rank[i] != i: # 直到排名和索引位置一致(升序)或者反过来(降序)
                    r = rank[i] # 当前nums[i]的排名rank[i]
                    self.nums[i],self.nums[r]=self.nums[r],self.nums[i]
                    rank[i],rank[r]=rank[r],rank[i]
        else:
            for i in range(self.n): # 升序
                while rank[i] != i:
                    r = rank[i] 
                    self.nums[i],self.nums[r]=self.nums[r],self.nums[i]
                    rank[i],rank[r]=rank[r],rank[i]           


if __name__ == '__main__':
    nums = [5,4,3,2,1,0,9]
    solution = countSort(nums,True)
    solution.count_sort()
    print(nums)