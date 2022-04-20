/*** 
 * @Author: chenbei
 * @Date: 2022-04-20 08:08:17
 * @LastEditTime: 2022-04-20 08:12:32
 * @Description: count.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\count.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o count count.cpp
.\count.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 统计指定值数目,如果希望依据条件就使用count_if
    vector<int> src = {1,1,1,2,2,3,2,4,5,2,5,2,5,3,55,4,2};
    auto it = count(src.begin(),src.end(),2); 
    cout << it << endl; // 6个2
    return 0;
}