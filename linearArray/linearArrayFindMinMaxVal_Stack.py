import math
from typing import List,Tuple
class getMinMaxStack:
    def __init__(self):
        self.stk = []
        self.minstk = [math.inf]
        self.maxstk = [-math.inf]
    def push(self,val):
        self.stk.append(val) # -1位置看成栈顶
        self.minstk.append(min(self.minstk[-1],val))
        self.maxstk.append(max(self.maxstk[-1],val))
    def pop(self):
        self.maxstk.pop() 
        self.minstk.pop()
        self.stk.pop()
    def top(self):
        return self.stk[-1]
    def getMin(self):
        return self.minstk[-1]
    def getMax(self):
        return self.maxstk[-1]
class linearArrayFindMinMaxValStack:
    def __init__(self):
        self.solution = getMinMaxStack()
    def findMinMaxVal(self,theArray : List) -> Tuple or None:
        for i in range(len(theArray)):
             self.solution.push(theArray[i])
        return (self.solution.getMin(),self.solution.getMax())
if __name__ == '__main__':
    a = [1,5,3,2,5,7,9,2,8,-1]
    solution = linearArrayFindMinMaxValStack()
    ans = solution.findMinMaxVal(a)
    print(f"maxVal = {ans[0]}, minVal = {ans[1]}")