from ListNode import ListNode
class linkedListCircularExistDoublePointers:
    def circularIsExist(self,root:ListNode):
        pass
if __name__ == '__main__':
    root = ListNode(3)
    root.next = ListNode(2)
    root.next.next = ListNode(0)
    root.next.next.next = ListNode(-4)
    root.next.next.next.next = root.next.next
    solution = linkedListCircularExistDoublePointers()
    print(True if solution.circularIsExist(root) else False)