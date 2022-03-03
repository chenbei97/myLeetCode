from typing import List
class linearArrayMergeSortedArrayIteration:
    def mergeSortedArray(self,v1:List,v2:List):
        for i in range(len(v2)):
            v1.append(v2[i])
        v1.sort()
if __name__ == '__main__':
    v1 = [1,3,5,6,-2,-5,10]
    v2 = [23,43,-3,5]
    solution = linearArrayMergeSortedArrayIteration()
    solution.mergeSortedArray(v1,v2)
    print(v1)