<!--
 * @Author: chenbei
 * @Date: 2022-03-15 09:01:11
 * @LastEditTime: 2022-03-30 11:43:58
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

​		使用递归的分治策略，总是将序列分为2半，初始时递归到最深处，也就是每个元素都看成1个有序子序列，序列的元素个数是1。

​		每个子序列都处于上次分为2半的左部分或者右部分，初始时就是2个元素的序列左部分1个元素和右部分1个元素进行比较。

​		从完整的原序列的左右部分开始开始，每层递归都是先递归左部分，再递归右部分。所以从**递归最深处开始程序退栈时，执行的程序总是上一层递归的左递归**。例如2个元素比较程序结束后退回递归上一层，这个程序实际是具有2个元素子序列的左递归和右递归，它本身执行的程序是更上一层递归的左递归->也就是4个元素子序列的左递归。所以4个元素的子序列执行完左递归，应该执行右递归，也就是另外具有2个元素的子序列，那么它也会继续左递归和右递归，只不过元素只有1个了，已达到递归最深处无法再递归。

​		最后1层递归，就是原序列的左递归结束后，再执行原序列的右递归，会得到2个有序的子序列，这2个子序列再进行归并操作，就可以得到完整的有序子序列。归并算法的时间复杂度是O(n)，归并操作数是log2n，所以总的时间复杂度是O(nlog2n)，算法空间复杂度是O(n)。

​		最后归并排序是稳定性排序算法，相同元素情况下总是左递归先执行，所以不会改变相同元素的相对次序。

​		归并函数的实现由2个函数组成，第1个函数实现递归过程，并拆分2个区间，然后把左右区间带入下次递归，这是确定归并次数。真正的归并操作由第2个函数决定，这个函数其实就是合并2个有序数组的思路，可以使用双指针法和迭代法，这里使用双指针。这个函数如果单独拿出来使用合并2个数组，要求数组必须是有序的，否则不能合并为整体有序的数组。为什么每次归并的一定是有序数组呢，这就是因为递归分治的问题，从递归最深处的2个元素开始，就是有序的了，每次归并结束回到上一层递归依然是有序的

```c++
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
template<typename T>
vector<T> merge(const vector<T>&left,const vector<T>&right,bool reverse=false);
template<typename T>
vector<T> mergeSort(const vector<T>&nums,bool reverse = false){ // 归并排序
    int n = nums.size();
    if (n < 2) return nums; // 至少有2个元素
    int mid = n / 2; // 中间位置
    vector<T> left(nums.begin(),nums.begin()+mid);
    vector<T> right(nums.begin()+mid,nums.end());
    return merge(mergeSort(left,reverse),mergeSort(right,reverse),reverse);
}
template<typename T>
vector<T> merge(const vector<T>&left,const vector<T>&right,bool reverse) { // 归并操作
    // 用于归并下层递归退出后已得到的2个有序子序列
    // 最初的2个有序子序列各自只有1个元素
    vector<T> res;
    int n1=left.size()-1,n2=right.size()-1;
    int i=0,j=0;
    while (i<=n1 || j<=n2)
    {
        if (reverse?left[i]>right[j]:left[i]<=right[j]) // 如果是降序,就大的被添加否则小的被添加
        {
            res.push_back(left[i]);
            ++i;
        }
        else
        {
            res.push_back(right[j]);
            ++j;
        }
        // 结束后i,j可能会超出范围,需要进行考虑
        // 参考双指针法实现2个有序数组合并
        if (i>n1&& j<=n2) // 可能i先超范围
        {   
            for(int k=j;k<=n2;++k)
            { // 把right剩余的直接加进去
                res.push_back(right[k]);
            }
            break;
        }
        if (i<=n1 && j>n2)
        { // 可能j先超范围
            for(int k=i;k<=n1;++k)
            { // 把left剩余的直接加进去
                res.push_back(left[k]);
            }
            break;
        }
    }
    return res;
}   
```

