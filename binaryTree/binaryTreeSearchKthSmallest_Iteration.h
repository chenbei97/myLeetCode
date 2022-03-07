#ifndef binaryTreeSearchKthSmallestIteration_
#define binaryTreeSearchKthSmallestIteration_
#include <vector>
#include <iostream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;
class binaryTreeSearchKthSmallestIteration{
    public:
        binaryTreeSearchKthSmallestIteration(TreeNode*root){
            this->root = root;
            count_node_num(this->root);// 把所有节点及其子节点的数目计算完毕存到subNodeNum
        }
        int kthSmallest(int k){
            TreeNode *node = this->root;
            while (node){
                int n = get_node_num(node->left); // 获取node的左子树节点数量
                if (n+1<k){ // 加上node有n+1个节点,比k小,只能从右子树找
                    node = node->right;
                    k = k-(n+1); // 右子树只需要找到第[k-(n+1)]这么小的元素即可
                }
                else if (n+1==k) return node->val;//node就是第k小
                else node = node->left; // 说明第k小在node.left的下方
            }
            return -1; // 如果k给的有问题默认返回-1
        }
    protected:
        unordered_map<TreeNode*,int> subNodeNum;
        TreeNode * root ;
        int count_node_num(TreeNode *node){
            if (!node) return 0;
            subNodeNum[node] = count_node_num(node->left)+count_node_num(node->right)+1;
            return subNodeNum[node];
        }
        int get_node_num(TreeNode*node){
            if (!node) return 0;
            return subNodeNum[node];
        }

};
void _binaryTree_searchKthSmallest_iteration(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    binaryTreeSearchKthSmallestIteration solution(root);
    int val = solution.kthSmallest(1);
    cout<<"iteration: the smallest k element is "<<val<<endl;
}
#endif // !binaryTreeSearchKthSmallestIteration