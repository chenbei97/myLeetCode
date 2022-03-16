'''
Author: chenbei
Date: 2022-03-09 11:20:37
LastEditTime: 2022-03-16 08:19:35
Description: judge linkedList has circular by double pointers
FilePath: \myLeetCode\linkedList\linkedListCircularExist_DoublePointers.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListCircularExistDoublePointers:
    def circularIsExist(self,root:ListNode):
        if not root or not root.next:
            return False
        slow,fast = root,root.next
        while slow!= fast:
            if not slow or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
if __name__ == '__main__':
    root = ListNode(3)
    root.next = ListNode(2)
    root.next.next = ListNode(0)
    root.next.next.next = ListNode(-4)
    root.next.next.next.next = root.next.next
    solution = linkedListCircularExistDoublePointers()
    print(True if solution.circularIsExist(root) else False)