```python
from typing import List,Any
class mergeSort:
    def __init__(self,reverse=False) -> Any:
        self.reverse = reverse
    def merge_sort(self,arr:List[int or float])->List[int or float]:
        if len(arr) < 2: return arr
        mid = len(arr) // 2
        left,right = arr[0:mid],arr[mid:]
        return self.merge(self.merge_sort(left),self.merge_sort(right))
    def merge(self,left:List[int or float],right:List[int or float]):
        n1,n2 = len(left)-1,len(right)-1
        i,j=0,0
        ans = []
        while i<=n1 or j <=n2:
            if left[i]>right[j] if self.reverse else left[i]<=right[j]:
                ans.append(left[i])
                i += 1
            else :
                ans.append(right[j])
                j += 1
            if i>n1 and j <=n2:
                for k in range(j,n2+1):
                    ans.append(right[k])
                break
            if j>n2 and i<=n1:
                for k in range(i,n1+1):
                    ans.append(left[k])
                break
        return ans
    def setReverse(self,reverse:bool)->None:
        self.reverse = reverse
```

## 快速排序

​		快速排序本质上是一种冒泡排序基础上的分而治之的递归算法。

​		算法是**先找到1个基准(总是取排序区间内的首个元素)，然后将比基准小的元素都放在基准左边，比基准大的元素放在基准右边，相同的数可以放在任一边**。这里要注意的是**基准值在这一轮排序中是不会变的，但是基准值的位置是可以变的**，只要最后满足基准值是数组的分界线即可。数组这轮排序完毕以后，应当返回分区的位置，也就是基准值的新位置，可能还是一开始的位置，这说明基准值选取的恰好是本轮区间排序的最小值(如果是降序排列，就是最大值)，那么下一轮递归时就没有左递归了。

​		递归之前，会带入要递归区间的边界，左递归区间边界是[low,pivot-1]，右区间边界是[pivot+1,high]。pivot是上一轮递归的排序区间[low,high]所得到的基准值新位置，所以并不保证pivot-1＞low和pivot+1<high。所以这也是递归终止的条件，在排序之前，要判断区间边界的问题。

​		之所以排序区间[low,high]能够进行排序并得到新基准的位置用于下一轮，是因为满足先决条件low<high。所以2个递归子区间进入排序之前，也会先判断low和pivot-1，以及pivot+1和high的大小关系。

​		快速排序的时间复杂度最坏为O(n^2)，最好为O(nlog2n)。空间复杂度最坏为O(n)，最好为O(log2n)。

​		快速排序是一种不稳定的排序算法，也是不适合链表结构实现的排序方法。

​		具体的排序程序，有不同的写法，下方的程序给出了2种partition函数的写法。

