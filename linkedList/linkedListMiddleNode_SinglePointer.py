'''
Author: chenbei
Date: 2022-04-11 15:20:40
LastEditTime: 2022-04-11 15:27:30
Description: linkedListMiddleNode_SinglePointer.py
FilePath: \myLeetCode\linkedList\linkedListMiddleNode_SinglePointer.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListMiddleNodeSinglePointer:
    def getMiddleNode(self,root:ListNode)->None:
        n,k=0,0
        cur = root
        while cur:
            n += 1
            cur =cur.next
        cur = root
        while k < n//2:
            cur = cur.next
            k = k+1
        return cur
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
    solution = linkedListMiddleNodeSinglePointer()
    ans = solution.getMiddleNode(root)
    print(ans.val)