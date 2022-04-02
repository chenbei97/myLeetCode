'''
Author: chenbei
Date: 2022-04-02 11:03:57
LastEditTime: 2022-04-02 11:10:39
Description: linkedListRemoveElements_Iteration.py
FilePath: \myLeetCode\linkedList\linkedListRemoveElements_Iteration.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListRemoveElementsRecursion:
    def removeElements(self,root:ListNode,val:int)->None:
        dummy = ListNode(0,root) # 哑节点,root's prev,这是因为root也可能被删除,为了方便使用前1位开始
        cur = dummy
        while cur.next:
            if cur.next.val == val: # cur的下一个节点和val相等
                cur.next = cur.next.next # 断开cur.next与cur和cur的联系
            else:
                cur = cur.next # cur.next被保留,移动cur到cur.next
        return dummy.next

if __name__ == '__main__':
    root = ListNode(10)
    root.next = ListNode(9)
    root.next.next = ListNode(6)
    root.next.next.next = ListNode(2)
    root.next.next.next.next = ListNode(4)
    root.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next = ListNode(2)
    root.next.next.next.next.next.next.next = ListNode(7)
    root.next.next.next.next.next.next.next.next = ListNode(1)
    solution = linkedListRemoveElementsRecursion()
    ans = solution.removeElements(root,2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next