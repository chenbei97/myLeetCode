from typing import List
class linearArrayMaxSubArrayIteration:
    def maxSubArray(self,nums:List)->int:
        n = len(nums)
        ans = []
        for i in range(n):
            subArraySum = nums[i] # 某个子数组的末尾元素
            ans.append(subArraySum)
            for j in reversed(range(i)):
                subArraySum += nums[j] # 从这个末尾元素连续的向前计算,每合并1个元素就添加进答案
                ans.append(subArraySum)
        return max(ans)

if __name__ == '__main__':
    a = [-2,1,-3,4,-1,2,1,-5,4]
    solution = linearArrayMaxSubArrayIteration()
    ans = solution.maxSubArray(a)
    print("the maxSubArray sum is ",ans)