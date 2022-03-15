/*** 
 * @Author: chenbei
 * @Date: 2022-03-07 09:21:34
 * @LastEditTime: 2022-03-15 11:06:52
 * @Description: design an iterator of binarySearchTree by recursion
 * @FilePath: \myLeetCode\binaryTree\binaryTreeInOrderSearchIterator_Recursion.h
 * @A boy without dreams
 */
#ifndef binaryTreeInOrderSearchIteratorRecursion_
#define binaryTreeInOrderSearchIteratorRecursion_
#include "TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;
class binaryTreeInOrderSearchIteratorRecursion{
    public:
        binaryTreeInOrderSearchIteratorRecursion(TreeNode*root):idx(0),arr(inOrderTraversal(root)){}
        int next(){return arr[idx++];}
        bool hasNext(){return idx<arr.size();}
    protected:
        vector<int> arr;
        int idx;
        void inOrder(TreeNode*root,vector<int>& v){
            if (!root) return;
            inOrder(root->left,v);
            v.push_back(root->val);//保存数值
            inOrder(root->right,v); // 中序遍历
        }
        vector<int> inOrderTraversal(TreeNode*root){
            vector<int> ans;
            inOrder(root,ans);
            return ans;
        }
};
void _binaryTree_inOrderSearchIterator_recursion(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left= new TreeNode(9);
    root->right->right = new TreeNode(20);
    binaryTreeInOrderSearchIteratorRecursion iterator(root);
    cout<<"recursion search iterator => \n";
    cout<<"next1 is "<<iterator.next()<<" ";
    cout<<"next2 is "<<iterator.next()<<" ";
    cout<<"next3 is "<<iterator.next()<<" ";
    cout<<"next4 is "<<iterator.next()<<" ";
    cout<<"next5 is "<<iterator.next()<<" ";
    cout<<"has next? "<< (iterator.hasNext()?"true":"false")<<endl;

}
#endif // !binaryTreeInOrderSearchIteratorRecursion_