from ListNode import ListNode
class linkedListRemoveDuplicatesIteration:
    def removeDuplicates(self,root:ListNode)->ListNode:
        if not root : return None
        if not root.next : return root
        # fast = root.next
        # slow = root
        # ans = slow
        # while fast :
        #     while fast.val == slow.val:
        #         fast = fast.next
        #         if not fast : break
        #     if not fast: break
        #     slow.next = fast
        #     fast = fast.next
        #     slow = slow.next
        # return ans
        p = root.next
        ans = root
        while p:
            while p.val == root.val:
                p = p.next
                root.next = None # 防止链表全部元素都重复连续2个break直接返回原来的ans=root
                if not p:break
            if not p: break
            root.next = p
            p = p.next
            root = root.next
        return ans

        
if __name__ == '__main__':
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(2)
    root.next.next.next = ListNode(3)
    root.next.next.next.next = ListNode(3)
    root.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next.next.next = ListNode(5)
    solution = linkedListRemoveDuplicatesIteration()
    ans = solution.removeDuplicates(root)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next