/*** 
 * @Author: chenbei
 * @Date: 2022-02-14 07:58:04
 * @LastEditTime: 2022-03-15 11:19:39
 * @Description: tree's preOrder by morris
 * @FilePath: \myLeetCode\binaryTree\binaryTreePreOrder_Morris.h
 * @A boy without dreams
 */
#ifndef binaryTreePreOrderMorris_
#define binaryTreePreOrderMorris_
#include <vector>
#include <algorithm>
#include "TreeNode.h"
#include <iostream>
/*
morris遍历是二叉树遍历算法的超强进阶算法
跟递归、非递归（栈实现）的空间复杂度，
morris遍历可以将非递归遍历中的空间复杂度降为O(1)
从而实现时间复杂度为O(N)
morris遍历利用的是树的叶节点左右孩子为空（树的大量空闲指针）
帮助孩子能够重新回到父的这个原本需要借用栈来实现的过程
实现空间开销的极限缩减
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
class binaryTreePreOrderMorris {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root)
        {
            if (!root->left) // 如果没有左孩子
            {
                ans.push_back(root->val);
                root = root->right; // 根节点右移
            }
            else // 有左孩子
            {
                TreeNode* next = root->left; // 找到左孩子最右的子节点
                while (next->right && next->right != root)
                {
                    next = next->right; // 先赋值后判断
                }
                if (!next->right) // 第1次到达必定右孩子为空,条件成立
                {
                    ans.push_back(root->val);
                    next->right = root; // 右孩子为nullptr,让右孩子指回root
                    root = root->left; // 根节点左移
                }
                else // 第2次到达,右孩子指向root
                {
                    next->right = nullptr;// 右孩子为root,让右孩子指回nullptr
                    root = root->right;// 根节点右移
                }
            }
        }
        return ans;
    }
};
void _binaryTree_preOrder_morris()
{
    binaryTreePreOrderMorris solution;
    TreeNode node7(7);
    TreeNode node6(6);
    TreeNode node5(5);
    TreeNode node4(4);
    TreeNode node3(3,&node6,&node7);
    TreeNode node2(2,&node4,&node5);
    TreeNode node1(1,&node2,&node3);
    TreeNode * root = &node1;
    vector<int> ret = solution.preorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  "; // 1  2  4  5  3  6  7
    }
    cout<<"\n";
}
#endif // !binaryTreePreOrderMorris_