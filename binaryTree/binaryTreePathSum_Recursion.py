'''
Author: chenbei
Date: 2022-03-06 10:06:29
LastEditTime: 2022-03-15 11:18:10
Description: calculate tree's pathsum by recursion
FilePath: \myLeetCode\binaryTree\binaryTreePathSum_Recursion.py
A boy without dreams
'''
from TreeNode import TreeNode
from typing import Optional
class binaryTreePathSumRecursion:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        t = []
        ans = []
        def loop(root):
            if root is None:
                return
            t.append(root.val) # 说明这个节点非空,该点位于在某条路径上
            if root.left is None and root.right is None: # 到了叶子节点说明路径到头
                ans.append(sum(t))
            if root.right: # 右节点不为空继续递归,判断它的左右节点是否为空，直到为空说明路径结束
                loop(root.right)
            if root.left :
                loop(root.left) # 左节点同理
            t.pop() # 1个路径到头,ans添加完路径和之后,应当返回上1个节点,持续退栈直到全局根节点
        loop(root)
        print(ans)
        if targetSum in ans :
            return True
        return False
if __name__ == '__main__':
    '''
            1
           / \
          2   3 
         / \ /
        4  5 6
         \   /
         10 11
             \
             12
    '''
    root1 = TreeNode(1) 
    root1.left = TreeNode(2)
    root1.right = TreeNode(3) 
    root1.left.left = TreeNode(4)
    root1.left.right = TreeNode(5)
    root1.right.left = TreeNode(6) 
    root1.left.left.right = TreeNode(10)
    root1.right.left.left = TreeNode(11) 
    root1.right.left.left.right = TreeNode(12) 
    solution = binaryTreePathSumRecursion()
    ans = solution.hasPathSum(root1,33)
    print("recursion: the path which the pathsum is 33 is exist? ",True if ans else False)