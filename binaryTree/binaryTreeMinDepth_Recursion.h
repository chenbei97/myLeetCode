#ifndef binaryTreeMinDepthRecursion_
#define binaryTreeMinDepthRecursion_
#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeNode.h"
using namespace std;
class binaryTreeMinDepthRecursion{
    public:
        int getMinDepth(TreeNode * root){
            if (!root) return 0;
            depths.clear();
            getBranchDepth(root,1);
            vector<int>::iterator minDepth =  // 嫌麻烦可以用auto代替
                min_element(depths.begin(),depths.end());
            return *minDepth;
        }
        int treeMinDepth(TreeNode* root){
            // 最大节点的找法是从叶子节点开始,总是返回以这个节点为根节点的左右子树最大深度+1,
            // 显然叶子节点左右子树深度是(0,0),那么该节点返回值是1
            // 然后该节点的相邻兄弟节点也返回了1个值,这2个节点的最大值再+1作为它们的父节点返回值
            // 依次类推直到全局根节点,就可以得到最大深度
            if(!root) return 0;
            // 最小深度怎么做呢?
            // 从叶子节点开始,总是返回更小的那个,因为都是(0,0),所以叶子节点返回值必定是1
            // 叶子节点的父节点呢?取决于兄弟节点的情况
            // 如果兄弟节点不为空,毫无疑问兄弟节点深度只可能大于等于叶子节点深度
            // 所以应当返回叶子节点的深度+1,叶子节点可以是左节点也可以是右节点
            // 但是不管是哪种都是返回另一个节点的深度+1,于是有下方2行代码
            if (count > 0){
                if (!root->left) return 1+treeMinDepth(root->right); // 总是返回兄弟节点的深度+1
                if (!root->right) return 1+treeMinDepth(root->left); // 总是返回兄弟节点的深度+1
            }
            count = 1;
            // 但是也可能遇见2个节点均为空的情况,if(!root) return 0;已经涵盖这个情况
            // 为了避免root刚进入会执行2个递归占用时间,引入count=0,只有＞0才会执行2个语句
            return 1 + min(treeMinDepth(root->left), treeMinDepth(root->right));
        }
    private:
        vector<int> depths;
        int count = 0;
        void getBranchDepth(TreeNode*root,int d){
            TreeNode * t = root;
            if (!t->left && ! t->right){
                depths.push_back(d);
            }
            d++;
            if (root->left) getBranchDepth(root->left,d);
            if (root->right) getBranchDepth(root->right,d);
        }
};
void _binaryTree_minDepth_recursion(){
    binaryTreeMinDepthRecursion solution;
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
    cout<<"method1: tree min depth is "<<depth<<endl; // 7
    depth = solution.treeMinDepth(root);
    cout<<"method2: tree min depth is "<<depth<<endl;
}
#endif // !binaryTreeMinDepthRecursion_