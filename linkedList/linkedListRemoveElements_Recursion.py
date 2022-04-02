'''
Author: chenbei
Date: 2022-04-02 10:42:35
LastEditTime: 2022-04-02 10:53:40
Description: linkedListRemoveElements_Recursion.py
FilePath: \myLeetCode\linkedList\linkedListRemoveElements_Recursion.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListRemoveElementsRecursion:
    def removeElements(self,root:ListNode,val:int)->None:
        if not root:
            return root
        # 递归到最深处,到达last节点,last.next=None直接返回
        # 之后下边操作相当于last.next = None
        root.next = self.removeElements(root.next,val)
        # 然后比较root.val和val是否相等,相等就放弃last节点,返回last.next=None
        # 这是为了下一轮递归的root.next接收的还是None,此时的root是上一轮递归root的prev
        # 如果不相等,说明root可以保留,下一轮递归的root.next=root(上一轮保留的非空root)
        # 如此进行下去,最后返回的root是去除了等于val节点的链表
        return root.next if root.val==val else root
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