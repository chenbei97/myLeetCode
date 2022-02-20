from TreeNode import TreeNode
from typing import List
class binaryTreeRightViewQueue:
    def rightView(self,root:TreeNode)->List:
        if not root : return []
        q = [root] # 因为queue的Queue获取首元素后就会自动删除,在这里不能用,用列表代替队列
        ans = []
        while len(q)!= 0: # 不要用while not q
            ans.append(q[0].val)
            print(ans[-1],end=" ")
            qSize = len(q)
            for _ in range(qSize):
                t = q[0]
                q.pop(0)
                if t.right : q.append(t.right) # 如果想得到左视图就先左后右
                if t.left : q.append(t.left)
        return ans
if __name__ == '__main__':
    root1 = TreeNode(1) # √
    root1.left = TreeNode(2)
    root1.right = TreeNode(3) # √
    root1.left.left = TreeNode(4)
    root1.left.right = TreeNode(5)
    root1.right.left = TreeNode(6) # √
    root1.left.left.right = TreeNode(10)
    root1.right.left.left = TreeNode(11) # √
    root1.right.left.left.right = TreeNode(12) # √
    solution =binaryTreeRightViewQueue()
    ans = solution.rightView(root1)