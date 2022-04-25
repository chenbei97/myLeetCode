/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 07:59:14
 * @LastEditTime: 2022-04-25 08:14:01
 * @Description: test accumulate.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\accumulate.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\accumulate accumulate.cpp
..\output\accumulate.exe
*/
#include <numeric>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 计算累加和 c++17之后放入algorithms库中,c++11之前放入numeric库中
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    int sum = accumulate(src.begin(), src.end(), 0);
    cout << "sum = " << sum << endl; // 55
    // 还可以指定累加器,变成取负号累加,累乘
    sum = accumulate(src.begin(), src.end(), 0, minus<int>());
    cout << "sum = " << sum << endl; // -55
    vector<int> src2 = {1,2,3};
    sum = accumulate(src2.begin(), src2.end(), 1, multiplies<int>());
    cout << "sum = " << sum << endl; // 6
    return 0;
}