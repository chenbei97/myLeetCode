from TreeNode import TreeNode
from queue import Queue
class binaryTreeMergeCommonTreeRecursion:
    def mergeCommonTree(self,root1:TreeNode,root2:TreeNode):
        if not root2 : return root1
        if not root1 : 
            root1 = root2 
            return root1
        root1.val += root2.val
        root1.right = self.mergeCommonTree(root1.right,root2.right) # 记得返回值分别更新的roo1的right和left
        root1.left = self.mergeCommonTree(root1.left,root2.left) # 左右先后顺序是无所谓的
        return root1
    def levelOrder(self,root:TreeNode)->None:
        q = Queue()
        t = root
        if not t:
            print("None")
            return
        while t:
            print(f"({t.val}) ",end="")
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
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.right = TreeNode(3)
    root1.left.left = TreeNode(4)
    root1.left.right = TreeNode(5)
    root1.right.left = TreeNode(6)
    root1.left.left.right = TreeNode(10)
    root1.right.left.left = TreeNode(11)
    root1.right.left.left.right = TreeNode(12)

    root2 = TreeNode(-5)
    root2.left = TreeNode(-9)
    root2.right = TreeNode(-3)
    root2.left.left = TreeNode(-1)
    root2.left.right = TreeNode(0)
    root2.right.left = TreeNode(-14)
    root2.right.right = TreeNode(-15)

    solution = binaryTreeMergeCommonTreeRecursion()
    root = solution.mergeCommonTree(root1,root2)
    solution.levelOrder(root)
    
