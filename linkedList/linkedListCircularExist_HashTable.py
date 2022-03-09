from ListNode import ListNode
from collections import defaultdict
class linkedListCircularExistHashTable:
    def circularIsExist(self,root:ListNode):
        d = defaultdict(int)
        while root:
            if root in d.keys():
                return True
            d[root] += 1 # 随便做个动作
            root = root.next
        return False
if __name__ == '__main__':
    root = ListNode(3)
    root.next = ListNode(2)
    root.next.next = ListNode(0)
    root.next.next.next = ListNode(-4)
    root.next.next.next.next = root.next.next
    solution = linkedListCircularExistHashTable()
    print(True if solution.circularIsExist(root) else False)