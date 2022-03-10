from typing import List
class linearArrayRelativeOrderHashTable:
    def relativeOrder(self,arr1:List[int],arr2:List[int])->List[int]:
        d = dict()
        for idx,val in enumerate(arr2):
            d[val] = idx
        for i in range(len(arr1)):
            for j in range(i+1,len(arr1)):#类似于冒泡排序的写法
                if arr1[i] in d.keys() and arr1[j] in d.keys():
                    if d[arr1[i]]>d[arr1[j]]:
                        arr1[i],arr1[j]=arr1[j],arr1[i]
                elif arr1[i] not in d.keys() and arr1[j] not in d.keys():
                    if arr1[i]>arr1[j]:
                        arr1[i],arr1[j]=arr1[j],arr1[i]
                else:
                    if arr1[j] in d.keys():
                        arr1[i],arr1[j]=arr1[j],arr1[i]
        return arr1
if __name__ == '__main__':
    a = [0,2,3,1,3,2,4,6,7,9,2,19] 
    b = [2,1,4,3,9,6]
    solution = linearArrayRelativeOrderHashTable()
    print(solution.relativeOrder(a,b)) # [2,2,2,1,4,3,3,9,6,0,7,19]