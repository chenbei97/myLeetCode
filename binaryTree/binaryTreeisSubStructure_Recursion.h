#ifndef binaryTreeisSubStructureRecursion_
#define binaryTreeisSubStructureRecursion_
#include "TreeNode.h"
#include <iostream>
using namespace std;
class binaryTreeisSubStructureRecursion{
    public:
        bool isSubStructure(TreeNode * tree1,TreeNode * tree2){
            // 思路和迭代解法是一样的,只是更简洁没有很多if_else判断
            // 迭代思路:是找到1个可能合适的根节点,再进行比较,没找到再尝试根节点的左右节点和第2棵树的比较
            // 这里不管三七二十一直接全部带进入loop函数,只要有1个行就可以
            // loop函数和compareSubTree函数完全一样,只是把后2个判断返回true的条件写在一起了
            // 同时多增加了1个判断,这是避免第1次进入loop函数导致的问题
            // 假如没有这个条件,tree2为None无论tree1是否为None,3种调用进入loop函数都直接返回true
            // 看起来还没什么问题,因为空节点确实也算第1棵树的子树,即使tree1=None
            // 如果tree1为None,就会造成调用出错,因为空指针没有属性left和right
            if (!tree1 || !tree2) return 0;
            return loop(tree1, tree2) 
                    || isSubStructure(tree1->left, tree2) 
                    || isSubStructure(tree1->right, tree2);
        }
    protected:
        bool loop(TreeNode * tree1,TreeNode * tree2){
            if (!tree2) return 1;
            if (!tree1 || tree1->val != tree2->val) return 0;
            return loop(tree1->left, tree2->left) 
                && loop(tree1->right, tree2->right);
        }
};
void _binaryTree_isSubStructure_recursion(){
    /*
         3        3   3(C++ 也出现了爆栈)
        / \      /   /
       4   5    4   4
     /  \        \   \
    1    2        2   3
    */
    TreeNode * root1 = new TreeNode (3); // 必须分配空间,否则后面root1->left = new TreeNode(4)会报错
    root1->left = new TreeNode(4); // 因为这个指针不知道是指向数组名还是单个对象地址
    root1->right = new TreeNode(5);// 同理
    root1->left->left = new TreeNode (1);
    root1->left->right = new TreeNode (2);

    TreeNode * root2 = new TreeNode(3); // 先分配空间
    root2->left = new TreeNode (4);
    root2->left->right = new TreeNode (2);

    TreeNode * root3 = new TreeNode(3);// 先分配空间
    root3->left = new TreeNode (4);
    root3->left->right = new TreeNode (3);

    binaryTreeisSubStructureRecursion solution;
    // bool res1 = solution.isSubStructure(root1,root2); // 会爆栈
    // bool res2 = solution.isSubStructure(root1,root3);
    // cout <<"res1 is "<<res1<<" res2 is "<<res2<<endl;

    /*
        使用下方二叉树继续测试
                 3         
                / \       
               4   5        
             /  \                       
            1    2      
             \    \
              -3   7
              /   /
             9   10   
            /
           11
             \
             12
    */
    TreeNode * tree = new TreeNode(3);
    tree->left = new TreeNode(4);tree->right=new TreeNode(5);
    tree->left->left = new TreeNode(1);tree->left->right = new TreeNode(2);

    tree->left->left->right = new TreeNode(-3);
    tree->left->left->right->left = new TreeNode(9);
    tree->left->left->right->left->left = new TreeNode(11);
    tree->left->left->right->left->left->right = new TreeNode(12);

    tree->left->right->right = new TreeNode(7);
    tree->left->right->right->left = new TreeNode(10);

    cout<<"12 is subStructure of tree ? "<<solution.isSubStructure(tree,new TreeNode(12))<<"\n";
    cout<<"10 is subStructure of tree ? "<<solution.isSubStructure(tree,new TreeNode(10))<<"\n";
    cout<<"-1 is subStructure of tree ? "<<solution.isSubStructure(tree,new TreeNode(-1))<<"\n";
}
#endif // !binaryTreeisSubStructureRecursion_