from typing import List,Tuple
class linearArrayFindMinMaxValRecursion:
    def findMinMaxVal(self,theArray : List) -> Tuple or None:
            def loop(a):
                n = len(a)
                if (n < 1):  # 首次进入
                    return None, None
                if (n == 1):
                    minVal, maxVal = a[0], a[0]
                    return minVal, maxVal
                if len(a) % 2 == 1:
                    minVal, maxVal = a[0], a[0]
                    a = a[1:]
                else:
                    if a[0] > a[1]:
                        minVal, maxVal = a[1], a[0]
                    else:
                        minVal, maxVal = a[0], a[1]
                    a = a[2:]
                n = len(a) # a调整过要重新更改长度
                if (n < 1) : # 再次进入
                    return minVal,maxVal
                if  n != 2 :
                    a1 = a[0:int(n/2)]
                    a2 = a[int(n/2):n]
                    # print("a1 = ",a1," a2 = ",a2," minVal = ",minVal," maxVal = ",maxVal)
                    p1,q1 = loop(a1)
                    p2,q2 = loop(a2)
                    # if p1<p2 :
                    #     if minVal < p1: pass
                    #     else : minVal = p1
                    # else :
                    #     if minVal < p2 : pass
                    #     else : minVal = p2
                    # if q1<q2 :
                    #     if maxVal > q2: pass
                    #     else : maxVal = q2
                    # else :
                    #     if maxVal > q1 : pass
                    #     else : maxVal = q1
                    # return minVal,maxVal
                    return min(minVal,p1,p2),max(maxVal,q1,q2)# 和上述程序等价
                else :
                    # if a[0]> a[1] :
                    #     return minVal if minVal < a[1] else a[1],maxVal if maxVal > a[0] else a[0]
                    # else:
                    #     return minVal if minVal < a[0] else a[0], maxVal if maxVal > a[1] else a[1]
                    return min(a[0],a[1],minVal),max(a[0],a[1],maxVal) # 多比1次,和上述程序等价
            return loop(theArray)
if __name__ == '__main__':
    import numpy as np
    from  time import  time
    solution = linearArrayFindMinMaxValRecursion()
    q = np.random.randint(0,1000000,10000000)
    t1 = time()
    ans1 = solution.findMinMaxVal(q)
    print(f"maxVal = {ans1[0]}, minVal = {ans1[1]} cost_time = {time()-t1}") # 递归慢 7.166433095932007 s
    def other(a):
        minIdx,maxIdx = 0,0
        for i in range(1,len(a)):
            if (a[i] > a[maxIdx]) : maxIdx = i
            elif (a[i]) < a[minIdx] : minIdx = i
        return minIdx,maxIdx
    t2 = time()
    ans2 = other(q)
    print(f"maxVal = {q[ans2[0]]}, minVal = {q[ans2[1]]} cost_time = {time()-t2}") # 循环稍快 4.8972837924957275 s
    # 但是这2种方法都比linearArrayFindMinMaxIndex_Iteration给出的迭代法慢
    # 它的时间为cost_time = 3.7687370777130127 s,事实上可以证明这个方法也是比较次数最少的