'''
Author: chenbei
Date: 2022-04-01 08:52:39
LastEditTime: 2022-04-01 09:07:16
Description: linearArrayIntersection_DoublePointers.py
FilePath: \myLeetCode\linearArray\linearArrayIntersection_DoublePointers.py
A boy without dreams
'''
from typing import List
class linearArrayIntersectionDoublePointers:
    def intersect(self,nums1:List[int],nums2:List[int])->List[int]:
        nums1.sort()
        nums2.sort() # 必须事先有序,双指针的比较法才有意义
        p1,p2 = 0,0
        ans = []
        while p1<len(nums1) and p2<len(nums2):
            if nums1[p1]<nums2[p2]: # 说明能和nums[p2]相等的p1在后面
                p1 += 1
            elif nums1[p1] > nums2[p2]:# 说明能和nums[p1]相等的p2在后面
                p2 += 1
            else:
                ans.append(nums1[p1]) # 相等的元素被添加,然后交集已找到同时前进1个距离继续寻找
                p1 += 1
                p2 += 1
        return ans
if __name__ == '__main__':
    nums1 = [4,9,5]
    nums2 = [9,4,9,8,4]
    solution = linearArrayIntersectionDoublePointers()
    ans = solution.intersect(nums1,nums2)
    print(ans)