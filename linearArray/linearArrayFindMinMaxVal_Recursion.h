#ifndef linearArrayFindMinMaxValRecursion_
#define linearArrayFindMinMaxValRecursion_
#include <iostream>
#include <utility>
using namespace std;
class linearArrayFindMinMaxValRecursion{
    public:
        pair<int,int> findMinMaxVal(int * a,int n){
            pair<int,int> ans;
            if (n < 1)  return ans;
            
            if (n == 1){
                ans.first = ans.second = a[0];
                return ans;
            }
        
            if (n % 2 == 1){
                ans.first = ans.second = a[0];
                int * temp = new int [n-1];
                copy(a+1,a+n,temp);//注意复制的时候不要忘记+n
                a = temp;
                n--;
            }
            else{
                if (a[0] > a[1]){
                    ans.first = a[1];
                    ans.second = a[0];
                }
                else{
                    ans.first = a[0];
                    ans.second = a[1];
                }
                int * temp = new int [n-2];
                copy(a+2,a+n,temp);
                a = temp;
                n -= 2;
            }
            
            if (n<1) return ans;

            if (n!=2){
                //const int m = n / 2 ;
                int * a1 = new int [n/2];
                int * a2 = new int [n-n/2]; // 偶数可能造成3/2=1的情况
                copy(a,a+n/2,a1);
                copy(a+n/2,a+n,a2);
                pair<int,int> left = findMinMaxVal(a1,n/2);
                pair<int,int> right = findMinMaxVal(a2,n-n/2);
                ans.first = min(min(left.first,right.first),ans.first);
                ans.second = max(max(left.second,right.second),ans.second);
                return ans;
            }
            else{
                ans.first = min(min(a[0],a[1]),ans.first);
                ans.second = max(max(a[0],a[1]),ans.second);
                return ans;
            }
        }
};
void _linearArray_findMinMaxVal_recursion(){
    const int n = 10;
	int a[n] = { 10,9,7,-1,5,3,2,4,1,13 };
    linearArrayFindMinMaxValRecursion solution;
    auto ans = solution.findMinMaxVal(a,n);
    cout << "the maxest element is " << ans.second << endl;
	cout << "the minest element is " << ans.first << endl;
}
#endif // !linearArrayFindMinMaxValRecursion_
