/*
g++ -o ..\output\partition partition.cpp
..\output\partition.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
namespace partition_test { // 防止命名空间冲突
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last) return first; // 如果迭代器没找到符合条件p的元素就会到达last,那么直接返回first
 
    for (ForwardIt i = std::next(first); i != last; ++i) { // 对first后边的元素总是循环遍历
        if (p(*i)) { // 只要迭代器i指向的元素满足条件就交换到前边first的位置
            std::iter_swap(i, first);
            ++first; // 然后移动first,最终的结果就是first会指向分组后首个不满足条件的元素
        }
    }
    return first;
}
}
int main()
{
    /*
        定义于头文件<algorithm>
        c++11:
            template< class ForwardIt, class UnaryPredicate >
            ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p );
        c++20:
            template< class ForwardIt, class UnaryPredicate >
            constexpr ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p );
        c++17:(重载)
            template< class ExecutionPolicy, class ForwardIt, class UnaryPredicate >
            ForwardIt partition( ExecutionPolicy&& policy,ForwardIt first, ForwardIt last, UnaryPredicate p );
        作用:
            重排序范围[first, last)中的元素
            使得谓词p对其返回true的元素前于谓词p对其返回false的元素,谓词表达式必须可转化为bool
            不保持相对顺序
            如果指定了策略policy,则按照策略执行
        返回值:指向第二组元素首元素的迭代器
        可能的实现如下：
            template<class ForwardIt, class UnaryPredicate>
            ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
            {
                first = std::find_if_not(first, last, p);
                if (first == last) return first;
            
                for (ForwardIt i = std::next(first); i != last; ++i) {
                    if (p(*i)) {
                        std::iter_swap(i, first);
                        ++first;
                    }
                }
                return first;
            }
        不过partition函数是不稳定的,会影响元素相对次序,现在使用stable_partition函数代替
        此函数还可应用于快速排序，可见myLeetCode/coreAlgorithms/quickSort.hpp
    */
    vector<int> src = {8,7,5,3,6,-1,2,4,0,10,9};
    // 测试使用partition函数,将数字分为2组,奇数和偶数
    auto first = src.begin();
    auto last = src.end();
    auto secondIter = std::partition(first, last, [](int em){ return em % 2 != 0; });
    ostream_iterator<int> out(cout," ");
    copy(first, secondIter, out);
    cout << endl; // 奇数组：9 7 5 3 -1
    copy(secondIter, last, out);
    cout << endl; // 偶数组：6 2 4 0 10 8
    // 如果使用自定义的partition函数,将数字分为2组,奇数和偶数
    vector<int> dst = {8,7,5,3,6,-1,2,4,0,10,9};
    first = dst.begin();
    last = dst.end();
    secondIter = partition_test::partition(first, last, [](int em){ return em % 2 != 0; }); 
    copy(first, secondIter, out);
    cout << endl; // 奇数组：7 5 3 -1 9
    copy(secondIter, last, out);
    cout << endl; // 偶数组：8 2 4 0 10 6
    // 可以看出partition函数是不稳定的,因为它会改变元素的相对顺序
    return 0;
}