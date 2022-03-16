/*** 
 * @Author: chenbei
 * @Date: 2022-02-28 11:31:57
 * @LastEditTime: 2022-03-16 08:22:05
 * @Description: merge two ordered linkedList by iteration
 * @FilePath: \myLeetCode\linkedList\linkedListMergeTwoOrdered_Iteration.h
 * @A boy without dreams
 */
#ifndef linkedListMergeTwoOrderedIteration_
#define linkedListMergeTwoOrderedIteration_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListMergeTwoOrderedIteration{
    public:
        ListNode* mergeTwoListsMy(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        ListNode * t = new ListNode(); // 事先new 1个,这样ans才是t的这个地址
        ListNode * ans = t;
        //int index = 0;
        while (list1 || list2)
        {
            //index ++;
            //if (index > 10) break;
            if (list1 && list2)
            {
                if (list1->val < list2->val)
                {
                    //cout<<"list1 < list2 "<<list1->val<<","<<list2->val<<"\n";
                    t->val = list1->val; // 不要使用 t= list1,t=t->next后list1也被改变了
                    t->next = new ListNode (); // 让t->next new出来的用于下次赋值
                    t = t->next;  
                    list1 = list1->next;
                }
                else if (list1->val > list2->val)
                {
                    //cout<<"list1 > list2 "<<list1->val<<","<<list2->val<<"\n";
                    t->val = list2->val;
                    t->next = new ListNode ();
                    t = t->next; 
                    list2 = list2->next;
                }
                else 
                {
                    //cout<<"list1 = list2 "<<list1->val<<","<<list2->val<<"\n";
                    t->val = list1->val;
                    t->next = new ListNode(list2->val);
                    t->next->next = new ListNode ();
                    
                    //cout<<"before <list1> = "<<list1->val<<"\n";
                    list1 = list1->next;
                    //cout<<"before <list2> = "<<list2->val<<"\n";
                    list2 = list2->next;
                    // 如果均为空会直接退出了,那么此时t多new了1个,所以将其置为0
                    // 均为空直接退出的情况只可能发生在list1和list2同时到下1个节点
                    // 其它情况必定最多有1个不为空,如果有1个不为空就直接执行后面的else if
                    if (!list1 && !list2) t->next->next = nullptr;
                    t = t->next->next;
                }
                
            }

            else if (list1 && !list2)
            {
                // cout<<"here1"<<endl;
                t->val = list1->val;
                t->next = list1->next; // 直接让t后边的等于list1后边的,无需再new
                break;
            }
            
            else if (list2 && !list1)
            {
                // cout<<"here2"<<endl;
                t->val = list2->val;
                t->next = list2->next; // 同理
                break;
            }
        }
        return ans; 
    }
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            ListNode * t = new ListNode (); // 第1个节点的前1个节点
            ListNode * ans = t ;//记录最初始的t
            while (list1 && list2){
                if (list1->val <= list2->val){
                    t->next = list1; // 首次t->next是真正的第1个节点
                    list1 = list1->next;
                }
                else {
                    t->next = list2;
                    list2 = list2->next;
                }
                t = t->next;
            } 
            // 最多有1个链表还没合并完
            if(list1) t->next = list1;
            else if(list2) t->next = list2;
            else t->next = nullptr;
            return ans->next;
        }

};
void _linkedList_mergeTwoOrdered_iteration(){
    linkedListMergeTwoOrderedIteration solution;
    ListNode * t1;
    ListNode * t2;
    t1 = new ListNode(1);
    t1->next = new ListNode(2);
    t1->next->next = new ListNode(4);
    //cout<<t1->val<<" "<<t1->next->val<<" "<<t1->next->next->val<<endl;
    t2 = new ListNode(1);
    t2->next = new ListNode(3);
    t2->next->next = new ListNode(4);
    // t2->next->next->next = new ListNode(6);
    ListNode* ans = solution.mergeTwoListsMy(t1,t2);
    cout<<"my iteration method:\n";
    while (ans!= nullptr)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
    //cout<<t1->val<<" "<<t1->next->val<<" "<<t1->next->next->val<<endl;
    ans = solution.mergeTwoLists(t1,t2);
    cout<<"other iteration method:\n";
    while (ans!= nullptr)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif // !linkedListMergeTwoOrderedIteration_