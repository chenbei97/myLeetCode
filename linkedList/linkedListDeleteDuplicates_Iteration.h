/*** 
 * @Author: chenbei
 * @Date: 2022-03-01 11:20:58
 * @LastEditTime: 2022-03-16 08:19:55
 * @Description: delete duplicates by iteration
 * @FilePath: \myLeetCode\linkedList\linkedListDeleteDuplicates_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListDeleteDuplicatesIteration_
#define linkedListDeleteDuplicatesIteration_
#include "ListNode.h"
#include <iostream>
#include <algorithm>
using namespace std;
class linkedListDeleteDuplicatesIteration{
    public:
        ListNode* deleteDuplicates(ListNode* head){
            if (!head) return nullptr;
            if (!head->next) return head;
            ListNode * p = new ListNode(-1,head);
            ListNode * dummpy = p;
            while (p->next->next){ // p->next->next为空就无需执行了
                if (p->next->val == p->next->next->val){
                    int x = p->next->val;
                    while (p->next->val == x){ // 所有等于x的p->next都被跳过
                        p->next = p->next->next; 
                        if (!p->next) break; // p->next可能是空节点
                    }
                    // while退出时p->next非空且不重复 或者 是空节点
                }
                else{ // 不等说明p->next确实是唯一的
                    p = p->next;
                }
                if (!p->next) break;
            }
            return dummpy->next;
    }
};
void _linkedList_deleteDuplicates_iteration(){
    linkedListDeleteDuplicatesIteration solution;
    ListNode * root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next->next = new ListNode(6);
    root->next->next->next->next->next->next->next = new ListNode(6);
    root->next->next->next->next->next->next->next->next = new ListNode(7);
    auto ans = solution.deleteDuplicates(root);
    cout<<"iteration:delete duplicates :\n";
    ListNode * t = ans;
    while (t){
        cout<<t->val<<" ";
        t = t->next;
    }
    cout<<"\n";
}
#endif // !linkedListDeleteDuplicatesIteration
