/*** 
 * @Author: chenbei
 * @Date: 2022-03-02 08:23:16
 * @LastEditTime: 2022-03-16 08:24:03
 * @Description: remove the node from end by iteration
 * @FilePath: \myLeetCode\linkedList\linkedListRemoveTheNodeFromEnd_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListRemoveTheNodeFromEndIteration_
#define linkedListRemoveTheNodeFromEndIteration_
#include "ListNode.h"
#include <iostream>
#include <algorithm>
using namespace std;
class linkedListRemoveTheNodeFromEndIteration{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            int length = 0;
            ListNode* t = head;
            while (t){
                t = t->next;
                length++;
            }
            if (length < 2) return nullptr; // 只有1个元素或者没有元素返回都是空
            int stop = length - n;
            if (stop == 0){ // 要考虑只有2个元素的特殊情况,此时length=2,stop=0
                return head->next;
            }
            length = 1; // 从1开始是让head更新到stop节点的前1个,前提是stop≠0
            t = head;
            while (length<stop){
                head = head->next;
                length++;
            }
            head->next = head->next->next; // 这个说明删除的不是第1个节点
            return t;
        }

};
void _linkedList_removeTheNodeFromEnd_iteration(){
    linkedListRemoveTheNodeFromEndIteration solution ;
    ListNode * root = new ListNode (1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    cout<<"iterations: remove the n node of linkedList\n";
    auto ans = solution.removeNthFromEnd(root,2);
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
    // ListNode * root1 = new ListNode(1);
    // auto ans = solution.removeNthFromEnd(root1,1);
    // if (!ans) cout<<"ans is nullptr\n";
    // root1->next = new ListNode(2);
    // ans = solution.removeNthFromEnd(root1,2);
    // cout<<"ans_val = "<<ans->val<<endl;
}
#endif // !linkedListRemoveTheNodeFromEndIteration_