/*** 
 * @Author: chenbei
 * @Date: 2022-04-01 16:06:18
 * @LastEditTime: 2022-04-01 16:40:40
 * @Description: linearArrayColorClassify_DoublePointers.h
 * @FilePath: \myLeetCode\linearArray\linearArrayColorClassify_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linearArrayColorClassifyDoublePointers_
#define linearArrayColorClassifyDoublePointers_
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class linearArrayColorClassifyDoublePointers{
    public:
        void setColors(vector<int>&nums){
            int n = nums.size();
            int ptr1 = 0, ptr2 = 0;
            for (int i = 0; i < n; ++i) { // 1次遍历
                if (nums[i] == 1) { //  ptr2总是指向靠前的范围
                    swap(nums[i], nums[ptr2]); //元素1被换到前边去
                    ++ptr2;// 避免重复被换回来,现在的nums[ptr2]可能是0也可能是2
                } 
                else if (nums[i] == 0) { //ptr1也是指向靠前的范围
                    swap(nums[i], nums[ptr1]);//元素0也要换到前边去,现在的nums[ptr1]不是0,只可能是1或者2
                    if (ptr1 < ptr2) { // ptr1指向的是1or2,ptr2指向的是0or2
                        // ptr2如果先+,必定比ptr1大,ptr1因为指向的是1or2,ptr2可能指向0,故ptr2一定要换到前边试一试
                        swap(nums[i], nums[ptr2]);// 现在的nums[i]是nums[ptr1]
                        // 还要把nums[ptr1]和nums[ptr2]交换一下,现在的nums[ptr2]不是1
                    }
                    ++ptr1; // 避免重复被换回来
                    ++ptr2;
                }
            }
        }
};
void _linearArray_colorClassify_doublePointers(){
    linearArrayColorClassifyDoublePointers solution;
    vector<int> nums = {2,0,2,1,1,0,2,0,1,2,0,0,2};
    solution.setColors(nums);
    ostream_iterator<int> os(cout," ");
    cout<<"double pointers as follows\n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif//!linearArrayColorClassifyDoublePointers_