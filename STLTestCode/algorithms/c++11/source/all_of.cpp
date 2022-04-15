/*
 * @Author: chenbei
 * @Date: 2022-04-15 19:20:48
 * @LastEditTime: 2022-04-15 20:35:18
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\all_of.cpp
 * @Description: all_of testcode
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isOdd ( int i ) { return i % 2 == 1; }
bool lessThan11 ( int i ) { return i < 11; }
int main(){
    // all_of可以判断序列是否所有元素都满足某个条件
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {1,3,5,7,9};
    vector<int> v3 = {1,2,3,4,5,6,7,8,9,10,11};
    cout<<"{1,2,3,4,5,6,7,8,9,10} all of isOdd? "<<std::boolalpha
        <<all_of(v1.begin(), v1.end(), isOdd)<<endl;//false
    cout<<"{1,3,5,7,9} all of isOdd? "<<std::boolalpha
        <<all_of(v2.begin(), v2.end(), isOdd)<<endl;//false

    cout<<"{1,2,3,4,5,6,7,8,9,10} all of lessThan11? "<<std::boolalpha
        <<all_of(v1.begin(), v1.end(), lessThan11)<<endl;//true
    cout<<"{1,2,3,4,5,6,7,8,9,10,11} all of lessThan11? "<<std::boolalpha
        <<all_of(v3.begin(), v3.end(), lessThan11)<<endl;//false
    
    cout<<"1,3,5,7,9 all of > 0? "<<std::boolalpha
        <<all_of(v2.begin(), v2.end(), [](int i){return i > 0;})<<endl;//true
    
    // all_of_equal的区别不使用谓词来测试序列的元素,而是使用一个值来进行比较
    // c++20标准已没有这个函数
    // cout<<"{1,2,3,4,5,6,7,8,9,10} all of equal 1? "<<std::boolalpha
    //     <<all_of_equal(v1.begin(), v1.end(), 1)<<endl;//false
    return 0;
}
/*
all_of函数原型: 
namespace boost { namespace algorithm {
template<typename InputIterator, typename Predicate>
	bool all_of ( InputIterator first, InputIterator last, Predicate p );
template<typename Range, typename Predicate>
	bool all_of ( const Range &r, Predicate p );
}}

all_of_equal函数原型
namespace boost { namespace algorithm {
template<typename InputIterator, typename V>
	bool all_of_equal ( InputIterator first, InputIterator last, V const &val );
template<typename Range, typename V>
	bool all_of_equal ( const Range &r, V const &val );
}}
*/