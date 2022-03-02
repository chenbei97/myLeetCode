from ListNode import ListNode
class linkedListRemoveTheNodeFromEndIteration:
        def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
            length = 0
            t = head
            while t:
                t = t.next
                length += 1
            if length<2 :
                return None
            stop = length - n
            if stop < 1:
                return head.next
            t = head
            length = 1 # 前提是stop不等于0
            while length < stop : # stop节点的前1个
                head = head.next
                length += 1
            head.next = head.next.next
            return t



            
if __name__ == '__main__':
    solution = linkedListRemoveTheNodeFromEndIteration()
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    ans = solution.removeNthFromEnd(root,2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next
    