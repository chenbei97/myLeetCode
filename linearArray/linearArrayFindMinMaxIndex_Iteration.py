from typing import List,Tuple
class linearArrayFindMinMaxIndexIteration:
    def findMinMaxIndex(self,theArray : List) -> Tuple or None:
        n = len(theArray)
        if n < 1:
            return None
        if n == 1 :
            return (0,0)
        minIdx,maxIdx = 0,0 
        if n % 2 == 1: # 奇数
            minIdx = 0
            maxIdx = 0
            start = 1
        else :
            if theArray[0] > theArray[1] :
                minIdx = 1
                maxIdx = 0
            else :
                minIdx = 0
                maxIdx = 1
            start = 2
        
        for i in range(start,n,2):
            if theArray[i]>theArray[i+1]: # a[i]更大
                if theArray[i] > theArray[maxIdx] : 
                    maxIdx = i
                if theArray[i+1] < theArray[minIdx]: 
                    minIdx=i+1
            else:  # a[i+1]更大
                if theArray[i+1] > theArray[maxIdx] : 
                    maxIdx = i+1
                if theArray[i] < theArray[minIdx]: 
                    minIdx=i
        return (minIdx,maxIdx) # min&max tuple
if __name__ == '__main__':
    import numpy as np
    from  time import  time
    a = []
    for i in range (100):
        a.append(np.random.randint(0,100))
    print("the Array is ",a)
    solution = linearArrayFindMinMaxIndexIteration()
    ans = solution.findMinMaxIndex(a)
    print("index is ",ans)
    print(f"the maxest element is {a[ans[1]]}, and the minest element is {a[ans[0]]}")
    q = np.random.randint(0,1000000,10000000)
    t1 = time()
    ans = solution.findMinMaxIndex(q)
    print(f"maxVal = {q[ans[0]]}, minVal = {q[ans[1]]} cost_time = {time()-t1}") # cost_time = 3.7687370777130127 s
                