'''
Author: chenbei
Date: 2022-03-28 16:48:34
LastEditTime: 2022-03-28 16:50:49
Description: cardinalitySort.py
FilePath: \myLeetCode\coreAlgorithms\cardinalitySort.py
A boy without dreams
'''
from typing import Any, List
class cardinalitySort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def cardinality_sort(self)->List[int or float]:
        pass


if __name__ == '__main__':
    nums = [5,4,3,2,1,0,9]
    solution = cardinalitySort(nums,True)
    solution.cardinality_sort()
    print(nums)