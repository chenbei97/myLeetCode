'''
Author: chenbei
Date: 2022-03-01 10:04:23
LastEditTime: 2022-03-16 08:20:10
Description: delete duplicates by iteration
FilePath: \myLeetCode\linkedList\linkedListDeleteDuplicates_Iteration.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListDeleteDuplicatesIteration:
    def deleteDuplicates(self,root:ListNode)->ListNode:
        if not root : return None
        if not root.next : return root
        p = ListNode(-1,root)
        dummy = p
        while p.next.next:
            if p.next.val == p.next.next.val : # 目前next和next.next均非空且重复
                x = p.next.val # 记录这个值 
                while p.next.val == x: # next为x的节点都被跳过
                    p.next = p.next.next # 先更新,后比较,所以最终p.next=None或不等于x的非空节点
                    if not p.next : break # 不能为空,否则p.next没有next属性
            else:
                p = p.next # p的next和next/next不相等才能保证p.next是唯一的值
            if not p.next :break # p.next不为空才行
        return dummy.next 
if __name__ == '__main__':
    root = ListNode(1)
    root.next = ListNode(1)
    root.next.next = ListNode(1)
    root.next.next.next = ListNode(1)
    root.next.next.next.next = ListNode(1)
    root.next.next.next.next.next = ListNode(1)
    root.next.next.next.next.next.next = ListNode(1)
    root.next.next.next.next.next.next.next = ListNode(1)
    root.next.next.next.next.next.next.next.next = ListNode(1)
    solution = linkedListDeleteDuplicatesIteration()
    ans = solution.deleteDuplicates(root)
    if not ans : print(None)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next