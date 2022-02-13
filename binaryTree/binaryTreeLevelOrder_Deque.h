#ifndef binaryTreeLevelOrderDeque_
#define binaryTreeLevelOrderDeque_
#include <vector>
#include <deque>
#include "TreeNode.h"
#include <iostream>
using namespace std;
class binaryTreeLevelOrderDeque{
    public:
        vector<vector<int>> levelOrderTraversalNestWithNull(int height,TreeNode* root,bool rever =false){
            // 和使用queue实现的区别在于Deque是双端队列
            // 唯一的区别是使用pop_front函数来删除队首元素
            // 其它思路上没有区别，且一步到位，这里直接给出嵌套型的带返回null的写法
            // 同时还提供了翻转列表的方法,这些就自底向上打印二叉树的层元素
            vector<vector<int>> ans;
            if (!root){
                ans.push_back(vector<int>(-1));
            }
            TreeNode * t = root;
            deque<TreeNode*> q;
            q.push_back(t);
            while (!q.empty())
            {
                vector<int> k;
                int qSize = q.size();
                for (int i=0;i<qSize;i++){
                    t = q.front(); // 和queue一样
                    q.pop_front(); // 不是pop而是pop_front
                    if (!t){ // 空节点
                        q.push_back(nullptr);  // 左右2个必定是空节点
                        q.push_back(nullptr);
                        k.push_back(-1);
                    }
                    else{ // 非空节点
                        q.push_back(t->left); // 左右节点是不是空不重要
                        q.push_back(t->right);
                        k.push_back(t->val);
                    }
                }
                ans.push_back(k);
                k.clear(); // 记得清理

                if (flattenVector(ans).size() == pow(2,height)-1)
                    break;  // 展平后的元素来控制while退出
            }
            if (rever){
                reverse(ans.begin(),ans.end());
            }
            return ans;
        }
    protected:
        vector<int> flattenVector(vector<vector<int>> &x){ // 用于展平vector
            vector<int> ans;
            for(size_t i =0;i<x.size();i++)
                for(size_t j =0;j<x[i].size();j++)
                ans.push_back(x[i][j]);
            return ans;
        }
};
void _binaryTree_levelOrder_deque(){
    binaryTreeLevelOrderDeque  solution;
        /*
                1
            -1        2
        -1   -1    6     -1
    -1  -1 -1 -1 10  8 -1  -1
    */
    TreeNode y15(10);
    TreeNode y13(8);
    TreeNode y12(10);
    TreeNode y6(6,&y12,&y13);
    TreeNode y3(2,&y6,nullptr);
    TreeNode y1(1,nullptr,&y3);
    auto ret = solution.levelOrderTraversalNestWithNull(4,&y1,true); // 翻转列表
    for(size_t i =0;i<ret.size();i++){
        for(size_t j =0;j<ret[i].size();j++)
            cout<<ret[i][j]<<" ";
        cout<<"\n";
    }
}
#endif // !binaryTreeLevelOrderDeque_