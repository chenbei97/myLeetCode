#ifndef binaryTreeInvert_Recursion_
#define binaryTreeInvert_Recursion_
#include "TreeNode.h"
#include <queue>
#include <iostream>
class binaryTreeInvertRecursion{
    public:
        void invert(TreeNode*& root){
            if (!root) return;
            swap(root->left,root->right);
            invert(root->right); // 先左后右和先右后左都可以,这也是为何能使用栈/队列的原因
            invert(root->left); 
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
void _binaryTree_invert_recursion(){
    binaryTreeInvertRecursion solution;
    /*
          1               1
         / \             / \
        2   3           3   2
       / \ / \         / \ / \
      4  5 6  7       7  6 5  4
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<"use recursion invert tree\n";
    cout<<"before invert the tree is \n";
    solution.levelOrder(root);
    solution.invert(root);
    cout<<"after invert the tree is \n"; 
    solution.levelOrder(root);

    root->left->right = nullptr;
    cout<<"after change,before invert the tree is \n";
    solution.levelOrder(root);
    solution.invert(root);
    cout<<"after change,after invert the tree is \n";
    solution.levelOrder(root);

}
#endif // !binaryTreeInvert_Recursion_