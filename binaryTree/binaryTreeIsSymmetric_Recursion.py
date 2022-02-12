from typing import Optional
from TreeNode import TreeNode
class binaryTreeIsSymmetricRecursion:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        left = root.left
        right = root.right
        def loop(left,right):
            # 对于root,left,right的最小单元应满足这样的条件
            if (left is None and right is None): # 双None的情况先判断
                return True
            if (left is None or right is None or left.val != right.val):
                return False
            # 然后需要更新left和right
            # 下一次需要比较left的左子树和right的右子树
            # 以及left的右子树和right的左子树
            # 它们都要返回True才行
            return loop(left.left,right.right) and loop(left.right,right.left)
        return loop(left,right) # 从全局根节点的左右子树开始
if __name__ == '__main__':
    
    tree1 = TreeNode(1)  
    tree1.left = tree1.right = TreeNode(2)
    tree1.left.left = tree1.right.right = TreeNode(3) 
    tree1.left.right = tree1.right.left = TreeNode(4)

    tree2 = TreeNode(1)
    tree2.left = tree2.right = TreeNode(2)
    tree2.left.left = tree2.right.right = TreeNode(3)
    tree2.left.right = TreeNode(4)
    tree2.right.left = TreeNode(5)

    solution = binaryTreeIsSymmetricRecursion()
    print("tree1 is symmetric ? ",solution.isSymmetric(tree1))
    print("tree2 is symmetric ? ",solution.isSymmetric(tree2))

    