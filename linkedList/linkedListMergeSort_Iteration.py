'''
Author: chenbei
Date: 2022-04-06 08:00:48
LastEditTime: 2022-04-06 09:56:48
Description: linkedListMergeSort_Iteration.py
FilePath: \myLeetCode\linkedList\linkedListMergeSort_Iteration.py
Signature: A boy without dreams
'''
from ListNode import ListNode
class linkedListMergeSortIteration:
    def mergeSort(self,head:ListNode)->ListNode:
        h, length, intv = head, 0, 1
        while h: 
            h, length = h.next, length + 1 # 计算链表长度
        res = ListNode(0) 
        res.next = head # 哑节点

        # 大循环,每轮intv进行链表归并
        while intv < length:
            pre, h = res, res.next # 辅助头节点的前1个节点和辅助头节点
            while h: # 小循环,每次h都是全局head节点,一轮intv要找出所有的(h1,h2)
                # 寻找链表的头节点h1
                h1, i = h, intv
                while i and h: # h从head开始找
                    h, i = h.next, i - 1 
                # i=0说明,h作为head的链表只有1个元素,只能作为h1用,h2不存在直接break
                if i: break # 这种情况出现在奇数长度,且第1轮intv=1时,最后必然只剩下1个元素

                # 寻找链表的头节点h2,此时的h的后1个作为h2,i也是
                h2, i = h, intv
                while i and h: 
                    h, i = h.next, i - 1 # h指针已经被移动到下一个要合并的单元头部
                c1, c2 = intv, intv - i # 一般情况下c1=c2,如果是奇数可能c2=c1-1
                
                # 合并h1和h2两个链表
                while c1 and c2: # 所有的节点都归并过为止
                    if h1.val < h2.val: 
                        # 更新h1->next,减少c1
                        pre.next, h1, c1 = h1, h1.next, c1 - 1 # pre的next指向当前被归并的节点,它负责衔接res
                    else: 
                        # 更新h2->next,减少c2
                        pre.next, h2, c2 = h2, h2.next, c2 - 1 # pre的next指向当前被归并的节点
                    pre = pre.next # 更新pre
                pre.next = h1 if c1 else h2 # h1,h2可能有剩余的节点,直接接在pre后边即可
                while c1 > 0 or c2 > 0: 
                    pre, c1, c2 = pre.next, c1 - 1, c2 - 1 # 把pre移动到合并的链表末尾,例如第0和第1个节点末尾就是第1个节点
                pre.next = h # 此时的h已经移动到第2个节点,让pre.next衔接上
            intv *= 2 # 下一轮链表归并
        return res.next
if __name__ == '__main__':
    root = ListNode(10)
    root.next = ListNode(9)
    root.next.next = ListNode(6)
    root.next.next.next = ListNode(8)
    root.next.next.next.next = ListNode(4)
    root.next.next.next.next.next = ListNode(5)
    root.next.next.next.next.next.next = ListNode(2)
    root.next.next.next.next.next.next.next = ListNode(7)
    root.next.next.next.next.next.next.next.next = ListNode(1)
    solution = linkedListMergeSortIteration()
    ans = solution.mergeSort(root)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next