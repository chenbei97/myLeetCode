from ListNode import ListNode
class linkedListIntersectionNodeHashSet:
        def getIntersectionNodeSet(self, headA: ListNode, headB: ListNode) -> ListNode:
            s = set()
            t = headA
            while t :
                s.add(t)
                t = t.next
            t = headB
            while t:
                if t in s:
                    return t
                t = t.next
            return None
        def getIntersectionNodeDict(self, headA: ListNode, headB: ListNode) -> ListNode:
            from collections import defaultdict
            d = defaultdict(ListNode)
            t = headA
            while t:
                d[t] = t.val
                t = t.next
            t = headB
            while t:
                if t in d.keys():
                    return t
                t = t.next
            return None
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

    solution = linkedListIntersectionNodeHashSet()
    ans = solution.getIntersectionNodeSet(n1,m1)
    if ans :
        print("hashSet:intersection node val is ",ans.val)
    else:
        print("hashSet:intersection node not exists")

    ans = solution.getIntersectionNodeDict(n1,m1)
    if ans :
        print("hashDict:intersection node val is ",ans.val)
    else:
        print("hashDict:intersection node not exists")