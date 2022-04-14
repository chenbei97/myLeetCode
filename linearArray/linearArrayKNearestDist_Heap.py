'''
Author: chenbei
Date: 2022-04-14 15:47:58
LastEditTime: 2022-04-14 16:19:04
Description: linearArrayKNearestDist_Heap.h
FilePath: \myLeetCode\linearArray\linearArrayKNearestDist_Heap.py
Signature: A boy without dreams
'''
import heapq # 引入小根堆
from typing import List
class linearArrayKNearestDistSort:
    def kNearestDist(self,points:List[List[int]],k:int)->List[List[int]]:
        # python的默认堆(优先级队列)是小根堆,也就是堆顶元素是最小的,C++是大根堆
        # 最小的负距离在小根堆上,其实就是最大的正距离在大根堆上
        q = [(-x ** 2 - y ** 2, i) for i, (x, y) in enumerate(points[:k])] # 前k个放进堆里
        heapq.heapify(q) # 初始化小根堆方法,存储的是tuple(dist,i)
        
        n = len(points)
        for i in range(k, n): # 第k+1开始
            x, y = points[i] # 解包更方便操作
            dist = -x ** 2 - y ** 2 # 比较的也是负距离
            # heappushpop方法不是依赖于堆的,所以要指定处理哪个堆,不依赖对象性质的设计方法
            heapq.heappushpop(q, (dist, i)) # (dist, i)=(距离,编号),推送元素到堆q,删除堆顶元素并返回,这里不用接受返回值
        ans = [points[identity] for (_, identity) in q] # 现在q都是元组对象(dist,i),只要编号i
        return ans

if __name__ == '__main__':
    nums = [[1,1],[3,4],[-3,4],[5,5],[3,7],[10,6]]
    solution = linearArrayKNearestDistSort()
    ans = solution.kNearestDist(nums,3)
    for point in ans :
        print(point)