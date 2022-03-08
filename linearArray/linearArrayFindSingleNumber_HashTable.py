from collections import defaultdict
from typing import List
class linearArrayFindSingleNumberHashTable:
    def singleNumber(self,nums:List)->int:
        d = defaultdict(int)
        for num in nums:
            d[num]+=1
        for key,value in d.items():
            if value == 1:
                return key
        return 0
if __name__ == '__main__':
    a = [3,2,3,5,5,3,2,5,2,-1]
    solution = linearArrayFindSingleNumberHashTable()
    ans = solution.singleNumber(a)
    print("hashTable=> the single number is ",ans)