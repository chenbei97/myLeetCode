/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 08:40:35
 * @LastEditTime: 2022-04-21 08:41:52
 * @Description: test sort.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\sort.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o sort sort.cpp
.\sort.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5};
    sort(src.begin(), src.end(), [](int a, int b){return a>b;}); // 按照降序
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl;
    return 0;
}
