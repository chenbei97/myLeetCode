/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 09:21:36
 * @LastEditTime: 2022-04-02 13:27:09
 * @Description: linkedListReverseList_Iteration.h
 * @FilePath: \myLeetCode\linkedList\linkedListReverseList_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListReverseListIteration_
#define linkedListReverseListIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListReverseListIteration{
    public:
        ListNode* reverse(ListNode * root){
            ListNode* prev = nullptr; // 当前节点cur和前1个节点prev
            ListNode* cur = root;
            while (cur){
                ListNode*next = cur->next;
                cur->next = prev;//让cur的next指向前1个节点
                prev = cur; // 在cur被cur.next覆盖之前先交给prev管理
                cur = next; // prev和cur都实现了向前移动1个单位
            }
            return prev; //最后prev为最后1个节点,cur为nullptr节点
        }
};
void _linkedList_reverseList_iteration(){
    linkedListReverseListIteration solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.reverse(root);
    cout<<"reverse list by iteration as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListReverseListIteration_