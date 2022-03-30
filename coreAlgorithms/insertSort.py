'''
Author: chenbei
Date: 2022-03-15 13:38:50
LastEditTime: 2022-03-30 12:25:09
Description: insertSort.py
FilePath: \myLeetCode\coreAlgorithms\insertSort.py
A boy without dreams
'''
from typing import List,Any
class insertSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def insert_sort(self)->List[int or float]:
        for i in range(1,self.n):
            idx = i-1 # 当前未排序的第1个元素的前1个
            t = self.nums[i] # 事先未排序的第1个元素,因为这个位置可能会被前1个元素替换
            # 让idx+1>0是为了让idx能取到0不退出while
            # 这样可以继续比较第0个元素和t,来决定t放在0前还是0后
            # while后边要加小括号,注意and优先级高
            while idx+1 > 0 and (self.nums[idx]<t \
                if self.reverse else self.nums[idx]>t):# reverse=True:前边的小交换说明是降序
                    self.nums[idx+1]=self.nums[idx] # 从未排序的第1个元素开始向前,总是让前1个元素替换后1个元素
                    idx -= 1 # idx∈[0,i-1],i-1替换i,i-2替换i-1,直到idx替换idx+1,idx的位置就空出来被t替换
            self.nums[idx+1] = t # idx的位置就空出来被t替换,因为while结束idx多减了1,所以用idx+1
if __name__ == '__main__':
    nums = [5,4,3,2,1,9]
    solution = insertSort(nums,True)
    solution.insert_sort()
    print(nums)