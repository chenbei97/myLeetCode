/*** 
 * @Author: chenbei
 * @Date: 2022-02-21 10:05:06
 * @LastEditTime: 2022-03-15 11:05:09
 * @Description: find binaryTree all paths by stack
 * @FilePath: \myLeetCode\binaryTree\binaryTreeAllPaths_Stack.h
 * @A boy without dreams
 */
#ifndef binaryTreeAllPathsStack_
#define binaryTreeAllPathsStack_
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include "TreeNode.h"
using namespace std;
class binaryTreeAllPathsStack{
    public:
        vector<string> allPaths(TreeNode * root){
           vector<string> ans;
           if (!root) return ans;
           stack<pair<TreeNode*,string>> stk; // 保存每个遍历过的节点指针及其路径,栈顶元素是当前节点和当前路径
           TreeNode * p = root; // 定义一个当前节点的指针,目前指向root
           string path ; // 到当前节点的路径
           while ( p || !stk.empty()){ // p可能是右方向的节点,也可能是空节点
           // 如果是空节点不会执行二级while,会继续路径退栈更新p指向栈顶元素,返回到上一父节点
           // 然后判断是否为完整路径,是则添加路径,不是p更新为p的右节点
           // 如果p还是空节点会重新指向栈顶,此时的栈顶元素是上一次退栈后的栈顶,然后继续退栈
           // 极端的情况下会一路退到栈中不再有路径,一级while循环也就退出了,程序也退出

           // 如果是右方向的节点,就会进入二级while循环,找到以它为父节点的最左路径,直到最左路径结束while退出
           // 遇到空节点的时候就会退回到上一级父节点(即路径出栈),观察右节点的情况,右节点为空说明一条完整的路径结束,添加这个路径
           // 无论右节点是不是为空都会更新p到右节点回到一级while循环来判断,这个情况已经描述过
           // 极端的情况下,每次更新的右节点都不为空,那么总会路径分叉尝试找到这个右节点的最左路径直到两个子节点都为空才会有退栈操作
                while (p){
                    if (p == root) //p首次指向root时因为还没有路径,无需箭头→
                        path += to_string(p->val); // 添加当前节点路径
                    else 
                        path = path + "->" + to_string(p->val); // 如果p不是首次,后续的路径都是加→
                    stk.push(pair<TreeNode*,string>(p,path)); // 添加这个节点路径
                    p = p->left; // 每个非空节点都是先找最左路径
                }
                // 如果p是空节点,会尝试p的兄弟节点,p需要先返回到上一级节点
                p = stk.top().first; // 此时回到上一级父节点
                path = stk.top().second; // 路径回到上一级
                stk.pop(); // 记得退栈
                if (! p->left && !p->right) // 父节点的左节点已经是空节点,右节点也是空说明是一条完整路径了
                    ans.push_back(path); // 添加这个路径
                p = p->right ; // 无论右节点是否为空均更新交由一级while去判断
                // if (p) cout<<"("<<p->val<<","<<ans.size()<<") ";
                // else cout<<"(null,"<<ans.size()<<") ";
           }
           return ans; // 一级while退出说明路径不能再退回了,全局根节点都已经删除
        }
};
void _binaryTree_allPaths_stack(){
    binaryTreeAllPathsStack solution;
    // TreeNode * root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->left->left->right = new TreeNode(10);
    // root->right->left->left = new TreeNode(11) ;
    // root->right->left->left->right = new TreeNode(12) ;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
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
#endif // !binaryTreeAllPathsStack_