#ifndef binaryTreeInOrderRecursion_
#define binaryTreeInOrderRecursion_
#include <vector>
#include "TreeNode.h"
#include <iostream>
class binaryTreeInOrderRecursion {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root != nullptr)
        {
        inorderTraversal(root->left);
        data.push_back(root->val);
        inorderTraversal(root->right);
        }
        return data;
    }
    vector<int> data;
};
void _binaryTree_inOrder_recursion()
{
    binaryTreeInOrderRecursion solution;
    TreeNode node3(3);
    TreeNode node2(2,&node3,nullptr);
    TreeNode node1(1,nullptr,&node2);
    TreeNode root [3] = {node1,node2,node3};
    vector<int> ret = solution.inorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  ";// 4  5  2  6  7  3  1
    }
    cout<<"\n";
}
#endif // !binaryTreeInOrderRecursion_