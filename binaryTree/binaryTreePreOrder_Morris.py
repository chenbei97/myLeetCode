'''
morrisq前序遍历的实现原则:
1.最开始cur=root,如果cur无左孩子,cur向右移动(cur=cur.right)
2.如果cur有左孩子,找到cur左子树上最右的节点,记为mostright
    2.1如果mostright的right指针指向空,让其指向cur,cur向左移动(cur=cur.left)
    2.2如果mostright的right指针指向cur,让其指向空,cur向右移动(cur=cur.right)
3.cur为空时停止遍历
对于后序,正好左右相反
1.最开始cur=root,如果cur无右孩子,cur向左移动(cur=cur.left)
2.如果cur有右孩子,找到cur右子树上最左的节点,记为mostleft
    2.1如果mostleft的left指针指向空,让其指向cur,cur向右移动(cur=cur.right)
    2.2如果mostleft的left指针指向cur,让其指向空,cur向左移动(cur=cur.left)
3.cur为空时停止遍历
cur移动之前先记录其val,前序无需反转,后序需要反转
'''
from typing import List
from typing import Optional
from TreeNode import TreeNode
class binaryTreePreOrderMorris:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        while root:
            if root.left is None:
                ans.append(root.val)
                root = root.right
            else:
                # 找到左子树最右边的节点
                next = root.left # 左子树的根节点开始向下寻找最右的子节点
                while next.right and next.right != root: # 这个节点的右节点指向了root就停止
                    next = next.right # 注意是先赋值后判断的,运行到9后再判断然后结束循环
                print(f"before => mostright is {next.val},"\
                    f"right is {next.right.val if next.right is not None else None},"\
                        f"cur is {root.val},ans is {ans}")
                # 最右的节点的右节点可能为空也可能指向root
                if next.right != root: # 第1次到达时必然是指向空的
                    ans.append(root.val) # 第1次添加,root还是1没变
                    next.right = root # 最右节点的右节点为空时让它指向root
                    root = root.left # 根节点左移
                    print("root = root.left")
                else:
                    next.right = None # 最右节点的右节点指向root时则让它指向None
                    root = root.right # 根节点右移
                    print("root = root.right")
                print(f"after => mostright is {next.val},"\
                    f"right is {next.right.val if next.right is not None else None},"\
                        f"cur is {root.val},ans is {ans}")
        return ans # 无需反转
if __name__ == '__main__':
    n11 = TreeNode(11)
    n10 = TreeNode(10)
    n9 = TreeNode(9)
    n8 = TreeNode(8)
    n7 = TreeNode(7,None,n11)
    n6 = TreeNode(6,n10,None)
    n5 = TreeNode(5,None,n9)
    n4 = TreeNode(4,n8,None)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreePreOrderMorris()
    ret = solution.preorderTraversal(n1) # [1, 2, 4, 5, 3, 6, 7]
    print(ret)