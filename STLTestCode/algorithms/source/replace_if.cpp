/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:27:03
 * @LastEditTime: 2022-04-21 11:28:06
 * @Description: test replace_if.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\replace_if.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\replace_if replace_if.cpp
..\output\replace_if.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 依据条件替换某些值,例如偶数全部替换成0
    vector<int> src = {1,3,5,2,4,6};
    replace_if(src.begin(), src.end(), [](int x){return x%2==0;}, 0);
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout << endl;
    return 0;
}