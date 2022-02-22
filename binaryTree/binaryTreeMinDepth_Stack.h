#ifndef binaryTreeMinDepthStack_
#define binaryTreeMinDepthStack_
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include "TreeNode.h"
using namespace std;
class binaryTreeMinDepthStack{
    public:
       int getMinDepth(TreeNode * root){
            if (!root) return 0 ;
            // 本方法的思路来源于计算二叉树最大深度
            depths.clear();
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
                    depths.push_back(d); // 去掉判断条件,只要1条路径结束就记录其深度
                }
                p = p ->right;
            }
            return *min_element(depths.begin(),depths.end());
        }
    private :
        vector<int> depths;
};
void _binaryTree_minDeth_stack(){
    binaryTreeMinDepthStack solution;
    TreeNode * root = new TreeNode(1);
    TreeNode * t = root;
    for(int i = 1;i<=10;i++){
        t->left = new TreeNode (i);
        t = t->left;
    } // 11
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->left->right = new TreeNode(1);
    root->right->left->right->left->right->left = new TreeNode(1); // 7
    int depth = solution.getMinDepth(root);
    cout<<"method3: tree min depth is "<<depth<<endl; // 7
}
#endif // !binaryTreeMinDepthStack_