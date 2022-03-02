from ListNode import ListNode
class linkedListRemoveTheNodeFromEndDoublePointers:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast, slow = head, head
        while n > 0:
            fast = fast.next
            n -= 1
        if not fast:
            return slow.next
        while fast.next:
            fast, slow = fast.next, slow.next
        slow.next = slow.next.next
        return head
if __name__ == '__main__':
    solution = linkedListRemoveTheNodeFromEndDoublePointers()
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    ans = solution.removeNthFromEnd(root,2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next