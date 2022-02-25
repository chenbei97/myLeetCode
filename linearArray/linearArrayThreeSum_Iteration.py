from typing import List
class linearArrayThreeSumIteration:
    def threeSum(self, nums: List[int]) -> List[List[int]] :
        if len(nums) <3 : return []
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i> 0 and nums[i]==nums[i-1]:
                continue
            for j in range(i+1,len(nums)):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                for k in range(j+1,len(nums)):
                    if k > j+1 and nums[k] == nums[k-1]:
                        continue
                    if nums[i]+nums[j]+nums[k] == 0:
                        ans.append([nums[i],nums[j],nums[k]])
        return ans
if __name__ == '__main__':
    a = [-2,5,-3,-1,-4,7,4,0,8] # [-4,-3,-2-1,0,4,5,7,8]
    solution = linearArrayThreeSumIteration()
    ans = solution.threeSum(a)
    for k in ans :
        print(k)
