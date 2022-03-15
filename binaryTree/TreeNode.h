/*** 
 * @Author: chenbei
 * @Date: 2022-02-14 07:58:04
 * @LastEditTime: 2022-03-15 10:28:42
 * @Description: TreeNode.h
 * @FilePath: \myLeetCode\binaryTree\TreeNode.h
 * @A boy without dreams
 */
#ifndef TreeNode_
#define TreeNode_
using namespace std;
struct TreeNode 
  {
      int val;
      TreeNode *left;     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif //!TreeNode_