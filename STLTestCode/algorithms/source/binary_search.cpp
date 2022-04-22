/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 08:22:08
 * @LastEditTime: 2022-04-22 08:37:23
 * @Description: test binary_search.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\binary_search.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\binary_search binary_search.cpp
..\output\binary_search.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到这个值返回true,否则返回false
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    int value = 5;
    auto it = binary_search(src.begin(), src.end(), value);
    if(it)
    {
        cout << "find " << value << endl; // find 5
    }
    else
    {
        cout << "not find " << value << endl;
    }
    // 指定函数对象也可以,但必须和用于对被查找序列进行排序的比较操作有相同的效果
    // 现在容器是升序的,但是传入的比较函数对象是降序的
    // 所以返回的是false,而不是true
    auto it2 = binary_search(src.begin(), src.end(), value,greater<int>());
    if(it2)
    {
        cout << "find " << value << endl;
    }
    else
    {
        cout << "not find " << value << endl; // not find 5
    }
    return 0;
}