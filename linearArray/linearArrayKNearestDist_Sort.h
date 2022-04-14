/*** 
 * @Author: chenbei
 * @Date: 2022-04-14 15:08:22
 * @LastEditTime: 2022-04-14 15:36:21
 * @Description: linearArrayKNearestDist_Sort.h
 * @FilePath: \myLeetCode\linearArray\linearArrayKNearestDist_Sort.h
 * @Signature: A boy without dreams
 */
#ifndef linearArrayKNearestDistSort_
#define linearArrayKNearestDistSort_
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class linearArrayKNearestDistSort{
    public:
        vector<vector<int>> kNearestDist(vector<vector<int>>&nums,int k){
            // nums是容器的容器,内容器只有2个元素
            // 返回bool值的匿名函数
            auto foo = [](const vector<int>&z1,const vector<int>&z2)->bool{
                return z1[0]*z1[0]+z1[1]*z1[1]<z2[0]*z2[0]+z2[1]*z2[1];
            };
            sort(nums.begin(),nums.end(),foo);
            return {nums.begin(),nums.begin()+k};//聚合类型
        }
};
void _linearArray_kNearestDist_sort(){
    linearArrayKNearestDistSort solution;
    vector<vector<int>> nums = {{3,4},{6,8},{1,1},{-3,4},{5,5},{7,9},{4,4}};
    auto ans = solution.kNearestDist(nums,3); // 最近的3个{3,4},{1,1},{-3,4}
    ostream_iterator<int> os(cout," ");
    cout<<"get k nearest distance by sort as follows\n";
    for (auto& vec:ans){
        copy(vec.begin(),vec.end(),os);
        cout<<"\n";
    }
}
#endif//!linearArrayKNearestDistSort_