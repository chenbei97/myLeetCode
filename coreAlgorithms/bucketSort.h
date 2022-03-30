/*** 
 * @Author: chenbei
 * @Date: 2022-03-28 16:46:34
 * @LastEditTime: 2022-03-30 12:22:59
 * @Description: bucketSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\bucketSort.h
 * @A boy without dreams
 */
#ifndef bucketSort_
#define bucketSort_
#include <vector>
#include <iostream>
#include <iterator> // include ostream_iterator
#include "insertSort.h" // 这里的桶排序以插入排序为基础
using namespace std;
template<typename T>
void bucketSort(vector<T> &nums,int bucket_count=5,bool reverse=false){
    // buck_count指定桶的个数,与用户对要排序的数据的考虑有关,选择合适的大小
    T maxVal = *max_element(nums.begin(),nums.end());
    T minVal = *min_element(nums.begin(),nums.end());
    // 注意不要使用(maxVal-minVal+1)/ bucket_count
    int bucket_size = (maxVal-minVal)/ bucket_count+1;//桶区间的范围数,是连续的bucket_size个数
    vector<vector<T>> buckets(bucket_count);//分配bucket_count个桶
    // 每个桶分到的数取决于在桶区间内的数有多少个
    for (auto num :nums){ // 每个数放入哪个桶取决于(num-minVal)/bucket_size的差值
        // 特殊情况,num为最小值自然是第0个桶,最大值就是第bucket-1个桶
        // (maxVal-minVal)/bucket_size=(maxVal-minVal)/(maxVal-minVal+1)*bucket_count=bucket_count-1
        int which_buckets = (num-minVal)/bucket_size;//增强可读性∈[0,bucket_count-1]
        buckets[which_buckets].push_back(num);
    }
    nums.clear();
    for (auto bucket: buckets){
        insertSort(bucket,reverse);//桶排序
        nums.insert(reverse?nums.begin():nums.end(),
            bucket.begin(),bucket.end());//每个桶依次被接在nums后边,降序要前插升序尾插
    }
}
void _bucketSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    bucketSort(nums,3,true);
    ostream_iterator<int> os(cout," "); 
    cout<<"bucketSort => \n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !bucketSort_