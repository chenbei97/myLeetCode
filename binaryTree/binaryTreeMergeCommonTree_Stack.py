'''
Author: chenbei
Date: 2022-02-20 10:59:17
LastEditTime: 2022-03-15 11:16:03
Description: merge two trees by stack
FilePath: \myLeetCode\binaryTree\binaryTreeMergeCommonTree_Stack.py
A boy without dreams
'''
from TreeNode import TreeNode
from queue import Queue
class binaryTreeMergeCommonTreeStack:
    def mergeCommonTree(self,root1:TreeNode,root2:TreeNode):
        if not root2 : return root1
        if not root1 :
           root1 = root2
           return root1
        s1,s2 = [root1],[root2]
        while s1:
            p,q = s1[0],s2[0]
            s1.pop(0),s2.pop(0)
            p.val += q.val
            if not p.left and q.left :
                p.left = q.left
            else :
                if p.left and q.left:
                    s1.append(p.left)
                    s2.append(q.left)
            if not p.right and q.right :
                p.right = q.right
            else :
                if p.right and q.right :
                    s1.append(p.right)
                    s2.append(q.right)
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

    solution = binaryTreeMergeCommonTreeStack()
    root = solution.mergeCommonTree(root1,root2)
    solution.levelOrder(root)