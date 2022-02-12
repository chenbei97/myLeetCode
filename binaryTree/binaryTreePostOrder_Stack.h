#ifndef binaryTreePostOrder_Stack_
#define binaryTreePostOrder_Stack_
#include <vector>
#include <stack>
#include <algorithm>
#include "TreeNode.h"
#include <iostream>
/*
1.定义一个栈 stk,先将根节点压入栈
2.若栈不为空,每次从栈中弹出一个节点(根节点开始)
3.保存该节点的值
4.先把节点左孩子压入栈,接着把节点右孩子压入栈(如果有孩子节点)
5.重复 2-4 所以右孩子先出栈、左孩子后出栈
6.返回结果为根、右、左，反转即得到左、右、根为后序遍历
*/
class binaryTreePostOrderStack{
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> stk;
            stk.push(root);
            while (!stk.empty())
            {
                TreeNode* node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                if (node->left!= nullptr)
                    stk.push(node->left);
                if (node->right!= nullptr)
                    stk.push(node->right);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};
void _binaryTree_postOrder_stack()
{
    /* 
        输入要求[1,null,2,3]
            1
           / \
          2   3
         /\   /\
        4  5 6  7
        输出为[4,5,2,6,7,3,1]
    */
    binaryTreePostOrderStack solution;

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
        cout <<*it<<"  ";
    }
    cout<<"\n"; // [4,5,2,6,7,3,1]
}
#endif // !binaryTreePostOrder_Stack_