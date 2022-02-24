#ifndef linearArrayFindMinMaxIndexIteration_
#define linearArrayFindMinMaxIndexIteration_
#include <iostream>
#include <utility>
using namespace std;
class linearArrayFindMinMaxIndexIteration{
    public:
        pair<int,int> findMinMaxIndex(int * a , int n ){
            pair<int,int> ans ; // min,max
            if (n < 1) return ans;
            if (n == 1) {
                ans.first = ans.second = 0;
                return ans;
            }
            int start ; // 循环的起始点取决于n的奇偶性
            if ( n % 2 == 1) { // 奇数
                ans.first = ans.second = 0 ; // a[0]被拿去作为最初的min,max值
                start = 1 ; // 从(1,2)开始到(n-1,n)可以两两成对
            }
            else{
                if (a[0] > a[1]){
                    ans.first = 1;
                    ans.second = 0;
                }
                else {
                    ans.first = 0;
                    ans.second = 1;
                }
                start = 2 ; // 从(2,3)一直到(n,n-1)可以两两成对
            }

            // 到这里可以保证比较的是两两成对的元素
            for (int i = start ; i < n ; i+=2){
                if (a[i] > a[i+1]){ // a[i]更大
                    if (a[i]> a[ans.second]) ans.second = i ; // 更大的元素和目前最大值去比较
                    if (a[i+1] < a[ans.first]) ans.first = i+1; // 更小的元素和目前最小值去比较
                }
                else {  // a[i+1]更大
                    if (a[i+1]> a[ans.second]) ans.second = i+1 ;
                    if (a[i] < a[ans.first]) ans.first = i;
                }
            }
            return ans;
        }
};
void _linearArray_findMinMaxIndex_iteration(){
    const int n = 10;
	int a[n] = { 10,9,7,-1,5,3,2,4,1,13 };
    linearArrayFindMinMaxIndexIteration solution;
    auto ans = solution.findMinMaxIndex(a,n);
    cout << "the maxest element is " << a[ans.second] << endl;
	cout << "the minest element is " << a[ans.first] << endl;
}
#endif // !linearArrayFindMinMaxIndexIteration_