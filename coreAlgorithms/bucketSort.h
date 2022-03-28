/*** 
 * @Author: chenbei
 * @Date: 2022-03-28 16:46:34
 * @LastEditTime: 2022-03-28 16:49:37
 * @Description: bucketSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\bucketSort.h
 * @A boy without dreams
 */
#ifndef bucketSort_
#define bucketSort_
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void bucketSort(vector<T> &nums,bool reverse=false){

}
void _bucketSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    bucketSort(nums,true);
    ostream_iterator<int> os(cout," "); 
    cout<<"bucketSort => \n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !bucketSort_