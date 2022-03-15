<!--
 * @Author: chenbei
 * @Date: 2022-03-15 09:01:11
 * @LastEditTime: 2022-03-15 10:09:13
 * @LastEditors: chenbei
 * @Description: some basic and core algorithms
 * @FilePath: \myLeetCode\coreAlgorithms\coreAlgorithms.md
-->

## 二分查找

​		查找一个数组的指定元素，如果存在该元素就返回下标，如果不存在就返回-1
​        时间复杂度O(logn),数组要求事先是有序的
​        从0和n-1开始,反复取中间坐标值,比较target和nums[mid]的大小关系调整left,right的位置
​        程序结束条件是left>right为止。

```c++
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
template<typename T>
int binarySearch(const vector<T>&nums, const T& target){
    vector<T> temp(nums);
    sort(temp.begin(),temp.end(),less_equal<T>()); // function object
    int left = 0, right = temp.size()-1;
    while (left<=right){
        int mid = (left + right) / 2 ; // 2个区间
        if (temp[mid] == target) return mid;
        if (temp[mid] < target) left = mid+1; // target∈[mid+1,right]
        if (temp[mid] > target) right = mid-1; // target∈[left,mid-1]
    }
    return -1;
}
```

```python
from typing import Any, List
class binarySearch:
    def __init__(self,nums:List[int or float],target:int or float) -> Any:
        self.nums = nums
        self.nums.sort()
        self.target = target
    def search(self) -> int:
        left,right = 0,len(self.nums)-1
        while left<=right:
            mid = (left+right) // 2
            if self.nums[mid] == self.target:
                return mid
            if self.nums[mid] < self.target: # target∈[mid+1,right]
                left = mid + 1
            if self.nums[mid] > self.target: # target∈[left,mid-1]
                right = mid - 1
        return -1
    def sorted(self,reverse=False)->List[int or float]:
        if reverse:
            self.nums.sort(reverse=True)
        return self.nums
```

## 冒泡排序

​		思想：对n个元素的相邻2个元素进行比较，后边大于前边就进行交换，一直到最后，就可以让最大的元素放在n-1的位置。同样的方法对前n-1个元素两两比较，就可以让最大的元素放在位置n-2。以此类推，就可以实现数组升序。也可以依次比较后n,n-1,n-2..,2个元素，总是把最小的元素放在第1,2,..个位置。

​		冒泡排序最好情况：顺序数组，只需遍历一次，时间复杂度O(n)；最差时逆序数组，时间复杂度O(n(n-1)/2)，平均时间复杂度O(n^2)。

​		一般情况，冒牌排序只适合数据量小、基本顺序的数组排序，是排序时间效率最低的一种方法。不过冒泡排序不会改变相同元素的位置，是一种稳定性排序算法。

```c++
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void bubbleSort(vector<T> &nums,bool reverse=false){
    for(int i=0;i<nums.size()-1; i++){
        for(int j=i+1;j<nums.size();j++){
            if (reverse?nums[i] < nums[j]:nums[i] > nums[j]) 
                swap(nums[i],nums[j]);
        }
    }
}
```

```python
from typing import Any, List
class bubbleSort:
    def __init__(self,nums:List[int or float],reverse:False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def bubble_sort(self)->List[int or float]: # 依次比较后n,n-1,n-2,..2个元素,总是把小的放在前边
        for i in range(self.n-1):
            for j in range(i+1,self.n):
                if self.nums[i]<self.nums[j] if self.reverse else self.nums[j]>self.nums[i]:
                    self.nums[i],self.nums[j]=self.nums[j],self.nums[i]
        return self.nums
    def _bubble_sort(self, arr): # 另一种写法
        for i in range(len(arr)):
            for j in range(len(arr) - i - 1): # 这是依次比较前n,n-1,..2个元素,总是把最大的放在后面
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr
```





