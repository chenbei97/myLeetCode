/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:28:56
 * @LastEditTime: 2022-04-21 11:30:13
 * @Description: test remove.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\remove.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\remove remove.cpp
..\output\remove.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 移除指定元素,返回指向end的迭代器
    vector<int> src = {1,2,3,0,0,0,4,5,6};
    auto it = remove(src.begin(), src.end(), 0);
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), it, out); // it指向end
    cout << endl;
    return 0;
}