```c++
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
template<typename T>
int partition(vector<T>&nums,int low,int high,bool reverse=false);
template<typename T>
int partition_new(vector<T>&nums,int low,int high,bool reverse);
template<typename T>
void quickSort(vector<T>&nums,int low,int high,bool reverse = false){
    if (low < high){ // 递归的终止条件
        int piovtIdx = partition_new(nums,low,high,reverse);//真正的排序过程,用partition_new函数也可以
        // 得到的pivotIdx是排序区间[low,high]内基准值的位置
        // 开始基准值总是取递归的排序区间首元素,即pivot=nums[low],pivotIdx=low
        // 一轮排序中pivot是不会变的,但是pivotIdx可能会变
        // 最终目的是pivotIdx之前的元素都比nums[pivotIdx]小,之后的元素都比nums[pivotIdx]大
        // pivotIdx=low不变说明pivot是[low,high]区间内最小的元素(或者降序排列时最大的元素)
        // 这样下次的递归区间没有左区间,只有右区间,因为low>piovtIdx-1
        // 其实就等于递归区别从[low,high]变成了[low+1,high],首元素已经确定无需再排
        quickSort(nums,low,piovtIdx-1,reverse); 
        quickSort(nums,piovtIdx+1,high,reverse);
    }   
}
template<typename T>
int partition(vector<T>&nums,int low,int high,bool reverse){
    // 真正的排序函数,能够进入此函数说明low<high
    T pivot = nums[low]; // 总是取排序区间首元素为基准值,目前的pivotIdx=low
    while (low<high)
    {
        // 第1个while目的是把基准值位置右边的所有比基准值大的元素挪到基准值左边
        while (low<high &&  // reverse=true要求降序,后边比前边的小无需交换,让high向前移动
                ( reverse?nums[high]<=pivot:nums[high]>=pivot))
        {
            --high; // 如果是降序,后者要比前者小才无需交换
            // 如果是升序,后者要比前者大才无需交换
        }
        // while结束,high最多到low(如果到low说明后边的每一个元素都比基准值大(小))
        nums[low] = nums[high]; // 如果后边有比基准值更小(大)的就把它挪到基准值位置左边
        // 第2个while目的是把基准值位置左边的所有比基准值小的元素挪到基准值右边
        while (low<high && 
                (reverse?nums[low]>=pivot:nums[low]<=pivot))
        {
            ++low;//升序,前者小于后者才无需交换,降序反过来
        }
        // while结束,low最多到high(如果到high说明前边的每一个元素都比基准值小(大))
       nums[high] = nums[low]; // 前边有比基准值更大(小)的就把它挪到基准值位置右边
    }
    nums[low] = pivot; // 现在的low值可能变化也可能没变,low是基准值的新位置
    return low;
}
template<typename T>
int partition_new(vector<T>&nums,int low,int high,bool reverse){
    // 另1种排序和分区的写法
    T pivot = nums[low];// 总是取排序区间首元素为基准值
    int behindPivotIdx = low+1; // 初始为基准值位置的后1个
    int i = low+1;
    while (i<=high){ // [low+1,high]
        if (reverse?nums[i]>=pivot:nums[i]<=pivot) // 以降序为例,如果元素≥基准值就交换到基准值位置的后面
        {
            swap(nums[i],nums[behindPivotIdx]); // 交换到基准值的后面位置,基准值本身不动
            behindPivotIdx++; // 相当于轮流把大于基准值的元素依次放到基准值位置后面
        }
        // 小于基准值的元素就无需再移动,在原位置即可
        i++; // 查看下1个元素
    }
    // while结束后,在behindPivotIdx之前的元素都满足比基准值大,之后的元素都比基准值小
    // 此时把基准值和behindPivotIdx-1位置元素交换
    // 那么新基准值位置之前的所有元素就满足了都比基准值大,且之后的所有元素都比基准值小
    // 例如[1,5,3,2,6,0]->[6,5,3,2,1,0],0和1元素就是low=0和behindPivotIdx=5
    swap(nums[low],nums[behindPivotIdx-1]);
    return behindPivotIdx-1; // 基准值1的新位置是4
}
```

## 堆排序

​		堆分为大根堆和小根堆，大根堆要求根节点值 ≥ 子节点值，小根堆要求根节点值 ≤ 子节点值。

​		将数组转化为根堆，重复从根堆中取出数值最大/小的节点，并让剩余的堆维持根堆性质。

​		主要涉及到2个函数，第1个是初始化根堆，第2个是取出堆顶元素后重构根堆的函数。

​		关于初始化根堆要了解的东西：从最后一个非叶子结点遍历，是为了从最小的子树开始检查，最小子树只需要比较根节点和2个子节点就可以确定最小子树是否满足定义。若不满足定义，只需要交换1次，因为子节点不会再有子树会比根节点的值大，否则它不是最小子树。然后继续检查倒数第2个子树，倒数第3个子树，直到全局最大树，每个子树都是更上一级子树的子节点。倒序检查的目的是若低级子树满足根堆定义，则高级子树的根节点值大于2个低级子树时那么高级树也必定满足根堆定义，因为低级子树已检查过定义。但更大树如果存在子树(左或右子树)大于更大树的根节点值，很可能子树的子树也会比更大树的根节点值大，这也是为何for循环内部的while循环要检查子树的所有子树，这是为了实现自上而下的交换，把小的值下移到子树，大的值上移到根。while循环是自上而下的检查，每一轮都会把子树较大的移到根，最后一轮循环结束，那个节点把自己的值给了根，节点自己则应该接收更大树根值。单纯的交换根节点和某个子树的子树的..子树的某个节点，虽然保证了当前根节点大于了所有子节点，但是可能会破坏某个已有子树的子树的..子树的根节点也要大于它下方的所有节点的事实，因为所有子树都要满足根节点大于子节点。而倒序遍历因为是从最小子树往全局最大树检查的，基层子树开始就保证不会破坏这种关系，那么全局树也不会破坏这种关系。

