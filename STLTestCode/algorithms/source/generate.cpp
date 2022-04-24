/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:16:40
 * @LastEditTime: 2022-04-24 14:53:40
 * @Description: test generate.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\generate.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\generate generate.cpp
..\output\generate.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 生成数据
    vector<int> src(20);
    generate(src.begin(), src.end(), [](){return rand()%100;});
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout << endl;
    int i = 0; // 用于制造升序序列
    generate(src.begin(), src.end(), [&i](){i+=2; return i;});
    copy(src.begin(), src.end(), out);
    cout << endl;
    return 0;
}
