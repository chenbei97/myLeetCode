/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 11:30:48
 * @LastEditTime: 2022-04-02 13:26:33
 * @Description: linkedListOddEven_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListOddEven_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListOddEvenIteration_
#define linkedListOddEvenIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListOddEvenIteration{
    public:
        ListNode* oddEven(ListNode * root){
            ListNode* ans;
            return  ans;
        }
};
void _linkedList_oddEven_iteration(){
    linkedListOddEvenIteration solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.oddEven(root);
    cout<<"get oddEven by iteration as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListOddEvenIteration_