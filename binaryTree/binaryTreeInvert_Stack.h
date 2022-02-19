#ifndef binaryTreeInvert_Stack_
#define binaryTreeInvert_Stack_
#include "TreeNode.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
class binaryTreeInvertStack{
    public:
        void invert(TreeNode*&root){
            if (root == nullptr) return;
            stack<TreeNode*> s;
            s.push(root);
            while (!s.empty())
            {
                TreeNode * t = s.top();
                s.pop();
                swap(t->left,t->right);// 队列的话因为先入先出,所以先处理的是交换后的左节点也就是原来的右节点
                if (t->left != nullptr) // 栈是先入后出,交换后,原来的右节点先入栈,然后左节点入栈,但是后入先出,先处理左节点
                    s.push(t->left); // 但是这种处理机制对反转二叉树没有影响,先处理左还是右没有什么区别,因为队列和栈都会为空位置,所有节点的左右节点都会处理到
                if (t->right != nullptr)
                    s.push(t->right);
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
void _binaryTree_invert_stack(){
    binaryTreeInvertStack solution;
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
    cout<<"use stack invert tree\n";
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
#endif //!binaryTreeInvert_Stack_