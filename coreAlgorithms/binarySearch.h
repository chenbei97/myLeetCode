/*** 
 * @Author: chenbei
 * @Date: 2022-03-15 09:03:50
 * @LastEditTime: 2022-03-15 10:05:32
 * @Description: binary search
 * @FilePath: \myLeetCode\coreAlgorithms\binarySearch.h
 * @A boy without dreams
 */
#ifndef binarySearch_
#define binarySearch_
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
void _binarySearch_testCode(){
    vector<double> nums={4.8,5.2,7.9,10,11.2,44.2,-14.7,2};
    cout <<"binarySearch=> 44.2's idx in sorted nums is "<<binarySearch(nums,44.2)<< endl;
    cout <<"binarySearch=> 11's idx in sorted nums is "<<binarySearch(nums,11.0)<< endl;
}
#endif // !binarySearch_

