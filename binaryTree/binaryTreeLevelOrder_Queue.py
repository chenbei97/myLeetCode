from queue import Queue # 单端FIFO队列,deque是双端队列,priority_queue是优先级队列,都继承于queue
from typing import List
from typing import Optional
from queue import Empty
from TreeNode import TreeNode
class binaryTreeLevelOrderQueue:
    def levelOrderTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        ans = []
        q = Queue()
        while root : # root最终会更新到队列为空为止
            ans.append(root.val)
            if root.left : # 左节点不为空
                q.put_nowait(root.left) # 左节点入列
            if root.right :# 右节点不为空
                q.put_nowait(root.right) # 右节点入列
            try :
                root = q.get_nowait()  # 队首元素出列(首次是根)
            except Empty:
                # print("queue is empty")
                break
        return ans
    # 此函数的区别是如果有的二叉树元素是None,后面不是None,也会把None打出来
    # 前提是需要知道树的高度,否则会无穷尽的打印None,因为他不知道什么结束循环
    # 所以规定只打印pow(2,height)-1这么多元素,超出的其实都是None但不会打印
    def levelOrderTraversalWithNone(self,height,root: Optional[TreeNode] ) -> List[List[int]]:
        ans = []
        q = Queue()
        q.put_nowait(root)
        while not q.empty() : # root最终会更新到队列为空为止
            try:
                root = q.get_nowait()  # 队首元素出列(首次是根)
            except Empty:
                break
            ans.append(root.val if root else None)
            # print(ans)
            q.put_nowait(root.left if root else None) # 左节点入列
            q.put_nowait(root.right if root else None) # 右节点入列
            if len(ans) == pow(2,height)-1:
                break
        return ans
    def ravelList(theList : List):
        return sum[theList,[]]
if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    s = binaryTreeLevelOrderQueue()
    ret1 = s.levelOrderTraversal(n1)
    print(ret1)

    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n2 = TreeNode(2,None,n5)
    n3 = TreeNode(3,n6,None)
    n1 = TreeNode(1,n2,n3)
    print(s.levelOrderTraversal(n1))
    ret2 = s.levelOrderTraversalWithNone(3,n1)
    print(ret2)