​		关于取出堆顶元素需要知道的东西：本质上不是删除堆顶元素，而是用数组后边的元素去覆盖前边的元素。事实上取出的是数组的最后1个元素，这样方便删除，然后把这个元素插入到合适的位置即可。这里的while循环是自上而下的检查。而不是初始化时自下而上的检查。在while内部尝试找到某个合适的位置插入这个元素，如果插入的元素比2个子树的节点值都大，就把元素覆盖到2个子树的根节点，因为是自顶向下的，元素能比2个子树节点都大的话，说明就找到了合适的位置，2个子树的下方必定不会有更合适的位置，然后把原本不合适的2个子树根节点的值挪到后边，它将在以后的for循环中被检查。如此重复，假设能检查到最后1个非叶子节点，它一定是要插入元素的根节点，它如果没有插入的元素更合适，就让元素替换这个非叶子节点，这样其实相当于要插入的元素还是最大/小的，它只是覆盖到前一个位置。

​		堆积排序的时间复杂度为O(nlog2n)，空间复杂度O(1)，也就是下方程序中临时变量记录rootVal或者lastVal。

​		堆排序是不稳定的排序方法，也是不适合于链表结构实现的算法。

```c++
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
template<typename T>
void popHeap(vector<T>&nums,bool reverse = false);
template<typename T>
void initialHeap(vector<T>&nums,bool reverse = false);
template<typename T>
T topHeap(vector<T>&nums);
template<typename T>
void heapSort(vector<T>&nums, bool reverse = false){
    vector<int> ans;
    initialHeap(nums,reverse);
    while (!nums.empty()){
        ans.push_back(topHeap(nums));
        popHeap(nums,reverse);   
    }
    nums = ans;
}
template<typename T>
void initialHeap(vector<T>&nums,bool reverse){
    // 建立大根堆或者小根堆
    // 下面的注释统一以大根堆进行说明
    int n = nums.size();
    // 从最后1个具有非叶子节点(有孩子的节点)开始,它在数组的位置为n/2
    for (int root = n/2 ;root >=0;--root){
        T rootVal = nums[root]; // 记录根的值
        int child = root*2; // 检测根的子树是否也是大根堆
        while (child<=n-1) // 检测子树要检查到最后1个不超过范围的元素为止
        {
            // child<n-1的条件可以保证child+1不越界,child+1就是child的兄弟节点
            if (child < n-1 && (reverse?nums[child]<nums[child+1]:nums[child]>nums[child+1]))
                ++child; // 如果兄弟节点更大,只需要比较根节点和兄弟节点即可
            if (reverse?rootVal>=nums[child]:rootVal<=nums[child])
                break; // 根节点值比最大的子节点那个还大,说明root以下的子树满足大根堆定义
            
            // 不满足大根堆的定义时nums[child]<nums[root],但是有可能child的child也会比root大
            // 除了交换root和child,在child不超出范围时也要继续检测child的子树
            nums[child/2] = nums[child]; // root就是child/2,<=>nums[root]=nums[child]
            child *= 2; // 检测child的孩子2*child和2*child+1,下一轮while进行判断,必要的话也会交换child和它的child
            // 有可能会nums[child*2]或nums[child*2+1]>nums[child]
            // 让child*2和child*2+1的较大者和child比较,child大则已,小就交换
            // 因为child在进入下一轮while之前已经变成child's child,所以依然nums[child/2]=max(nums[child],nums[child+1])
            // 直到child超出n-1的数组范围
        }
        // 在while内,如果不满足根堆定义,每个根节点都会和其孩子的较大值交换,最后1次while结束child是孩子
        // 它的父亲child/2将其父亲child/4替换了,child/2本身应当接收原本较小的那个根节点值也就是rootVal
        // 根节点也应当回到子树内这个合适的节点位置,while结束后child/2就是这个位置
        nums[child/2] = rootVal; // 最合适的那个节点接收原来的根节点值
    }
}
template<typename T>
void popHeap(vector<T>&nums,bool reverse){
    // 移除全局根节点,然后重新排列根堆,就是用后面的覆盖前边的即可
    int lastIdx = nums.size()-1;
    T lastVal = nums[lastIdx--];//所以记录好最后1个元素
    nums.pop_back();
    int child=1; // 覆盖的过程和初始化根堆过程是一样的,root是现在的nums[0],区别是自上而下的遍历
    while (child<=lastIdx){ // 类似于检查子树是否满足根堆定义,重构根堆
        if (child<lastIdx && (reverse?nums[child]<nums[child+1]:nums[child]>nums[child+1]))
            ++child; // 找到2个更大/小的子节点和要插入的节点比较
        if (reverse?lastVal>=nums[child]:lastVal<=nums[child])
            break; // 要插入的节点大/小于2个子节点就一定满足根堆定义
        nums[child/2] = nums[child]; // 把大的子节点值覆盖根节点root
        child *= 2; // 不满足,插入节点更合适的位置应当在child的child中寻找
    }
    // 每1轮while结束,child都是提前扩到2倍,child/2才是最后1个换到其根节点child/4的节点
    nums[child/2] = lastVal; // 最后1轮,child/2换到child/4,故child/2是最适合lastVal插入的位置
}
template<typename T>
T topHeap(vector<T>&nums){
    return nums[0];
}
```

