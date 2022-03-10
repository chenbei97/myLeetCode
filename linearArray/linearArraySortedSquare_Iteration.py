from typing import List
class linearArraySortedSquareIteration:
    def sortedSquares(self,nums:List[int])->List[int]:
        ans = []
        for c in nums:
            ans.append(c*c)
        ans.sort()
        return ans
if __name__ == '__main__':
    a = [-2,5,-3,-1,-4,7,4,0,8] 
    solution = linearArraySortedSquareIteration()
    print(solution.sortedSquares(a))