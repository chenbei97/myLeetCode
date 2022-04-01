/*** 
 * @Author: chenbei
 * @Date: 2022-04-01 16:17:11
 * @LastEditTime: 2022-04-01 16:24:19
 * @Description: linearArrayColorClassify_Iteration.h
 * @FilePath: \myLeetCode\linearArray\linearArrayColorClassify_Iteration.h
 * @A boy without dreams
 */
#ifndef linearArrayColorClassifyIteration_
#define linearArrayColorClassifyIteration_
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class linearArrayColorClassifyIteration{
    public:
        void setColors(vector<int>&nums){
            int n = nums.size();
            int ptr = 0;
            for (int i = 0; i < n; ++i) { // 第1次遍历结果是所有的0跑到前边
                if (nums[i] == 0) {
                    swap(nums[i], nums[ptr]); // ptr总是指向靠前的范围
                    ++ptr; // 把是0的元素交换前边,然后交换过的不要再交换,所以让ptr++
                }
            }//结束后ptr是在最后1个0的后边位置
            for (int i = ptr; i < n; ++i) { //从不是0的位置开始同理把1弄到前边,2自动排好
                if (nums[i] == 1) {
                    swap(nums[i], nums[ptr]);
                    ++ptr;
                }
            }
        }
};
void _linearArray_colorClassify_iteration(){
    linearArrayColorClassifyIteration solution;
    vector<int> nums = {2,0,2,1,1,0,2,0,1,2,0,0,2};
    solution.setColors(nums);
    ostream_iterator<int> os(cout," ");
    cout<<"iteration as follows\n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif//!linearArrayColorClassifyIteration_