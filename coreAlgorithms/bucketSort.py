'''
Author: chenbei
Date: 2022-03-28 16:46:49
LastEditTime: 2022-03-28 16:51:43
Description: bucketSort.py
FilePath: \myLeetCode\coreAlgorithms\bucketSort.py
A boy without dreams
'''
from typing import Any, List
class bucketSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def bucket_sort(self)->List[int or float]:
        pass


if __name__ == '__main__':
    nums = [5,4,3,2,1,0,9]
    solution = bucketSort(nums,True)
    solution.bucket_sort()
    print(nums)