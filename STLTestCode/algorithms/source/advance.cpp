/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 11:49:45
 * @LastEditTime: 2022-04-22 11:50:49
 * @Description: test advance.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\advance.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\advance advance.cpp
..\output\advance.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 前进3个迭代器,但是不返回任何东西
    // next返回移动后的迭代器
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it = src.begin();
    advance(it,3); // 让迭代器指向第四个元素
    cout << *it << endl;// 4
    ostream_iterator<int> out(cout," ");
    return 0;
}