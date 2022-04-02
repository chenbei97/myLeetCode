'''
Author: chenbei
Date: 2022-04-02 11:30:11
LastEditTime: 2022-04-02 15:56:54
Description: linkedListRotateList_Iteration.py
FilePath: \myLeetCode\linkedList\linkedListRotateList_Iteration.py
A boy without dreams
'''
from ListNode import ListNode
class linkedListRotateListIteration:
    def rotate(self,root:ListNode,k:int)->None:
        if not root or not root.next or not k :
            return root
        iter = root
        length = 0
        while iter.next:
            iter = iter.next
            length += 1 
        # 此时iter=last,length还差1才是真正的长度
        length += 1

        newFirst = 0 if not k % length else length - k % length
        if not newFirst: # 为0的情况直接返回
            return root
        newLast = newFirst -1 + 1 # 尾节点必定是新节点前1个,但是需要再+1次前进
        iter.next = root
        while newLast:
            iter = iter.next # 前进newLast+1次
            newLast -= 1
        ans = iter.next # 此时iter是尾节点,下一个是首节点
        iter.next = None # 断开联系
        return ans
if __name__ == '__main__':
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    root.next.next.next.next = ListNode(5)
    root.next.next.next.next.next = ListNode(6)
    root.next.next.next.next.next.next = ListNode(7)
    root.next.next.next.next.next.next.next = ListNode(8)
    root.next.next.next.next.next.next.next.next = ListNode(9)
    solution = linkedListRotateListIteration()
    ans = solution.rotate(root,3)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next