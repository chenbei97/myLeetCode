from HbltNode import HbltNode
from queue import Queue
class binaryTreeMergeMaxHblt:
    def mergeHblt(self,root1:HbltNode,root2:HbltNode)->None or HbltNode:
        # 由于不同于C++的机制,交换递归中的root.right和root2并不能改变原来root1的right
        # 且每次返回的root1,root2是不一样的,是1个层的2个节点
        # 所以应当在第3个if判断中用root1.right,root2去接收返回值来更新实际的root1和root2
        # 而不是在第3个if结束后再进行递归,递归结束才会看看root1的左右子树是否为None的问题
        if not root2 :
            return root1,root2 # 第1个改动 要返回值
        if not root1:
            root1 = root2
            return root1,root2 # 第2个改动 要返回值
        if root1.val < root2.val:
            root1,root2 = root2,root1
            root1.right,root2 = self.mergeHblt(root1.right,root2) # 第3个改动,在内部更新递归且要更新全局的root1和root2
            
        if not root1.left : # 基准树的左节点为空,就把右节点交换过来
            root1.left = root1.right
            root1.right = None
            root1.number = 1 # 有1个子节点是None的父节点必然编号为1
        else :
            if root1.left.val < root1.right.val :# 必要的话交换基准树的左右节点
                root1.left,root1.right = root1.right,root1.left
                root1.number = root1.right.number + 1 # 两个非空节点的父节点编号是右节点编号+1
        return root1,root2 # 第4个改动 要返回值,也可只返回root1

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
    root1,root2 = solution.mergeHblt(n9,n15)
    print("after merge,root1's rank and data is")
    solution.levelOrder(root1)
    print("after merge,root2's rank and data is")
    solution.levelOrder(root2) # root2本身没有被改变过
