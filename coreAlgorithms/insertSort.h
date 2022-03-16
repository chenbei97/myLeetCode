/*** 
 * @Author: chenbei
 * @Date: 2022-03-15 13:38:41
 * @LastEditTime: 2022-03-16 09:21:45
 * @Description: insertSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\insertSort.h
 * @A boy without dreams
 */
#ifndef insertSort_
#define insertSort_
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
void _insertSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    insertSort(nums,true);
    cout<<"insertSort => \n";
    ostream_iterator<int> os(cout," ");
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif //!insertSort_