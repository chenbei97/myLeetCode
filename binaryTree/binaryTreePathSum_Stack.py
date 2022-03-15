'''
Author: chenbei
Date: 2022-03-06 10:52:17
LastEditTime: 2022-03-15 11:18:23
Description: calculate tree's pathsum by stack
FilePath: \myLeetCode\binaryTree\binaryTreePathSum_Stack.py
A boy without dreams
'''
from TreeNode import TreeNode
from typing import Optional
class binaryTreePathSumStack:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        pathSums = []
        stk = []
        pathSum = []
        p = root
        while p or len(stk)!=0: # p可能是空节点或者右节点,是空节点但不栈空还会退栈
            while p : # 这个右节点不为空,就总是找它作为父节点的最左路径
                pathSum.append(p.val)
                temp = pathSum.copy() # 必须深拷贝,保证每次添加的是不同的地址
                stk.append((p,temp)) # 添加元组
                # 这个打印的结果可以看出来,stk每次存的都是temp,相同的地址,每个元素同步变化
                # print("h1=>",[x[1] for x in stk]) # 相当于存的是[pathSum,pathSum,pathSum,....]
                p = p.left # 总是找最左路径
            # while退出时p是父节点的左节点,且为空
            p = stk[-1][0] # p回到父节点,它不为空
            pathSum = stk[-1][1] # 路径也回到父节点时的路径
            # print("h4=>",[x[1] for x in stk])
            stk.pop() # 删除路径栈空节点的路径
            # print("h5=>",[x[1] for x in stk])
            if p.right is None and p.left is None: # 之前p的左节点已经为空,现在右节点也为空
                pathSums.append(sum(pathSum)) # 说明到达叶子节点,一个完整的路径结束
            # 无论右节点是否为空都会切右路,交由下一次的while的判断,不在这里进行筛选
            p = p.right
        print(pathSums)
        if targetSum in pathSums:
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
    solution = binaryTreePathSumStack()
    ans = solution.hasPathSum(root1,33)
    print("stack: the path which the pathsum is 33 is exist? ",True if ans else False)