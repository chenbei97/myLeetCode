/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 15:54:34
 * @LastEditTime: 2022-04-22 15:56:10
 * @Description: test move.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\move.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\move move.cpp
..\output\move.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 将src的一些东西移动到目标,右值引用效率更高
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst;
    move(src.begin(),src.end(),back_inserter(dst));
    cout<<"dst:\n";
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(),dst.end(),out);
    cout<<endl;
    cout<<"src:\n";
    copy(src.begin(),src.end(),out);
    cout<<endl;
    return 0;
}