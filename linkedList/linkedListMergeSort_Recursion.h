/*** 
 * @Author: chenbei
 * @Date: 2022-04-06 08:01:08
 * @LastEditTime: 2022-04-06 10:31:02
 * @Description: linkedListMergeSort_Recursion.h
 * @FilePath: \myLeetCode\linkedList\linkedListMergeSort_Recursion.h
 * @@Signature: A boy without dreams
 */
#ifndef linkedListMergeSortRecursion_
#define linkedListMergeSortRecursion_
#include "ListNode.h"
#include <iostream>
using namespace std;
class linkedListMergeSortRecursion{
    public:
        ListNode* mergeSort(ListNode * root){
            if (!root || !root->next) return root;
            ListNode*slow = root,*fast = root->next;// 快慢指针用于找到链表中点
            while (fast && fast->next){ // 找到中点的技巧是让快指针的速度是慢指针的2倍
                fast = fast->next->next;
                slow = slow->next; // fast走2步,slow走1步,fast最终停在last-1
            }
            // 如果链表长度是奇数例如7,mid=3(0,1,2--3--4,5,6),则fast=1->3->5,slow=0->1->2,mid=slow.next
            // 如果是偶数8,mid=4取右边(0,1,2,3--4,5,6,7),fast=1->3->5->7,slow=0->1->2->3
            ListNode * mid = slow->next;
            slow->next = nullptr; // mid是slow的下一个,然后断开链表,就是slow.next=None
            // 递归的分开链表,每次都是最初2个链表的头节点,head和mid
            ListNode* left = mergeSort(root), *right = mergeSort(mid);

            // 合并链表left和right
            ListNode * ans = new ListNode(0);//哑节点
            ListNode * h = ans;//辅助的头节点h,res和h指向1个内存
            while (left && right){ // 合并链表结束的条件是2个链表的节点都已经归并
                if (left->val < right->val){
                    h->next = left;
                    left = left->next;
                }
                else{
                    h->next = right;
                    right = right->next;
                }
                h = h->next;// h是用于衔接res的,res记录了起始位置,h的next接上节点以后就更新h
            }
            h->next = left?left:right;// 若ledt结束直接接上right即可否则直接接上left即可
            return ans->next;
        }
};
void _linkedList_mergeSort_recursion(){
    linkedListMergeSortRecursion solution;
    ListNode *root = new ListNode (3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = new ListNode(4);
    auto ans = solution.mergeSort(root);
    cout<<"mergeSort by recursion as follows\n";
    while (ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<"\n";
}
#endif//!linkedListMergeSortRecursion_