```python
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
```

## 计数排序

计数排序的关键在于计算数字的排名，以传入的数组长度建立初始全0的名次数组rank。让数组的元素两两进行比较，每个元素和另一个元素比较的时候，如果某个更大，就让这个位置的名次增1(升序)，如果是降序的话就反过来，让更小的那个元素位置的名次增1。

所以两两比较的关键就是不要重复比较，所以类似于冒泡排序的遍历方法，我称之为回头遍历法，控制变量i到达的位置，和i以前的那些数回头比较，用j表示。

有了名次只需要按照名次指定的位置也就是rank[i]，把nums[i]移动到那里即可。可以使用临时数组temp，让temp[rank[i]]=nums[i]即可，那么temp就是排好序的数组。但是这里希望节省空间，不使用临时数组进行原地排序。所以如果是升序，就从左到右遍历数组元素。理想的情况也就是最后的情况，如果每个元素的位置都和排名一致，也就是位置0是排名0，位置n是排名n，就说明完成了排序。否则的话，只要存在排名不和位置一致，就反复交换当前的元素nums[i]到指定的位置nums[rank[i]]，当然nums[rank[i]]的元素也会换回来，它还要继续确定真正的名次位置，但是一旦nums完成了一次排名，rank也发生了变化，它也要对应变化，即rank[i]和rank[rank[i]]进行交换，因为每次rank[i]都会发生变化，所以还需要临时变量t=rank[i]记录它。

当输入元素是 n个[0,k]之间的整数时，计数排序的时间复杂度为 O(n + k)，同时还需要额外的数组空间用于计算排名。

计数排序一般用于排序整数，不适用于按字母顺序排序人名。

计数排序是稳定性排序算法。

C++版本的实现。

