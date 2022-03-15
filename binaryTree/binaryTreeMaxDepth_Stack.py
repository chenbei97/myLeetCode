'''
Author: chenbei
Date: 2022-02-22 11:44:03
LastEditTime: 2022-03-15 11:17:21
Description: calculate tree's maxdepth by stack
FilePath: \myLeetCode\binaryTree\binaryTreeMaxDepth_Stack.py
A boy without dreams
'''
from TreeNode import TreeNode
class binaryTreeMaxDepthStack:
    def getMaxDepth(self,root:TreeNode)->int:
        depth = 0
        if not root :return depth
        stk = []
        d = 0
        p = root
        while p or len(stk)!= 0 :
            while p:
                if p == root : d=1
                else : d += 1
                stk.append((p,d))
                p = p.left
            p = stk[0][0]
            d = stk[0][1]
            stk.pop(0)
            if not p.right and not p.left :
                if d > depth:
                    depth = d 
            p = p.right
        return depth
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
    solution = binaryTreeMaxDepthStack()
    ans = solution.getMaxDepth(root1)
    print("method3: tree max depth is ",ans)