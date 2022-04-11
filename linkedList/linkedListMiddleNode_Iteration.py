'''
Author: chenbei
Date: 2022-04-11 10:08:33
LastEditTime: 2022-04-11 14:43:13
Description: linkedListMiddleNode_Iteration.py
FilePath: \myLeetCode\linkedList\linkedListMiddleNode_Iteration.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListMiddleNodeIteration:
    def getMiddleNode(self,root:ListNode)->None:
        l = [root]
        while l[-1].next != None:
            l.append(l[-1].next)
        return l[len(l)//2]
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
    solution = linkedListMiddleNodeIteration()
    ans = solution.getMiddleNode(root)
    print(ans.val)