/*** 
 * @Author: chenbei
 * @Date: 2022-03-07 10:54:04
 * @LastEditTime: 2022-03-15 11:21:15
 * @Description: search the k smallest element in searchTree by inOrder
 * @FilePath: \myLeetCode\binaryTree\binaryTreeSearchKthSmallest_InOrder.h
 * @A boy without dreams
 */
#ifndef binaryTreeSearchKthSmallestInOrder_
#define binaryTreeSearchKthSmallestInOrder_
#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;
class binaryTreeSearchKthSmallestInOrder{
    public:
        int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk ;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left; // 到了最左路径的节点
            }
            root = stk.top();
            stk.pop();
            --k; //然后开始倒退,直到k为0说明是第k小
            if (k == 0) {
                break;
            }
            root = root->right;
        }
        return root->val;
    }

};
void _binaryTreeSearchKthSmallest_InOrder(){
    binaryTreeSearchKthSmallestInOrder solution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    //root->left->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);
    int val = solution.kthSmallest(root,1);
    cout<<"inorder(stack): the smallest k element is "<<val<<endl;

}
#endif // !binaryTreeSearchKthSmallestInOrder_