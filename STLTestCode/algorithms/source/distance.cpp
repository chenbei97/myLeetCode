/*
g++ -o ..\output\distance distance.cpp
..\output\distance.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    /*  distance可以返回两个迭代器之间的距离
        template< class InputIt >
        typename std::iterator_traits<InputIt>::difference_type
            distance( InputIt first, InputIt last);
        定义于头文件<iterator>,C++17起为constexpr
        InputIt必须满足遗留输入迭代器(LegacyInputIterator)的要求
        若InputIt额外满足遗留随机访问迭代器(LegacyRandomAccessIterator)的要求则操作更高效
        从first走到last所需的自增数
        若使用随机访问迭代器且first可从 last 抵达，则值可能为负(C++11起)
    */
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it1 = src.begin();
    vector<int>::iterator it2 = src.end();
    cout << "distance: " << distance(it1,it2) / 2 << endl; // 5
    auto pivot = *std::next(it1, std::distance(it1,it2)/2); // pivot = 5,从begin=0移动5位
    cout << "pivot: " << pivot << endl; // src[5]=6,中间元素的下一个,如果是偶数那位置就是n/2=5
    src.push_back(11);
    it1 = src.begin();
    it2 = src.end();
    cout <<"distance: " << distance(it1,it2) / 2 << endl; // 5
    cout << "pivot = "<< *std::next(it1, std::distance(it1,it2)/2) << endl; //如果是奇数,n/2不会影响还是5,pivot恰好是中间元素
    return 0;
}