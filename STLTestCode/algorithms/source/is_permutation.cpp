/*
 * @Author: chenbei
 * @Date: 2022-04-15 21:44:06
 * @LastEditTime: 2022-04-15 22:07:18
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\is_permutation.cpp
 * @Description: test is_permutation.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 用来检查一个序列是不是另一个序列的排列,如果是,会返回true
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {2,3,6};
    vector<int> v3 = {1,2,3,6};
    // 省略谓词和序列2的end选项,省略谓词时默认使用交集判断
    // v1是v3的排列之一,v3不是v1的,v1,v2直接更没关系,v2不是v3的排列,v3也不是v2的
    cout<<boolalpha<<is_permutation ( v1.begin(), v1.end(), v3.begin() )<<endl;//true
    cout<<boolalpha<<is_permutation ( v3.begin(), v3.end(), v1.begin() )<<endl;//false
    cout<<boolalpha<<is_permutation ( v1.begin(), v1.end(), v2.begin())<<endl;//false
    cout<<boolalpha<<is_permutation ( v2.begin(), v2.end(), v3.begin())<<endl;//false
    cout<<boolalpha<<is_permutation ( v3.begin(), v3.end(), v2.begin())<<endl;//false
    // 只省略谓词
    cout<<boolalpha<<is_permutation ( v1.begin(), v1.end(), v3.begin(), v3.end() )<<endl;//false
    return 0;
}
/*
template< class ForwardIterator1, class ForwardIterator2 >
bool is_permutation ( ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2 );

template< class ForwardIterator1, class ForwardIterator2, class BinaryPredicate >
bool is_permutation ( ForwardIterator1 first1, ForwardIterator1 last1,
                      ForwardIterator2 first2, BinaryPredicate p );


template< class ForwardIterator1, class ForwardIterator2 >
bool is_permutation ( ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2 );

template< class ForwardIterator1, class ForwardIterator2, class BinaryPredicate >
bool is_permutation ( ForwardIterator1 first1, ForwardIterator1 last1,
                      ForwardIterator2 first2, ForwardIterator2 last2,
                      BinaryPredicate p );
*/