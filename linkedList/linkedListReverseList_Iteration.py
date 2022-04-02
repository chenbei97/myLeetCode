'''
Author: chenbei
Date: 2022-04-02 09:22:35
LastEditTime: 2022-04-02 10:26:52
Description: linkedListReverseList_Iteration.py
FilePath: \myLeetCode\linkedList\linkedListReverseList_Iteration.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListReverseListIteration:
    def reverse(self,root:ListNode)->ListNode:
        prev = ListNode(None,None)
        cur = root # 当前节点cur和前1个节点prev
        while cur:
            next = cur.next
            cur.next = prev # 让cur的next指向前1个节点
            prev = cur # 在cur被cur.next覆盖之前先交给prev管理
            cur = next # prev和cur都实现了向前移动1个单位
        return prev # 最后prev为最后1个节点,cur为nullptr节点
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
    solution = linkedListReverseListIteration()
    ans = solution.reverse(root)
    while ans:
        if ans.val != None:
            print(ans.val,end=" ")
        ans = ans.next