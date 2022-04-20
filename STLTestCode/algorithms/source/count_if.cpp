/*** 
 * @Author: chenbei
 * @Date: 2022-04-20 08:08:33
 * @LastEditTime: 2022-04-20 08:17:18
 * @Description: count_if.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\count_if.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o count_if count_if.cpp
.\count_if.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到符合条件的元素,是偶数的统计个数
    vector<int> src = {1,3,5,7,9,0,2,-2};
    auto it = count_if(src.begin(),src.end(),[](int x){return x%2==1;});
    cout << it << endl; // 5
    return 0;
}