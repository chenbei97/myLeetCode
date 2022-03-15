/*** 
 * @Author: chenbei
 * @Date: 2022-02-14 07:58:04
 * @LastEditTime: 2022-03-15 11:20:17
 * @Description: tree's preOrder by stack
 * @FilePath: \myLeetCode\binaryTree\binaryTreePreOrder_Stack.h
 * @A boy without dreams
 */
#ifndef binaryTreePreOrderStack_
#define binaryTreePreOrderStack_
#include <vector>
#include <stack>
#include <algorithm>
#include "TreeNode.h"
#include <iostream>
/*
1.定义一个栈 stk,先将根节点压入栈
2.若栈不为空,每次从栈中弹出一个节点(根节点开始)
3.保存该节点的值
4.先把节点右孩子压入栈,接着把节点左孩子压入栈(如果有孩子节点)
5.重复 2-4 所以左孩子先出栈、右孩子后出栈
6.返回结果为根、左、右
*/
class binaryTreePreOrderStack{
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> stk;
            stk.push(root);
            while (!stk.empty())
            {
                TreeNode* node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                if (node->right!= nullptr) // 唯一的区别右孩子先压栈
                    stk.push(node->right);
                if (node->left!= nullptr)
                    stk.push(node->left);

            }
            return ans; // 无需反转
        }
};
void _binaryTree_preOrder_stack()
{
    binaryTreePreOrderStack solution;

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
#endif // !binaryTreePreOrderStack_