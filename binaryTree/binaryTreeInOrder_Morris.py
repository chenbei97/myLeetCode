from typing import List
from typing import Optional
from TreeNode import TreeNode
'''
前序遍历：
1.最开始cur=root,如果cur无左孩子,将当前节点值保存,cur向右移动(cur=cur.right)
2.如果cur有左孩子,找到cur左子树上最右的节点,记为mostright
    2.1如果mostright的right指针指向空,将当前节点值保存,让其指向cur,cur向左移动(cur=cur.left)
    2.2如果mostright的right指针指向cur,让其指向空,cur向右移动(cur=cur.right)
3.cur为空时停止遍历

后序遍历：
1.最开始cur=root,如果cur无右孩子,cur向左移动(cur=cur.left)
2.如果cur有右孩子,找到cur右子树上最左的节点,记为mostleft
    2.1如果mostleft的left指针指向空,让其指向cur,cur向右移动(cur=cur.right)
    2.2如果mostleft的left指针指向cur,让其指向空,cur向左移动(cur=cur.left)
3.cur为空时停止遍历
cur移动之前先记录其val,前序无需反转,后序需要反转

中序遍历：
1.最开始cur=root,若cur无左孩子,将当前节点值保存,cur向右移动(cur=cur.right)
2.如果cur有左孩子,找到cur左子树上最右的节点,记为mostright
    2.1如果mostright的right指针指向空,让其指向cur,cur向左移动(cur=cur.left)
    2.2如果mostright的right指针指向cur,将当前节点值保存,让其指向空,cur向右移动(cur=cur.right)
3.cur为空时停止遍历
中序遍历和前序遍历的程序完全相同，区别是前序在2.1保存值,后序是2.2保存值
'''
class binaryTreeInOrderMorris:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        return ans

if __name__ == '__main__':
    n7 = TreeNode(7)
    n6 = TreeNode(6)
    n5 = TreeNode(5)
    n4 = TreeNode(4)
    n2 = TreeNode(2,n4,n5)
    n3 = TreeNode(3,n6,n7)
    n1 = TreeNode(1,n2,n3)
    solution = binaryTreeInOrderMorris()
    ret = solution.inorderTraversal(n1) # [4, 2, 5, 1, 6, 3, 7]
    print(ret)