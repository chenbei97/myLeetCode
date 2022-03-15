'''
Author: chenbei
Date: 2022-02-14 07:58:04
LastEditTime: 2022-03-15 11:18:54
Description: tree's postOrder by morris
FilePath: \myLeetCode\binaryTree\binaryTreePostOrder_Morris.py
A boy without dreams
'''
from typing import List
from typing import Optional
from TreeNode import TreeNode
'''
前序遍历:
1.最开始cur=root,如果cur无左孩子,将当前节点值保存,cur向右移动(cur=cur.right)
2.如果cur有左孩子,找到cur左子树上最右的节点,记为mostright
    2.1如果mostright的right指针指向空,将当前节点值保存,让其指向cur,cur向左移动(cur=cur.left)
    2.2如果mostright的right指针指向cur,让其指向空,cur向右移动(cur=cur.right)
3.cur为空时停止遍历

后序遍历:
1.最开始cur=root,如果cur无右孩子,cur向左移动(cur=cur.left)
2.如果cur有右孩子,找到cur右子树上最左的节点,记为mostleft
    2.1如果mostleft的left指针指向空,让其指向cur,cur向右移动(cur=cur.right)
    2.2如果mostleft的left指针指向cur,让其指向空,cur向左移动(cur=cur.left)
3.cur为空时停止遍历
cur移动之前先记录其val,前序无需反转,后序需要反转

中序遍历:
1.最开始cur=root,若cur无左孩子,将当前节点值保存,cur向右移动(cur=cur.right)
2.如果cur有左孩子,找到cur左子树上最右的节点,记为mostright
    2.1如果mostright的right指针指向空,让其指向cur,cur向左移动(cur=cur.left)
    2.2如果mostright的right指针指向cur,将当前节点值保存,让其指向空,cur向右移动(cur=cur.right)
3.cur为空时停止遍历
中序遍历和前序遍历的程序完全相同,区别是前序在2.1保存值,后序是2.2保存值
'''
class binaryTreePostOrderMorris:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        while root:
            if root.right is None:
                ans.append(root.val)
                root = root.left
            else:
                # 找到右子树最左边的节点
                next = root.right # 右子树的根节点开始向下寻找最左的子节点
                while next.left and next.left != root: # 这个节点的左节点指向了root就停止
                    next = next.left # 注意是先赋值后判断的,运行到10后再判断然后结束循环
                print(f"before => mostleft is {next.val},"\
                    f"left is {next.left.val if next.left is not None else None},"\
                        f"cur is {root.val},ans is {ans}")
                # 最左的节点的左节点可能为空也可能指向root
                if next.left != root: # 第1次到达时必然是指向空的
                    ans.append(root.val) # 第1次添加,root还是1没变
                    next.left = root # 最左节点的左节点为空时让它指向root
                    root = root.right # 根节点右移
                    print("root = root.right")
                else:
                    next.left = None # 最左节点的左节点指向root时则让它指向None
                    root = root.left # 根节点左移
                    print("root = root.left")
                print(f"after => mostleft is {next.val},"\
                    f"left is {next.left.val if next.left is not None else None},"\
                        f"cur is {root.val},ans is {ans}")
        return ans[::-1]
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
    solution = binaryTreePostOrderMorris()
    ret = solution.postorderTraversal(n1) # [8, 4, 9, 5, 2, 10, 6, 11, 7, 3, 1]
    print(ret)