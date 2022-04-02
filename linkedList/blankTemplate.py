'''
Author: chenbei
Date: 2022-04-02 09:33:45
LastEditTime: 2022-04-02 09:46:04
Description: blankTemplate.py
FilePath: \myLeetCode\linkedList\blankTemplate.py
A boy without dreams
'''
from ListNode import ListNode
class A:
    def func(self,root:ListNode)->None:
        pass
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
    solution = A()
    ans = solution.func(root)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next