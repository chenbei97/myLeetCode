#ifndef binaryTreePostOrderMorris_
#define binaryTreePostOrderMorris_
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
*/
class binaryTreePostOrderMorris {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root)
        {
            if (!root->right) // 如果没有右孩子
            {
                ans.push_back(root->val);
                root = root->left; // 根节点左移
            }
            else // 有右孩子
            {
                TreeNode* next = root->right; // 找到右孩子最左的子节点
                while (next->left && next->left != root)
                {
                    next = next->left; // 先赋值后判断
                }
                if (!next->left) // 第1次到达必定左孩子为空,条件成立
                {
                    ans.push_back(root->val);
                    next->left = root; // 左孩子为nullptr,让左孩子指回root
                    root = root->right; // 根节点右移
                }
                else // 第2次到达,左孩子指向root
                {
                    next->left = nullptr;// 左孩子为root,让左孩子指回nullptr
                    root = root->left;// 根节点左移
                }
            }
        }
        reverse(ans.begin(), ans.end()); // 需要反转
        return ans;
    }
};
void _binaryTree_postOrder_morris()
{
    binaryTreePostOrderMorris solution;
    TreeNode node7(7);
    TreeNode node6(6);
    TreeNode node5(5);
    TreeNode node4(4);
    TreeNode node3(3,&node6,&node7);
    TreeNode node2(2,&node4,&node5);
    TreeNode node1(1,&node2,&node3);
    TreeNode * root = &node1;
    vector<int> ret = solution.postorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  "; // 4  5  2  6  7  3  1
    }
    cout<<"\n";
}
#endif // !binaryTreePostOrderMorris_