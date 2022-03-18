/*** 
 * @Author: chenbei
 * @Date: 2022-03-17 14:55:02
 * @LastEditTime: 2022-03-18 11:52:23
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
/*
从最后一个非叶子结点遍历,是为了从最小的子树开始检查,最小子树只需要比较根节点和2个子节点就可以确定最小子树是否满足定义
不满足定义,只需要交换1次,因为子节点不会再有子树会比根节点的值大,否则它不是最小子树
然后继续检查倒数第2个子树,倒数第3个子树直到全局最大树,每个子树都是更上一级子树的子节点
倒序检查的目的是若低级子树满足根堆定义,则高级子树的根节点值大于2个低级子树时那么高级树也必定满足根堆定义,因为低级子树已检查过定义
但更大树如果存在子树(左或右子树)大于更大树的根节点值,很可能子树的子树也会比更大树的根节点值大
这也是为何for循环内部的while循环要检查子树的所有子树,这是为了实现自上而下的交换,把小的值下移到子树,大的值上移到根
while循环是自上而下的检查,每一轮都会把子树较大的移到根,最后一轮循环结束,那个节点把自己的值给了根,节点自己则应该接收更大树根值
单纯的交换根节点和某个子树的子树的..子树的某个节点,虽然保证了当前根节点大于了所有子节点
但是可能会破坏某个子树的子树的..子树的根节点也要大于它下方的所有节点的事实,因为所有子树都要满足根节点大于子节点
而倒序遍历因为是从最小子树往全局最大树检查的,基层子树开始就保证不会破坏这种关系,那么全局树也不会破坏这种关系
*/
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
            
            // 不满足大根堆的定义时nums[child]<nums[root],但是有可能child的child也会比root大
            // 除了交换root和child,在child不超出范围时也要继续检测child的子树
            nums[child/2] = nums[child]; // root就是child/2,<=>nums[root]=nums[child]
            child *= 2; // 检测child的孩子2*child和2*child+1,下一轮while进行判断,必要的话也会交换child和它的child
            // 有可能会nums[child*2]或nums[child*2+1]>nums[child]
            // 让child*2和child*2+1的较大者和child比较,child大则已,小就交换
            // 因为child在进入下一轮while之前已经变成child's child,所以依然nums[child/2]=max(nums[child],nums[child+1])
            // 直到child超出n-1的数组范围
        }
        // 在while内,如果不满足根堆定义,每个根节点都会和其孩子的较大值交换,最后1次while结束child是孩子
        // 它的父亲child/2将其父亲child/4替换了,child/2本身应当接收原本较小的那个根节点值也就是rootVal
        // 根节点也应当回到子树内这个合适的节点位置,while结束后child/2就是这个位置
        nums[child/2] = rootVal; // 最合适的那个节点接收原来的根节点值
    }
}
/*
本质上不是删除堆顶元素,而是用数组后边的元素去覆盖前边的元素
事实上取出的是数组的最后1个元素,这样方便删除,然后把这个元素插入到合适的位置即可
这里的while循环是自上而下的检查,而不是初始化时自下而上的检查
在while内部尝试找到某个合适的位置插入这个元素,如果插入的元素比2个子树的节点值都大,就把元素覆盖到2个子树的根节点
因为是自顶向下的,元素能比2个子树节点都大的话,说明就找到了合适的位置,2个子树的下方必定不会有更合适的位置
然后把原本不合适的2个子树根节点的值挪到后边,它将在以后的for循环中被检查
如此重复,假设能检查到最后1个非叶子节点,它一定是要插入元素的根节点,它如果没有插入的元素更合适,就让元素替换这个非叶子节点
这样其实相当于要插入的元素还是最大/小的,它只是覆盖到前一个位置
*/
template<typename T>
void popHeap(vector<T>&nums,bool reverse){
    // 移除全局根节点,然后重新排列根堆,就是用后面的覆盖前边的即可
    int lastIdx = nums.size()-1;
    T lastVal = nums[lastIdx--];//所以记录好最后1个元素
    nums.pop_back();
    int child=1; // 覆盖的过程和初始化根堆过程是一样的,root是现在的nums[0],区别是自上而下的遍历
    while (child<=lastIdx){ // 类似于检查子树是否满足根堆定义,重构根堆
        if (child<lastIdx && (reverse?nums[child]<nums[child+1]:nums[child]>nums[child+1]))
            ++child; // 找到2个更大/小的子节点和要插入的节点比较
        if (reverse?lastVal>=nums[child]:lastVal<=nums[child])
            break; // 要插入的节点大/小于2个子节点就一定满足根堆定义
        nums[child/2] = nums[child]; // 把大的子节点值覆盖根节点root
        child *= 2; // 不满足,插入节点更合适的位置应当在child的child中寻找
    }
    // 每1轮while结束,child都是提前扩到2倍,child/2才是最后1个换到其根节点child/4的节点
    nums[child/2] = lastVal; // 最后1轮,child/2换到child/4,故child/2是最适合lastVal插入的位置
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