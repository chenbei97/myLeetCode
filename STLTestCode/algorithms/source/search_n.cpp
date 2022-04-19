/*** 
 * @Author: chenbei
 * @Date: 2022-04-19 13:16:35
 * @LastEditTime: 2022-04-19 13:22:39
 * @Description: search_n.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\search_n.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o search_n search_n.cpp
.\search_n.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {8,2,2,2,4,9,100,2,2,2,2,50,6,6};
    auto it = search_n(src.begin(),src.end(),4,2);
    if (it == src.end())
        cout << "not found" << endl;
    else
        cout << *(it-1) << endl;
    auto it1 = search_n(src.begin(),src.end(),2,6);
    if (it1 == src.end())
        cout << "not found" << endl;
    else
        cout << *(it1-1) << endl;
    
    vector<int> src1 = {1,2,3,4,5,-1,6,7,8,9,10};
    auto it2 = search_n(src1.begin(),src1.end(),1,-1);
    if (it2 == src1.end())
        cout << "not found" << endl;
    else
        cout << *(it2-1) << endl;
    return 0;
}