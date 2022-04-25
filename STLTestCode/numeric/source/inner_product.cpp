/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:32:21
 * @LastEditTime: 2022-04-25 08:34:43
 * @Description: test inner_product.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\inner_product.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\inner_product inner_product.cpp
..\output\inner_product.exe
*/
#include <numeric>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 作内积
    vector<int> src1 = {1,3,5,7,9};
    vector<int> src2 = {2,4,6,8,10};
    int sum = inner_product(src1.begin(), src1.end(), src2.begin(), 100);
    cout << sum << endl; // 290=2+12+30+56+90+100
    return 0;
}