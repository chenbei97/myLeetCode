/*** 
 * @Author: chenbei
 * @Date: 2022-03-16 10:08:31
 * @LastEditTime: 2022-03-16 15:18:14
 * @Description: mergeSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\mergeSort.h
 * @A boy without dreams
 */
#ifndef mergeSort_
#define mergeSort_
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
template<typename T>
vector<T> merge(const vector<T>&left,const vector<T>&right,bool reverse=false);
template<typename T>
vector<T> mergeSort(const vector<T>&nums,bool reverse = false){ // 归并排序
    int n = nums.size();
    if (n < 2) return nums; // 至少有2个元素
    int mid = n / 2; // 中间位置
    vector<T> left(nums.begin(),nums.begin()+mid);
    vector<T> right(nums.begin()+mid,nums.end());
    return merge(mergeSort(left,reverse),mergeSort(right,reverse),reverse);
}
template<typename T>
vector<T> merge(const vector<T>&left,const vector<T>&right,bool reverse) { // 归并操作
    // 用于归并下层递归退出后已得到的2个有序子序列
    // 最初的2个有序子序列各自只有1个元素
    vector<T> res;
    int n1=left.size()-1,n2=right.size()-1;
    int i=0,j=0;
    while (i<=n1 || j<=n2)
    {
        if (reverse?left[i]>right[j]:left[i]<=right[j]) // 如果是降序,就大的被添加否则小的被添加
        {
            res.push_back(left[i]);
            ++i;
        }
        else
        {
            res.push_back(right[j]);
            ++j;
        }
        // 结束后i,j可能会超出范围,需要进行考虑
        // 参考双指针法实现2个有序数组合并
        if (i>n1&& j<=n2) // 可能i先超范围
        {   
            for(int k=j;k<=n2;++k)
            { // 把right剩余的直接加进去
                res.push_back(right[k]);
            }
            break;
        }
        if (i<=n1 && j>n2)
        { // 可能j先超范围
            for(int k=i;k<=n1;++k)
            { // 把left剩余的直接加进去
                res.push_back(left[k]);
            }
            break;
        }
    }
    return res;
}   
void _mergeSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9}; 
    auto ans = mergeSort(nums,true);
    cout<<"mergeSort => \n";
    ostream_iterator<int> os(cout," ");
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif // !mergeSort_