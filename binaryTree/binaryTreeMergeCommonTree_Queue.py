from TreeNode import TreeNode
from queue import Queue
class binaryTreeMergeCommonTreeQueue:
    def mergeCommonTree(self,root1:TreeNode,root2:TreeNode):
        if not root2 : return root1
        if not root1 :
           root1 = root2
           return root1
        s1,s2 = Queue(),Queue() # 必须这样空队列,不能直接s1,s2=Queue(root1),Queue(root2)
        s1.put_nowait(root1),s2.put_nowait(root2)
        while not s1.empty(): # 且不能用while s1 会抛出Empty异常
            p,q = s1.get_nowait(),s2.get_nowait()
            p.val += q.val
            if not p.left and q.left :
                p.left = q.left
            else :
                if p.left and q.left:
                    s1.put_nowait(p.left)
                    s2.put_nowait(q.left)
            if not p.right and q.right :
                p.right = q.right
            else :
                if p.right and q.right :
                    s1.put_nowait(p.right)
                    s2.put_nowait(q.right)
        return root1
    def levelOrder(self,root:TreeNode)->None:
        q = Queue()
        t = root
        if not t:
            print("None")
            return
        while t:
            print(f"({t.val}) ",end="")
            if t.left:
                q.put_nowait(t.left)
            if t.right:
                q.put_nowait(t.right)
            if not q.empty():
                t = q.get_nowait()
            else :
                print()
                return
if __name__ == '__main__':
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.right = TreeNode(3)
    root1.left.left = TreeNode(4)
    root1.left.right = TreeNode(5)
    root1.right.left = TreeNode(6)
    root1.left.left.right = TreeNode(10)
    root1.right.left.left = TreeNode(11)
    root1.right.left.left.right = TreeNode(12)

    root2 = TreeNode(-5)
    root2.left = TreeNode(-9)
    root2.right = TreeNode(-3)
    root2.left.left = TreeNode(-1)
    root2.left.right = TreeNode(0)
    root2.right.left = TreeNode(-14)
    root2.right.right = TreeNode(-15)

    solution = binaryTreeMergeCommonTreeQueue()
    root = solution.mergeCommonTree(root1,root2)
    solution.levelOrder(root)