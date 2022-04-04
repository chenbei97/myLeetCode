'''
Author: chenbei
Date: 2022-04-04 12:08:16
LastEditTime: 2022-04-04 12:34:50
FilePath: \myLeetCode\linkedList\linkedListAddTwoNumbers_Stack.py
Description: linkedListAddTwoNumbers_Stack.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListAddTwoNumbersStack:
    def addTwoNumbers(self,root1:ListNode,root2:ListNode)->None:
        s1, s2 = [], [] # two stacks,和链表的数字顺序是一样的
        while root1:
            s1.append(root1.val) # push root1 to stack
            root1 = root1.next
        while root2:
            s2.append(root2.val) # push root2 to stack
            root2 = root2.next
        carry, dummy = 0, ListNode()
        while s1 or s2:
            val1 = 0 if not s1 else s1.pop() # 取出来时候要从尾部取
            val2 = 0 if not s2 else s2.pop()
            sum = val1 + val2 + carry
            carry = sum // 10
            sum = sum % 10 # 计算的是高位的节点数字,要放在前边
            # node的下一个节点接手了原本dummy的下一个节点
            node = ListNode(sum, dummy.next) # 头插是因为要求高位在前边
            dummy.next = node
        if carry:
            node = ListNode(carry, dummy.next)
            dummy.next = node
        return dummy.next

if __name__ == '__main__':
    root1 = ListNode(7)
    root1.next = ListNode(2)
    root1.next.next = ListNode(4)
    root1.next.next.next = ListNode(3)
    root2 = ListNode(5)
    root2.next = ListNode(6)
    root2.next.next = ListNode(4)
    solution = linkedListAddTwoNumbersStack()
    ans = solution.addTwoNumbers(root1,root2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next