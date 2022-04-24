/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 14:46:28
 * @LastEditTime: 2022-04-24 14:55:49
 * @Description: test generate_n.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\generate_n.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\generate_n generate_n.cpp
..\output\generate_n.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 与generate指定填充的值, 不同之处在于generate_n指定了生成的数据的个数
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    generate_n(back_inserter(src), 5, [&i](){i+=2;return i;});
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);// 1 2 3 4 5 6 7 8 9 10 2 4 6 8 10
    cout << endl;
    return 0;
}
