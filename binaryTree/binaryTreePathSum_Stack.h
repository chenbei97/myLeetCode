#ifndef binaryTreePathSumStack_
#define binaryTreePathSumStack_
#include <stack>
#include <iostream>
#include <vector>
#include <numeric>
#include "TreeNode.h"
using namespace std;
class binaryTreePathSumStack{
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            vector<int> pathSums;
            vector<int> pathSum; // 到当前节点的路径
            stack<pair<TreeNode*,vector<int>>> stk; // 保存每个遍历过的节点指针及其路径,栈顶元素是当前节点和当前路径
            TreeNode * p = root; // 定义一个当前节点的指针,目前指向root
            while ( p || !stk.empty())
            {
                while (p)
                {
                    pathSum.push_back(p->val);
                    // vector<int> temp(pathSum.size()) ; //C++貌似不需要使用新的变量承接
                    // copy(pathSum.begin(),pathSum.end(),temp.begin());
                    stk.push(pair<TreeNode*,vector<int>>(p,pathSum)); // 添加这个节点路径
                    p = p->left; // 每个非空节点都是先找最左路径
                }
                p = stk.top().first; // 此时回到上一级父节点
                pathSum = stk.top().second; // 路径回到上一级
                stk.pop(); // 记得退栈
                if (! p->left && !p->right) // 父节点的左节点已经是空节点,右节点也是空说明是一条完整路径了
                        pathSums.push_back(accumulate(pathSum.begin(),pathSum.end(),0)); // 添加这个路径
                p = p->right ; // 无论右节点是否为空均更新交由一级while去判断
            }
            for(int i =0;i<pathSums.size();i++)
                cout<<pathSums[i]<<" ";
            cout<<endl;
            if (find(pathSums.begin(),pathSums.end(),targetSum)!= pathSums.end())
                return true;
            return false;
        }
};
void _binaryTree_pathSum_stack(){
    binaryTreePathSumStack solution;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->right = new TreeNode(10);
    root->right->left->left = new TreeNode(11) ;
    root->right->left->left->right = new TreeNode(12) ;
    auto ans  = solution.hasPathSum(root,33);
    cout << "stack: the path which the pathsum is 33 is exist? "<<(ans?"true":"false")<<"\n";
}
#endif // !binaryTreePathSumStack