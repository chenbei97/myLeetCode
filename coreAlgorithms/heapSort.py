'''
Author: chenbei
Date: 2022-03-17 14:56:27
LastEditTime: 2022-03-18 11:25:43
Description: heapSort.py
FilePath: \myLeetCode\coreAlgorithms\heapSort.py
A boy without dreams
'''
from typing import List
class heapSort:
    def __init__(self,nums:List[int or float],reverse=False) -> None:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def heap_sort(self)->None:
        self.tnums = self.nums.copy() # 写在这里是避免二次调用heap_sort时出错,深拷贝改变tnums不会改变nums
        ans = []
        self.initialHeap()
        while len(self.tnums)>0:
            ans.append(self.topHeap())
            self.popHeap()
        for x in range(self.n): # 不要用self.nums = ans,会改变原有地址
            self.nums[x] = ans[x] # 赋值不改变最初传入的nums地址
    def initialHeap(self)->None:
        for root in reversed(range(self.n//2+1)):
            rootVal = self.tnums[root]
            child = root * 2
            while child<=self.n-1: # 检查root的所有子节点
                if child<self.n-1 and (self.tnums[child]<self.tnums[child+1] \
                    if self.reverse else self.tnums[child]>self.tnums[child+1]):
                        child += 1 # 找到2个子节点更大的那个和根节点比较
                if rootVal>=self.tnums[child] if self.reverse else rootVal<=self.tnums[child]:
                    break # 如果大根堆时根节点大于子节点或者小根堆时根节点小于子节点则必定root也满足根堆定义
                self.tnums[child//2] = self.tnums[child] # 否则根节点被子节点覆盖
                child *= 2 # 继续检查后边的子节点,很可能child的child也会比root大
            # while结束后,child多乘了1次2,所以while内执行的是child//2覆盖child//4的值
            self.tnums[child//2] = rootVal # child/2应当被之前换下来的较小值rootVal覆盖
        # print(self.tnums) # 9 5 3 4 1 0 2
    def popHeap(self)->None:
        lastIdx = len(self.tnums)-1
        lastVal = self.tnums[lastIdx] # 把根堆最大/小值移除后就是把后面的值依次往前覆盖
        self.tnums.pop(-1)
        lastIdx  = lastIdx-1
        child = 1 # 覆盖的过程和初始化根堆过程是一样的,root是现在的nums[0],区别是自上而下的遍历
        while child<=lastIdx:
            if child<lastIdx and (self.tnums[child]<self.tnums[child+1] \
                if self.reverse else self.tnums[child]>self.tnums[child+1]):
                    child += 1 # 找到2个更大/小的子节点和要插入的节点比较       
            if lastVal>=self.tnums[child] if self.reverse else lastVal<=self.tnums[child]:
                break; # 要插入的节点大/小于2个子节点就一定满足根堆定义
            self.tnums[child//2] = self.tnums[child]; # 把大/小的子节点值覆盖根节点root
            child *= 2; # 不满足,插入节点更合适的位置应当在child的child中寻找
        # 每1轮while结束,child都是提前扩到2倍,child/2才是最后1个换到其根节点child/4的节点
        if self.tnums == []:return # 防止出现 list assignment index out of range 错误
        self.tnums[child//2] = lastVal # 最后1轮,child/2换到child/4,故child/2是最适合lastVal插入的位置

    def topHeap(self)->int or float:
        return self.tnums[0]

    def setReverse(self,reverse=False)->None:
        self.reverse = reverse
if __name__ == '__main__':
    nums = [5,4,3,2,1,0,9] # 2,6,10,4,8,12,-1,3
    solution = heapSort(nums,True)
    solution.heap_sort()
    print(nums)
    solution.setReverse(False)
    solution.heap_sort()
    print(nums)