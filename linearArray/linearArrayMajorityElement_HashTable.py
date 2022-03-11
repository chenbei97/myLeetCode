from typing import List
from collections import defaultdict
class linearArrayMajorityElementHashTable:
    def majorityElement(self,nums:List)->int:
        d = defaultdict(int)
        for num in nums:
            d[num] += 1
        maxKey = nums[0]
        maxVal = d[maxKey]
        for num in nums[1:]:
            if d[num]>maxVal:
                maxVal = d[num]
                maxKey = num
        return maxKey
if __name__ == '__main__':
    a = [5,2,5,5,5,3,2,5,2,5,7,8,5,5]
    solution = linearArrayMajorityElementHashTable()
    ans = solution.majorityElement(a)
    print("hashTable=> the majority element is ",ans)