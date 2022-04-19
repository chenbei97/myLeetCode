/*** 
 * @Author: chenbei
 * @Date: 2022-04-19 11:18:55
 * @LastEditTime: 2022-04-19 11:22:36
 * @Description: test find_if_not.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\find_if_not.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o find_if_not find_if_not.cpp
.\find_if_not.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {9,7,4,1,3,8,5,2,9,-100};
    vector<int>::iterator it = find_if_not(src.begin()+1,src.end(),[](int i){return i>2;}); //没有大于2的就返回
    cout << *it << endl; // 1, <2
    auto it2 = find_if_not(src.begin(),src.end(),[](int i){return i>0;}); // 没有大于0的就返回
    if (it2 == src.end())
        cout << "all elements > 0" << endl;
    else
        cout << *it2 << endl; // -100, <0
    return 0;
}