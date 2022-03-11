from typing import List
class linearArrayMajorityElementSort:
    def majorityElement(self,nums:List)->int:
        nums.sort()
        return nums[len(nums)//2]
if __name__ == '__main__':
    a = [5,2,5,5,5,3,2,5,2,5,7,8,5,5]
    solution = linearArrayMajorityElementSort()
    ans = solution.majorityElement(a)
    print("sort=> the majority element is ",ans)