#ifndef linearArrayFindMinMaxValStack_
#define linearArrayFindMinMaxValStack_
#include <stack>
#include <utility>
#include <iostream>
using namespace std;
class getMinMaxStack{
    public:
        getMinMaxStack(){minstk.push(INT_MAX);maxstk.push(-INT_MAX);} 
        // 用于比较,初始最小值为inf,初始最大值为-inf
        void push(int val){
            stk.push(val);
            minstk.push(min(minstk.top(),val)); // 存放的是与stk对应的此刻最小值
            maxstk.push(max(maxstk.top(),val)); // 存放的是与stk对应的此刻最大值
        }
        int top(){
            return stk.top();
        }
        void pop(){
            stk.pop();
            minstk.pop(); // mstk的最小值是基于此刻的stk,也要更新
            maxstk.pop();// 同理
        }
        int getMin(){
            return minstk.top(); // 此刻的最小值
        }
        int getMax(){
            return maxstk.top(); // 此刻的最大值
        }
    protected:
        stack<int> stk;
        stack<int> minstk;
        stack<int> maxstk;
};
class linearArrayFindMinMaxValStack{
    public:
        pair<int,int> findMinMaxVal(int * a , int n){
            for(int i =0;i<n;i++){
                solution.push(a[i]);
            }
            return make_pair(solution.getMin(),solution.getMax());
        }
    protected:
        getMinMaxStack solution;
};
void _linearArray_findMinMaxVal_stack(){
    linearArrayFindMinMaxValStack solution;
    int a[10] = {1,5,3,2,5,7,9,2,8,-1};
    auto ans = solution.findMinMaxVal(a,10);
    cout << "stack=> the maxest element is " << ans.second << endl;
	cout << "stack=> the minest element is " << ans.first << endl;
}
#endif // !linearArrayFindMinMaxValStack_