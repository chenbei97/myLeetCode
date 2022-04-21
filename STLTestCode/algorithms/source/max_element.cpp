/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 08:07:59
 * @LastEditTime: 2022-04-21 08:14:42
 * @Description: test max_element.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\max_element.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o max_element max_element.cpp
.\max_element.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
    // 找到容器中最大值
    vector<int> src = {0,1,1,2,2,8,0,9,-1,3,-2,4,6};
    auto it = max_element(src.begin(), src.end());
    if (it != src.end())
    {
        cout <<*(it-1) << " " <<*(it)<<" "<<*(it+1)<<endl;
    }
    
    list<int> src2 = {0,1,1,2,2,8,0,9,-1,3,-2,4,6};
    auto it2 = max_element(src2.begin(), src2.end());
    if (it2 != src2.end())
    {
        cout <<*(it2)<<endl; // list不支持+和-操作,可以++,--
        --it2;
        cout <<*(it2)<<endl; // 0
        ++it2;
        ++it2;
        cout <<*(it2)<<endl;// -1
    }
    return 0;
}