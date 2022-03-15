'''
Author: chenbei
Date: 2022-02-19 09:56:34
LastEditTime: 2022-03-15 11:08:13
Description: invert binaryTree by queue
FilePath: \myLeetCode\binaryTree\binaryTreeInvert_Queue.py
A boy without dreams
'''
from TreeNode import TreeNode
from queue import Queue
class binaryTreeInvertQueue:
    def invert(self,root : TreeNode) -> TreeNode:
        if not root : return root
        q = Queue()
        q.put_nowait(root)
        while not q.empty():
            t = q.get_nowait()
            t.left,t.right = t.right,t.left
            if t.right :
                q.put_nowait(t.right)
            if t.left :
                q.put_nowait(t.left)
        return root
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
    # 测试完全二叉树
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    solution = binaryTreeInvertQueue()
    ans = solution.invert(root)
    solution.levelOrder(ans)