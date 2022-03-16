'''
Author: chenbei
Date: 2022-03-02 13:46:17
LastEditTime: 2022-03-16 08:24:00
Description: remove the node from end by double pointers
FilePath: \myLeetCode\linkedList\linkedListRemoveTheNodeFromEnd_DoublePointers.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListRemoveTheNodeFromEndDoublePointers:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast, slow = head, head
        while n > 0:
            fast = fast.next
            n -= 1
        if not fast:
            return slow.next
        while fast.next:
            fast, slow = fast.next, slow.next
        slow.next = slow.next.next
        return head
if __name__ == '__main__':
    solution = linkedListRemoveTheNodeFromEndDoublePointers()
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    ans = solution.removeNthFromEnd(root,2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next