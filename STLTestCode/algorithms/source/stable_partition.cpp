/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:38:13
 * @LastEditTime: 2022-04-22 16:39:54
 * @Description: test stable_partition.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\stable_partition.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\stable_partition stable_partition.cpp
..\output\stable_partition.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 稳定的分割,把是偶数的放在前面,是奇数的放在后面,不改变原来的顺序
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    stable_partition(src.begin(), src.end(), [](int x){return x%2==0;});
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out); // 2 4 6 8 10 1 3 5 7 9
    cout << endl;
    return 0;
}