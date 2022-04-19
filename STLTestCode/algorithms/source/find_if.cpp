/*** 
 * @Author: chenbei
 * @Date: 2022-04-19 08:09:02
 * @LastEditTime: 2022-04-19 08:13:55
 * @Description: test find_if.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\find_if.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o find_if find_if.cpp
.\find_if.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {9,0,4,1,3,8,5,2,9};
    vector<int>::iterator it = find_if(src.begin()+1,src.end(),[](int i){return i>6;});
    cout << *it << endl;
    auto it2 = find_if(src.begin(),src.end(),[](int i){return i<0;});
    if (it2 == src.end())
        cout << "not found" << endl;
    else
        cout << *it2 << endl;
    return 0;
}