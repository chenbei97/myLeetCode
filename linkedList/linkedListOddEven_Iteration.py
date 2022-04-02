'''
Author: chenbei
Date: 2022-04-02 11:30:43
LastEditTime: 2022-04-02 11:33:53
Description: linkedListOddEven_Iteration.py
FilePath: \myLeetCode\linkedList\linkedListOddEven_Iteration.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListOddEvenIteration:
    def oddEven(self,root:ListNode)->None:
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
    solution = linkedListOddEvenIteration()
    ans = solution.oddEven(root)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next