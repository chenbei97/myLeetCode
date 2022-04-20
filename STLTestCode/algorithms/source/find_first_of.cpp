/*** 
 * @Author: chenbei
 * @Date: 2022-04-20 08:21:17
 * @LastEditTime: 2022-04-20 08:26:08
 * @Description: teat find_first_of.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\find_first_of.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o find_first_of find_first_of.cpp
.\find_first_of.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 找到要求寻找的元素,只要是要求的范围内的元素就可以,即0或者-1先被找到都可以
    vector<int> src = {1,2,3,4,5,6,0,7,8,-1,-2};
    vector<int> which = {0,-1,};
    auto it = find_first_of(src.begin(),src.end(),which.begin(),which.end());
    cout << *(it-1) << endl; // 0先被找到,位置为6,前一个位置的元素是6
    return 0;
}
