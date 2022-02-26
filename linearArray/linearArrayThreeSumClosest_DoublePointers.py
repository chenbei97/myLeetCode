from typing import List
class linearArrayThreeSumClosestDoublePointers :
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = 1e7
        n = len(nums)
        nums.sort()
        for i in range(n):
            if (i>0 and nums[i] == nums[i-1]):
                continue
            j,k = i+1,n-1
            while j<k :
                s = nums[i]+nums[j]+nums[k]
                if s-target == 0:
                    return target
                if abs(s-target) < abs(ans-target):
                    ans = s
                if s-target > 0:
                    k -= 1 # k减小可以减小差值
                if s-target < 0:
                    j += 1 # j增加可以增大差值
        return ans
if __name__ == '__main__':
    import numpy as np
    a = np.arange(1,101)
    target = 298
    solution = linearArrayThreeSumClosestDoublePointers()
    ans = solution.threeSumClosest(list(a),target)
    print("the ans is ",ans)