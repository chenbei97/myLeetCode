#ifndef binaryTreeInOrderMorris_
#define binaryTreeInOrderMorris_
#include <vector>
#include <algorithm>
#include "TreeNode.h"
#include <iostream>
/*
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
*/
class binaryTreeInOrderMorris {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
         while (root)
        {
            if (!root->left) 
            {
                ans.push_back(root->val);
                root = root->right; 
            }
            else 
            {
                TreeNode* next = root->left; 
                while (next->right && next->right != root)
                {
                    next = next->right; 
                }
                if (!next->right) 
                {
                    // ans.push_back(root->val); 和前序唯一的区别不在这里追加
                    next->right = root; 
                    root = root->left; 
                }
                else 
                {
                    ans.push_back(root->val); // 在这里追加
                    next->right = nullptr;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};
void _binaryTree_inOrder_morris()
{
    binaryTreeInOrderMorris solution;
    TreeNode node7(7);
    TreeNode node6(6);
    TreeNode node5(5);
    TreeNode node4(4);
    TreeNode node3(3,&node6,&node7);
    TreeNode node2(2,&node4,&node5);
    TreeNode node1(1,&node2,&node3);
    TreeNode * root = &node1;
    vector<int> ret = solution.inorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  "; // 1  2  4  5  3  6  7
    }
    cout<<"\n";
}
#endif // !binaryTreeInOrderMorris_