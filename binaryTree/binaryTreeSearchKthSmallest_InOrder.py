'''
Author: chenbei
Date: 2022-03-07 10:54:14
LastEditTime: 2022-03-15 11:21:48
Description: search the k smallest element in searchTree by inOrder
FilePath: \myLeetCode\binaryTree\binaryTreeSearchKthSmallest_InOrder.py
A boy without dreams
'''
from typing import Optional
from TreeNode import TreeNode
class binaryTreeSearchKthSmallestInOrder:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if k == 0:
                return root.val
            root = root.right
if __name__ == '__main__':
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    solution = binaryTreeSearchKthSmallestInOrder()
    print("inorder(stack): the smallest k element is ",solution.kthSmallest(root,6))