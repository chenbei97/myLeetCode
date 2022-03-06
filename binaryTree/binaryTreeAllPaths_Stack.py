from TreeNode import TreeNode
from typing import List
class binaryTreeAllPathsStack:
    def allPaths(self,root:TreeNode)->List:
        if not root : return []
        paths = []
        stk = [] # 保存每个遍历过的节点指针及其路径,栈顶元素是当前节点和当前路径
        path = "" # 到当前节点的路径
        p = root
        while p or len(stk)!=0 : # p可能是右方向的节点,也可能是空节点
            while p : # 如果是右方向的节点,就会进入二级while循环,找到以它为父节点的最左路径,直到最左路径结束while退出
                if p == root: # 首次为root的特殊处理,不加箭头
                    path = path+str(p.val)
                else:
                    path = path+"->"+str(p.val)
                stk.append((p,path)) # 使用元组,C++用pair
                p = p.left # 每个非空节点都是先找最左路径
            # 如果是空节点不会执行二级while,会继续路径退栈更新p指向栈顶元素,返回到上一父节点
            p = stk[-1][0] # 回到父节点
            path = stk[-1][1] # 元组对象第2个是路径
            stk.pop()# 左节点是空节点了,遇到空节点的时候就会退回到上一级父节点(即路径出栈)
            if not p.left and not p.right : # 父节点的左节点已经是空节点,右节点也是空说明是一条完整路径了
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
