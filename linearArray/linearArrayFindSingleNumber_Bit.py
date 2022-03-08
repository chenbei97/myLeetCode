from typing import List
class linearArrayFindSingleNumberBit:
     def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            total = sum((num >> i) & 1 for num in nums)
            if total % 3:
                # Python 这里对于最高位需要特殊判断
                if i == 31:
                    ans -= (1 << i)
                else:
                    ans |= (1 << i)
        return ans
if __name__ == '__main__':
    a = [3,2,3,5,5,3,2,5,2,-1]
    solution = linearArrayFindSingleNumberBit()
    ans = solution.singleNumber(a)
    print("hashTable=> the single number is ",ans)