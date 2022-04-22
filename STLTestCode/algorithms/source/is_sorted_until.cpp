/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:33:19
 * @LastEditTime: 2022-04-22 16:38:34
 * @Description: test is_sorted_until.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\is_sorted_until.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\is_sorted_until is_sorted_until.cpp
..\output\is_sorted_until.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 直到不是有序的
    vector<int> src = {5,3,1,2,3,4,5,3,7,8,9,10};
    auto it = is_sorted_until(src.begin(), src.end());
    if (it == src.end())
    {
        cout << "all is sorted" << endl;
    }
    else
    {
        cout << "partial is sorted" << endl;
        cout << "the first unsorted element is " << *it << endl;
    }
    return 0;
}