/*** 
 * @Author: chenbei
 * @Date: 2022-03-17 14:55:02
 * @LastEditTime: 2022-03-17 17:00:11
 * @Description: heapSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\heapSort.h
 * @A boy without dreams
 */
#ifndef heapSort_
#define heapSort_
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
template<typename T>
void popHeap(vector<T>&nums,bool reverse = false);
template<typename T>
void initialHeap(vector<T>&nums,bool reverse = false);
template<typename T>
T topHeap(vector<T>&nums);

template<typename T>
void heapSort(vector<T>&nums, bool reverse = false){
    vector<int> ans;
    initialHeap(nums,reverse);
    while (!nums.empty()){
        ans.push_back(topHeap(nums));
        popHeap(nums,reverse);   
    }
    nums = ans;
}
template<typename T>
void initialHeap(vector<T>&nums,bool reverse){
    // 建立大根堆或者小根堆
    // 下面的注释统一以大根堆进行说明
    int n = nums.size();
    // 从最后1个具有非叶子节点(有孩子的节点)开始,它在数组的位置为n/2
    for (int root = n/2 ;root >=0;--root){
        T rootVal = nums[root]; // 记录根的值
        int child = root*2; // 检测根的子树是否也是大根堆
        while (child<=n-1) // 检测子树要检查到最后1个不超过范围的元素为止
        {
            // child<n-1的条件可以保证child+1不越界,child+1就是child的兄弟节点
            if (child < n-1 && (reverse?nums[child]<nums[child+1]:nums[child]>nums[child+1]))
                ++child; // 如果兄弟节点更大,只需要比较根节点和兄弟节点即可
            if (reverse?rootVal>=nums[child]:rootVal<=nums[child])
                break; // 根节点值比最大的子节点那个还大,说明root以下的子树满足大根堆定义
            // 不满足大根堆的定义时nums[child]<nums[root]
            // 把子节点的值和根节点的值交换,就符合根节点>子节点的定义了
            nums[child/2] = nums[child]; // root就是child/2,<=>nums[root]=nums[child]
            child *= 2; // 由于root会慢慢向全局根节点移动,child的孩子2*child和2*child+1
            // 有可能会nums[child*2]或nums[child*2+1]>nums[child]
            // 让child*2和child*2+1的较大者和child比较
            // 那么nums[child]=max(nums[child*2],nums[child*2+1])
            // 直到child超出n-1的数组范围
        }
        // 在while内,根节点会被子树内最合适(大)的节点依次向上替换
        // 根节点也应当回到子树内这个合适的节点位置,while结束后child/2就是这个位置
        nums[child/2] = rootVal; // 最合适的那个节点接收原来的根节点值
    }

}
template<typename T>
void popHeap(vector<T>&nums,bool reverse){
    int lastIdx = nums.size()-1;
    T lastVal = nums[lastIdx--];
    nums.pop_back();
    int root=0,child=1;
    while (child<=lastIdx){
        if (child<lastIdx && (reverse?nums[child]<nums[child+1]:nums[child]>nums[child+1]))
            ++child;
        if (reverse?lastVal>=nums[child]:lastVal<=nums[child])
            break;
        nums[child/2] = nums[child];
        child *= 2; 
    }
    nums[child/2] = lastVal; 
}
template<typename T>
T topHeap(vector<T>&nums){
    return nums[0];
}
void _heapSort_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};//20,12,35,15,10,80,30,17,2,1
    cout<<"heapSort => \n";
    heapSort(nums,true);
    ostream_iterator<int> os(cout," ");
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !heapSort_