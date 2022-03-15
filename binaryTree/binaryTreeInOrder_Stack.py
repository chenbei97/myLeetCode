'''
Author: chenbei
Date: 2022-02-14 07:58:04
LastEditTime: 2022-03-15 11:06:40
Description: binaryTree inOrder by stack
FilePath: \myLeetCode\binaryTree\binaryTreeInOrder_Stack.py
A boy without dreams
'''
from typing import List
from typing import Optional
from TreeNode import TreeNode
'''
1.定义一个栈 stk
2.将树的左节点依次入栈,更新root,直到左节点为空,此时root为空
3.root为空时,让root等于弹出的栈顶元素并保存,然后更新root为右节点
直到root不为空,也就是root上移才有可能,这时右节点也入栈,保存后root又更新为左节点
然后root又为空,root会继续更新为栈顶元素,如果栈顶元素也没有,循环退出
4.重复 2-3 的操作
'''
class binaryTreeInOrderStack:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans, stk = [], []
        while root or stk:
            if root:
                print("if: root is ",root.val)
                stk.append(root) # 中序遍历左节点先入栈
                print("if: stk is ",[x.val for x in reversed(stk)]) # 追踪stk
                root = root.left # 更新为左节点,左节点为空时执行else语句
                print("if: root is update to root.left = ",root.val if root else None)
            else:
                root = stk.pop() # 节点出栈
                print("else: root = stk.top() is ",root.val)
                ans.append(root.val)
                print("else: ans is ",ans) # 追踪ans
                root = root.right # 更新为右节点
                print("else: root is update to root.right = ",root.val if root else None)
        return ans
        '''
            if: root is  1
            if: stk is  [1]
            if: root is update to root.left =  2
            if: root is  2
            if: stk is  [2, 1]
            if: root is update to root.left =  4
            if: root is  4
            if: stk is  [4, 2, 1]
            if: root is update to root.left =  None
            else: root = stk.top() is  4
            else: ans is  [4]
            else: root is update to root.right =  None
            else: root = stk.top() is  2
            else: ans is  [4, 2]
            else: root is update to root.right =  5
            if: root is  5
            if: stk is  [5, 1]
            if: root is update to root.left =  None
            else: root = stk.top() is  5
            else: ans is  [4, 2, 5] !!!这里要开始注意了
            else: root is update to root.right =  None 右节点为空
            else: root = stk.top() is  1 但是栈还不为空就可以执行else语句 更新root为top
            else: ans is  [4, 2, 5, 1]
            else: root is update to root.right =  3
            if: root is  3
            if: stk is  [3]
            if: root is update to root.left =  6
            if: root is  6
            if: stk is  [6, 3]
            if: root is update to root.left =  None
            else: root = stk.top() is  6
            else: ans is  [4, 2, 5, 1, 6]
            else: root is update to root.right =  None
            else: root = stk.top() is  3
            else: ans is  [4, 2, 5, 1, 6, 3]
            else: root is update to root.right =  7
            if: root is  7
            if: stk is  [7]
            if: root is update to root.left =  None
            else: root = stk.top() is  7
            else: ans is  [4, 2, 5, 1, 6, 3, 7]
            else: root is update to root.right =  None
            [4, 2, 5, 1, 6, 3, 7]
        '''

if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreeInOrderStack()
    ret = solution.inorderTraversal(n1) # [4, 2, 5, 1, 6, 3, 7]
    print(ret)