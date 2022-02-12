from typing import List
from typing import Optional
from TreeNode import TreeNode
class binaryTreePreOrderRecursion:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            nonlocal ans
            ans.append(root.val) # 在开头位置进行append
            dfs(root.left)
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
    solution = binaryTreePreOrderRecursion()
    ret = solution.preorderTraversal(n1) # [1, 2, 4, 5, 3, 6, 7]
    print(ret)