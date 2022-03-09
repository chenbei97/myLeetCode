from typing import List
class linearArrayNonRepeatingSubsetRecursion:
    def subsets(self,nums:List)->List[List]:
        ans = []
        t = []
        def loop(cur,nums):
            if len(nums) == cur:
                # print("h3=>",t)
                ans.append(t.copy()) # 每次添加的是t的元素,用copy整个新地址,不然t的改变会影响ans
                return
            t.append(nums[cur])
            # print("h1=>",t)
            loop(cur+1,nums)
            t.pop()
            # print("h2=>",t)
            loop(cur+1,nums)
        loop(0,nums)
        return ans

if __name__ == '__main__':
    a = [1,2,3]
    solution = linearArrayNonRepeatingSubsetRecursion()
    ans = solution.subsets(a)
    for x in ans:
        print(x)