from typing import List
class linearArraySortedSquareDoublePointers:
    def sortedSquares(self,nums:List[int])->List[int]:
        n = len(nums)
        neg = -1
        for i in range(n):
            if nums[i] < 0:
                neg = i
            else:break
        ans = []
        i,j = neg,neg+1
        while i>=0 or j<=n-1:
            if i<0:
                ans.append(nums[j]*nums[j])
                j += 1
                if j>n-1:break
            elif j>n-1:
                ans.append(nums[i]*nums[i])
                i -= 1
                if i<0:break
            elif abs(nums[i])<abs(nums[j]):
                ans.append(nums[i]*nums[i])
                i -= 1
            else:
                ans.append(nums[j]*nums[j])
                j += 1
        return ans
if __name__ == '__main__':
    a = [-3,-2,-1,0,4,7,8] 
    solution = linearArraySortedSquareDoublePointers()
    print(solution.sortedSquares(a))