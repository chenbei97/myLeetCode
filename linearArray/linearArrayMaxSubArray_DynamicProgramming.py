from typing import List
class linearArrayMaxSubArrayDynamicProgramming:
    def maxSubArray(self,nums:List)->int:
        pre,maxAns=0,nums[0]
        for num in nums:
            pre = max(pre+num,num)
            maxAns = max(maxAns,pre)
        return maxAns
if __name__ == '__main__':
    a = [5,2,5,5,5,3,2,5,2,5,7,8,5,5]
    solution = linearArrayMaxSubArrayDynamicProgramming()
    ans = solution.maxSubArray(a)
    print("the maxSubArray sum is ",ans)