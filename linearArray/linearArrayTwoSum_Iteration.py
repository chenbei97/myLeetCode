from typing import List
class linearArrayTwoSumIteration:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n<2 : return [-1,-1]
        for i in range(n):
            if i == n-1 :
                return [-1,-1]
            for j in range(i+1,n):
                if nums[i]+nums[j] == target :
                    return [i,j]
        return [-1,-1]
if __name__ == '__main__':
    a = [1,4,2,78,32,23,45,0,9]
    
    solution = linearArrayTwoSumIteration()
    print("two sum is ",solution.twoSum(a,9))
