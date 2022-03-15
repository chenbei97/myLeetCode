/*** 
 * @Author: chenbei
 * @Date: 2022-02-22 08:02:17
 * @LastEditTime: 2022-03-15 11:17:05
 * @Description: calculate tree's maxdepth by recursion
 * @FilePath: \myLeetCode\binaryTree\binaryTreeMaxDepth_Recursion.h
 * @A boy without dreams
 */
#ifndef binaryTreeMaxDepthRecursion_
#define binaryTreeMaxDepthRecursion_
#include "TreeNode.h"
#include <iostream>
using namespace std;
class binaryTreeDepthRecursion{
    public:
        int getMaxDepth(TreeNode* root){
            depth = 0; //solution传入不同的root时都要先清零,因为solution是个对象,属性值会累积
            if (!root) return depth; 
            depth = 1 ;
            getBranchMaxDepth(root,depth);
            return depth;
        }
        int treeMaxDepth(TreeNode* root) { // 另一种递归方法
            int l , r; // 记录左右子树的深度
            if (!root) return 0 ;
            l = treeMaxDepth(root->left); // 是空节点也要返回值否则无法比较
            r = treeMaxDepth(root->right);
            return  l > r ? (l+1) : (r+1); // +1是每次递归非空则深度+1
            /*
            这样的写法也可以,用max比较,然后+1,这种写法强调无论是左方向还是右方向只要不为0就会增1
            但是最大的深度肯定是2个方向最大的,接下来的节点分裂也是这样的操作
            if (!root) return 0;
            int l = treeMaxDepth(root->left), r = treeMaxDepth(root->right);
            return 1 + max(l, r); 
            */
        }
    private:
        int depth;
        void getBranchMaxDepth(TreeNode* root,int d){
            TreeNode * t = root;
            if (!t->left && ! t->right){
                if (d > depth) depth = d; // 每个节点分裂时,左右节点携带的d都是相同的
                return; // 但是depth只有1个,所有的路径都可以和depth相比,比较结束最后的depth就是深度
            }
            d++ ;
            if (t->left) getBranchMaxDepth(t->left,d);
            if (t->right) getBranchMaxDepth(t->right,d);
        }
};
void _binaryTree_maxDepth_recursion(){
    binaryTreeDepthRecursion solution;
    TreeNode * root = new TreeNode(1);
    TreeNode * t = root;
    for (int i = 1; i<=5;i++){
        t->left = new TreeNode(i);
        t = t->left;
    }
    int depth = solution.getMaxDepth(root);
    cout<<"method1: tree max depth is "<<depth<<endl;
    depth = solution.treeMaxDepth(root);
    cout<<"method2: tree max depth is "<<depth<<endl;

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->left->right = new TreeNode(1);
    root->right->left->right->left->right->left = new TreeNode(1);
    depth = solution.getMaxDepth(root);
    cout<<"method1: tree max depth is "<<depth<<endl;
    depth = solution.treeMaxDepth(root);
    cout<<"method2: tree max depth is "<<depth<<endl;

    TreeNode * root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->left->left->right = new TreeNode(10);
    root1->right->left->left = new TreeNode(11) ;
    root1->right->left->left->right = new TreeNode(12) ;
    depth = solution.getMaxDepth(root1);
    cout<<"method1: tree max depth is "<<depth<<endl;
    depth = solution.treeMaxDepth(root1);
    cout<<"method2: tree max depth is "<<depth<<endl;
}
#endif // !binaryTreeMaxDepthRecursion_