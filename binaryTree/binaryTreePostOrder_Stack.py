from typing import List
from typing import Optional
from TreeNode import TreeNode
'''
1.定义一个栈 stk,先将根节点压入栈
2.若栈不为空,每次从栈中弹出一个节点(根节点开始)
3.保存该节点的值
4.先把节点左孩子压入栈,接着把节点右孩子压入栈(如果有孩子节点)
5.重复 2-4 所以右孩子先出栈、左孩子后出栈
6.返回结果为根、右、左,反转即得到左、右、根为后序遍历
'''
class binaryTreePostOrderStack:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = [] # ans为队列机制,先进先出
        if root is None:
            return ans
        stk = [root] # 初始栈存储根节点 stk为栈机制后入先出
        while stk: # stk不为None
            print("before pop -> ",[x.val for x in stk])
            node = stk.pop()  # 出栈先右后左
            print("after pop -> ",[x.val for x in stk]) # 跟踪stk删除后的情况
            ans.append(node.val) # 最终为[1,3,7,6,2,5,4]
            if node.left: 
                stk.append(node.left) #入栈先左后右 
            if node.right:
                stk.append(node.right)
        return ans[::-1] # reverse [4,5,2,6,7,3,1]
        '''
            先序遍历是根左右,借助栈改变遍历孩子的顺序为根右左
            然后反转就能得到左右根,也即是后序遍历
            root = 1
            stk=[1],node=1,stk=[],ans=[1]
            stk=[2,3],node=3,stk=[2],ans=[1,3]
            stk=[2,6,7],node=7,stk=[2,6],ans=[1,3,7]
            stk=[2,6],node=6,stk=[2],ans=[1,3,7,6]
            stk=[2],node=2,stk=[],ans=[1,3,7,6,2]
            stk=[4,5],node=5,stk=[4],ans=[1,3,7,6,2,5]
            stk=[4],node=4,stk=[],ans=[1,3,7,6,2,5,4]
            pop的元素依次是1,3,7,6,2,5,4,也就是ans
            入栈:根先入,然后根出,追加到队列
                总是秉承左节点先入右节点后入的原则
            出栈:每次入栈完成检查栈是否为空,右节点先出追加到队列,然后检查右节点是否还有左右节点
                如果有,按照入栈规则添加,然后右节点先出,然后左节点再出     
        '''
if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreePostOrderStack()
    ret = solution.postorderTraversal(n1) #  [4,5,2,6,7,3,1]
    print(ret)