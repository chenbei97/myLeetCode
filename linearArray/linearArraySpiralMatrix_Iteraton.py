'''
Author: chenbei
Date: 2022-03-31 10:40:41
LastEditTime: 2022-03-31 12:39:33
Description: linearArraySpiralMatrix_Iteraton.py
FilePath: \myLeetCode\linearArray\linearArraySpiralMatrix_Iteraton.py
A boy without dreams
'''
from typing import List
class linearArraySpiralMatrixIteraton:
    def spiralOrder(self,nums:List[List[int]]):
        ans = []
        rows,cols = len(nums),len(nums[0])
        top,left,right,bottom = 0,0,cols-1,rows-1
        while top<=bottom and left<=right:
            for col in range(left,right+1): # +1是因为right也要访问到
                ans.append(nums[top][col]) # top行 [left,right]
            for row in range(top+1,bottom+1): # right列 [top+1,bottom]
                ans.append(nums[row][right])
            if top<bottom and left<right:
                for col in reversed(range(left,right)): # bottom行 [left,right-1]
                    ans.append(nums[bottom][col])
                for row in reversed(range(top+1,bottom)): # left列 [top+1,bottom-1]
                    ans.append(nums[row][left])
            top += 1
            bottom -= 1
            left += 1
            right -= 1
        return ans
if __name__ == '__main__':
    nums = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    solution = linearArraySpiralMatrixIteraton()
    ans = solution.spiralOrder(nums) # [1,2,3,4,8,12,11,10,9,5,6,7]
    print(ans)