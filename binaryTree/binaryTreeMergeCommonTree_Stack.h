/*** 
 * @Author: chenbei
 * @Date: 2022-02-20 10:36:38
 * @LastEditTime: 2022-03-15 11:15:53
 * @Description: merge two trees by stack
 * @FilePath: \myLeetCode\binaryTree\binaryTreeMergeCommonTree_Stack.h
 * @A boy without dreams
 */
#ifndef binaryTreeMergeCommonTreeStack_
#define binaryTreeMergeCommonTreeStack_
#include <iostream>
#include <queue>
#include <stack>
#include "TreeNode.h"
class binaryTreeMergeCommonTreeStack{
    public:
        void mergeCommonTree(TreeNode*& root1,TreeNode*& root2){
            if (!root2) return;
            if (!root1) {root1=root2;return;}
            stack<TreeNode*> s1,s2;
            s1.push(root1);
            s2.push(root2);
            while (! s1.empty()){ // 使用s1而不是s2,以root1为基准树,root2是被合并的
                TreeNode * p = s1.top(); // 获取2个栈的首元素
                s1.pop();
                TreeNode * q = s2.top();
                s2.pop();
                p->val += q->val; // 直接加到p上
                
                // 左节点的情况
                if (!p->left && q->left ){ // 第1棵树的左节点为空但是第2棵树的左节点不为空
                    p->left = q->left; // 直接交换
                } 
                else {  // 可能左节点均不为空或者第1棵树左节点不为空但第2棵树左节点为空
                    if (p->left && q->left){ // 均不为空,就把两个节点分别入列后面会继续比
                        s1.push(p->left);
                        s2.push(q->left);
                    }
                    // 否则的话,不需要做什么,也不需要入列
                }

                // 右节点同理
                if (!p->right && q->right ){ // 第1棵树的右节点为空但是第2棵树的右节点不为空
                    p->right = q->right; // 直接交换
                } 
                else {  // 可能右节点均不为空或者第1棵树右节点不为空但第2棵树右节点为空
                    if (p->right && q->right){ // 均不为空,就把两个节点分别入列后面会继续比
                        s1.push(p->right);
                        s2.push(q->right);
                    }
                    // 否则的话,不需要做什么,也不需要入列
                }  
            }
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
void _binaryTree_mergeCommonTree_stack(){
    TreeNode * root1 = new TreeNode (7);
    root1->left = new TreeNode(6);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(3);
    root1->right->left = nullptr;
    root1->right->right = new TreeNode(1);
    TreeNode * root2 = new TreeNode (7);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(7);
    root2->left->right = new TreeNode(9);
    root2->right->left = new TreeNode (11);
    root2->right->right = nullptr;
    binaryTreeMergeCommonTreeStack solution;
    solution.mergeCommonTree(root1,root2);
    solution.levelOrder(root1);
}
#endif // !binaryTreeMergeCommonTreeStack_