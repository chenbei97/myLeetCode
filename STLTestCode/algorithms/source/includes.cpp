/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 08:38:32
 * @LastEditTime: 2022-04-22 08:40:01
 * @Description: test includes.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\includes.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\includes includes.cpp
..\output\includes.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // src的元素是否包含src2指定的元素,返回bool值
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> src2 = {10,8,3,5,7,0,2,4};
    auto it = includes(src.begin(), src.end(), src2.begin()+2, src2.end()-3);
    if(it)
    {
        cout << "src includes src2" << endl;
    }
    else
    {
        cout << "src not includes src2" << endl;
    }
    return 0;
}