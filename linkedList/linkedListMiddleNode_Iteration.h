/*** 
 * @Author: chenbei
 * @Date: 2022-04-11 10:07:56
 * @LastEditTime: 2022-04-11 14:42:39
 * @Description: linkedListMiddleNode_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListMiddleNode_Iteration.h
 * @@Signature: A boy without dreams
 */
#ifndef linkedListMiddleNodeIteration_
#define linkedListMiddleNodeIteration_
#include "ListNode.h"
#include <iostream>
#include <vector>
using namespace std;
class linkedListMiddleNodeIteration{
    public:
        ListNode* getMiddleNode(ListNode * root){
            vector<ListNode*> A = {root}; 
            while (A.back()->next != nullptr){
                // cout<<A.back()->val<<" ";
                A.push_back(A.back()->next); // 装的A的back的next,从back=root开始
            }  
            return A[A.size() / 2];
        }
};
void _linkedList_middleNode_iteration(){
    linkedListMiddleNodeIteration solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(7);
    auto ans = solution.getMiddleNode(root);
    cout<<"find middle node by iteration as follows\n";
    cout << "3 2 0 -4 4 7 to => "<<ans->val<<endl;
}
#endif//!linkedListMiddleNodeIteration_