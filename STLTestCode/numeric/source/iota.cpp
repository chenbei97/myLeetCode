/*
 * @Author: chenbei
 * @Date: 2022-04-16 10:10:39
 * @LastEditTime: 2022-04-16 10:29:28
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\iota.cpp
 * @Description: test iota.cpp
 * @Signature: A boy without dreams
 */
#include <numeric>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src(2000);
    iota(src.begin(),src.end(),100); //从100开始增长的序列,[100,2099]
    ostream_iterator<int> out(cout," ");
    copy(src.begin(),src.end(),out);
    cout<<endl;
    return 0;
}
/*
template<typename ForwardIterator, typename T> 
      BOOST_CXX14_CONSTEXPR void iota(ForwardIterator, ForwardIterator, T);
*/