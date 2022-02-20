#ifndef binaryTreeRightViewQueue_
#define binaryTreeRightViewQueue_
#include <queue>
#include <vector>
#include <iostream>
#include "TreeNode.h"
using namespace std;
class binaryTreeRightViewQueue{
    public :
        vector<int> rightView(TreeNode*root){
            vector<int> ans;
            if (!root) return ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()){
                ans.push_back(q.front()->val);//注意,在这里获取q的首元素
                cout<<q.front()->val<<" ";
                int qSize = q.size();
                for(int i = 0;i<qSize;i++){ 
                    TreeNode * t = q.front();// front()保证可以是层的最后1个元素就要求右节点先入列
                    // 如果是返回嵌套层序列表,是在这里添加 ans.push_back(t->val);
                    if (t->right) q.push(t->right);
                    if (t->left) q.push(t->left); // 注意,左右需要颠倒
                    // 如果先左后右,得到的其实是左视图,先右后左才是右视图
                    q.pop();
                }
            }
            cout<<"\n";
            return ans;
        }
};
void _binaryTree_rightView(){
    binaryTreeRightViewQueue solution;
    TreeNode * root2 = new TreeNode (7); // √
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(5); // √
    root2->left->left = new TreeNode(7);
    root2->left->right = new TreeNode(9); 
    root2->right->left = new TreeNode (11);// √
    root2->right->right = nullptr;
    vector<int> ans = solution.rightView(root2);
}
#endif // !binaryTreeRightViewQueue_