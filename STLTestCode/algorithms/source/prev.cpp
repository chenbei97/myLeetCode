/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 14:46:36
 * @LastEditTime: 2022-04-22 14:48:23
 * @Description: test prev.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\prev.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\prev prev.cpp
..\output\prev.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 和next对应,可以返回移动后的迭代器,advance是不同的返回void
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    auto it = prev(src.end(), 3);
    cout << *it << endl;// 8
    return 0;
}
