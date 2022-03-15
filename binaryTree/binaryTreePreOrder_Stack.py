'''
Author: chenbei
Date: 2022-02-14 07:58:04
LastEditTime: 2022-03-15 11:20:36
Description: tree's preOrder by stack
FilePath: \myLeetCode\binaryTree\binaryTreePreOrder_Stack.py
A boy without dreams
'''
from typing import List
from typing import Optional
from TreeNode import TreeNode
"""
1.定义一个栈 stk,先将根节点压入栈
2.若栈不为空,每次从栈中弹出一个节点(根节点开始)
3.保存该节点的值
4.先把节点右孩子压入栈,接着把节点左孩子压入栈(如果有孩子节点)
5.重复 2-4 所以左孩子先出栈、右孩子后出栈
6.返回结果为根、左、右
"""
class binaryTreePreOrderStack:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = [] # ans为队列机制,先进先出
        if root is None:
            return ans
        stk = [root] # 初始栈存储根节点 stk为栈机制后入先出
        while stk: # stk不为None
            print("before pop -> ",[x.val for x in stk])
            node = stk.pop()  # 出栈根先出,然后先左后右
            print("after pop -> ",[x.val for x in stk]) # 跟踪stk删除后的情况
            ans.append(node.val) 
            if node.right: # 和后序遍历不同,先将右孩子压入栈
                stk.append(node.right)
            if node.left: 
                stk.append(node.left) #入栈先右后左 
 
        return ans  # 无需反转

if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreePreOrderStack()
    ret = solution.preorderTraversal(n1) # [1, 2, 4, 5, 3, 6, 7] 
    print(ret)