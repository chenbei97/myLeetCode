'''
Author: chenbei
Date: 2022-02-14 15:48:59
LastEditTime: 2022-03-15 11:11:39
Description: judge an tree is subStructure of other tree by recursion
FilePath: \myLeetCode\binaryTree\binaryTreeisSubStructure_Recursion.py
A boy without dreams
'''
from TreeNode import TreeNode
class binaryTreeisSubStructureRecursion:
    def isSubStructure(self,tree1: TreeNode,tree2:TreeNode) -> bool :
        if tree1 is None or tree2 is None :
            return False
        # 思路和迭代解法是一样的,只是更简洁没有很多if_else判断
        # 迭代思路:是找到1个可能合适的根节点,再进行比较,没找到再尝试根节点的左右节点和第2棵树的比较
        # 这里不管三七二十一直接全部带进入loop函数,只要有1个行就可以
        # loop函数和compareSubTree函数完全一样,只是把后2个判断返回true的条件写在一起了
        # 同时多增加了1个判断,这是避免第1次进入loop函数导致的问题
        # 假如没有这个条件,tree2为None无论tree1是否为None,3种调用进入loop函数都直接返回true
        # 看起来还没什么问题,因为空节点确实也算第1棵树的子树,即使tree1=None
        # 如果tree1为None,就会造成调用出错,因为空指针没有属性left和right
        def loop(left,right): 
            if right is None: 
                return True
            if left is None or left.val != right.val:
                return False
            return loop(tree1.left, tree2.left) and loop(tree1.right, tree2.right)
        return loop(tree1, tree2) \
                or self.isSubStructure(tree1.left, tree2) \
                or self.isSubStructure(tree1.right, tree2)


if __name__ == '__main__':
    '''
         3        3   3(爆栈) 
        / \      /   /      
       4   5    4   4       
     /  \        \   \                  
    1    2        2   3   
          \
           7
          /
         10               
    '''
    tree1 = TreeNode(3)
    tree1.left = TreeNode(4)
    tree1.right = TreeNode(5)
    tree1.left.left = TreeNode(1)
    tree1.left.right = TreeNode(2)
    tree1.left.right.right = TreeNode(7)
    tree1.left.right.right.left = TreeNode(10)

    tree2 = TreeNode(-1) # 寻找-1
    # tree2.left = TreeNode(4)
    # tree2.left.right = TreeNode(2)

    tree3 = TreeNode(10) # 寻找10
    # tree3.left = TreeNode(4)
    # tree3.left.right = TreeNode(3)

    solution = binaryTreeisSubStructureRecursion()
    ret1 = solution.isSubStructure(tree1,tree2)
    ret2 = solution.isSubStructure(tree1,tree3)
    print("ret1 is ",ret1," ret2 is ",ret2)