/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 08:19:10
 * @LastEditTime: 2022-04-21 08:36:22
 * @Description: test reverse.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\reverse.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o reverse reverse.cpp
.\reverse.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5};
    reverse(src.begin(), src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl;

    list<int> src2 = {1,2,3,4,5};
    reverse(src2.begin(), src2.end());
    ostream_iterator<int> out2(cout," ");
    copy(src2.begin(), src2.end(), out2);
    cout <<endl;

    int a []={1,2,3,4,5};
    reverse(a, a+5);
    ostream_iterator<int> out3(cout," ");
    copy(a, a+5, out3);
    cout <<endl;

    
    map<int, string> src3 = {{1,"a"},{2,"b"},{3,"c"},{4,"d"},{5,"e"}};
    
    // swap(pair<_T1, _T2>&, pair<_T1, _T2>&) = delete;
    // 所以不能直接reverse src3
    // reverse(src3.begin(), src3.end());

    return 0;
}