from psutil import swap_memory
from HbltNode import HbltNode
from queue import Queue
class binaryTreeMergeMaxHblt:
    def __init__(self) -> None:
        self.count = 0
    # def merge(self,root1:HbltNode,root2:HbltNode)->None or HbltNode
        # def loop(r1,r2):
        #     print("111111111")
        #     if not r2: 
        #         print("222222222")
        #         return 
        #     if not r1:  
        #         r1 = r2 # root1是基准
        #         print("33333333333")
        #         print("r1:")
        #         self.levelOrder(r1)
        #         print("r2:")
        #         self.levelOrder(r2)
        #         return r1,r2
        #     if r1.val < r2.val:
        #         print("4444444444444444")
        #         print("r1:")
        #         self.levelOrder(r1)
        #         print("r2:")
        #         self.levelOrder(r2)
        #         r1,r2 = r2,r1 # 必要的话交换基准树的右子树和非基准树
        #         print("swap success")
        #         print("r1:")
        #         self.levelOrder(r1)
        #         print("r2:")
        #         self.levelOrder(r2)
        #         return r1,r2
        # r1,r2 = loop(r1,r2)
        # root1,root2=r1,r2
        
        # print("555555555")
        # # root1.right = 
        # print("root1:")
        # self.levelOrder(root1)
        # print("root2:")
        # self.levelOrder(root2)
        # print("-------------------------------")
        # r1,r2 = loop(root1.right,root2)
        # print("666666666666")
        # print("r1:")
        # self.levelOrder(r1)
        # print("r2:")
        # self.levelOrder(r2)
        # print("-------------------------------")
        # root1.right=r1
        # print("root1:")
        # self.levelOrder(root1)
        # print("-------------------------------")
        # r1,r2 = loop(root1.right,root2)
        # print("root1:",self.levelOrder(root1))
        # print("root2:",self.levelOrder(root2))
        # self.levelOrder(root1.right)
        # self.levelOrder(root2)
        # if not root1.left : # 基准树的左节点为空,就把右节点交换过来
        #     print("777777777777777")
        #     root1.left = root1.right
        #     root1.right = None
        #     root1.number = 1 # 有1个子节点是None的父节点必然编号为1
        # if not root1.right:
        #     print("888888888888")
        #     root1.right = None
        #     root1.number = 1
        # elif (root1.left.val < root1.right.val) :# 必要的话交换基准树的左右节点
        #     print("9999999999")
        #     root1.left,root1.right = root1.right,root1.left
        #     root1.number = root1.right.number + 1 # 两个非空节点的父节点编号是右节点编号+1
    def merge(self,root1:HbltNode,root2:HbltNode)->None or HbltNode:
        if not root2 :
            return 
        if not root1:
            root1 = root2
            return 
        if root1.val < root2.val:
            root1,root2 = root2,root1
        self.merge(root1.right,root2)
        if not root1.left : # 基准树的左节点为空,就把右节点交换过来
            root1.left = root1.right
            root1.right = None
            root1.number = 1 # 有1个子节点是None的父节点必然编号为1
        else :
            if not root1.right:
                root1.number = 1
            elif root1.left.val < root1.right.val :# 必要的话交换基准树的左右节点
                root1.left,root1.right = root1.right,root1.left
                root1.number = root1.right.number + 1 # 两个非空节点的父节点编号是右节点编号+1
        return root1


    def levelOrder(self,root:HbltNode)->None:
        q = Queue()
        t = root
        if not t:
            print("None")
            return
        while t:
            print(f"({t.number},{t.val}) ",end="")
            if t.left:
                q.put_nowait(t.left)
            if t.right:
                q.put_nowait(t.right)
            if not q.empty():
                t = q.get_nowait()
            else :
                print()
                return
        
        
if __name__ == '__main__':
    '''
    数据值:
    tree1:         tree2:             merge:
           9                 15               15
          / \               /              /      \
         8   7             7              9        7
        / \ / \           /  \           / \      / \
       6    5  4         3    1         8  7     3   1
           / \              /          /  / \       / 
          3   2            0          6  5   4     0
         /                              / \
        1                              3   2        
                                      /
                                     1
    编号值:  
    tree1:         tree2:             merge:
           2                 1                3
          / \               /               /   \
         1   2             2               2     2
        / \ / \           /  \            / \   / \
       1    2  1         1    1          1   2 1   1
           / \               /          /   / \   / 
          1   1             1          1   2   1 1   
         /                                / \   
        1                                1   1    
                                        /
                                       1
    '''
    n1 = HbltNode(1,1)
    n2 = HbltNode(1,2)
    n3 = HbltNode(1,3,n1,None)
    n4 = HbltNode(1,4)
    n5 = HbltNode(2,5,n3,n2)
    n6 = HbltNode(1,6)
    n7 = HbltNode(2,7,n5,n4)
    n8 = HbltNode(1,8,n6,None)
    n9 = HbltNode(2,9,n8,n7)

    n11 = HbltNode(1,0)
    n12 = HbltNode(1,1,n11,None)
    n13 = HbltNode(1,3)
    n14 = HbltNode(2,7,n13,n12)
    n15 = HbltNode(1,15,n14,None)


    solution = binaryTreeMergeMaxHblt()
    print("root1's rank and data is")
    solution.levelOrder(n9)
    print("root2's rank and data is")
    solution.levelOrder(n15)
    # print("after swap,root2's rank and data is")
    # n15.left.left,n15.left.right = n15.left.right,n15.left.left
    # solution.levelOrder(n15)
    root1 = solution.merge(n9,n15)
    print("after merge,root1's rank and data is")
    solution.levelOrder(root1)
