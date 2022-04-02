'''
Author: chenbei
Date: 2022-04-02 10:15:25
LastEditTime: 2022-04-02 10:26:44
Description: linkedListReverseList_Recursion.py
FilePath: \myLeetCode\linkedList\linkedListReverseList_Recursion.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListReverseListIteration:
    def reverse(self,root:ListNode)->ListNode:
        if (not root) or (not root.next):
            return root
        newRoot = self.reverse(root.next) # 反复递归先到达最深处,root=last
        root.next.next = root # 让next.next指回自己
        root.next = None # 避免互指
        return newRoot
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
    solution = linkedListReverseListIteration()
    ans = solution.reverse(root)
    while ans:
        if ans.val != None:
            print(ans.val,end=" ")
        ans = ans.next