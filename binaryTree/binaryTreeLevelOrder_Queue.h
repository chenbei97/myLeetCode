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
       // 4个函数,分别用于返回展平列表不带null,返回展平列表带null,返回嵌套列表不带null和带null
        vector<int> levelOrderTraversal(TreeNode* root){
            vector<int>  ans ;
            if (!root) // root为空
                return ans;
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
            // 思路：上述不打印null的是控制t不为空才会入列,且t的左右子树不为空才会入列
            // 因为入列的是根、左、右，每次t更新又变成左节点，因为左节点先入
            // 这样可以保证每层总是从左到右依次遍历节点
            // 不过上边的函数是为空就不会再入列了,所以碰到空节点无法打印
            // 本函数为了解决这个问题，循环不再是t不为空来控制,相反无论t是否为空都入列
            // 只是下次t更新时如果是空节点,说明它左右节点必然也是空节点
            // 所以直接让队列添加2个空指针即可,相应的t是空节点则ans保存指定的值value=-1
            // -1是指定的一个数，value可以是任何数,因为这个函数本来目的是为了平衡二叉树的验证来使用
            // python中的实现因为None也可以被打印出来,所以无需指定1个数,直接打印None即可
            // 如果一个二叉树遍历出来有很多-1，无论是二叉树本来有的数据-1还是因为nullptr而指定的-1
            // 都不会改变原本二叉树是否平衡的结论
            // 本函数的while循环不通过t控制,而通过q是否为空来控制,但是因为nullptr也可以入列
            // 那么任意一个二叉树如果把nullptr可以当成节点的话就有无穷多个nullptr
            // 所以需要引入二叉树的高度限制,通过高度可以知道二叉树应该有的元素个数
            // 最多遍历到有至少1个非空节点的层,再后面就不再打印,因为没有意义
            vector<int>  ans ;
            if (!root) 
            {
                ans.push_back(-1); // 返回带-1的vector
                return ans;
            }
                
            queue<TreeNode*> q;
            TreeNode *t = root;

            q.push(t); // 为了能够进入while循环
            while (!q.empty())
            {
                
                t = q.front(); // 因为nullptr也可以入列,所以无需担心队列为空的问题
                q.pop();
            
                if (!t) // t为空
                {
                    // 左右节点必定是nullptr
                    // 因为为空,nullptr没有属性left和right,所以才要区分是否为空
                    q.push(nullptr);
                    q.push(nullptr);
                    ans.push_back(-1); // 遇到空节点保存指定值-1
                    cout<<"nullptr ";
                }
                else 
                {
                    cout<<t->val<<" ";
                    ans.push_back(t->val); // 这里从全局根节点开始的再到左右节点

                    // 只要t不为空就行,至于left和right是否为空都入列
                    q.push(t->left);
                    q.push(t->right);
                }

                if (ans.size() == pow(2,height)-1)
                    break; // 通过二叉树的元素个数来控制
            };
            return ans;
        }
        
        vector<vector<int>> levelOrderTraversalNest(TreeNode* root){
            vector<vector<int>> ans;
            if (!root)
                return ans;
            queue<TreeNode*> q;
            TreeNode * t = root;
            q.push(t);
            while (!q.empty()){
                vector<int> k;
                int qSize = q.size(); // 注意qSize必须是开始固定的,不要在for语句里边用q.size()会出问题
                for(int i=0;i<qSize;i++){
                    t = q.front();
                    q.pop();
                    k.push_back(t->val); // 不用担心t是否为空
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right); // 因为只允许不为空的t进入队列
                }
                ans.push_back(k);
                k.clear();// 不同于python,python需要可以每次创建相同变量来存储每层元素,所以无需clear
                // C++中k定义后就不能重复定义,所以k要清除所有元素用于下一次使用
            }
            return ans;
        }
        
        vector<vector<int>> levelOrderTraversalNestWithNull(int height,TreeNode*root){
            vector<vector<int>> ans;
            if (!root){
                ans.push_back(vector<int> (-1));
                return ans;
            }
            queue<TreeNode*> q;
            TreeNode *t = root;
            q.push(t);
            while (!q.empty()){
                vector<int> k;
                int qSize = q.size();
                for(int i =0;i<qSize;i++){
                    t = q.front(); // t可以为空
                    q.pop();
                    if (!t){
                        k.push_back(-1); // -1代表None或者null的意思
                        q.push(nullptr);
                        q.push(nullptr); // 空节点的左右节点必定为空,直接+2个指针即可
                    }
                    else{ // t不为空
                        k.push_back(t->val);
                        q.push(t->left);
                        q.push(t->right); // 左右节点是否为空不重要,直接添加
                    }
                }
                ans.push_back(k);
                k.clear(); // k要清空用于下次使用
                if (flattenVector(ans).size() == pow(2,height)-1) // 注意是展平后的元素个数
                    break; // 通过二叉树的元素个数来控制
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
    auto ret11 = solution.levelOrderTraversal(&n1);
    for(size_t i =0;i<ret11.size();i++)
        cout<<ret11[i]<<"  "; // 不返回None且不嵌套
    cout<<"\n";
    cout<<"ret12: \n";
    auto ret12 = solution.levelOrderTraversalNest(&n1);
    for(size_t i=0;i<ret12.size();i++){
        for(size_t j=0;j<ret12[i].size();j++){
            cout<<ret12[i][j]<<" ";
        } 
        cout<<endl;    // 不返回None但是嵌套
    }

    /*
                1
            -1        2
        -1   -1    6     -1
    -1  -1 -1 -1 10  8 -1  -1
    */
    TreeNode y15(10);
    //TreeNode y14(8);
    TreeNode y13(8);
    TreeNode y12(10);
    //TreeNode y11(10);
    //TreeNode y10(8);
    //TreeNode y9(8);
    //TreeNode y8(10);
    //TreeNode y7(4,&y14,&y15);
    TreeNode y6(6,&y12,&y13);
    //TreeNode y5(6,&y10,&y11);
    //TreeNode y4(4,&y8,&y9);
    TreeNode y3(2,&y6,nullptr);
    //TreeNode y2(2,&y4,&y5);
    TreeNode y1(1,nullptr,&y3);
    cout<<"ret21: \n";
    auto ret21 = solution.levelOrderTraversalWithNull(4,&y1);
    cout<<"\n";
    for(size_t i =0;i<ret21.size();i++)
        cout<<ret21[i]<<"  "; // 返回None不嵌套
    cout<<"\nret22: \n";
    auto ret22 = solution.levelOrderTraversalNestWithNull(4,&y1);
    for(size_t i=0;i<ret22.size();i++){
        for(size_t j=0;j<ret22[i].size();j++){
            cout<<ret22[i][j]<<" ";
        } 
        cout<<endl;    // 返回None且嵌套
    }
}
#endif  // !binaryTreeLevelOrderQueue_