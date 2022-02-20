#ifndef binaryTreeMergeCommonTreeRecursion_
#define binaryTreeMergeCommonTreeRecursion_
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
class binaryTreeMergeCommonTreeRecursion{
    public:
        void mergeCommonTree(TreeNode*& root1,TreeNode*& root2){
            if (!root2) return ;
            if (!root1) {root1 = root2;return;} 
            root1->val+=root2->val;
            mergeCommonTree(root1->left,root2->left);
            mergeCommonTree(root1->right,root2->right);
        }
        void levelOrder(TreeNode* root){
            if (root == nullptr) return;
            queue<TreeNode*> q;
            TreeNode * t = root;
            while (t != nullptr)
            {
                cout<<t->val<<" "; // 层次遍历打印节点的元素值
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                if (! q.empty())
                    t = q.front();
                else break ;
                q.pop();
            }
            cout<<"\n";
        }
};
void _binaryTree_mergeCommonTree_recursion(){
    TreeNode * root1 = new TreeNode (7);
    root1->left = new TreeNode(6);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(3);
    root1->right->left = nullptr;
    root1->right->right = new TreeNode(1);
    TreeNode * root2 = new TreeNode (7);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(7);
    root2->left->right = new TreeNode(9);
    root2->right->left = new TreeNode (11);
    root2->right->right = nullptr;
    binaryTreeMergeCommonTreeRecursion solution;
    solution.mergeCommonTree(root1,root2);
    solution.levelOrder(root1);
}
#endif //!binaryTreeMergeCommonTreeRecursion_