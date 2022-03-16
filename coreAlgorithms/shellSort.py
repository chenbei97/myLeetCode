'''
Author: chenbei
Date: 2022-03-16 08:47:20
LastEditTime: 2022-03-16 09:58:07
Description: shellSort.py
FilePath: \myLeetCode\coreAlgorithms\shellSort.py
A boy without dreams
'''
from typing import List,Any
class shellSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def shell_sort(self)->List[int or float]:
        gap = self.n // 2
        while gap>0:
            '''************code below similar to insertSort************'''
            for i in range(gap,self.n): # [0,gap-1]对应gap个子序列的有序部分,[gap,n-1]是无序部分的第1个元素
                t = self.nums[i]
                idx = i - gap # ∈[0,gap-1],确保子序列能取到有序部分的第1个元素
                while idx+gap>0 and (self.nums[idx]<t if self.reverse else self.nums[idx]>t):
                    self.nums[idx+gap] = self.nums[idx] # 后1个元素被前1个相隔gap的元素依次覆盖
                    idx -= gap
                self.nums[idx+gap] = t # 腾出来的位置,但是idx多减了1次gap要加回来
            '''************code above similar to insertSort************'''       
            gap //= 2
        return self.nums
if __name__ == '__main__':
    solution = shellSort([5,4,3,2,1,9],True)
    print(solution.shell_sort())