'''
Author: chenbei
Date: 2022-04-11 15:25:36
LastEditTime: 2022-04-11 15:29:52
Description: linkedListMiddleNode_DoublePointers.py
FilePath: \myLeetCode\linkedList\linkedListMiddleNode_DoublePointers.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListMiddleNodeDoublePointers:
    def getMiddleNode(self,root:ListNode)->None:
        slow ,fast = root,root
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
if __name__ == '__main__':
    root = ListNode(10)
    root.next = ListNode(9)
    root.next.next = ListNode(6)
    root.next.next.next = ListNode(8)
    root.next.next.next.next = ListNode(-1)
    root.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next = ListNode(2)
    root.next.next.next.next.next.next.next = ListNode(7)
    # root.next.next.next.next.next.next.next.next = ListNode(1)
    solution = linkedListMiddleNodeDoublePointers()
    ans = solution.getMiddleNode(root)
    print(ans.val)