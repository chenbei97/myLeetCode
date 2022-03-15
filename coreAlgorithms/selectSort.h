/*** 
 * @Author: chenbei
 * @Date: 2022-03-15 11:40:02
 * @LastEditTime: 2022-03-15 15:00:00
 * @Description: selectSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\selectSort.h
 * @A boy without dreams
 */
#ifndef selectSort_
#define selectSort_
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
void _selectSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    selectSort(nums,true);
    cout<<"selectSort => \n";
    ostream_iterator<int> os(cout," ");
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif //!selectSort_