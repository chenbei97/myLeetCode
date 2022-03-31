'''
Author: chenbei
Date: 2022-03-31 15:41:35
LastEditTime: 2022-03-31 16:19:05
Description: linearArrayFourSum_DoublePointers.py
FilePath: \myLeetCode\linearArray\linearArrayFourSum_DoublePointers.py
A boy without dreams
'''
from typing import List
class linearArrayFourSumDoublePointers:
    def fourSum(self,nums:List[int],target:int)->List[List[int]]:
        if not nums or len(nums) < 4:
            return  []
        nums.sort() # 有序是去重的前提
        ans = []
        # 首先固定第一个元素，要求first+3<=len(nums)-1,故first<=len(nums)-4
        for first in range(len(nums) - 3):# first取到len(nums-4)对应(len(nums)-3)
            # first不能为0,因为nums[first-1]要使用
            if first > 0 and nums[first] == nums[first - 1]: # 连续的2个值相等说明重复
                continue
            # 固定第2个元素second,同理second+2<=len(nums)-1,故second<=len(nums)-3
            for second in range(first + 1, len(nums) - 2):
                if second > first + 1 and nums[second] == nums[second - 1]: 
                    # 同样连续的2个第二元素相同就跳过
                    continue
                # 双指针确定第3,4个元素
                third = second + 1 # 固定的第2个元素后边
                fourth = len(nums) - 1 # 右端向前
                while third < fourth:
                    if nums[first] + nums[second] + nums[third] + nums[fourth] > target:
                        fourth -= 1 # 偏大需要让fourth前移,因为数组有序,可保证target缩小一些
                    elif nums[first] + nums[second] + nums[third] + nums[fourth] < target:
                        third += 1 # 偏小让third前移,可以变大
                    else: # 相等时,因为有third和fourth2个变量,所以可能存在多种相等情况还要继续考虑前移或后移
                        ans.append([nums[first], nums[second], nums[third], nums[fourth]])
                        # 右移指针，确保跳过重复元素
                        while third < fourth and nums[third] == nums[third + 1]:
                            third += 1 # 如果thrid<fourth,且third和后1个值相等就后移third继续判断
                        # 左移指针，确保跳过重复元素
                        while third < fourth and nums[fourth] == nums[fourth - 1]:
                            fourth -= 1 # 如果thrid<fourth,且fourth和前1个值相等就前移fourth继续判断
                        third += 1 # 正常也应该尝试前移和后移
                        fourth -= 1
        return ans
if __name__ == '__main__':
    nums = [1,0,-1,0,-2,2]
    target = 0
    solution = linearArrayFourSumDoublePointers()
    ans = solution.fourSum(nums,target)
    print(ans)