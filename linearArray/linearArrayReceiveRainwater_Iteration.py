'''
Author: chenbei
Date: 2022-04-01 13:35:53
LastEditTime: 2022-04-01 15:08:34
Description: linearArrayReceiveRainwater_Iteration.py
FilePath: \myLeetCode\linearArray\linearArrayReceiveRainwater_Iteration.py
A boy without dreams
'''
from typing import List
class linearArrayReceiveRainwaterIteration:
    def trap(self,nums:List[int])->int:
        # 水有多高取决于这个点左侧和右侧墙壁的最大高度
        n = len(nums)
        # 用于记录nums[i]左侧和右侧所有高度的最大值,在范围之外高度认为是0
        # 不要用leftMaxHeight = rightMaxHeight = [0 for _ in range(n)]这相当于是2个引用,结果会有干扰错误
        leftMaxHeight ,rightMaxHeight = [0 for _ in range(n)],[0 for _ in range(n)]
        for i in range(1,n):
            print(leftMaxHeight[i-1],nums[i-1])
            leftMaxHeight[i] = max(leftMaxHeight[i-1],nums[i-1]) # 最大高度总是依据当前高度和以往高度进行比较
            rightMaxHeight[n-1-i] = max(rightMaxHeight[n-i],nums[n-i]) # 初始时leftMaxHeight[0]=rightMaxHeight[n-1]=0
        print(leftMaxHeight)
        print(rightMaxHeight)
        water = 0
        for i in range(1,n-1):# i=0,n-1的wallHeight-nums[i]必定是0无需再判断
            wallHeight = min(leftMaxHeight[i],rightMaxHeight[i]) # 木桶理论
            # 可能比当前i对应的高度小。所以level-height[i]可能是负数
            water += max(0,wallHeight-nums[i]) # 更小的那个墙壁高度减去当前地面高度
        return water
if __name__ == '__main__':
    nums = [0,1,0,2,1,0,1,3,2,1,2,1]
    solution = linearArrayReceiveRainwaterIteration()
    ans = solution.trap(nums)
    print(ans) # 6