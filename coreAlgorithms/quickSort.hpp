#ifndef _QUICKSORT_HPP_
#define _QUICKSORT_HPP_
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;
// #include <forward_list>
namespace quickSortBySTL { // 防止命名空间冲突
template <class ForwardIt>
void quickSort(ForwardIt first, ForwardIt last,bool reverse=false) // T模板,提供前向迭代器的first和last
{
    if(first == last) return;
    ForwardIt middle1,middle2;
    auto pivot = *std::next(first, std::distance(first,last)/2); // 找到中间元素,distance可以返回2个迭代器之间的距离
    if (reverse) { // 降序
        middle1 = std::partition(first,last, // partition返回一个迭代器,指向第一个不满足条件的元素
                    [pivot,reverse](const auto& em){return em > pivot;});// 要求找到小于pivot的元素,也就是把小于pivot的元素放到前面
        middle2 = std::partition(middle1, last, [pivot](const auto& em){return em >= pivot;}); // 左区间是小于pivot的元素,右区间是大于pivot的元素
    } else {
        middle1 = std::partition(first,last, [pivot](const auto& em){return em < pivot;}); // 升序
        middle2 = std::partition(middle1, last, [pivot](const auto& em){return em <= pivot;});
    }
    quickSort(first, middle1, reverse); // 分而治之效率更快,左递归和右递归
    quickSort(middle2, last, reverse);
}
}
void _quickSortSTL_testCode(){
    vector<int> nums={5,4,3,2,1,0,9};
    auto first = nums.begin();
    auto last = nums.end();
    cout<<"quickSortSTL ascendingOrder => \n";
    quickSortBySTL::quickSort(first, last);
    ostream_iterator<int> os(cout," ");
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
    cout <<"quickSortSTL descendingOrder => \n";
    quickSortBySTL::quickSort(first, last,true);
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !_QUICKSORT_HPP_