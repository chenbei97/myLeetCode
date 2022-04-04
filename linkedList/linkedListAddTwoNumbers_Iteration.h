/*
 * @Author: chenbei
 * @Date: 2022-04-04 10:30:35
 * @LastEditTime: 2022-04-04 11:50:23
 * @FilePath: \myLeetCode\linkedList\linkedListAddTwoNumbers_Iteration.h
 * @Description: linkedListAddTwoNumbers_Iteration.h
 * @Signature: A boy without dreams
 */
#ifndef linkedListAddTwoNumbersIteration_
#define linkedListAddTwoNumbersIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListAddTwoNumbersIteration{
    public:
        ListNode* addTwoNumbers(ListNode * root1,ListNode * root2){
            ListNode* head =nullptr,*next=nullptr;
            int carry=0; // 进位
            while (root1!=nullptr||root2!=nullptr){ // 任何一个链表不为空
                int val1 = (root1==nullptr)?0:root1->val;
                int val2 = (root2==nullptr)?0:root2->val;
                int sum = val1+val2+carry; // 与低位来的进制数求和
                carry = sum/10; // 进制用于下一轮高位计算
                if (head==nullptr){ // 还没有头节点
                    head = new ListNode(sum%10); // 新链表的节点值是取模计算
                    next = head; // next用于衔接好head后边的每个节点
                }
                else{ // 已有头节点
                    next->next = new ListNode(sum%10);// 就由next去衔接
                    next = next->next;// 移动next
                }
                if (root1!=nullptr) root1 = root1->next; // 移动root1
                if (root2!=nullptr) root2 = root2->next; // 移动root2
            }
            if (carry!=0){ // 最后还有进位
                next->next = new ListNode(carry);
            }
            return head;
        }
};
void _linkedList_addTwoNumbers_iteration(){
    linkedListAddTwoNumbersIteration solution;
    ListNode *root1 = new ListNode (7),*root2 = new ListNode (5);
    root1->next = new ListNode(2);root2->next = new ListNode(6);
    root1->next->next = new ListNode(4);root2->next->next = new ListNode(4);
    root1->next->next->next = new ListNode(3);
    auto ans = solution.addTwoNumbers(root1,root2);
    cout<<"add list numbers by iteration as follows\n";
    while (ans){ 
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListAddTwoNumbersIteration_