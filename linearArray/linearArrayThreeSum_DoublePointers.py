from typing import List
class linearArrayThreeSumDoublePointers:
    def threeSum(self, nums: List[int]) -> List[List[int]]: # 768 ms
        if len(nums) <3 : return []
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i> 0 and nums[i]==nums[i-1]:
                continue
            k = len(nums)-1 # 右端指针
            for j in range(i+1,len(nums)): # 随着b的增加
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                while k > j and nums[j] + nums[k] + nums[i] > 0:
                    k -= 1
                if k == j: # 如果c退到了b不会再有这样的b和c,因为b只会更大,且c又不能比b小,所以直接break
                    break
                if nums[j] + nums[k] + nums[i] == 0:
                    ans.append([nums[j],nums[k],nums[i]])
        return ans
if __name__ == '__main__':
    a = [-2,5,-3,-1,-4,7,4,0,8] 
    solution = linearArrayThreeSumDoublePointers()
    ans = solution.threeSum(a)
    for k in ans :
        print(k)
    print()
    a = [-1,0,1,2,-1,-4]
    ans = solution.threeSum(a)
    for k in ans :
        print(k)