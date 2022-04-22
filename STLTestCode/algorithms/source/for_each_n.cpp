/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 08:47:29
 * @LastEditTime: 2022-04-22 08:49:11
 * @Description: test for_each_n.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\for_each_n.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\for_each_n for_each_n.cpp
..\output\for_each_n.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // for_each遍历指定个数的元素需要在begin和end调整
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    for_each(src.begin()+2, src.end()-3, [](int &i){cout << i << " ";});
    cout << endl;
    // for_each_n可以指定begin之后的n个元素
    int n = 5;
    for_each_n(src.begin()+2, n, [](int &i){cout << i << " ";});
    cout << endl;
    return 0;
}