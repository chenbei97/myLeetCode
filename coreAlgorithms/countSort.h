/*** 
 * @Author: chenbei
 * @Date: 2022-03-28 14:49:08
 * @LastEditTime: 2022-03-28 16:12:04
 * @Description: countSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\countSort.h
 * @A boy without dreams
 */
#ifndef countSort_
#define countSort_
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
template<typename T>
void countSort(vector<T> &nums,bool reverse=false){
    // 计数排序第一步是找到所有数字的排名
    vector<int> rank(nums.size());
    int i = 0;
    for(;i<nums.size();++i){ // 不重复的两两元素比较,只要某个位置元素比另一个位置元素大就提高1个排名
        for(int j=0;j<i;++j)//如果是升序,nums[j]<=nums[i],让数值大的排名高
            if(reverse?nums[j]>nums[i]:nums[j]<=nums[i]) ++rank[i];//排名高的体现就是让i这个位置排名+1
            else ++rank[j];// 降序就让数值小的时候提高排名
    }
    if (reverse){ // 降序
        for(int i=nums.size()-1;i>=0;--i){// 直到排名和索引位置一致(升序)或者反过来(降序)
            int r = rank[i];//当前元素nums[i]的排名是rank[i]
            swap(nums[i],nums[r]);//把当前元素交换到指定的排名位置处,那个元素交换回来,后序继续判断它的位置
            swap(rank[i],rank[r]);//排名也发生了变化要一并进行交换
        }
    }
    else{ // 升序
        for(int i=0;i<nums.size();++i){
            while (rank[i] != i){  
                int r = rank[i];
                swap(nums[i],nums[r]);
                swap(rank[i],rank[r]);
            }  
        }
    }

}
void _countSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    bubbleSort(nums,true);
    ostream_iterator<int> os(cout," "); 
    cout<<"countSort => \n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !countSort_