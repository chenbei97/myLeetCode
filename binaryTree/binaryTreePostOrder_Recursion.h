#ifndef binaryTreePostOrderRecursion_
#define binaryTreePostOrderRecursion_
#include <vector>
#include "TreeNode.h"
#include <iostream>
class binaryTreePostOrderRecursion {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != nullptr)
        {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        data.push_back(root->val);
        }
        return data;
    }
    vector<int> data;
};
void _binaryTree_postOrder_recursion()
{
    /* 
        输入要求[1,null,2,3]
            1
           / \
        nULL  2
             /
            3 
        输出为[3,2,1]
    */
    binaryTreePostOrderRecursion solution;
    TreeNode node3(3);
    TreeNode node2(2,&node3,nullptr);
    TreeNode node1(1,nullptr,&node2);
    TreeNode root [3] = {node1,node2,node3};
    vector<int> ret = solution.postorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  ";// 321
    }
    cout<<"\n";
}
#endif // !binaryTreePostOrderRecursion_