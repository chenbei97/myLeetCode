/*** 
 * @Author: chenbei
 * @Date: 2022-02-22 09:33:42
 * @LastEditTime: 2022-03-15 11:17:13
 * @Description: calculate tree's maxdepth by stack
 * @FilePath: \myLeetCode\binaryTree\binaryTreeMaxDepth_Stack.h
 * @A boy without dreams
 */
#ifndef binaryTreeMaxDepthStack_
#define binaryTreeMaxDepthStack_
#include "TreeNode.h"
#include <utility>
#include <iostream>
#include <stack>
using namespace std;
class binaryTreeMaxDepthStack{
    public:
        int getMaxDepth(TreeNode* root){
            int depth = 0;
            if (!root) return depth;
            // 本方法的思路来源于打印二叉树的所有路径
            stack<pair<TreeNode*,int>> stk;
            TreeNode * p = root;
            int d = 0 ;
            while (p || !stk.empty()){
                while (p){
                    if (p == root) d=1;
                    else d++;
                    stk.push(pair<TreeNode*,int>(p,d));
                    p = p->left;
                }
                p = stk.top().first;
                d = stk.top().second;
                stk.pop();
                if (!p->left && !p->right) {
                    if (d > depth) depth =d;
                }
                p = p ->right;
            }
            return depth;
        }
};
void _binaryTree_maxDepth_stack(){
    binaryTreeMaxDepthStack solution;
    TreeNode * root = new TreeNode (1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(6);
    root->right->right->right->left = new TreeNode(5);
    root->right->right->right->left->right = new TreeNode(7);
    int depth = solution.getMaxDepth(root);
    cout<<"method3: tree max depth is "<<depth<<endl;

    TreeNode * root1 = new TreeNode(1);
    TreeNode * t = root1;
    for (int i = 1; i<=5;i++){
        t->left = new TreeNode(i);
        t = t->left;
    }
    depth = solution.getMaxDepth(root1);
    cout<<"method3: tree max depth is "<<depth<<endl;

    root1->right = new TreeNode(1);
    root1->right->left = new TreeNode(1);
    root1->right->left->right = new TreeNode(1);
    root1->right->left->right->left = new TreeNode(1);
    root1->right->left->right->left->right = new TreeNode(1);
    root1->right->left->right->left->right->left = new TreeNode(1);
    depth = solution.getMaxDepth(root1);
    cout<<"method3: tree max depth is "<<depth<<endl;
}
#endif // !binaryTreeDepthStack_