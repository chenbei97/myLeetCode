'''
Author: chenbei
Date: 2022-03-16 10:08:42
LastEditTime: 2022-03-16 15:50:09
Description: mergeSort.py
FilePath: \myLeetCode\coreAlgorithms\mergeSort.py
A boy without dreams
'''
from typing import List,Any
class mergeSort:
    def __init__(self,reverse=False) -> Any:
        self.reverse = reverse
    def merge_sort(self,arr:List[int or float])->List[int or float]:
        if len(arr) < 2: return arr
        mid = len(arr) // 2
        left,right = arr[0:mid],arr[mid:]
        return self.merge(self.merge_sort(left),self.merge_sort(right))
    def merge(self,left:List[int or float],right:List[int or float]):
        n1,n2 = len(left)-1,len(right)-1
        i,j=0,0
        ans = []
        while i<=n1 or j <=n2:
            if left[i]>right[j] if self.reverse else left[i]<=right[j]:
                ans.append(left[i])
                i += 1
            else :
                ans.append(right[j])
                j += 1
            if i>n1 and j <=n2:
                for k in range(j,n2+1):
                    ans.append(right[k])
                break
            if j>n2 and i<=n1:
                for k in range(i,n1+1):
                    ans.append(left[k])
                break
        return ans
    def setReverse(self,reverse:bool)->None:
        self.reverse = reverse
if __name__ == '__main__':
    solution = mergeSort(False)
    print(solution.merge([2,6,10],[4,8,12])) # 单独使用merge必须传入与reverse对应的有序数组
    solution.setReverse(True)
    print(solution.merge_sort([5,4,3,2,1,9]))