/*** 
 * @Author: chenbei
 * @Date: 2022-04-02 10:15:19
 * @LastEditTime: 2022-04-02 10:25:40
 * @Description: linkedListReverseList_Recursion.h
 * @FilePath: \myLeetCode\linkedList\linkedListReverseList_Recursion.h
 * @A boy without dreams
 */
#include "ListNode.h"
#ifndef linkedListReverseListRecursion_
#define linkedListReverseListRecursion_
#include <iostream>
using namespace std;
class linkedListReverseListRecursion{
    public:
        ListNode* reverse(ListNode * head){
            // 以链表1->2->3->4->5举例
            if (head == nullptr || head->next == nullptr) {
            
                // 直到当前节点的下一个节点为空时返回当前节点,故只有last节点能满足情况
                // 5没有下一个节点,所以此处返回节点5,且多轮递归退栈时最终返回的都是5这个节点
            return head;
            }
            //递归传入下一个节点,目的是为了到达最后一个节点
            ListNode*newHead = reverse(head->next);//反复递归至最深处,也就是到达last节点
            /*
                第一轮出栈，head为5，head.next为空，返回5
                第二轮出栈，head为4，head.next为5，执行head.next.next=head也就是5.next=4，
                        把当前节点的子节点的子节点指向当前节点
                        此时链表为1->2->3->4<->5，由于4与5互相指向，所以此处要断开4.next=null
                        此时链表为1->2->3->4<-5
                        总是返回节点5
                第三轮出栈，head为3，head.next为4，执行head.next.next=head也就是4.next=3，
                        此时链表为1->2->3<->4<-5，由于3与4互相指向，所以此处要断开3.next=null
                        此时链表为1->2->3<-4<-5
                        总是返回节点5
                第四轮出栈，head为2，head.next为3，执行head.next.next=head也就是3.next=2，
                        此时链表为1->2<->3<-4<-5，由于2与3互相指向，所以此处要断开2.next=null
                        此时链表为1->2<-3<-4<-5
                        总是返回节点5
                第五轮出栈，head为1，head.next为2，执行head.next.next=head也就是2.next=1，
                        此时链表为1<->2<-3<-4<-5，由于1与2互相指向，所以此处要断开1.next=null
                        此时链表为1<-2<-3<-4<-5
                        总是返回节点5
                出栈完成，最终头节点5->4->3->2->1
            */
            head->next->next = head; // cur,next,让next的next指回cur
            head->next = nullptr; // 因为cur->next=next,next->next=cur,要避免互指断开cur->next
            return newHead;
        }
};
void _linkedList_reverseList_recursion(){
    linkedListReverseListRecursion solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.reverse(root);
    cout<<"reverse list by recursion as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListReverseListRecursion_