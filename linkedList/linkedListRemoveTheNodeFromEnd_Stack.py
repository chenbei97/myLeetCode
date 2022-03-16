'''
Author: chenbei
Date: 2022-03-02 08:30:41
LastEditTime: 2022-03-16 08:24:26
Description: remove the node from end by stack
FilePath: \myLeetCode\linkedList\linkedListRemoveTheNodeFromEnd_Stack.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListRemoveTheNodeFromEndStack:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        t = head
        stk = []
        while t:
            stk.append(t)
            t = t.next
        if len(stk) == n : return head.next
        while n > 0:
            stk.pop(-1)
            n -= 1
        previous = stk[-1]
        previous.next = previous.next.next
        return head
if __name__ == '__main__':
    solution = linkedListRemoveTheNodeFromEndStack()
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    ans = solution.removeNthFromEnd(root,4)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next