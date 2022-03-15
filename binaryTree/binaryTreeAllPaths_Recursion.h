/*** 
 * @Author: chenbei
 * @Date: 2022-02-20 19:04:04
 * @LastEditTime: 2022-03-15 09:15:40
 * @Description: find binaryTree all paths by recursion
 * @FilePath: \myLeetCode\binaryTree\binaryTreeAllPaths_Recursion.h
 * @A boy without dreams
 */
#ifndef binaryTreeAllPathsRecursion_
#define binaryTreeAllPathsRecursion_
#include <iostream>
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;
class binaryTreeAllPathsRecursion{
    protected:
        vector<string> paths;
    public:
        vector<string> allPaths(TreeNode * root){
            if (!root) return paths;
            findPaths(root,"");
            return paths;
        }
        void findPaths(TreeNode* root,string path){
            path += to_string(root->val);
            cout<< path<<endl;
            if (! root->left && ! root->right){
                paths.push_back(path); // 1条路径结束后存储起来就返回,再尝试其它方向
                // cout<<paths.size()<<"\n";
                return;
            }
            path += "->";
            // 每个节点都分出2个路径,广度搜索,直到左右节点都为空为止
            if (root->left) {cout <<"left"<<endl;findPaths(root->left,path);}; 
            if (root->right) {cout <<"right"<<endl;findPaths(root->right,path);};
        }   
};
void _binaryTree_allPaths_recursion(){
    binaryTreeAllPathsRecursion solution;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->right = new TreeNode(10);
    root->right->left->left = new TreeNode(11) ;
    root->right->left->left->right = new TreeNode(12) ;
    vector<string> ans = solution.allPaths(root);
    for (size_t i = 0 ; i <ans.size();i++){
        cout << ans[i]<<"\n";
    }
    /*
    1->3->6->11->12
    1->2->5
    1->2->4->10
    */
}
#endif // !binaryTreeAllPathsRecursion_