```c++
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void countSort(vector<T> &nums,bool reverse=false){
    // 计数排序第一步是找到所有数字的排名
    vector<int> rank(nums.size());
    int i = 0;
    for(;i<nums.size();++i){ // 不重复的两两元素比较,只要某个位置元素比另一个位置元素大就提高1个排名
        for(int j=0;j<i;++j)//如果是升序,nums[j]<=nums[i],让数值大的排名高
            if(reverse?nums[j]>nums[i]:nums[j]<=nums[i]) ++rank[i];//排名高的体现就是让i这个位置排名+1
            else ++rank[j];// 降序就让数值小的时候提高排名
    }
    if (reverse){ // 降序
        for(int i=nums.size()-1;i>=0;--i){// 直到排名和索引位置一致(升序)或者反过来(降序)
            int r = rank[i];//当前元素nums[i]的排名是rank[i]
            swap(nums[i],nums[r]);//把当前元素交换到指定的排名位置处,那个元素交换回来,后序继续判断它的位置
            swap(rank[i],rank[r]);//排名也发生了变化要一并进行交换
        }
    }
    else{ // 升序
        for(int i=0;i<nums.size();++i){
            while (rank[i] != i){  
                int r = rank[i];
                swap(nums[i],nums[r]);
                swap(rank[i],rank[r]);
            }  
        }
    }
}
```

Python版本的实现。

```python
from typing import Any, List
class countSort:
    def __init__(self,nums:List[int or float],reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
    def count_sort(self)->List[int or float]:
        rank = [0 for i in range(self.n)] # zeros list
        for i in range(1,self.n):
            for j in range(i):#目的是两两不重复的比较元素
                if self.nums[j]>self.nums[i] \
                    if self.reverse else self.nums[j]<=self.nums[i]: #如果是升序,nums[j]<=nums[i],让数值大的排名高
                        rank[i] += 1 # 排名高的体现就是让i这个位置排名+1
                else: rank[j] += 1 # 降序就让数值小的时候提高排名
        if self.reverse:
            for i in reversed(range(self.n)): # 降序
                while rank[i] != i: # 直到排名和索引位置一致(升序)或者反过来(降序)
                    r = rank[i] # 当前nums[i]的排名rank[i]
                    self.nums[i],self.nums[r]=self.nums[r],self.nums[i]
                    rank[i],rank[r]=rank[r],rank[i]
        else:
            for i in range(self.n): # 升序
                while rank[i] != i:
                    r = rank[i] 
                    self.nums[i],self.nums[r]=self.nums[r],self.nums[i]
                    rank[i],rank[r]=rank[r],rank[i]     
```

## 桶排序

桶排序是依据元素内最大值和最小值的范围划分区间，每个小区间内进行排序(可以使用插入、归并和快排等算法)，最后使用归并排序即可实现完整的序列排序。桶的个数由用户指定，与自己要排序的数据有关系。

桶排序可以在线性时间内完成排序，当输入元素个数为n，桶的个数是m时，桶的范围取决于nums数组的最大值b和最小值a的差值与桶的个数之商，即(b-a)/m+1，注意不要使用(b-a+1)/m，这可能会导致问题。例如m=3，但是最大值为9，这样可以得到桶的大小是(9-0+1)/3=3，但是9这个元素带入以后发现它属于编号3的桶，实际上第3个桶的编号是2就会导致越界，这是因为桶区间本应该是[0,2]、[3,5]、[6,8]、[9]，而使用(9-0)/3+1=4就正确。

每个桶内分到的元素个数取决于在这个区间有多少元素。

例如一个最小值5，最大值49的数组，它指定桶的大小为5，那么桶的范围数是(49-5+1)/5=9，故5个桶的区间分别为：

[5,13]、[14,22]、[23,31]、[32,40]、[41,49]。

**每个桶内排序时间复杂度为O(klog2k)，m个桶经过换算后时间复杂度为O(nlog2(n/m))**。当m接近n时，时间复杂度趋于一个很小的常数，即O(n)复杂度。

由于桶排序使用了辅助空间，所以桶排序的空间复杂度是O(n + m)。

如果桶内使用插入排序算法等稳定排序算法，则桶排序也是稳定排序算法。

这里给出以插入排序为基础的桶排序方法。

C++版本。

