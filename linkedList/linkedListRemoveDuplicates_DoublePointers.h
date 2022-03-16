/*** 
 * @Author: chenbei
 * @Date: 2022-02-28 16:52:13
 * @LastEditTime: 2022-03-16 08:22:56
 * @Description: remove duplicates by double pointers
 * @FilePath: \myLeetCode\linkedList\linkedListRemoveDuplicates_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linkedListRemoveDuplicatesDoublePointers_
#define linkedListRemoveDuplicatesDoublePointers_
#include "ListNode.h"
#include <iostream>
#include <algorithm>
using namespace std;
class linkedListRemoveDuplicatesDoublePointers{
    public:
        ListNode* removeDuplicates(ListNode* head) {
            // 前提必须是有序的
            if (!head) return nullptr;
            if (!head->next) return head;
            ListNode * slow = new ListNode(head->val), * fast = head->next;
            ListNode * ans = slow;
            while (fast->next || fast){
                if (fast->val != slow->val){
                    //cout<<"before:slow = "<< slow->val<<" fast = "<<fast->val<<endl;
                    slow->next = new ListNode(fast->val);
                    slow = slow->next;
                    fast = fast->next;
                    if (!fast) break;
                    //cout<<"after:slow = "<< slow->val<<" fast = "<<fast->val<<endl;
                }
                else{
                    //cout<<"while before:slow = "<< slow->val<<" fast = "<<fast->val<<endl;
                    while(fast->val == slow->val){
                        fast = fast->next;
                        if (!fast) break;
                    }
                    if (!fast) break;
                    //cout<<"while after:slow = "<< slow->val<<" fast = "<<fast->val<<endl;
                    slow->next = new ListNode(fast->val);
                    slow = slow->next;
                    //cout<<"next slow = "<< slow->val<<" fast = "<<fast->val<<endl;
                }
            }
            return ans;
    }
};
void _linkedList_removeDuplicates_doublePointers(){
    linkedListRemoveDuplicatesDoublePointers solution;
    ListNode * root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next->next->next = new ListNode(4);
    auto ans = solution.removeDuplicates(root);
    cout<<"double pointers:remove duplicates :\n";
    ListNode * t = ans;
    while (t){
        cout<<t->val<<" ";
        t = t->next;
    }
    cout<<"\n";
    ListNode * r1 = new ListNode(1);
    r1->next = new ListNode(2);
    r1->next->next = new ListNode(3);
    r1->next->next->next = new ListNode(3);
    ans = solution.removeDuplicates(r1);
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
}
#endif // !linkedListRemoveDuplicatesDoublePointers