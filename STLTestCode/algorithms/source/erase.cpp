/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:38:40
 * @LastEditTime: 2022-04-21 11:46:02
 * @Description: test erase.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\erase.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\erase erase.cpp
..\output\erase.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 去除指定的元素返回去除的个数
    vector<int> src = {0,1,2,2,2,2,5,4,2,6,4,2,43,2};
    auto it = erase(src,2); // 不传入迭代器,直接传容器
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout << endl;
    cout <<"it = " << it << endl; // it = 7
    return 0;
}