'''
Author: chenbei
Date: 2022-04-04 10:36:30
LastEditTime: 2022-04-04 12:28:48
FilePath: \myLeetCode\linkedList\linkedListAddTwoNumbers_Iteration.py
Description: linkedListAddTwoNumbers_Iteration.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListAddTwoNumbersIteration:
    def addTwoNumbers(self,root1:ListNode,root2:ListNode)->None:
        dummy = ListNode(None,None)
        next = dummy
        carry = 0
        while root1 or root2:
            val1 = 0 if root1 is None else root1.val
            val2 = 0 if root2 is None else root2.val
            sum = val1 + val2 + carry
            carry = sum // 10
            sum = sum % 10
            next.next = ListNode(sum)
            next = next.next
            root1 = root1.next if root1 else None
            root2 = root2.next if root2 else None
        if carry:
            next.next = ListNode(carry)
        return dummy.next

if __name__ == '__main__':
    root1 = ListNode(2)
    root1.next = ListNode(4)
    root1.next.next = ListNode(3)
    root2 = ListNode(5)
    root2.next = ListNode(6)
    root2.next.next = ListNode(4)
    solution = linkedListAddTwoNumbersIteration()
    ans = solution.addTwoNumbers(root1,root2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next