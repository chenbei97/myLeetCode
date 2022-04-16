/*
 * @Author: chenbei
 * @Date: 2022-04-15 20:10:56
 * @LastEditTime: 2022-04-15 20:39:40
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\any_of.cpp
 * @Description: test any_of.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isOdd ( int i ) { return i % 2 == 1; }
bool lessThan11 ( int i ) { return i < 11; }
int main(){
    // any_of正好与all_of相反,只要存在1个元素都满足策略就返回true
    // any_of_equal是使用1个值代替谓词来测试序列的元素
    vector<int> v1 = {-1,2,3,4,5,6,7,8};
    vector<int> v2 = {2,4,6,8,9};
    vector<int> v3 = {11,12};
    cout<<"{-1,1,2,3,4,5,6,7,8} any of < 0? "<<std::boolalpha
        <<any_of(v1.begin(), v1.end(), isOdd)<<endl;//true
    cout<<"{2,4,6,8,9} any of isOdd? "<<std::boolalpha
        <<any_of(v2.begin(), v2.end(), isOdd)<<endl;//true

    cout<<"{11,12} any of lessThan11? "<<std::boolalpha
        <<any_of(v3.begin(), v3.end(), lessThan11)<<endl;//false

    cout<<"2,4,6,8,9 any of > 10? "<<std::boolalpha
        <<any_of(v2.begin(), v2.end(), [](int i){return i > 10;})<<endl;//false
    
    return 0;
}
/*
// any_of函数原型:
namespace boost { namespace algorithm {
template<typename InputIterator, typename Predicate>
	bool any_of ( InputIterator first, InputIterator last, Predicate p );
template<typename Range, typename Predicate>
	bool any_of ( const Range &r, Predicate p );
}}
namespace boost { namespace algorithm {
template<typename InputIterator, typename V>
	bool any_of_equal ( InputIterator first, InputIterator last, V const &val );
template<typename Range, typename V>
	bool any_of_equal ( const Range &r, V const &val );
}}
*/