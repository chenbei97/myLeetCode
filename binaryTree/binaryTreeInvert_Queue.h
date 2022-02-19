#ifndef binaryTreeInvert_Queue_
#define binaryTreeInvert_Queue_
#include "TreeNode.h"
#include <queue>
#include <iostream>
using namespace std;
class binaryTreeInvertQueue{
    public:
        void invert(TreeNode*&root){
            if (!root) return;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode* t = q.front();
                q.pop(); // 遍历到1个节点就交换它的左右节点
                swap(t->left,t->right);
                if (t->left != nullptr) // 如果不为空指针就继续入列,下次继续判断
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            } 
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
void _binaryTree_invert_queue(){
    binaryTreeInvertQueue solution;
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
    cout<<"use queue invert tree\n";
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
#endif //!binaryTreeInvert_Recursion_