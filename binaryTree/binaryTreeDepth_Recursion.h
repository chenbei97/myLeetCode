#ifndef binaryTreeDepthRecursion_
#define binaryTreeDepthRecursion_
#include "TreeNode.h"
#include <iostream>
using namespace std;
class binaryTreeDepthRecursion{
    public:
        int getDepth(TreeNode* root){
            depth = 0; //solution传入不同的root时都要先清零,因为solution是个对象,属性值会累积
            if (!root) return depth; 
            depth = 1 ;
            getBranchDepth(root,depth);
            return depth;
        }
        int treeDepth(TreeNode* root) { // 另一种递归方法
            int l_h , r_h; // 记录左右子树的深度
            if (!root) return 0 ;
            l_h = treeDepth(root->left); // 是空节点也要返回值否则无法比较
            r_h = treeDepth(root->right);
            return  l_h > r_h ? (l_h+1) : (r_h+1); // +1是每次递归非空则深度+1
        }
    private:
        int depth;
        void getBranchDepth(TreeNode* root,int d){
            TreeNode * t = root;
            if (!t->left && ! t->right){
                if (d > depth) depth = d; // 每个节点分裂时,左右节点携带的d都是相同的
                return; // 但是depth只有1个,所有的路径都可以和depth相比,比较结束最后的depth就是深度
            }
            d++ ;
            if (t->left) getBranchDepth(t->left,d);
            if (t->right) getBranchDepth(t->right,d);
        }
};
void _binaryTree_depth_recursion(){
    binaryTreeDepthRecursion solution;
    TreeNode * root = new TreeNode(1);
    TreeNode * t = root;
    for (int i = 1; i<=5;i++){
        t->left = new TreeNode(i);
        t = t->left;
    }
    int depth = solution.getDepth(root);
    cout<<"method1: tree depth is "<<depth<<endl;
    depth = solution.treeDepth(root);
    cout<<"method2: tree depth is "<<depth<<endl;

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->left->right = new TreeNode(1);
    root->right->left->right->left->right->left = new TreeNode(1);
    depth = solution.getDepth(root);
    cout<<"method1: tree depth is "<<depth<<endl;
    depth = solution.treeDepth(root);
    cout<<"method2: tree depth is "<<depth<<endl;

    TreeNode * root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->left->left->right = new TreeNode(10);
    root1->right->left->left = new TreeNode(11) ;
    root1->right->left->left->right = new TreeNode(12) ;
    depth = solution.getDepth(root1);
    cout<<"method1: tree depth is "<<depth<<endl;
    depth = solution.treeDepth(root1);
    cout<<"method2: tree depth is "<<depth<<endl;
}
#endif // !binaryTreeDepthRecursion_