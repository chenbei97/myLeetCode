<!--
 * @Author: chenbei
 * @Date: 2022-03-15 09:01:11
 * @LastEditTime: 2022-03-16 10:01:21
 * @Description: some basic and core algorithms(based vector)
 * @FilePath: \myLeetCode\coreAlgorithms\coreAlgorithms.md
 * A boy without dreams
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

​		**冒泡排序最好情况：顺序数组，只需遍历一次，时间复杂度O(n)；最差时逆序数组，时间复杂度O(n(n-1)/2)，平均时间复杂度O(n^2)**。

​		一般情况，冒牌排序只适合数据量小、基本顺序的数组排序，是排序时间效率最低的一种方法。不过冒泡排序不会改变相同元素的位置，是一种**稳定性排序算法**。

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
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def bubble_sort(self)->List[int or float]: # 依次比较后n,n-1,n-2,..2个元素,总是把小的放在前边
        for i in range(self.n-1):
            for j in range(i+1,self.n):
                if self.nums[i]<self.nums[j] if self.reverse else self.nums[i]>self.nums[j]:
                    self.nums[i],self.nums[j]=self.nums[j],self.nums[i]
        return self.nums
    def _bubble_sort(self, arr): # 另一种写法
        for i in range(len(arr)):
            for j in range(len(arr) - i - 1): # 这是依次比较前n,n-1,..2个元素,总是把最大的放在后面
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr
```

## 选择排序

​		与冒泡排序的第1种方法的循环条件类似，冒泡排序总是拿未排序的第1个元素和后面的每一个元素进行比较，如果后面的大于未排序的第1个元素就进行交换，这种方法是可能很多元素都需要被交换。

​		选择排序的思想是，未排序的第1个元素后面，不需要所有元素都去和它比较，只需要找到比它小的那个元素即可，找到了在进行交换，如果没找到也无需交换，说明未排序的第1个元素就是最小的了。这种方式省去了很多可能的交换操作，尤其在逆序时效率要高于冒泡排序。

​		对于交换操作，**最好的情况顺序数组，交换0次，最坏的情况逆序数组需要交换3(n-1)次**。对于**比较操作，与数组本身无关，固定比较n(n-1)/2次，时间复杂度O(n^2)**。同时，选择排序因为交换的2个元素可能不相邻，所以相同元素的位置可能会改变，是**不稳定的排序方法**。

```c++
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void selectSort(vector<T> &nums,bool reverse=false){
    for(int i=0;i<nums.size()-1; i++){
        int idx = i ; // 此时未排序的第1个元素索引
        for(int j=i+1;j<nums.size();j++){
            if (reverse?nums[i] < nums[j]:nums[i] > nums[j]) 
                idx = j; // 升序:后边大就交换,降序:后边小交换
        }
        if (idx!=i) // 如果后面找到的值比未排序的第1个元素更大或者更小
            swap(nums[i],nums[idx]);
    }
}
```

```python
from typing import List,Any
class selectSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def select_sort(self)->List[int or float]:
        for i in range(self.n-1):
            idx = i # 记录当前未分类的第1个元素
            for j in range(i+1,self.n):
                if self.nums[i]<self.nums[j] if self.reverse \
                    else self.nums[i]>self.nums[j]:# reverse=False是有更小的元素交换
                    idx = j
            if idx != i:
                self.nums[idx],self.nums[i]=self.nums[i],self.nums[idx]
        return self.nums
