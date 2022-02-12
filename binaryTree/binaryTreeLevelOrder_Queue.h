#ifndef binaryTreeLevelOrderQueue_
#define binaryTreeLevelOrderQueue_
#include <vector>
#include <queue>
#include <math.h>
#include "TreeNode.h"
#include <iostream>
using namespace std;
class binaryTreeLevelOrderQueue{
    public:
        vector<int> levelOrderTraversal(TreeNode* root){
            vector<int>  ans ;
            queue<TreeNode*> q;
            TreeNode *t = root;
            while (t!=nullptr)
            {
                ans.push_back(t->val);
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                // try
                // {
                //     t = q.front();
                // }
                // catch(const exception& e)
                // {
                //     std::cerr << e.what() << '\n';
                //     return NULL;
                // }
                if (!q.empty())
                    t = q.front();
                else
                    return ans;
                q.pop();
            }
            return ans;
        }
        vector<int> levelOrderTraversalWithNull(int height,TreeNode* root){
            vector<int>  ans ;
            queue<TreeNode*> q;
            TreeNode *t = root;
            q.push(t);
            while (!q.empty())
            {
                
                t = q.front();
                q.pop();
                
                if (!t) ans.push_back(-1);// t为空
                else ans.push_back(t->val);

                // for(size_t i =0;i<ans.size();i++)
                //     cout<<t->val<<" "<<ans[i]<<"  ";
                // cout<<"\n";

                if(t) // t不是空指针才可能会有left和right
                {
                    q.push(t->left);
                    q.push(t->right);
                }
                // cout<<"qSize = "<<q.size()<<endl;
                if (ans.size() == pow(2,height)-1)
                    break;
            }
            return ans;
        }
};
void _binaryTree_levelOrder_queue(){
    binaryTreeLevelOrderQueue solution;
    TreeNode n15(10);
    TreeNode n14(8);
    TreeNode n13(8);
    TreeNode n12(10);
    TreeNode n11(10);
    TreeNode n10(8);
    TreeNode n9(8);
    TreeNode n8(10);
    TreeNode n7(4,&n14,&n15);
    TreeNode n6(6,&n12,&n13);
    TreeNode n5(6,&n10,&n11);
    TreeNode n4(4,&n8,&n9);
    TreeNode n3(2,&n6,&n7);
    TreeNode n2(2,&n4,&n5);
    TreeNode n1(1,&n2,&n3);
    auto ret1 = solution.levelOrderTraversal(&n1);
    for(size_t i =0;i<ret1.size();i++)
        cout<<ret1[i]<<"  ";
    cout<<"\n";

    TreeNode y15(10);
    TreeNode y14(8);
    TreeNode y13(8);
    TreeNode y12(10);
    TreeNode y11(10);
    TreeNode y10(8);
    TreeNode y9(8);
    TreeNode y8(10);
    TreeNode y7(4,nullptr,&n15);
    TreeNode y6(6,&n12,&n13);
    TreeNode y5(6,&n10,&n11);
    TreeNode y4(4,&n8,&n9);
    TreeNode y3(2,&n6,nullptr);
    TreeNode y2(2,&n4,&n5);
    TreeNode y1(1,nullptr,&n3);
    // 这个函数有些问题,C++可能无法做到像python那样即使是空指针也能打印出null的值
    // 因为nullptr无法继续遍历,但是Python的 q.put_nowait(root.left if root else None)
    // 很难在C++实现
    auto ret2 = solution.levelOrderTraversalWithNull(4,&y1);
    for(size_t i =0;i<ret2.size();i++)
        cout<<ret2[i]<<"  ";
    cout<<"\n";
}
#endif  // !binaryTreeLevelOrderQueue_