from typing import List
class linearArrayThreeSumClosestIteration :
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = 1e7
        n = len(nums)
        nums.sort()
        for i in range(n):
            if i >0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1,n):
                if j>i+1 and nums[j] == nums[j-1]:
                    continue
                for k in range(j+1,n):
                    if k > j+1 and nums[k] == nums[k-1]:
                        continue
                    delta = abs(nums[i]+nums[j]+nums[k]-target)
                    if delta == 0:
                        return target
                    else :
                        if delta < abs(target-ans):
                            ans = nums[i]+nums[j]+nums[k]
        return ans
if __name__ == '__main__':
    import numpy as np
    a = np.arange(1,101)
    target = 298
    solution = linearArrayThreeSumClosestIteration()
    ans = solution.threeSumClosest(list(a),target)
    print("the ans is ",ans)