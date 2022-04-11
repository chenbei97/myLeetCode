/*** 
 * @Author: chenbei
 * @Date: 2022-04-11 15:25:32
 * @LastEditTime: 2022-04-11 15:39:47
 * @Description: linkedListMiddleNode_DoublePointers.h
 * @FilePath: \myLeetCode\linkedList\linkedListMiddleNode_DoublePointers.h
 * @@Signature: A boy without dreams
 */
#ifndef linkedListMiddleNodeDoublePointers_
#define linkedListMiddleNodeDoublePointers_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListMiddleNodeDoublePointers{
    public:
        ListNode* getMiddleNode(ListNode * head){
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};
void _linkedList_middleNode_doublePointers(){
    linkedListMiddleNodeDoublePointers solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(7);
    auto ans = solution.getMiddleNode(root);
    cout<<"find middle node by double pointers as follows\n";
    cout << "3 2 0 -4 4 7 to => "<<ans->val<<endl;
}
#endif//!linkedListMiddleNodeDoublePointers_