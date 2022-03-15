'''
Author: chenbei
Date: 2022-02-15 08:58:31
LastEditTime: 2022-03-15 11:11:27
Description: judge an tree is subStructure of other tree by iteration
FilePath: \myLeetCode\binaryTree\binaryTreeisSubStructure_Iteration.py
A boy without dreams
'''
from TreeNode import TreeNode
from typing import Optional,List
from queue import Queue
class binaryTreeisSubStructureIteration:
    def __init__(self) -> None:
        self.Order = []
    def isSubStructure(self,tree1:TreeNode,tree2:TreeNode)->bool:
        self.Order.clear()
        self.__levelOrderTraversal(tree1)
        if tree1 and tree2 :
            nodes = self.__searchSameNode(tree1,tree2.val)
            print(nodes)
            if len(nodes) !=0:
                res = False
                for i in range (len(nodes)):
                    res = self.__compareSubtree(nodes[i],tree2)
                    if res :
                        return True
        return False

    def __searchSameNode(self,tree1:TreeNode,val)->bool:
        # https://blog.csdn.net/Haiqiang1995/article/details/79185622?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2~default~OPENSEARCH~Rate-4.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~OPENSEARCH~Rate-4.pc_relevant_default&utm_relevant_index=9
        # 这个方法是错的,tree1运行到5,tree2还是2,因为5!=2,就返回false
        # 实际上5不满足,tree1应当继续往下找可能的节点再和tree2的2比
        # res = False
        # if tree1 and tree2:
        #     if (tree1.val == tree2.val): # 前提是相同元素节点
        #         print("here is 1, ",tree1.val," ",tree2.val)
        #         res = self.__compareSubtree(tree1,tree2) # 同级比较所有节点
        #     if not res: 
        #         print("here is 2, ",tree1.val," ",tree2.val)
        #         res = self.__compareSubtree(tree1.left,tree2) # 没找到就比较错位级左子树和第2棵树
        #     if not res: # # 没找到就继续比较错位级右子树和第2棵树比较
        #         print("here is 3, ",tree1.val," ",tree2.val)
        #         res = self.__compareSubtree(tree1.right,tree2)      
        # return res
        # 本方法是基于层次遍历,让私有属性Order先记录所有的节点指针
        # 然后从中找到所有和tree2首元素相等的节点存储到1个新容器,可以排除很多不必要的递归操作
        # 然后两个节点相等的情况下再去以这个根节点为基础,比较各自的下级左右2个节点是否对应相等
        # 也就是进入compareSubtree函数的递归过程,这个过程和递归解法或网址提供的都是一样的
        # 但是本函数能够减少递归方式占用的大量内存避免爆栈,同时还纠正了网址的错误
        nodes = []
        if not tree1:
            return []
        if len(self.Order) == 0 :
            return []
        for i in range (len(self.Order)):
            if self.Order[i].val == val:
                nodes.append(self.Order[i])
        return nodes

    def __levelOrderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            pass
        q = Queue()
        while root : # root最终会更新到队列为空为止
            self.Order.append(root) # 存储的不是数值而是节点
            if root.left : # 左节点不为空
                q.put_nowait(root.left) # 左节点入列
            if root.right :# 右节点不为空
                q.put_nowait(root.right) # 右节点入列
            if not q.empty() :
                root = q.get_nowait()  # 队首元素出列(首次是根)
            else : break
    def __compareSubtree(self,tree1:TreeNode,tree2:TreeNode)->bool:
        if not tree2:
            return True # tree2先结束,存在
        if not tree1:
            return False # tree1先结束,不存在
        if tree1.val != tree2.val :
            return False # 即使都没结束,但是节点不相等也不存在
        # 都没结束且相等的话,说明当前级或者错位级的所有节点都相等,需要进入2棵树的下一级继续比较
        return self.__compareSubtree(tree1.left,tree2.left) \
               and self.__compareSubtree(tree1.right,tree2.right)
if __name__ == '__main__':
    '''
         3      2     3(不爆栈) 
        / \      \   /      
       4   5     7   4       
     /  \       /     \                  
    1    2     10      3   
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

    tree2 = TreeNode(2) 
    tree2.right = TreeNode(7)
    tree2.right.left = TreeNode(10)

    tree3 = TreeNode(3) 
    tree3.left = TreeNode(4)
    tree3.left.right = TreeNode(3)

    solution = binaryTreeisSubStructureIteration()
    ret1 = solution.isSubStructure(tree1,tree2)
    print("---------------------------------------")
    ret2 = solution.isSubStructure(tree1,tree3)
    print("ret1 is ",ret1," ret2 is ",ret2)