```c++
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
#include "insertSort.h" // 这里的桶排序以插入排序为基础
using namespace std;
template<typename T>
void bucketSort(vector<T> &nums,int bucket_count=5,bool reverse=false){
    // buck_count指定桶的个数,与用户对要排序的数据的考虑有关,选择合适的大小
    T maxVal = *max_element(nums.begin(),nums.end());
    T minVal = *min_element(nums.begin(),nums.end());
    // 注意不要使用(maxVal-minVal+1)/ bucket_count
    int bucket_size = (maxVal-minVal)/ bucket_count+1;//桶区间的范围数,是连续的bucket_size个数
    vector<vector<T>> buckets(bucket_count);//分配bucket_count个桶
    // 每个桶分到的数取决于在桶区间内的数有多少个
    for (auto num :nums){ // 每个数放入哪个桶取决于(num-minVal)/bucket_size的差值
        // 特殊情况,num为最小值自然是第0个桶,最大值就是第bucket-1个桶
        // (maxVal-minVal)/bucket_size=(maxVal-minVal)/(maxVal-minVal+1)*bucket_count=bucket_count-1
        int which_buckets = (num-minVal)/bucket_size;//增强可读性∈[0,bucket_count-1]
        buckets[which_buckets].push_back(num);
    }
    nums.clear();
    for (auto bucket: buckets){
        insertSort(bucket,reverse);//桶排序
        nums.insert(reverse?nums.begin():nums.end(),
            bucket.begin(),bucket.end());//每个桶依次被接在nums后边,降序要前插升序尾插
    }
}
```

Python版本。

```python
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
```

## 基数排序

基数排序本身也是基于桶排序的思路的。桶排序的缺点很明显，如果要排序的数据最大值很大，但是桶的数量指定数目不多时意味着桶的大小很大，这会占据很多的空间，而桶的大小变小意味着桶变多也是一样的结果。

基数排序是考虑了一个性质，比较两个数的大小可以从比较位的大小开始，可以从低位比也可以从高位比。这里选择从低位开始，比较完低位后就能确定在低位上谁更大，但是低位大的不一定大，所以还要比较高位，但是可以比较完低位后调整数字的位置(假如数字超过2个)。例如，数字19、234、6，比较低位，6和4和9，9＞6＞4，所以可以调整为{6,234,19}。然后比较第十位，也就是2>1>0，故调整为{6,19,234}，再看百位其实不用再比了。

**基数排序的时间复杂度是O(n * m)**，m是最大数字指定进制下的位数，取决于使用何种进制radix，radix越大，自然1位能表示的数更多，效率也更高，相较于桶排序时间复杂度O(nlog2(n/m))提高了。另外每个位会分配一个桶，**故空间复杂度为O(n+m)**，这和桶排序一样，区别在于m非常的小，可能就是几个位。

桶排序的m取决于最大值和桶的大小比值，如果桶的大小是5，这意味桶至多存放连续的5位数，那么桶需要65535/5个桶，如果只要5个桶，那每个桶的大小65525/5又过于庞大。如果使用基数排序，65525即使是用2进制表示为1111 1111 1111 1111也就是16位，每个位比较只有0或者1两个数字，故每次需要2个桶，共32个桶，远远低于正常的桶排序。

基数排序的关键有3个步骤：

第一、找到排序数组的最大值，确定其在指定进制下的最大位数maxbit是多少；

第二、根据最大位数maxbit可以确定需要进行几轮桶排序，每一轮根据radix分配radix个桶；

第三、从低位到高位进行maxbit轮桶排序，每次桶排序后清空原数组并把各个桶的元素放回原数组。

第一个步骤确定位数，可以使用最大数字和radix的反复连乘进行比较，每次连乘都没最大数字大位数就+1；

第二个步骤，关键是确定这个数字属于哪个桶，取决于数字的当前位是多少，这个位一定在[0,radix-1]之间。计算一个数字某个位在指定进制下是多少可以有2个方法。第一个是，先除后取余法，表达式为num/(radix^n)%radix，其中n就是哪一位，从0开始。第二个先取余后除法，表达式为(num%radix^(n+1))/radix^n，n从0开始。

