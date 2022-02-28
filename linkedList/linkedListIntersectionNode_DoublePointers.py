from ListNode import ListNode
class linkedListIntersectionNodeDoublePointers:
        def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
            if not headA or not headB: return None
            pa,pb = headA,headB
            while pa!= pb:
                if pa : pa = pa.next
                else : pa = headB
                if pb : pb = pb.next
                else : pb = headA
            return pa
if __name__ == '__main__':
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(4)

    m1 = ListNode(6)
    m2 = ListNode(7)

    s1 = ListNode(8)
    s2 = ListNode(10)
    s3 = ListNode(12)
    
    n1.next = n2
    n2.next = n3
    n3.next = s1

    m1.next = m2
    m2.next = s1

    s1.next = s2
    s2.next = s3

    solution = linkedListIntersectionNodeDoublePointers()
    ans = solution.getIntersectionNode(n1,m1)
    if ans :
        print("double pointers:intersection node val is ",ans.val)
    else:
        print("double pointers:intersection node not exists")
