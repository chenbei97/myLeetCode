/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:02:50
 * @LastEditTime: 2022-04-21 11:04:08
 * @Description: test copy.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\copy.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\copy copy.cpp
..\output\copy.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> src = {0,1,2,3,4,5,6,7,8,9};
    vector<int> dst;
    copy(src.begin()+1, src.begin()+6, back_inserter(dst));
    for (auto i : dst)
    {
        cout << i << " "; // 1,2,3,4,5
    }
    cout << endl;
    return 0;
}
