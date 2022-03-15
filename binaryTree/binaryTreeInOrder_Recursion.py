'''
Author: chenbei
Date: 2022-02-14 07:58:04
LastEditTime: 2022-03-15 11:06:26
Description: binaryTree inOrder by recursion
FilePath: \myLeetCode\binaryTree\binaryTreeInOrder_Recursion.py
A boy without dreams
'''
from typing import List
from typing import Optional
from TreeNode import TreeNode
class binaryTreeInOrderRecursion:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            nonlocal ans
            ans.append(root.val) # 在中间位置进行append
            dfs(root.right)
        ans = []
        dfs(root)
        return ans

if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreeInOrderRecursion()
    ret = solution.inorderTraversal(n1) # [4, 2, 5, 1, 6, 3, 7]
    print(ret)