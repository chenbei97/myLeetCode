/*** 
 * @Author: chenbei
 * @Date: 2022-03-17 09:45:06
 * @LastEditTime: 2022-03-17 14:04:11
 * @Description: quickSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\quickSort.h
 * @A boy without dreams
 */
#ifndef quickSort_
#define quickSort_
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
void _quickSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    cout<<"quickSort => \n";
    quickSort(nums,0,nums.size()-1,true);
    ostream_iterator<int> os(cout," ");
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !quickSort_