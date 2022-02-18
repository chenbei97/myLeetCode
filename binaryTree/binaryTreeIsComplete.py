from TreeNode import TreeNode
from queue import Queue
class binaryTreeIsComplete:
    def isComplete(self,root:TreeNode)->bool:
        if not root : return False
        q = Queue()
        q.put_nowait(root)
        while not q.empty():
            t = q.get_nowait()
            if t.left and t.right :
                q.put_nowait(t.left)
                q.put_nowait(t.right)
            if (t.left == None) and t.right :
                return False
            if (t.left != None and t.right ==None) \
                or (t.left == None and t.right == None):
                if (t.left != None and t.right ==None):
                    q.put_nowait(t.left)
                t = q.get_nowait() # 删除叶节点,无论子节点什么情况都肯定会删除
                while not q.empty():
                    t = q.get_nowait()
                    if (t.left == None and t.right == None):
                        pass
                    else:
                        return False
                return True
        return True
if __name__ == '__main__':
    # 测试完全二叉树
    root = TreeNode(7)
    root.left = TreeNode(6)
    root.right = TreeNode(5)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(2)
    root.right.right = TreeNode(1)
    solution = binaryTreeIsComplete ()
    res = solution.isComplete(root)
    print(f"the tree is complete ? {res}")
    root.left.left = None
    res = solution.isComplete(root)
    print(f"the tree is complete ? {res}")