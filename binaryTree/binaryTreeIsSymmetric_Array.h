/*** 
 * @Author: chenbei
 * @Date: 2022-02-14 07:58:04
 * @LastEditTime: 2022-03-15 11:12:03
 * @Description: judge an tree is symmetric by array
 * @FilePath: \myLeetCode\binaryTree\binaryTreeIsSymmetric_Array.h
 * @A boy without dreams
 */
#ifndef binaryTreeIsSymmetricArray_
#define binaryTreeIsSymmetricArray_
#include <vector>
#include <math.h>
#include <queue>
#include "TreeNode.h"
#include <iostream>
class binaryTreeIsSymmetricArray{
    public:
    // 不同于python,None可以被作为对象添加进ans,C++返回的nullptr必须指定指定的数来替代这个位置
    // value一般和二叉树的元素值不重复,但即使重复并不会改变结果
    vector<int> levelOrderTraversalWithNull(int height,int value,TreeNode* root){
            vector<int>  ans ;
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
                    ans.push_back(value); // 遇到空节点保存指定值value
                }
                else 
                {
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
    bool isSymmetric(int height,int value,TreeNode*root){
        vector<int> Array = levelOrderTraversalWithNull(height,value,root);
        Array.insert(Array.begin(),-1);// 插入1个元素是为了下标从1开始计算 此时列表为偶数2^height个
        for(int i=0 ; i<height;i++){
            int j1 = pow(2, i);
            int j2 = pow(2, i + 1) - 1;
            while (j1 <= j2){ // 小区间[2^i,2^(i+1)-1]对称进行比较,前索引小于等于后索引说明没比完继续比
                if (Array[j1] !=value && Array[j2] != value)  // 均不为空位置的值继续判断值是不是相等
                    if (Array[j1] != Array[j2])
                        return false;
                    else{
                        j1 += 1 ;// 均不为空且值相等继续比较下一组
                        j2 -= 1;
                    }

                else  // 可能有1个不为空也可能全为空
                    if (Array[j1] == value or Array[j2] == value)  // 有1个为空另一个不为空
                        return false;
                    else{ // 均为空
                        j1 += 1; // 均为空也继续下一组
                        j2 -= 1;
                    }
            }
        }
        return true;
    }
};
void _binaryTree_isSymmetric_array()
{
    binaryTreeIsSymmetricArray solution;
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
    auto ret2 = solution.levelOrderTraversalWithNull(4,-1,&y1);
    // for(size_t i =0;i<ret2.size();i++)
    //     cout<<ret2[i]<<"  ";
    // cout<<"\n";
    bool res = solution.isSymmetric(4,-1,&y1);
    cout <<"tree is symmetric? "<<res<<endl;

    TreeNode * root = new TreeNode [7];
    root[0].left = &root[1];root[0].right = &root[2];root[0].val = 1;
    root[1].left = &root[3];root[1].right = &root[4];root[1].val = 2;
    root[2].left = &root[5];root[2].right = &root[6];root[2].val = 2;
    root[3].val = 3;root[4].val = 4;
    root[5].val = 4;root[6].val = 3; // 1,2,2,3,4,5,3的二叉树结构
    res = solution.isSymmetric(3,-1,root);
    cout <<"tree is symmetric? "<<res<<endl;
}
#endif // !binaryTreeIsSymmetricArray_