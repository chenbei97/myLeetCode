/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 11:46:13
 * @LastEditTime: 2022-04-22 11:48:45
 * @Description: test next.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\next.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\next next.cpp
..\output\next.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // next可以获取指定步数后的迭代器,不指定步数默认1步
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    auto it = next(src.begin(), 3);
    cout << *it << endl;
    return 0;
}