'''
Author: chenbei
Date: 2022-02-22 14:10:06
LastEditTime: 2022-03-15 11:17:36
Description: calculate tree's mindepth by recursion
FilePath: \myLeetCode\binaryTree\binaryTreeMinDepth_Recursion.py
A boy without dreams
'''
from TreeNode import TreeNode
class binaryTreeMinDepthRecursion:
    count = 0
    def getMinDepth(self,root:TreeNode)->int:
        # 第1种递归方法,和找最大深度一样,只需记录depth的变化即可
        # 然后找到其中最小的depth即可,注意要从第一次子节点均为空开始的depth记录
        # 初始的depth=1不要算上
        if not root : return 0
        depths = [] # 最初的depth=1不记录
        def loop(root,d):
            if not root :
                return
            if not root.left and not root.right:
                depths.append(d) 
            d += 1
            if root.left : loop(root.left,d)
            if root.right : loop(root.right,d)
        loop(root,1)
        # print(depths)
        return min(depths)
    def treeMinDepth(self,root:TreeNode)->int:
        # 第2种递归方法,每个节点总是返回是空节点的子树深度,因为空节点深度更小
        if not root : return 0
        if self.count > 0 :
            if not root.right : return 1 + self.treeMinDepth(root.left)
            if not root.left : return 1 + self.treeMinDepth(root.right)
        self.count = 1 # 用于第一次进入时不执行2个if减少程序时间消耗
        return 1 + min(self.treeMinDepth(root.right),self.treeMinDepth(root.left)) 

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
    solution = binaryTreeMinDepthRecursion()
    ans = solution.getMinDepth(root1)
    print("method1: tree min depth is ",ans)
    ans = solution.treeMinDepth(root1)
    print("method2: tree min depth is ",ans)