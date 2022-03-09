from typing import List
class linearArrayNonRepeatingSubsetIteration:
    def subsets(self,nums:List)->List[List]:
        ans = []
        n = len(nums)
        for i in range(1<<n): # 2^n个可能
            t = []
            for j in range(n): # 1<<j用于检测i的每个位,从低位到高位
                if i & (1<<j):
                    t.append(nums[j]) # 不为0说明nums[j]在集合里
            ans.append(t)
        return ans

if __name__ == '__main__':
    a = [1,2,3]
    solution = linearArrayNonRepeatingSubsetIteration()
    ans = solution.subsets(a)
    for x in ans:
        print(x)