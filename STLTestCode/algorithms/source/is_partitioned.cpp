/*
 * @Author: chenbei
 * @Date: 2022-04-15 21:25:28
 * @LastEditTime: 2022-04-15 21:42:24
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\is_partitioned.cpp
 * @Description: is_partitioned.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool isOdd ( int i ) { return i % 2 == 1; }
bool lessThan10 ( int i ) { return i < 10; }
int main()
{
    // 序列中的项根据满足谓词的能力分开，则函数is_partitioned返回true
    // is_partitioned对于空和单个元素范围返回true，无论传递哪个谓词进行测试
    // 全部true,全部false或者前半部分true后半部分false
    vector<int> v = { 0, 1, 2, 3, 14, 15 }; //奇数没有在一起不能分两半
    cout<<boolalpha<<is_partitioned ( v.begin(), v.end(), isOdd )<<endl;//false
    cout<<boolalpha<<is_partitioned ( v.begin(), v.end(), lessThan10 )<<endl;//true

    vector<int> v1 = { 1,3,5,0,2,4}; //奇数都在前边为true可以
    cout<<boolalpha<<is_partitioned ( v1.begin(), v1.end(), isOdd )<<endl;//true
    vector<int> v2 = { 0,2,4,1,3,5};// 后边不行
    cout<<boolalpha<<is_partitioned ( v2.begin(), v2.end(), isOdd )<<endl;//false
    return 0;
}
/*
template<typename InputIterator, typename Predicate>
	bool is_partitioned ( InputIterator first, InputIterator last, Predicate p );
template<typename Range, typename Predicate>
	bool is_partitioned ( const Range &r, Predicate p );
*/