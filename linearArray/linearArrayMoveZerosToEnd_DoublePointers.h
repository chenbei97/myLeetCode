/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 09:57:47
 * @LastEditTime: 2022-03-31 10:22:15
 * @Description: linearArrayMoveZerosToEnd_DoublePointers.h
 * @FilePath: \myLeetCode\linearArray\linearArrayMoveZerosToEnd_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linearArrayMoveZerosToEndDoublePointers_
#define linearArrayMoveZerosToEndDoublePointers_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class linearArrayMoveZerosToEndDoublePointers{
    public:
        void moveZeros(vector<int>&nums){
            int left=0,n=nums.size();
            for(int right=0;right<n;++right){
                if (nums[right]!=0){//如果指针元素非0,就交换到左边
                    swap(nums[right],nums[left]);//一种倾向,0元素总是被交换到右边
                    ++left;//如果发生了交换,说明left位置已经非0,0元素一定在[left+1,]后面
                }
            }
        }
};
void _linearArray_moveZerosToEnd_doublePointers(){
    linearArrayMoveZerosToEndDoublePointers solution;
    vector<int> nums = {0,4,2,0,5,0,2,1};
    solution.moveZeros(nums);
    ostream_iterator<int> os(cout," ");
    cout<<"move zeros to end by double pointers as follows\n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif//!linearArrayMoveZerosToEndDoublePointers_