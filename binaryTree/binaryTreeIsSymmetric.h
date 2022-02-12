#ifndef binaryTreeIsSymmetric_
#define binaryTreeIsSymmetric_
#include "TreeNode.h"
#include <iostream>
using namespace std;
class binaryTreeIsSymmetric
{
public:
    bool isSymmetric(TreeNode * root){
        return compare_left_right(root->left,root->right);
    }
private:
    bool compare_left_right(TreeNode * left,TreeNode * right){
            // 最小单元根左右应当满足的条件
            if (left == nullptr && right == nullptr){
                return true; // 先排除都为nullptr的情况
            }
            if (left == nullptr || (right == nullptr) || left->val != right->val){
                return false;
            } //继续比较左子树的左子树和右子树的右子树是否对称
            // 以及左子树的右子树和右子树的左子树是否对称
            return compare_left_right(left->left,right->right) 
                    && compare_left_right(left->right,right->left);
    }
// public:
//     bool isSymmetric(TreeNode* root) {
//         return dfs(root, root);
//     }

//     bool dfs(TreeNode* root1, TreeNode* root2) {
//         if (!root1 && !root2) return 1;
//         if (!root1 || !root2 || root1->val != root2->val) return 0;
//         return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
//     }
};
void _binaryTree_is_symmetric()
{
    binaryTreeIsSymmetric solution;
    TreeNode * root = new TreeNode [7];
    root[0].left = &root[1];
    root[0].right = &root[2];
    root[1].left = &root[3];
    root[1].right = &root[4];
    root[2].left = &root[5];
    root[2].right = &root[6];

    for(int i =0;i<7;i++)
        root[i].val = i+1 ;
    root[3].val=3;root[4].val=3;root[5].val=3;root[6].val=3;
    bool res = solution.isSymmetric(&root[0]);
    cout <<"tree is symmetric? "<<res<<endl;

    for(int i =0;i<7;i++)
        root[i].val = 10 ;
    res = solution.isSymmetric(&root[0]);
    cout <<"tree is symmetric? "<<res<<endl;
}


#endif // !binaryTreeIsSymmetric_