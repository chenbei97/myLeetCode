/*** 
 * @Author: chenbei
 * @Date: 2022-02-18 15:19:29
 * @LastEditTime: 2022-03-15 11:09:35
 * @Description: judge binaryTree is complete by queue
 * @FilePath: \myLeetCode\binaryTree\binaryTreeIsComplete.h
 * @A boy without dreams
 */
#ifndef binaryTreeIsComplete_
#define binaryTreeIsComplete_
#include "TreeNode.h"
#include <queue>
#include <iostream>
using namespace std;
class binaryTreeIsComplete{
    public:
        bool isComplete(TreeNode*root){
            if (!root) return false; // 树为空,不是完全二叉树

            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) // 队列不为空
            {
                TreeNode * t = q.front(); // 获取队列首元素
                if (t->left && t->right){ // 如果2个孩子都不为空
                    q.pop(); // 删除父节点
                    q.push(t->left); // 两个子节点放在队列后边后序会再进行判断
                    q.push(t->right);
                }
                if ((t->left==nullptr) && (t->right != nullptr)) { // 左节点为空右节点不为空肯定不是完全二叉树
                    return false;
                }
                if ((t->left&& (t->right==nullptr))// 左节点不为空,右节点为空
                    ||(t->left==nullptr &&t->right == nullptr)){ //或左右均为空才有可能是完全二叉树
                     if (t->left&& (t->right==nullptr)){ // 如果是左节点不为空,右节点为空
                        q.push(t->left); // 放到队列后序再进行判断
                     }
                     q.pop(); // 无论是不是上边的情况都要删除t节点,pop放在if语句外
                     // 如果2个子节点均为空,说明t是叶子节点,删除它后目前队列上的所有节点应该都是叶子节点
                     // 如果不是就说明不是完全二叉树
                     while(!q.empty()){
                         t = q.front();
                         if (t->left==nullptr && t->right == nullptr){
                             q.pop(); // 是叶子节点,就继续判断下一个
                         }
                         else{
                             return false; // 必然不是完全二叉树
                         }
                     }
                     return true; // 说明没有进入小while,说明t已经是最后1个叶子节点,则是完全二叉树
                }
            
            }
            return true;  // 说明没有进入大while,t是唯一的非空节点,是完全二叉树  
        }
        void levelOrder(TreeNode* root){
            if (root == nullptr) return;
            queue<TreeNode*> q;
            TreeNode * t = root;
            while (t != nullptr)
            {
                cout<<t->val<<" "; // 层次遍历打印节点的元素值
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                if (! q.empty())
                    t = q.front();
                else break ;
                q.pop();
            }
            cout<<"\n";
        }
};
void _binaryTree_isComplete(){
    binaryTreeIsComplete solution;
    // 完全二叉树测试
    TreeNode * root = new TreeNode (7);
    root->left = new TreeNode(6);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(1);
    bool res = solution.isComplete(root);
    solution.levelOrder(root);
    cout<<"the root is complete tree? "<<res<<endl;

    // 非完全二叉树测试
    root->left->left = nullptr;
    solution.levelOrder(root);
    res = solution.isComplete(root);
    cout<<"the root is complete tree? "<<res<<endl;
}
#endif //!binaryTreeIsComplete_