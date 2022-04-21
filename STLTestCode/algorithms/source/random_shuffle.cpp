/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:37:09
 * @LastEditTime: 2022-04-21 10:43:12
 * @Description: random_shuffle.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\random_shuffle.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o random_shuffle random_shuffle.cpp
.\random_shuffle.exe
*/
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 和shuffle类似,不返回任何东西,产生均匀分布的随机数
    // 底层使用RandomAccessIterator迭代器,rand进行随机分布,没有随机种子
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    random_shuffle(src.begin(), src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl;
    return 0;
}