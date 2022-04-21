/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:01:32
 * @LastEditTime: 2022-04-21 10:08:10
 * @Description: test partitioned.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\partitioned.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o partitioned partitioned.cpp
.\partitioned.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到符合条件的元素,这里是返回第一个不是偶数的迭代器
    // 所以这个函数会改变原因有src的元素分布
    vector<int> src = {1,3,7,2,4,6,9,8,0,5};
    auto it = partition(src.begin(), src.end(), [](int x){return x%2==0;});
    cout << "partitioned: \n";
    cout <<*it<<endl; // 7,返回指向第1个奇数的迭代器,前边的都是偶数
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl; // 10 8 6 2 4 7 9 3 1 5
    return 0;
}