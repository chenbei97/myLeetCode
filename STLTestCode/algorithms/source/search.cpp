/*** 
 * @Author: chenbei
 * @Date: 2022-04-19 13:27:27
 * @LastEditTime: 2022-04-19 16:51:16
 * @Description: test search.cpp 
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\search.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o search search.cpp
.\search.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到指定的范围序列
    vector<int> src = {1000,4,6,5,8,9,7,4,6,5};
    vector<int> which = {4,6,5};
    auto it = search(src.begin(),src.end(),which.begin(),which.end());
    if (it == src.end())
        cout << "not found" << endl;
    else
        cout << *(it-1) << endl;
    vector<int> src1 = {5,9,11,3,3,4,5,6,7,2};
    auto it1 = search(src.begin(),src.end(),src1.begin(),src1.end());
    if (it1 == src.end())
        cout << "not found" << endl;
    else
        cout << *(it1-1) << endl;
    return 0;
}