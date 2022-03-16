'''
Author: chenbei
Date: 2022-02-28 11:36:59
LastEditTime: 2022-03-16 08:22:51
Description: merge two ordered linkedList by recursion
FilePath: \myLeetCode\linkedList\linkedListMergeTwoOrdered_Recursion.py
A boy without dreams
'''
from typing import Optional
from ListNode import ListNode
class linkedListMergeTwoOrderedRecursion:
        def mergeTwoLists(self, list1: Optional[ListNode],
            list2: Optional[ListNode]) -> Optional[ListNode]:
            if not list1 : return list2
            if not list2 : return list1
            if list1.val < list2.val:
                list1.next = self.mergeTwoLists(list1.next,list2)
                return list1
            else:
                list2.next = self.mergeTwoLists(list1,list2.next)
                return list2
if __name__ == '__main__':
    list1 = ListNode(1)
    list1.next = ListNode(2)
    list1.next.next = ListNode(4)
    list2 = ListNode(1)
    list2.next = ListNode(3)
    list2.next.next = ListNode(4)
    solution = linkedListMergeTwoOrderedRecursion()
    ans = solution.mergeTwoLists(list1,list2)
    while ans :
        print(ans.val,end=" ")
        ans = ans.next