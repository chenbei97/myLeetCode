/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:25:34
 * @LastEditTime: 2022-04-25 08:29:26
 * @Description: test reduce.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\reduce.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\reduce reduce.cpp
..\output\reduce.exe
*/
#include <numeric>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // reduce函数可以实现accumulate的功能
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    int sum = reduce(src.begin(), src.end(), 0, [](int a, int b) {return a + b;});
    cout << sum << endl; // 55
    // 默认情况下也是从左到右
    sum = reduce(src.begin(), src.end(), 0);
    cout << sum << endl; // 55
    // 指定不同的累加器
    vector<int> src2 = {1,2,3,4};
    sum = reduce(src2.begin(), src2.end(), 0, [](int a, int b) {return a * b;});
    cout << sum << endl; // 0
    return 0;
}