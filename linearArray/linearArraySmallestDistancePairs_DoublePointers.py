'''
Author: chenbei
Date: 2022-04-01 11:22:10
LastEditTime: 2022-04-01 11:43:00
Description: linearArraySmallestDistancePairs_DoublePointers.py
FilePath: \myLeetCode\linearArray\linearArraySmallestDistancePairs_DoublePointers.py
A boy without dreams
'''
from typing import List
class linearArraySmallestDistancePairsDoublePointers:
    def smallestKDistance(self,nums:List[int],k:int)->int:
        nums.sort()
        leftDist, rightDist = 0, nums[-1] - nums[0]
        while leftDist <= rightDist:
            midDist = (leftDist + rightDist) // 2
            if self.numOfLessThanDistance(nums,midDist) < k:
                leftDist = midDist + 1
            else:
                rightDist = midDist - 1
        return leftDist
    def numOfLessThanDistance(self,nums:List[int],dist:int):
            count = left = 0
            for right in range(len(nums)):
                while nums[right] - nums[left] > dist:
                    left += 1
                count += right - left
            return count

if __name__ == '__main__':
    nums = [1,10,5,23,40,14,2]
    solution = linearArraySmallestDistancePairsDoublePointers()
    ans = solution.smallestKDistance(nums,3)
    print(ans)