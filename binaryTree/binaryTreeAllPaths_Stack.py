from TreeNode import TreeNode
from typing import List
class binaryTreeAllPathsStack:
    def allPaths(self,root:TreeNode)->List:
        if not root : return []
        paths = []
        stk = []
        path = ""
        p = root
        while p or len(stk)!=0 :
            while p :
                if p == root:
                    path = path+str(p.val)
                else:
                    path = path+"->"+str(p.val)
                stk.append((p,path)) # 使用元组,C++用pair
                p = p.left # 寻找最左路径
            p = stk[0][0] # 回到父节点
            path = stk[0][1] # 元组对象第2个是路径
            stk.pop(0)
            if not p.left and not p.right :
                paths.append(path)
            p = p.right # 更新到父节点的右节点
        return paths
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
    # root1 = TreeNode(1) 
    # root1.left = TreeNode(2)
    # root1.right = TreeNode(3) 
    # root1.left.left = TreeNode(4)
    solution = binaryTreeAllPathsStack()
    ans = solution.allPaths(root1)
    for i in range(len(ans)):
        print(ans[i])
    '''
    1->3->6->11->12
    1->2->5
    1->2->4->10
    '''    
