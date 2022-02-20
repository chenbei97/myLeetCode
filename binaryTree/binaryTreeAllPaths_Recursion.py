from TreeNode import TreeNode
from typing import List
class binaryTreeAllPathsRecursion:
    def allPaths(self,root:TreeNode)->List:
        ans = []
        t = []
        def loop(root):
            if root is None:
                return
            t.append(str(root.val)) # 如果非空就添加这个值
            # 什么时候t作为一条路径?
            if root.right is None and root.left is None :
                ans.append("->".join(t)) # 左右节点都是空节点说明这条路径结束
            if root.right : loop(root.right) # 左右顺序无所谓
            if root.left : loop(root.left)
            print("before:",t,end="  ")
            t.pop() # 会把t删除到回到根节点
            print("after:",t,end="\n")
        loop(root)
        return ans
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
    solution = binaryTreeAllPathsRecursion()
    ans = solution.allPaths(root1)
    for i in range(len(ans)):
        print(ans[i])
    '''
    1->3->6->11->12
    1->2->5
    1->2->4->10
    '''