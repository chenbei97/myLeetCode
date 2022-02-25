from typing import List
from collections import defaultdict
class linearArrayTwoSumHashTable:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 哈希表在Python就是字典
        n = len(nums)
        if n < 2 : return [-1,-1]
        # 为了动态添加字典关键字使用defaultdict
        hashTable = defaultdict(int)
        for idx,val in enumerate(nums):
            hashTable[val] = idx # 索引是value,元素为key
        for idx,val in enumerate(nums):
            exist = hashTable[target-val] # 返回的是索引
            if exist and exist != idx:
                return [idx,exist]
        return [-1,-1]
                
if __name__ == '__main__':
    a = [1,4,2,78,32,23,45,0,9]
    solution = linearArrayTwoSumHashTable()
    print("two sum is ",solution.twoSum(a,9))