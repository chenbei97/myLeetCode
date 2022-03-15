/*** 
 * @Author: chenbei
 * @Date: 2022-03-15 10:30:56
 * @LastEditTime: 2022-03-15 11:48:33
 * @Description: bubbleSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\bubbleSort.h
 * @A boy without dreams
 */
#ifndef bubbleSort_
#define bubbleSort_
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
void _bubbleSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    bubbleSort(nums,true);
    ostream_iterator<int> os(cout," "); 
    cout<<"bubbleSort => \n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif //!bubbleSort_
