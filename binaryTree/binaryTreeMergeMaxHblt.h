/*** 
 * @Author: chenbei
 * @Date: 2022-02-17 13:14:46
 * @LastEditTime: 2022-03-15 11:16:08
 * @Description: merge two maxhblts by recursion
 * @FilePath: \myLeetCode\binaryTree\binaryTreeMergeMaxHblt.h
 * @A boy without dreams
 */
#ifndef binaryTreeMergeHblt_
#define binaryTreeMergeHblt_
#include "HbltNode.h"
#include <queue>
#include <iostream>
using namespace std;
class binaryTreeMergeHblt{
    public:
        void mergeHblt(HbltNode*& root1 , HbltNode*& root2){
            // 注:规定总会把root2合并到root1上
            if (root2 == nullptr) return;
            if (root1 == nullptr) {
                root1 = root2;
                return;
            }
            // 如果第1棵树的元素值<第2棵树的元素值,以第2棵树为基准树去合并第1棵树
            // 保证基准树总是为root1
            if (root1->node.second < root2->node.second) swap(root1,root2);

            mergeHblt(root1->right,root2); // 递归交换基准树的右子树和非基准树

            // 递归到树的最后1层时,root2不需要再看,基准树root1的节点可能有2种情况
            // 最大左高树不允许左节点为空节点但右节点非空,可以左右都非空或者右节点为空
            // 均为空的话不会执行到这,第1个if判断就已经返回
            if (root1->left == nullptr){
                root1->left = root1->right ; //右节点是非空节点
                root1->right = NULL; // 交换以后右节点是空节点
                root1->node.first = 1 ; // 右节点是非空节点,那么root作为父节点必然是编号1
            }
            else { // 都是非空节点,此时的root1还要满足左节点值大于右节点值
                // 必要的话交换2个节点
                cout<<"here:"<<root1->node.second
                    <<" "<<root1->left->node.second
                    <<" "<<root1->right->node.second<<"\n";
                if (root1->left->node.second < root1->right->node.second){
                    swap(root1->left,root1->right);
                }
                // 此时的root1作为父节点,其编号值应等于右路径的编号值+1
                root1->node.first = root1->right->node.first+1;
            }
        }
        void levelOrder(HbltNode* root){
            if (root == nullptr) return;
            queue<HbltNode*> q;
            HbltNode * t = root;
            while (t != nullptr)
            {
                cout<<"("<<t->node.first<<","<<t->node.second<<") "; // 层次遍历打印节点的编号值和元素值
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                if (! q.empty())
                    t = q.front();
                else break ;
                q.pop();
            }
            cout<<"\n";
        }
};
void _binaryTree_merge_maxHblt(){
    /*
    数据值:
    tree1:         tree2:             merge:
           9                 15               15
          / \               /              /      \
         8   7             7              9        7
        / \ / \           /  \           / \      / \
       6    5  4         3    1         8  7     3   1
           / \              /          /  / \       / 
          3   2            0          6  5   4     0
         /                              / \
        1                              3   2        
                                      /
                                     1
    编号值:  
    tree1:         tree2:             merge:
           2                 1                3
          / \               /               /   \
         1   2             2               2     2
        / \ / \           /  \            / \   / \
       1    2  1         1    1          1   2 1   1
           / \               /          /   / \   / 
          1   1             1          1   2   1 1   
         /                                / \   
        1                                1   1    
                                        /
                                       1
    */                                    
   HbltNode n1(1,1);             HbltNode n11(1,0);
   HbltNode n2(1,2);             HbltNode n12(1,1,&n11,nullptr);
   HbltNode n3(1,3,&n1,nullptr); HbltNode n13(1,3);
   HbltNode n4(1,4);             HbltNode n14(2,7,&n13,&n12);
   HbltNode n5(2,5,&n3,&n2);     HbltNode n15(1,15,&n14,nullptr);
   HbltNode n6(1,6);
   HbltNode n7(2,7,&n5,&n4);
   HbltNode n8(1,8,&n6,nullptr);
   HbltNode n9(2,9,&n8,&n7);
   
   binaryTreeMergeHblt solution;
   HbltNode* root1 = &n9;
   HbltNode* root2 = &n15;
   cout<<"root1's rank and data is\n";
   solution.levelOrder(root1);
   cout<<"root2's rank and data is\n";
   solution.levelOrder(root2);
   solution.mergeHblt(root1,root2);
   cout<<"after merge,root1's rank and data is\n";
   solution.levelOrder(root1);
}
#endif //!binaryTreeMergeHblt_