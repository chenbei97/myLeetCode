'''
Author: chenbei
Date: 2022-02-14 07:58:04
LastEditTime: 2022-03-15 11:13:33
Description: binaryTree levelOrder by queue
FilePath: \myLeetCode\binaryTree\binaryTreeLevelOrder_Queue.py
A boy without dreams
'''
from queue import Queue # 单端FIFO队列,deque是双端队列,priority_queue是优先级队列,都继承于queue
from typing import List
from typing import Optional
from queue import Empty
from TreeNode import TreeNode
class binaryTreeLevelOrderQueue:
    def levelOrderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        ans = []
        q = Queue()
        while root : # root最终会更新到队列为空为止
            ans.append(root.val)
            if root.left : # 左节点不为空
                q.put_nowait(root.left) # 左节点入列
            if root.right :# 右节点不为空
                q.put_nowait(root.right) # 右节点入列
            try :
                root = q.get_nowait()  # 队首元素出列(首次是根)
            except Empty:
                # print("queue is empty")
                break
        return ans
    
    # 此函数的区别是如果有的二叉树元素是None,后面不是None,也会把None打出来
    # 前提是需要知道树的高度,否则会无穷尽的打印None,因为他不知道什么结束循环
    # 所以规定只打印pow(2,height)-1这么多元素,超出的其实都是None但不会打印
    def levelOrderTraversalWithNone(self,height,root: Optional[TreeNode] ) -> List[int]:
        if root is None :
            return [None]
        ans = []
        q = Queue()
        q.put_nowait(root) # 为了能够进入while循环
        # 1.仿照C++的写法
        # while not q.empty():
        #     root = q.get_nowait() # 相当于pop和front函数的合并版
        #     if not root:
        #         q.put_nowait(None)
        #         q.put_nowait(None)
        #         ans.append(None) # 和C++的区别,None是可以添加的,C++只能指定1个数
        #     else:
        #         q.put_nowait(root.left)
        #         q.put_nowait(root.right)
        #         ans.append(root.val)
        #     if len(ans) == pow(2,height) - 1:
        #         break
        # 2.这样的写法也可以
        while not q.empty() : # root最终会更新到队列为空为止
            # 因为None也可添加,所以无需担心队列为空的问题,不需异常处理
            root = q.get_nowait()  # 队首元素出列(首次是根)
            ans.append(root.val if root else None) # 其实是把if_else的ans.append合并
            # 其实是把4条put_nowait语句合并了
            q.put_nowait(root.left if root else None) # 左节点入列
            q.put_nowait(root.right if root else None) # 右节点入列
            if len(ans) == pow(2,height)-1:
                break
        return ans
    
    def levelOrderTraversalNest(self, root: Optional[TreeNode]) -> List[List[int]]:
        # 即每个层也是1个列表,即使该层只有1个元素,需要的话可以借助flattenList函数展平嵌套列表
        if root is None:
            return [[]]
        ans = []
        # t = [] 不要写在while外部 
        q = Queue()
        q.put_nowait(root) # 进入while循环的条件
        while not q.empty():
            t = []  # 临时存储每层元素的小列表
            qSize = q.qsize() # 得到q目前有多少元素,每次q更新都是更新一层的
            for _ in range(qSize): # 所以可以遍历这个层
                node = q.get_nowait() # 从层的左端开始,因为从全局根节点开始q更新时总是左端先入的队列
                t.append(node.val)
                if node.left:
                    q.put_nowait(node.left) # 先左节点
                if node.right: 
                    q.put_nowait(node.right) # 后右节点
            # print("t is ", t)
            # t已经积累了这层全部元素
            ans.append(t) # 把更新的这层元素添加进ans
            # print("ans is ", ans)
            # t.clear() t清空也会导致ans没有
            # print("ans is ", ans)
        # 事项：之前把t=[]写在while外部,然后在ans.append(t)后使用t.clear(),这样是不行的
        # 因为t.clear()会导致ans也没有了,可以理解为共用1个变量,所以应当是在while内部t=[],这样每次创建新的内存
        return ans
    
    def levelOrderTraversalNestWithNone(self, height,root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return [[None]]
        ans = []
        q = Queue()
        q.put_nowait(root) 
        while not q.empty():
            t = []
            qSize = q.qsize() 
            for _ in range(qSize): 
                node = q.get_nowait() # 从层的左端开始,因为从全局根节点开始q更新时总是左端先入的队列
                t.append(node.val if node else None) # 第1个区别,为空则添加None,这是因为后边为None也入队列了
                q.put_nowait(node.left if node else None) # 第2个区别,只要node不为空,左右节点是否为空都无所谓
                q.put_nowait(node.right if node else None) # 如果node为空,那么追加2个None
            ans.append(t)
            # q永远不会为空,所以需要height限制
            if len(self.flattenList(ans)) == pow(2,height)-1: # 注意是展平后的所有元素
                break   
        return ans

    @staticmethod
    def flattenList(theList : List[List[int]]) -> List[int]:
        return sum(theList,[])
        
if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    s = binaryTreeLevelOrderQueue()
    ret1 = s.levelOrderTraversal(n1)# 返回展平型列表
    print(ret1)
    ret1 = s.levelOrderTraversalNest(n1) # 返回嵌套型列表
    print(ret1)
    print(s.flattenList(ret1)) # 调用展平列表函数
    # print(sum(ret1,[]))

    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n2 = TreeNode(2,None,n5)
    n3 = TreeNode(3,n6,None)
    n1 = TreeNode(1,n2,n3)
    print(s.levelOrderTraversal(n1)) 
    ret2 = s.levelOrderTraversalWithNone(3,n1) # 返回展平型列表且带None的列表
    print(ret2)
    ret2 = s.levelOrderTraversalNestWithNone(3,n1) # 返回带None的嵌套型列表
    print(ret2)