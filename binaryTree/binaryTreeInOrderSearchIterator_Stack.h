#ifndef binaryTreeInOrderSearchIteratorStack_
#define binaryTreeInOrderSearchIteratorStack_
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class binaryTreeInOrderSearchIteratorStack{
    public:
        binaryTreeInOrderSearchIteratorStack(TreeNode*root):idx(0),arr(inOrderTraversal(root)){}
        int next(){return arr[idx++];}
        bool hasNext(){return idx<arr.size();}
    protected:
        vector<int> arr;
        int idx;
        vector<int> inOrderTraversal(TreeNode*root){
            vector<int> ans;
            stack<TreeNode*> stk;
            while (root != nullptr ||  !stk.empty()) // 栈为空且root为空循环就会退出
            {
                if (root != nullptr){ //左节点不为空
                    stk.push(root); // 左节点依次压栈
                    root = root->left; // 一路更新到最左节点
                }
                else{ // 左节点是空的,root是空
                    root = stk.top(); // 退回到之前非空的左节点,也就是现在空的左节点的父节点
                    stk.pop(); // 路径栈先删除这个非空左节点
                    ans.push_back(root->val); // 保存好值
                    root = root->right; // 之前的子左节点为空,所以再试试添加右节点
                }    
            }
            return ans;
        }
};
void _binaryTree_inOrderSearchIterator_stack(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left= new TreeNode(9);
    root->right->right = new TreeNode(20);
    binaryTreeInOrderSearchIteratorStack iterator(root);
    cout<<"stack search iterator => \n";
    cout<<"next1 is "<<iterator.next()<<" ";
    cout<<"next2 is "<<iterator.next()<<" ";
    cout<<"next3 is "<<iterator.next()<<" ";
    cout<<"next4 is "<<iterator.next()<<" ";
    cout<<"next5 is "<<iterator.next()<<" ";
    cout<<"has next? "<< (iterator.hasNext()?"true":"false")<<endl;

}
#endif // !binaryTreeInOrderSearchIteratorStack_