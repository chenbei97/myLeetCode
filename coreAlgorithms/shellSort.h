/*** 
 * @Author: chenbei
 * @Date: 2022-03-16 08:46:53
 * @LastEditTime: 2022-03-16 09:58:37
 * @Description: shellSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\shellSort.h
 * @A boy without dreams
 */
#ifndef shellSort_
#define shellSort_
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
void _shellSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    shellSort(nums,true);
    cout<<"shellSort => \n";
    ostream_iterator<int> os(cout," ");
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !shellSort_