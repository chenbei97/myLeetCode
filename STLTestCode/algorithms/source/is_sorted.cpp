/*
 * @Author: chenbei
 * @Date: 2022-04-15 21:02:12
 * @LastEditTime: 2022-04-15 21:21:29
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\is_sorted.cpp
 * @Description: test is_sorted.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    // is_sorted检查是否满足指定有序的策略
    vector<int> v1={1,2,3};
    cout<<boolalpha<<is_sorted(v1.begin(),v1.end(),std::less<int>())<<"\n";//默认是否递增,true

    cout<<boolalpha<<is_sorted(v1.begin(),v1.end(),std::greater<int>())<<"\n";//false
    
    vector<int> v2 = { 1, 2, 3, 4, 5, 3 }; //找到第1个不符合有序条件的元素为止,否则返回end
    vector<int>::iterator it = is_sorted_until(v2.begin(),v2.end(),std::less<int>());
    cout<<*it<<"\n";
    return 0;
}
/*
namespace boost { namespace algorithm {
	template <typename ForwardIterator, typename Pred>
	bool is_sorted ( ForwardIterator first, ForwardIterator last, Pred p );
	
	template <typename ForwardIterator>
	bool is_sorted ( ForwardIterator first, ForwardIterator last );
	
	
	template <typename Range, typename Pred>
	bool is_sorted ( const Range &r, Pred p );
	
	template <typename Range>
	bool is_sorted ( const Range &r );
}}

namespace boost { namespace algorithm {
	template <typename ForwardIterator, typename Pred>
	FI is_sorted_until ( ForwardIterator first, ForwardIterator last, Pred p );
	
	template <typename ForwardIterator>
	ForwardIterator is_sorted_until ( ForwardIterator first, ForwardIterator last );
	
	
	template <typename Range, typename Pred>
	typename boost::range_iterator<const R>::type is_sorted_until ( const Range &r, Pred p );
	
	template <typename Range>
	typename boost::range_iterator<const R>::type is_sorted_until ( const Range &r );
}}

是否有序还有4个函数,其实是is_sorted的特化版本,装饰器
递增要求后者至少大于前者,严格递增不能相等只能大于
namespace boost { namespace algorithm {
	template <typename Iterator>
	bool is_increasing ( Iterator first, Iterator last );
	
	template <typename R>
	bool is_increasing ( const R &range );
}}
namespace boost { namespace algorithm {
	template <typename ForwardIterator>
	bool is_decreasing ( ForwardIterator first, ForwardIterator last );
	
	template <typename R>
	bool is_decreasing ( const R &range );
}}
namespace boost { namespace algorithm {
	template <typename ForwardIterator>
	bool is_strictly_increasing ( ForwardIterator first, ForwardIterator last );
	
	template <typename R>
	bool is_strictly_increasing ( const R &range );
}}
namespace boost { namespace algorithm {
	template <typename ForwardIterator>
	bool is_strictly_decreasing ( ForwardIterator first, ForwardIterator last );
	
	template <typename R>
	bool is_strictly_decreasing ( const R &range );
}}
*/
