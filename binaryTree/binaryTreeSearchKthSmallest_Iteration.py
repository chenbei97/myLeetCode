from typing import Optional
from TreeNode import TreeNode
class binaryTreeSearchKthSmallestIteration:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        pass
if __name__ == '__main__':
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    solution = binaryTreeSearchKthSmallestIteration()
    print("iteration: the smallest k element is ",solution.kthSmallest(root,6))