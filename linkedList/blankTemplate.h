/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 09:23:48
 * @LastEditTime: 2022-04-02 13:28:11
 * @Description: blankTemplate.h
 * @FilePath: \myLeetCode\linkedList\blankTemplate.h
 * @A boy without dreams
 */
#ifndef _
#define _
#include "ListNode.h"
#include <iostream>
using namespace std;
class A{
    public:
        ListNode* func(ListNode * root){
            ListNode* ans;
            return  ans;
        }
};
void _linkedList(){
    A solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.func(root);
    cout<<" as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!_