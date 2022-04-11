/*** 
 * @Author: chenbei
 * @Date: 2022-04-11 15:20:31
 * @LastEditTime: 2022-04-11 15:24:21
 * @Description: linkedListMiddleNode_SinglePointer.h
 * @FilePath: \myLeetCode\linkedList\linkedListMiddleNode_SinglePointer.h
 * @@Signature: A boy without dreams
 */
#ifndef linkedListMiddleNodeSinglePointer_
#define linkedListMiddleNodeSinglePointer_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListMiddleNodeSinglePointer{
    public:
        ListNode* getMiddleNode(ListNode * root){
            int n = 0;
            ListNode*cur = root;
            while (cur){
                ++n;
                cur = cur->next;
            }
            cur = root;
            int k = 0;
            while (k<n/2)
            {
                ++k;
                cur = cur->next;
            }
            return cur;
        }
};
void _linkedList_middleNode_singlePointer(){
    linkedListMiddleNodeSinglePointer solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(7);
    auto ans = solution.getMiddleNode(root);
    cout<<"find middle node by single pointer as follows\n";
    cout << "3 2 0 -4 4 7 to => "<<ans->val<<endl;
}
#endif//!linkedListMiddleNodeSinglePointer_