C++版本。

```c++
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
int maxBitsOfRadix(const vector<int>&nums,int radix=10);
int whichBucket(const int&nums,int which_bit,int radix=10);
void radixSort(vector<int> &nums,int radix=10,bool reverse=false){
    // 基数排序因为要求低位到高位的数字,只适用于整数排序
    int maxbit = maxBitsOfRadix(nums,radix);//指定进制的最大位数                                                                                                       
    // cout<<"maxbit = "<<maxbit<<endl;
    for (int i = 0;i<maxbit;++i){ //从低位到高位,让数字的该位和桶的编号对应,例如6进制时低位是5,就放入buckets[5]
        vector<vector<int>> buckets(radix);//每个位都在[0,raidx-1]之间,需要radix个桶 
        for (const int &num : nums){ // 遍历每个数字
            int which_bucket = whichBucket(num,i,radix);// 找出数字在指定进制以及当前位属于的桶编号
            if (reverse)
                which_bucket = radix - 1 - which_bucket; //降序的话桶0不和数字0对应,而是与数字radix-1对应
            buckets[which_bucket].push_back(num); // 把符合条件的数字移入这个桶
        }
        nums.clear();//清空nums,把每个桶的元素放回去,用于下一次判断,继续判断高位
        for (auto &bucket:buckets){
            for(const int& num:bucket){
                nums.push_back(num);
            }
        }
    }
}
int whichBucket(const int&num, int which_bit,int radix){
        // 找出数字在指定进制以及指定位属于的进制桶编号
        int radix_n = 1;// r^0
        while (which_bit--){
            radix_n *= radix; // 计算r^n
        }
        // // (x%r^(n+1))/r^n可以计算数字x第n位的数字是多少,进而知道属于哪个桶
        // int which_bucket = (num % (radix*radix_n)) / radix_n;
        // return which_bucket;
        return num/(radix_n)%radix; // 2个方法都可以 num/(radix^which_bit)%radix
}
int maxBitsOfRadix(const vector<int>&nums,int radix){
    // 用于找到数组中最大元素在指定进制radix下的最大位数
    int maxVal = *max_element(nums.begin(),nums.end());
    int maxbit = 1;//至少1位
    int p = radix;
    while (maxVal >= p) //满radix进1,常见基数排序的进制可取2,3,4,5...10
    {
        p *= radix;//例如6进制,[0,5]可以用1位表示,[6,35]可以用6进制数10~55表示
        // 36就必须用3位即100来表示
        ++maxbit;//只要满足条件就说明进1位,初始radix=6,若num<6,则maxbit=1不变
    }
    return maxbit;
}
```

Python版本。

```c++
from typing import Any, List
class radixSort:
    def __init__(self,nums:List[int or float],radix=5,reverse=False) -> Any:
        self.nums = nums
        self.n = len(self.nums)
        self.reverse = reverse
        self.radix = radix
    def radix_sort(self)->List[int or float]:
        maxbit = self.maxBitOfRadix()
        for i in range(maxbit):
            buckets = [[] for _ in range(self.radix)]
            for num in self.nums:
                which_bucket = self.whichBucket(num,i)
                if self.reverse:
                    which_bucket = self.radix - 1 - which_bucket
                buckets[which_bucket].append(num)
            self.nums.clear()
            for bucket in buckets:
                for num in bucket:
                    self.nums.append(num)
    def maxBitOfRadix(self)->int:
        maxVal = max(self.nums)
        maxbit = 1
        p = self.radix
        while maxVal>=p:
            p *= self.radix
            maxbit += 1
        return maxbit
    def whichBucket(self,num:int,which_bit:int)->int:
        # 2个方法都可以
        # radix_n = 1 # r^0
        # while which_bit:
        #     radix_n *= self.radix
        #     which_bit -= 1
        # return (num % (self.radix*radix_n)) // radix_n
        return num//(self.radix**which_bit)%self.radix
```



































