from typing import Optional
from ListNode import ListNode
class linkedListMergeTwoOrderedIteration:
        def mergeTwoListsMy(self, list1: Optional[ListNode],
            list2: Optional[ListNode]) -> Optional[ListNode]:
            if not list1 and not list2 : return None
            t = ListNode()
            ans = t
            while list1 or list2:
                if list1 and list2 :
                    if list1.val < list2.val:
                        t.val = list1.val
                        t.next = ListNode()
                        t = t.next
                        list1 = list1.next
                    elif list1.val > list2.val:
                        t.val = list2.val
                        t.next = ListNode()
                        t = t.next
                        list2 = list2.next
                    else :
                        t.val = list1.val
                        t.next = ListNode(list2.val)
                        t.next.next = ListNode()
                        list1 = list1.next
                        list2 = list2.next
                        if not list1 and not list2:
                            t.next.next = None
                        t = t.next.next
                elif not list1 and list2 :
                    t.val = list2.val
                    t.next = list2.next
                    break
                elif not list2 and list1:
                    t.val = list1.val
                    t.next = list1.next
                    break
            return ans

        def mergeTwoLists(self, list1: Optional[ListNode],
            list2: Optional[ListNode]) -> Optional[ListNode]:
            t = ListNode()
            ans = t
            while list1 and list2:
                if list1.val <= list2.val:
                    t.next = list1
                    list1 = list1.next
                else:
                    t.next = list2
                    list2 = list2.next
                t = t.next
            if list1 or list2 :
                if list1 : t.next = list1
                else : t.next = list2
            else : t.next = None
            return ans.next
if __name__ == '__main__':
    list1 = ListNode(1)
    list1.next = ListNode(2)
    list1.next.next = ListNode(4)
    list2 = ListNode(1)
    list2.next = ListNode(3)
    list2.next.next = ListNode(4)
    solution = linkedListMergeTwoOrderedIteration()
    ans = solution.mergeTwoListsMy(list1,list2)
    while ans :
        print(ans.val,end=" ")
        ans = ans.next
    ans = solution.mergeTwoLists(list1,list2)
    print()
    while ans :
        print(ans.val,end=" ")
        ans = ans.next
