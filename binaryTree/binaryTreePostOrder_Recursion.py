from typing import List
from typing import Optional
from pip import main
from TreeNode import TreeNode
class binaryTreePostOrderRecursion:
    '''
    函数参数中的冒号是参数的类型建议符,告诉程序员希望传入的实参的类型
    函数后面跟着的箭头是函数返回值的类型建议符,用来说明该函数返回的值是什么类型
    '''
    def postorderTraversal(self, root: Optional[TreeNode] = None) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            dfs(root.right)
            nonlocal ans # 非局部变量
            ans.append(root.val)
            print(ans)

        ans = []
        dfs(root)
        return ans
if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreePostOrderRecursion()#  [4,5,2,6,7,3,1]
    ret = solution.postorderTraversal(n1)
    print(ret)