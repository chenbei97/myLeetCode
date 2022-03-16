'''
Author: chenbei
Date: 2022-03-03 11:42:21
LastEditTime: 2022-03-16 14:22:59
Description: merge two sortOrdered array by double pointers
FilePath: \myLeetCode\linearArray\linearArrayMergeSortedArray_DoublePointers.py
A boy without dreams
'''
from typing import List
class linearArrayMergeSortedArrayDoublePointers:
    def mergeSortedArray(self,v1:List,v2:List):
        # 没排序就事先排好序
        v1.sort()
        v2.sort()
        ans = []
        n1,n2 = len(v1)-1,len(v2)-1
        p1,p2=0,0
        while p1<=n1 or p2<=n2:  
            if v1[p1] <= v2[p2]:
                ans.append(v1[p1])
                p1 += 1
            else :
                ans.append(v2[p2])
                p2 += 1
            if p1>n1 and p2<=n2:
                for i in range(p2,n2+1):
                    ans.append(v2[i])
                break
            if p1<=n1 and p2> n2:
                for i in range(p1,n1+1):
                    ans.append(v1[i])
                break
        return ans         

if __name__ == '__main__':
    v1 = [1,3,5,6,-2,-5,10]
    v2 = [23,43,-3,5]
    solution = linearArrayMergeSortedArrayDoublePointers()
    ans = solution.mergeSortedArray(v1,v2)
    print(ans)