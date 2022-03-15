'''
Author: chenbei
Date: 2022-02-20 19:04:09
LastEditTime: 2022-03-15 11:04:46
Description: find binaryTree all paths by recursion
FilePath: \myLeetCode\binaryTree\binaryTreeAllPaths_Recursion.py
A boy without dreams
'''
from TreeNode import TreeNode
from typing import List
class binaryTreeAllPathsRecursion:
    def allPaths(self,root:TreeNode)->List:
        ans = []
        t = []
        # index = 0
        def loop(root):
            # nonlocal index
            # print("index:",index,end="  ")
            # index += 1
            if root is None:
                return
            t.append(str(root.val)) # 如果非空就添加这个值
            # 什么时候t作为一条路径?
            if root.right is None and root.left is None :
                ans.append("->".join(t)) # 每到1个节点就分出2个路径,右节点优先,左节点压栈,直到2个子节点都是空为止
                # print("ans:",ans,end="\n") # 存储1条路径
                # index = 0
            if root.right : 
                # print("right")
                loop(root.right) # 左右顺序无所谓
            if root.left : 
                # print("left") # 观察输出结果,在after: ['1']后执行了此句,这是因为以上方为主的递归过程结束了
                loop(root.left)
            # print("before:",t,end="  ")
            t.pop() # 因为每个节点二分的时候,t.pop()也压栈,压栈次数和节点压栈次数相同,结果就是退回全局根节点
            # print("after:",t,end="\n")
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