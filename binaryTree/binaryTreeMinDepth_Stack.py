'''
Author: chenbei
Date: 2022-02-22 14:54:11
LastEditTime: 2022-03-15 11:17:46
Description: calculate tree's mindepth by stack
FilePath: \myLeetCode\binaryTree\binaryTreeMinDepth_Stack.py
A boy without dreams
'''
from TreeNode import TreeNode
class binaryTreeMinDepthStack:
    def getMinDepth(self,root:TreeNode)->int:
        if not root :return 0
        stk = []
        depths = []
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
                depths.append(d)
            p = p.right
        return min(depths)
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
    solution = binaryTreeMinDepthStack()
    ans = solution.getMinDepth(root1)
    print("method3: tree min depth is ",ans)