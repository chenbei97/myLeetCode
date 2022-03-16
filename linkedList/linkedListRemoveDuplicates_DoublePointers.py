'''
Author: chenbei
Date: 2022-02-28 16:53:14
LastEditTime: 2022-03-16 08:23:15
Description: remove duplicates by double pointers
FilePath: \myLeetCode\linkedList\linkedListRemoveDuplicates_DoublePointers.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListRemoveDuplicatesDoublePointers:
    def removeDuplicates(self,root:ListNode)->ListNode:
        if not root : return None
        if not root.next : return root
        slow,fast = ListNode(root.val),root.next
        t = slow.next
        ans = slow
        while fast or fast.next : # 避免fast不为空时直接退出循环了
            if fast.val != slow.val:
                t = ListNode(fast.val) # 不等就可以让slow的next创建和fast值相等的节点
                slow = slow.next
                fast = fast.next
                if not fast : break # 避免fast为空时会继续判断fast.next,空节点没有next
            else :
                while fast.val == slow.val:
                    fast = fast.next
                    if not fast : break # fast为空再次判断while是没有val,所以要加
                if not fast : break
                slow.next = ListNode(fast.val) # 构建前提是fast不为空,所以也要加判断
                slow = slow.next

        return ans

if __name__ == '__main__':
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    root.next.next.next.next = ListNode(5)
    root.next.next.next.next.next = ListNode(6)
    root.next.next.next.next.next.next = ListNode(7)
    root.next.next.next.next.next.next.next = ListNode(8)
    root.next.next.next.next.next.next.next.next = ListNode(11)
    solution = linkedListRemoveDuplicatesDoublePointers()
    ans = solution.removeDuplicates(root)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next