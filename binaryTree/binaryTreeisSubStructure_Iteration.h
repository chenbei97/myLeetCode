#ifndef binaryTreeisSubStructureIteration_
#define binaryTreeisSubStructureIteration_
#include "TreeNode.h"
#include <vector>
#include <queue>
#include <deque>
#include <iostream>
using namespace std ;
class binaryTreeisSubStructureIteration{
    public :bool isSubStructure(TreeNode*tree1,TreeNode*tree2){
            Order.clear(); // 防止同一个solution下次重复添加
            levelOrder(tree1);
            if (tree1 && tree2){ // 前提2个都是非空节点才可以比较
                vector<TreeNode*> p = searchSameNode(tree1,tree2->val);// 尝试寻找相等的节点
                // 层次遍历可以避免左子树不存在但右子树存在sameNode的情况检测不出来而被漏过
                if (p.size() != 0){ // 说明确实存在合适的相等节点去筛选
                    bool res = false ;
                    for (size_t i = 0 ; i<p.size() ;i++ ){
                        cout<<"p[i] = "<<p[i]<<endl;
                        res = compareSubtree(p[i],tree2);
                        if (res) return true; // 如果有节点满足了就不要进行下一次遍历了
                    }
                }
            }
            return false; // 有非空节点或者均不为空但是for循环结束都没有为true的返回false
    }
    int getCount(){return count;}
    protected:
        int count = 0; // 必须有个数初始化否则会出错
        vector<TreeNode*>Order;
        void levelOrder(TreeNode* root){
                queue<TreeNode*> q;
                TreeNode *t = root;
                while (t!=nullptr)
                {
                    Order.push_back(t);
                    if (t->left != nullptr)
                        q.push(t->left);
                    if (t->right != nullptr)
                        q.push(t->right);
                    if (!q.empty()) t = q.front();
                    else return;
                    q.pop();
                }
        }
        vector<TreeNode*> searchSameNode(TreeNode*subtree,int val){
                vector<TreeNode*>  p ;
                if (subtree == nullptr) return p; // 如果遇到的是空节点,层次遍历的下一个也必定是空节点
                if (Order.size() == 0) return p; // 说明tree1没有元素
                for(size_t i = 0 ; i< Order.size();i++){
                    if (Order[i]->val == val){ // 找到tree1层次遍历所有和tree2首节点相等的节点
                        p.push_back(Order[i]);
                    }
                }
                return p; // 返回存储满足条件的节点容器
            }
        
        // https://blog.csdn.net/Haiqiang1995/article/details/79185622?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2~default~OPENSEARCH~Rate-4.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~OPENSEARCH~Rate-4.pc_relevant_default&utm_relevant_index=9
        // 这个网站提供的方法是错的,如果用main中的案例,当遍历到tree1的5和tree
        //bool searchSameNode(TreeNode*root1,TreeNode*root2){
            //bool res = false; // 如果能够找到就返回true,否则其它任何情况都是false
            // if (root1 != nullptr && root2 !=nullptr)
            // { // 只有2个节点都不为空才可能有这样的子树
            //     if (root1->val == root2->val){ // 且2个节点的值一样才能以这个节点为基础继续寻找,否则其它任何情况也都是false
            //         res = compareSubtree(root1,root2); // 返回寻找的结果
            //         if (!res){ // 如果没找到,尝试左子树和第2棵树,是否存在错位子树
            //             res = compareSubtree(root1->left,root2);
            //         }
            //         if (!res){ // 还没找到,尝试右子树和第2棵树,是否存在错位子树
            //             res = compareSubtree(root1->right,root2); // 无论结果如何都直接返回了
            //         }
            //     }      
            // }
           // return res;    
        //}
        bool compareSubtree(TreeNode*r1,TreeNode*r2){
            // 下边2个条件主要是用于compareSubTree再次调用自身的时候判断
            // 现在给出3种调用情况的分析,即(r1,r2),(r1.left,r2),(r1.right,r2)

            // 第1次进入时如果是r1,r2,均不为空且相等已满足,直接就进入下一次调用
            // 如果均不为空但是不相等返回false?应当尝试r1的下一个节点和r2
            // 即r1.left和r2.left and r1.right和r2.right的比较 相当于进入相等的节点下一级,比较是否各自对应相等
            // 能够再次进入下次调用说明下一级的所有节点2棵树确实相等,那就需要比较下下级，如此类推
            // 直到r2结束,一般是第1棵树层次大于等于第2棵树,如果r2为空,说明第1棵树存在这样的子树
            // 如果r2还没结束,r1先结束就返回false,不存在这样的子树
            
            // 第1次进入r1.left和r2时,r2肯定不为空,r1.left可能为空也可能不会;
            // 如果r1.left为空,说明第1棵树已经结束,但r2没结束,不存在这样的子树
            // 如果r1.left不为空,比较值是否相等,如果相等,第1棵树的这个节点是和r2相等的,只是不在一个层
            // 那么就进入下一次递归,对2棵树错位级的所有节点进行比较,即第1棵树的下一级和第2棵树的当前级所有节点比较
            // 后面思路类似,直到r2结束,如果r2先结束说明存在这样的子树,r1先结束不存在这样的子树
            // 都没结束就进入第1棵树的下下级和第2棵树的下级所有节点的比较

            // 第1次进入r1.right和r2时,和第1次进入r1.left和r2的情况一样,都是2棵树错位级的所有节点进行比较
            count++;
            if (!r2) return true; // 为空返回true
            if (!r1) return false;// 为空返回false
            if (r1->val != r2->val) return false; // 均不为空还要比较下值,不相等返回false
            return compareSubtree(r1->left,r2->left) && compareSubtree(r1->right,r2->right);
        }
};
void _binaryTree_isSubStructure_iteration(){
    binaryTreeisSubStructureIteration solution;
    /*
         3      2     3(不爆栈) 
        / \      \   /      
       4   5     7   4       
     /  \       /     \                  
    1    2     10      3   
          \
           7
          /
         10     
    */
    TreeNode * root1 = new TreeNode (3); // 必须分配空间,否则后面root1->left = new TreeNode(4)会报错
    root1->left = new TreeNode(4); // 因为这个指针不知道是指向数组名还是单个对象地址
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode (1);
    root1->left->right = new TreeNode (2);
    root1->left->right->right = new TreeNode(7);
    root1->left->right->right->left = new TreeNode(10);

    TreeNode * root2 = new TreeNode(2); // 先分配空间
    root2->right = new TreeNode (7);
    root2->right->left = new TreeNode (10);

    TreeNode * root3 = new TreeNode(3);// 先分配空间
    root3->left = new TreeNode (4);
    root3->left->right = new TreeNode (3);
    cout<<"--------------------------------------\n";
    bool res1 = solution.isSubStructure(root1,root2);
    cout<<"tree2 is subStructure of tree1 ? ans is "<<res1<<"\n";
    cout <<"recursion times = "<<solution.getCount()<<"\n";
    cout<<"--------------------------------------\n";
    bool res2 = solution.isSubStructure(root1,root3);
    cout<<"tree3 is subStructure of tree1 ? ans is "<<res2<<"\n";
    cout <<"recursion times = "<<solution.getCount()<<"\n";
}   
#endif //!binaryTreeisSubStructureIteration_