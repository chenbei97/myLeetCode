#ifndef binaryTreeInOrderStack_
#define binaryTreeInOrderStack_
#include <vector>
#include <stack>
#include "TreeNode.h"
#include <iostream>
/*
1.定义一个栈 stk
2.将树的左节点依次入栈,更新root,直到左节点为空,此时root为空
3.root为空时,让root等于弹出的栈顶元素并保存,然后更新root为右节点
直到root不为空,也就是root上移才有可能,这时右节点也入栈,保存后root又更新为左节点
然后root又为空,root会继续更新为栈顶元素,如果栈顶元素也没有,循环退出
4.重复 2-3 的操作
*/
class binaryTreeInOrderStack {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while (root != nullptr ||  !stk.empty()) // 栈为空且root为空循环就会退出
        {
            if (root != nullptr){ //左节点不为空
                stk.push(root); // 左节点依次压栈
                root = root->left; // 一路更新到最左节点
            }
            else{ // 左节点是空的,root是空
                root = stk.top(); // 取出栈顶元素给root
                stk.pop(); // 记得要出栈
                ans.push_back(root->val); // 保存好值
                root = root->right; // 更新为右节点
            }    
        }
        return ans;
    }
};
void _binaryTree_inOrder_stack()
{
    binaryTreeInOrderStack solution;
    TreeNode node7(7);
    TreeNode node6(6);
    TreeNode node5(5);
    TreeNode node4(4);
    TreeNode node3(3,&node6,&node7);
    TreeNode node2(2,&node4,&node5);
    TreeNode node1(1,&node2,&node3);
    TreeNode * root = &node1;
    vector<int> ret = solution.inorderTraversal(root);
    for(vector<int>::const_iterator it = ret.begin(); it!=ret.end();it++)
    {
        cout <<*it<<"  ";// [4, 2, 5, 1, 6, 3, 7]
    }
    cout<<"\n";
}
#endif // !binaryTreeInOrderStack_