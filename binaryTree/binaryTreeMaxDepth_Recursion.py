from TreeNode import TreeNode
class binaryTreeMaxDepthRecursion:
    def getMaxDepth(self,root:TreeNode)->int:
        depth = 0
        if not root : return depth
        depth = 1
        def loop(root,d):
            nonlocal depth
            if not root : return
            if not root.left and not root.right :
                if d > depth :
                    depth = d 
                return
            d += 1
            if root.right : loop(root.right,d)
            if root.left : loop(root.left,d)
        loop(root,depth)
        return depth
    def treeMaxDepth(self,root:TreeNode)->int: # 第2种递归方法
        l,r = 0,0
        if not root : return 0
        l = self.treeMaxDepth(root.left)
        r = self.treeMaxDepth(root.right)
        print(f"({l},{r})",end=" ")
        return  l+1 if l>r else r+1

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
    solution = binaryTreeMaxDepthRecursion()
    ans = solution.getMaxDepth(root1)
    print("method1: tree max depth is ",ans)
    ans = solution.treeMaxDepth(root1)
    print("method2: tree max depth is ",ans)

