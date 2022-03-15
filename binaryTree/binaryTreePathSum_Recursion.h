/*** 
 * @Author: chenbei
 * @Date: 2022-03-06 10:06:46
 * @LastEditTime: 2022-03-15 11:17:53
 * @Description: calculate tree's pathsum by recursion
 * @FilePath: \myLeetCode\binaryTree\binaryTreePathSum_Recursion.h
 * @A boy without dreams
 */
#ifndef binaryTreePathSumRecursion_
#define binaryTreePathSumRecursion_
#include <stack>
#include <iostream>
#include <vector>
#include <numeric>
#include "TreeNode.h"
using namespace std;
class binaryTreePathSumRecursion{
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            pathSums.clear();
            pathSum.clear();
            findPaths(root);
            if (find(pathSums.begin(),pathSums.end(),targetSum)!= pathSums.end())
                return true;
            return false;
        }
        void findPaths(TreeNode*root){
            if (!root) return;
            pathSum.push_back(root->val);
            if (!root->left && ! root->right){
                pathSums.push_back(accumulate(pathSum.begin(),pathSum.end(),0));
            }
            if (root->left) findPaths(root->left);
            if (root->right) findPaths(root->right);
            pathSum.pop_back();
        }
    
    protected:
        vector<int> pathSums;
        vector<int> pathSum;

};
void _binaryTree_pathSum_recursion(){
    binaryTreePathSumRecursion solution;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->right = new TreeNode(10);
    root->right->left->left = new TreeNode(11) ;
    root->right->left->left->right = new TreeNode(12) ;
    auto ans  = solution.hasPathSum(root,33);
    cout << "recursion: the path which the pathsum is 33 is exist? "<<(ans?"true":"false")<<"\n";
}
#endif // !binaryTreePathSumRecursion