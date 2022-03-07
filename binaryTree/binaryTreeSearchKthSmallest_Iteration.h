#ifndef binaryTreeSearchKthSmallestIteration_
#define binaryTreeSearchKthSmallestIteration_
#include <vector>
#include <iostream>
#include "TreeNode.h"
using namespace std;
class binaryTreeSearchKthSmallestIteration{
    public:
        int kthSmallest(TreeNode* root, int k){

        }
};
void _binaryTree_searchKthSmallest_iteration(){
    binaryTreeSearchKthSmallestIteration solution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    //root->left->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);
    int val = solution.kthSmallest(root,1);
    cout<<"iteration: the smallest k element is "<<val<<endl;
}
#endif // !binaryTreeSearchKthSmallestIteration