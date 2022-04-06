'''
Author: chenbei
Date: 2022-04-06 08:01:14
LastEditTime: 2022-04-06 10:29:55
Description: linkedListMergeSort_Recursion.py
FilePath: \myLeetCode\linkedList\linkedListMergeSort_Recursion.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListMergeSortRecursion:
    def mergeSort(self,head:ListNode)->ListNode:
        if not head or not head.next: return head # 无需排序
        slow, fast = head, head.next # 快慢指针用于找到链表中点
        while fast and fast.next: # 找到中点的技巧是让快指针的速度是慢指针的2倍
            fast, slow = fast.next.next, slow.next # fast走2步,slow走1步,fast最终停在last-1
        # 如果链表长度是奇数例如7,mid=3(0,1,2--3--4,5,6),则fast=1->3->5,slow=0->1->2,mid=slow.next
        # 如果是偶数8,mid=4取右边(0,1,2,3--4,5,6,7),fast=1->3->5->7,slow=0->1->2->3
        mid, slow.next = slow.next, None # mid是slow的下一个,然后断开链表,就是slow.next=None
        # 递归的分开链表,每次都是最初2个链表的头节点,head和mid
        left, right = self.mergeSort(head), self.mergeSort(mid) 
        
        # 合并链表left和right
        h = res = ListNode(0) # 辅助的头节点h,res和h指向1个内存
        while left and right: # 合并链表结束的条件是2个链表的节点都已经归并
            if left.val < right.val: # 让h的next接上小的那个节点
                h.next, left = left, left.next # 小的已经被归并,它更新为下个节点
            else: h.next, right = right, right.next # 同理
            h = h.next # h是用于衔接res的,res记录了起始位置,h的next接上节点以后就更新h
        # 这一步是可能1个结束另一个还没结束
        h.next = left if left else right # 若ledt结束直接接上right即可否则直接接上left即可
        
        return res.next

if __name__ == '__main__':
    root = ListNode(10)
    root.next = ListNode(9)
    root.next.next = ListNode(6)
    root.next.next.next = ListNode(8)
    root.next.next.next.next = ListNode(4)
    root.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next = ListNode(2)
    root.next.next.next.next.next.next.next = ListNode(7)
    root.next.next.next.next.next.next.next.next = ListNode(1)
    solution = linkedListMergeSortRecursion()
    ans = solution.mergeSort(root)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next