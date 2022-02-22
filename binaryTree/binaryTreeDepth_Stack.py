from TreeNode import TreeNode
class binaryTreeDepthStack:
    def getDepth(self,root:TreeNode)->int:
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
    solution = binaryTreeDepthStack()
    ans = solution.getDepth(root1)
    print("method3: tree depth is ",ans)