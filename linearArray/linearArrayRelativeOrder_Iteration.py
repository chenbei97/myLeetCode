from typing import List
class linearArrayRelativeOrderIteration:
    def relativeOrder(self,arr1:List[int],arr2:List[int])->List[int]:
        upper = max(arr1)
        frequency = []
        for i in range(upper+1):
            frequency.append(0)
        for x in arr1:
            frequency[x] += 1
        ans = []
        for x in arr2: # arr1与arr2共有的元素
            for i in range(frequency[x]):
                ans.append(x)
            frequency[x] = 0
        for x in range(upper+1): # 现在frequency[x]非0的x都是arr2没有但arr1有的
            for i in range(frequency[x]):
                ans.append(x) # frequency[x]非0时,把x添加进答案
        return ans
if __name__ == '__main__':
    a = [0,2,3,1,3,2,4,6,7,9,2,19] 
    b = [2,1,4,3,9,6]
    solution = linearArrayRelativeOrderIteration()
    print(solution.relativeOrder(a,b)) # [2,2,2,1,4,3,3,9,6,0,7,19]