'''
Author: chenbei
Date: 2022-03-17 14:56:27
LastEditTime: 2022-03-17 14:57:43
Description: heapSort.py
FilePath: \myLeetCode\coreAlgorithms\heapSort.py
A boy without dreams
'''
from typing import List,Any
class heapSort:
    def __init__(self,nums:List[int or float],reverse=False) -> None:
        self.nums = nums
        self.reverse = reverse
    def heap_sort(self)->Any:
        pass
    def setReverse(self,reverse=False)->None:
        self.reverse = reverse
if __name__ == '__main__':
    nums = [2,6,10,4,8,12,-1,3]
    solution = heapSort(nums,False)
    solution.heap_sort(0,7)
    print(nums)
    solution.setReverse(True)
    solution.heap_sort(0,7)
    print(nums)