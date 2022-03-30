'''
Author: chenbei
Date: 2022-03-28 16:46:49
LastEditTime: 2022-03-30 12:59:36
Description: bucketSort.py
FilePath: \myLeetCode\coreAlgorithms\bucketSort.py
A boy without dreams
'''
import itertools
from typing import Any, List
from insertSort import insertSort
class bucketSort:
    def __init__(self,nums:List[int or float],bucket_count=5,reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.bucket_count = bucket_count
        self.reverse = reverse
    def bucket_sort(self)->List[int or float]:
        maxVal,minVal = max(self.nums),min(self.nums)
        bucket_size = (maxVal-minVal)//self.bucket_count+1
        # 准备好bucket_count个容器
        buckets = [[] for _ in range(self.bucket_count)] 
        for num in nums:
            which_bucket = (num-minVal)//bucket_size
            buckets[which_bucket].append(num)
        self.nums.clear()
        # 降序的话要反向遍历buckets,因为后边的大
        for bucket in (reversed(buckets) if self.reverse else buckets):
            solution = insertSort(bucket,self.reverse)
            solution.insert_sort()
            self.nums.extend(bucket) # 可以去除嵌套列表
        
if __name__ == '__main__':
    nums = [5,4,3,2,1,0,9]
    solution = bucketSort(nums,3,True)
    solution.bucket_sort()
    print(nums)