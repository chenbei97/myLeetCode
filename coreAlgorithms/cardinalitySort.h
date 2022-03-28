/*** 
 * @Author: chenbei
 * @Date: 2022-03-28 16:48:24
 * @LastEditTime: 2022-03-28 16:48:25
 * @Description: cardinalitySort.h
 * @FilePath: \myLeetCode\coreAlgorithms\cardinalitySort.h
 * @A boy without dreams
 */
#ifndef cardinalitySort_
#define cardinalitySort_
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void cardinalitySort(vector<T> &nums,bool reverse=false){

}
void _cardinalitySort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    cardinalitySort(nums,true);
    ostream_iterator<int> os(cout," "); 
    cout<<"cardinalitySort => \n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !cardinalitySort_