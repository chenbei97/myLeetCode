/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 11:03:51
 * @LastEditTime: 2022-04-02 11:15:50
 * @Description: linkedListRemoveElements_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListRemoveElements_Iteration.h
 * @A boy without dreams
 */
#include "ListNode.h"
#ifndef linkedListRemoveElementsIteration_
#define linkedListRemoveElementsIteration_
#include <iostream>
using namespace std;
class linkedListRemoveElementsIteration{
    public:
        ListNode* removeElements(ListNode * root,int val){
            // 哑节点,root's prev,这是因为root也可能被删除,为了方便使用前1位开始
            ListNode* dummy = new ListNode(0,root);
            ListNode* cur = dummy;
            while (cur->next){
                if (cur->next->val == val){
                    cur->next = cur->next->next; // 断开cur.next与cur和cur的联系
                }
                else{
                    cur = cur->next; // cur.next被保留,移动cur到cur.next
                }
            }
            return dummy->next;
        }
};
void _linkedList_removeElements_iteration(){
    linkedListRemoveElementsIteration solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.removeElements(root,3);
    cout<<"removeElements by iteration as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListRemoveElementsIteration_