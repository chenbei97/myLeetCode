'''
Author: chenbei
Date: 2022-04-14 15:35:15
LastEditTime: 2022-04-14 15:42:07
Description: linearArrayKNearestDist_Sort.py
FilePath: \myLeetCode\linearArray\linearArrayKNearestDist_Sort.py
Signature: A boy without dreams
'''
from typing import List
class linearArrayKNearestDistSort:
    def kNearestDist(self,nums:List[List[int]],k:int)->List[List[int]]:
        sort_method = lambda x: (x[0] ** 2 + x[1] ** 2 ) # python不需要,提供reverse选项
        nums.sort(key=sort_method)
        return nums[:k]

if __name__ == '__main__':
    nums = [[1,1],[3,4],[-3,4],[5,5],[3,7],[10,6]]
    solution = linearArrayKNearestDistSort()
    ans = solution.kNearestDist(nums,3)
    for point in ans :
        print(point)