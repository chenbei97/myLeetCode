'''
Author: chenbei
Date: 2022-05-18 17:41:17
LastEditTime: 2022-05-18 17:49:50
Description: linearArrayFullPermutation_Recursion.py
FilePath: \myLeetCode\linearArray\linearArrayFullPermutation_Recursion.py
Signature: A boy without dreams
'''
from typing import List
class linearArrayFullPermutationRecursion:
    def __init__(self) -> None:
        self.res = []
        self.n = 0
    def permute(self,nums:List[int])->List[List[int]]:
        self.n = len(nums)
        self.backTrace(nums,0)
        return self.res
        
    def backTrace(self,nums:List[int],first:int):
        if first == self.n:
            self.res.append(nums.copy()) # 必须带上copy否则保存的都是引用最后都是1,2,3
            return
        for i in range(first,self.n):
            nums[i],nums[first]=nums[first],nums[i] # 改变数组状态
            self.backTrace(nums,first+1) # 递归
            nums[i],nums[first]=nums[first],nums[i] # 撤销操作
if __name__ == '__main__':
    nums = [1,2,3]
    solution = linearArrayFullPermutationRecursion()
    '''
        i = 0,first = 0
        i = 1,first = 1 --> i = 2,first = 1 --> 1,3,2
        i = 2,first = 2--> 1,2,3

        i = 1,first = 0
        i = 1,first = 1 --> i = 2,first = 2 --> 2,3,1
        i = 2,first = 2-->2,1,3

        i = 2,first = 0
        i = 1,first = 1 --> i = 2,first = 2-->3,1,2
        i = 2,first = 2--> 3,2,1
    '''
    ans = solution.permute(nums)
    print(ans)
