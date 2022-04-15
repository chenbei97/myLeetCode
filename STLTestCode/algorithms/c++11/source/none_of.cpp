/*
 * @Author: chenbei
 * @Date: 2022-04-15 20:42:45
 * @LastEditTime: 2022-04-15 20:51:06
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\none_of.cpp
 * @Description: test none_of.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isOdd ( int i ) { return i % 2 == 1; }
int main(){
    // none_of每个元素都不满足策略就返回true
    // none_of_equal是使用1个值代替谓词来测试序列的元素
    vector<int> v1 = {2,4,6};
    vector<int> v2 = {-1,-2,-3};
    vector<int> v3 = {11,12};
    cout<<"none_of (2,4,6, isOdd ) "<<std::boolalpha//没有1个是奇数
        <<none_of ( v1.begin(),v1.end(), isOdd )<<endl;//true
    
    cout<<"none_of (-1,-2,-3, >0 )"<<std::boolalpha //没有1个大于0
        <<none_of(v2.begin(), v2.end(), [](int i){return i > 0;})<<endl;//true
    cout <<"none_of (11,12, <=11 )"<<std::boolalpha //没有1个小于等于11,错有11
        <<none_of(v3.begin(), v3.end(), [](int i){return i <= 11;})<<endl;//false
    return 0;
}
/*
namespace boost { namespace algorithm {
template<typename InputIterator, typename Predicate>
	bool none_of ( InputIterator first, InputIterator last, Predicate p );
template<typename Range, typename Predicate>
	bool none_of ( const Range &r, Predicate p );
}}

namespace boost { namespace algorithm {
template<typename InputIterator, typename V>
	bool none_of_equal ( InputIterator first, InputIterator last, V const &val );
template<typename Range, typename V>
	bool none_of_equal ( const Range &r, V const &val );
}}
*/