/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 08:16:10
 * @LastEditTime: 2022-04-21 08:17:38
 * @Description: test min_element.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\min_element.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o min_element min_element.cpp
.\min_element.exe
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
    auto it = min_element(src.begin(), src.end());
    if (it != src.end())
    {
        // 3,-2,4
        cout <<*(it-1) << " " <<*(it)<<" "<<*(it+1)<<endl;
    }
    
    list<int> src2 = {0,1,1,2,2,8,0,9,-1,3,-2,4,6};
    auto it2 = min_element(src2.begin(), src2.end());
    if (it2 != src2.end())
    {
        cout <<*(it2)<<endl; // list不支持+和-操作,可以++,--
        --it2;
        cout <<*(it2)<<endl; // 3
        ++it2;
        ++it2;
        cout <<*(it2)<<endl;// 4
    }
    return 0;
}
