#ifndef linkedListRemoveDuplicatesIteration_
#define linkedListRemoveDuplicatesIteration_
#include "ListNode.h"
#include <iostream>
#include <algorithm>
using namespace std;
class linkedListRemoveDuplicatesIteration{
    public:
        ListNode* removeDuplicates(ListNode* head){
            if (!head) return nullptr;
            if (!head->next) return head;
            ListNode * ans = head;
            ListNode * p = head->next;
            while (p){
                while (p->val == head->val){
                    p = p->next;
                    head->next = nullptr; // 避免全部元素都是重复的直接退出返回,把后边的直接掐死
                    if (!p) break;
                }
                if (!p) break;
                head->next = p; // 让head指向p,无需new,把当前p的地址给当前的head
                p = p->next;
                head = head->next;
            }
            return ans;
        }

};
void _linkedList_removeDuplicates_iteration(){
    linkedListRemoveDuplicatesIteration solution;
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
    ListNode * t = ans;
    cout<<"iteration:remove duplicates :\n";
    while (t){
        cout<<t->val<<" ";
        t = t->next;
    }
    cout<<"\n";
}
#endif // !linkedListRemoveDuplicatesIteration_