```

## 插入排序

​		把数组看成两段，有序序列和无序序列，初始的有序序列为第1个元素，从第2个元素总是插入有序序列的合适位置，使之仍然有序，元素遍历结束，整个数组都有序。

​		关键的操作是，未排序的第1个元素从后向前开始，总是让前一个元素去替换后一个元素，这是覆盖操作，所以未排序的第1个元素所在位置会被前一个覆盖，所以才需要临时变量t先记录好这个位置的元素。覆盖操作直到位置idx，idx由这样的规则确定：如果是降序，未排序的元素依次从后向前和它之前已排序的每个元素比较，当未排序的元素比某个元素小，说明未排序元素应当插入在这个元素的前边，否则更合适的插入位置只能在更前边(未排序元素更大,大的元素在前)；升序同理，也是从后往前和前边已排序的每个元素作比较，所以未排序的元素比某个元素大时，插入位置就在该元素之后，否则说明更合适的插入位置在前边(未排序元素更小,小的在前)

​		由于第0个元素也要被比较到，所以注意idx取值范围是[0,i-1]，所以while结束idx变为[-1,i]，所以腾出来的真实位置idx应当是idx+1。**最好的情况，数组已经有序，此时只需要比较n-1次，并无需移动元素**，直接尾插；**最坏的情况，是每次都需要头插，总的比较次数是n(n-1)/2；取平均大约需要比较次数n^2/4，时间复杂度O(n^2)**。

​		插入排序是一种**稳定的排序方法**。

```c++
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void insertSort(vector<T> &nums,bool reverse=false){
    for(int i=1;i<nums.size(); ++i){
        T t = nums[i]; // 记录未排序元素的第1个,这个位置可能会被前1个元素覆盖所以需要临时记录
        int idx = i - 1; // ∈[0,i-1]
        while (idx+1>0 &&(reverse? nums[idx]<t : nums[idx]>t)){ // reverse=true时,前<后交换说明按降序排列
            nums[idx+1] = nums[idx]; // idx能取到0
            --idx;
        } // while结束后idx多减了1次,需要补回来
        nums[idx+1] = t ; //腾出来的idx位置给未排序的第1个元素,用idx+1
    }
}
```

```python
from typing import List,Any
class insertSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def insert_sort(self)->List[int or float]:
        for i in range(1,self.n):
            idx = i-1 # 当前未排序的第1个元素的前1个
            t = self.nums[i] # 事先未排序的第1个元素,因为这个位置可能会被前1个元素替换
            # 让idx+1>0是为了让idx能取到0不退出while
            # 这样可以继续比较第0个元素和t,来决定t放在0前还是0后
            # while后边要加小括号,注意and优先级高
            while idx+1 > 0 and (self.nums[idx]<t \
                if self.reverse else self.nums[idx]>t):# reverse=True:前边的小交换说明是降序
                    self.nums[idx+1]=self.nums[idx] # 从未排序的第1个元素开始向前,总是让前1个元素替换后1个元素
                    idx -= 1 # idx∈[0,i-1],i-1替换i,i-2替换i-1,直到idx替换idx+1,idx的位置就空出来被t替换
            self.nums[idx+1] = t # idx的位置就空出来被t替换,因为while结束idx多减了1,所以用idx+1
        return self.nums
```

## 希尔排序

​		希尔排序的原理：序列间隔为gap的那些元素都看成同1个子序列，然后对每个子序列进行插入排序，之后让gap减半，同理对新生成的子序列仍然分别进行插入排序。一般的gap从原序列长度的一半开始，直到gap<1为止，gap=1是最后1次插入排序。

​		很明显，在gap=1时，希尔排序就是插入排序。之所以要事先对gap>1的情况先进行插入排序，是为了降低总体的时间复杂度，随着gap的降低原序列会更加有序，所以可能gap=1时只需要比较1次而无需移动元素。

​		结论，**希尔排序的时间复杂度介于O(nlog2n)到O(n^2)之间，另外希尔排序是一种不稳定的排序算法**。

```c++
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
template<typename T>
void shellSort(vector<T>&nums,bool reverse =false){
    int n = nums.size();
    int gap = n / 2;
    while (gap>0){ //gap=1时是最后1次排序
        /***********code below similar to insertSort***********/
        for(int i=gap;i<n;i++){ // 前gap个元素∈[0,gap-1]对应gap个子序列的有序部分(第1个元素)
            T t = nums[i]; // 每个子序列未排序的第1个元素,i∈[gap,n-1]
            int idx = i - gap; // 确保对各个子序列来说idx能取到第1个元素∈[0,gap-1]
            while (idx+gap>0 &&(reverse?nums[idx]<t:nums[idx]>t)){ // nums[idx]是前1个元素,小于t交换说明是降序
                nums[idx+gap] = nums[idx]; // 后1个元素被前1个相隔gap的元素依次覆盖
                idx -= gap;
            }
            nums[idx+gap] = t; // 腾出来的位置,while结束idx多减了1次gap,gap要加回来
        }
        /***********code above similar to insertSort***********/
        gap /= 2; // 直到1是最后1次插入排序
    }
}
```

```python
from typing import List,Any
class shellSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def shell_sort(self)->List[int or float]:
        gap = self.n // 2
        while gap>0:
            '''************code below similar to insertSort************'''
            for i in range(gap,self.n): # [0,gap-1]对应gap个子序列的有序部分,[gap,n-1]是无序部分的第1个元素
                t = self.nums[i]
                idx = i - gap # ∈[0,gap-1],确保子序列能取到有序部分的第1个元素
                while idx+gap>0 and (self.nums[idx]<t if self.reverse else self.nums[idx]>t):
                    self.nums[idx+gap] = self.nums[idx] # 后1个元素被前1个相隔gap的元素依次覆盖
                    idx -= gap
                self.nums[idx+gap] = t # 腾出来的位置,但是idx多减了1次gap要加回来
            '''************code above similar to insertSort************'''       
            gap //= 2
        return self.nums
```

## 归并排序



## 快速排序

## 堆排序

## 计数排序

## 桶排序

## 基数排序

