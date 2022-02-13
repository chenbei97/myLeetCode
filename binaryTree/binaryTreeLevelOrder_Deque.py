from collections import deque
from typing import List
from typing import Optional
from TreeNode import TreeNode
class binaryTreeLevelOrderDeque:
    # 和使用queue实现的区别在于Deque是双端队列,唯一的区别是使用popleft函数来得到队首元素
    # 其它思路上没有区别，且一步到位，这里直接给出嵌套型的带返回None的写法，
    # 其他三种，嵌套不带None,带None不嵌套,不带None也不嵌套参考使用Queue的写法
    # 同时还提供了翻转列表的方法,这些就自底向上打印二叉树的层元素
    def levelOrderTraversalNestWithNone(self,height, root: Optional[TreeNode],rever:bool) -> List[List[int]]:
        if root is None:
            return [None]
        ans = []
        q = deque([root]) # deque在collection中,是个类可以进行构造
        while q : # deque没有empty函数,用q本身代替就可
            qSize = len(q) # deque没有size()函数,所以用len
            t = []
            for _ in range(qSize):
                root = q.popleft() # 相当于单端列表的front函数,双端列表pop删除的是队尾,popleft才是队首,队首先入先出
                t.append(root.val if root else None)
                q.append(root.left if root else None)
                q.append(root.right if root else None)
            ans.append(t)    
            if len(self.flattenList(ans)) == pow(2,height)-1: # 注意是展平后的所有元素
                break  
        if rever:
            return ans[::-1] 
        return ans

    @staticmethod
    def flattenList(theList : List[List[int]]) -> List[int]:
        return sum(theList,[])
if __name__ == '__main__':
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n2 = TreeNode(2,None,n5)
    n3 = TreeNode(3,n6,None)
    n1 = TreeNode(1,n2,n3)
    s = binaryTreeLevelOrderDeque()
    ret = s.levelOrderTraversalNestWithNone(3,n1,True)
    print(ret) # 返回嵌套的带None的列表