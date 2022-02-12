#ifndef binaryTreePreOrderRecursion_
#define binaryTreePreOrderRecursion_
#include <vector>
#include "TreeNode.h"
#include <iostream>
class binaryTreePreOrderRecursion {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != nullptr)
        {
        data.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        }
        return data;
    }
    vector<int> data;
};
void _binaryTree_preOrder_recursion()
{
    binaryTreePreOrderRecursion solution;
    TreeNode node7(7);
    TreeNode node6(6);
    TreeNode node5(5);
    TreeNode node4(4);
    TreeNode node3(3,&node6,&node7);
    TreeNode node2(2,&node4,&node5);
    TreeNode node1(1,&node2,&node3);
    TreeNode * root = &node1;
    vector<int> ret = solution.preorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  "; // 1  2  4  5  3  6  7
    }
    cout<<"\n";
}
#endif // !binaryTreePreOrderRecursion_