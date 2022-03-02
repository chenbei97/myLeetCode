#ifndef linkedListRemoveTheNodeFromEndStack_
#define linkedListRemoveTheNodeFromEndStack_
#include "ListNode.h"
#include <iostream>
#include <stack>
using namespace std;
class linkedListRemoveTheNodeFromEndStack{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            stack<ListNode*>  s;
            ListNode * t = head;
            while (t){
                s.push(t); // s.size()=m
                t = t->next;
            }
            if (n == s.size()) return head->next; // 说明删除的是第1个节点
            while (n>0){ // pop n次
                s.pop(); 
                n--; 
            }
            // s的栈顶为m-n位置的节点是删除节点的前1个节点
            ListNode * previous_node = s.top();
            previous_node->next = previous_node->next->next;
            return head;
            
    }
};
void _linkedList_removeTheNodeFromEnd_stack(){
    linkedListRemoveTheNodeFromEndStack solution;
    ListNode * root = new ListNode (1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    auto ans = solution.removeNthFromEnd(root,2);
    cout<<"stack: remove the n node of linkedList\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif // !linkedListRemoveTheNodeFromEndStack_