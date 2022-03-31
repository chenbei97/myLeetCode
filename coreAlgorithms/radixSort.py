'''
Author: chenbei
Date: 2022-03-28 16:48:34
LastEditTime: 2022-03-31 08:11:05
Description: radixSort.py
FilePath: \myLeetCode\coreAlgorithms\radixSort.py
A boy without dreams
'''
from typing import Any, List
class radixSort:
    def __init__(self,nums:List[int or float],radix=5,reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
        self.radix = radix
    def radix_sort(self)->List[int or float]:
        maxbit = self.maxBitOfRadix()
        for i in range(maxbit):
            buckets = [[] for _ in range(self.radix)]
            for num in self.nums:
                which_bucket = self.whichBucket(num,i)
                if self.reverse:
                    which_bucket = self.radix - 1 - which_bucket
                buckets[which_bucket].append(num)
            self.nums.clear()
            for bucket in buckets:
                for num in bucket:
                    self.nums.append(num)
    def maxBitOfRadix(self)->int:
        maxVal = max(self.nums)
        maxbit = 1
        p = self.radix
        while maxVal>=p:
            p *= self.radix
            maxbit += 1
        return maxbit
    def whichBucket(self,num:int,which_bit:int)->int:
        # 2个方法都可以
        # radix_n = 1 # r^0
        # while which_bit:
        #     radix_n *= self.radix
        #     which_bit -= 1
        # return (num % (self.radix*radix_n)) // radix_n
        return num//(self.radix**which_bit)%self.radix
if __name__ == '__main__':
    nums = [5,4,3,2,1,0,9]
    solution = radixSort(nums,2,True)
    solution.radix_sort()
    print(nums)