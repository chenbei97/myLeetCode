#include "binaryTree.h"
#include <iostream>
using namespace std;
int main()
{
    cout <<"preOrder as follows\n";
    _binaryTree_preOrder_morris();
    _binaryTree_preOrder_recursion();
    _binaryTree_preOrder_stack();

    cout <<"inOrder as follows\n";
    _binaryTree_inOrder_recursion();
    _binaryTree_inOrder_stack();
    _binaryTree_inOrder_morris();

    cout <<"postOrder as follows\n";
    _binaryTree_postOrder_recursion();
    _binaryTree_postOrder_morris();
    _binaryTree_postOrder_stack();

    cout <<"levelOrder as follows\n";
    _binaryTree_levelOrder_queue();
    _binaryTree_levelOrder_deque();

    cout <<"binaryTree is symmetric as follows\n";
    _binaryTree_isSymmetric_recursion();
    _binaryTree_isSymmetric_array(); 

    cout <<"tree2 is subStructure of tree1?\n";
    _binaryTree_isSubStructure_recursion();
    _binaryTree_isSubStructure_iteration();

    cout <<"tree2 is merged to tree1,tree1 is ?\n";
    _binaryTree_mergeCommonTree_recursion();
    _binaryTree_mergeCommonTree_stack();
    _binaryTree_mergeCommonTree_queue();
    cout <<"hblt2 is merged to hblt1,tree1 is ?\n";
    _binaryTree_merge_maxHblt();

    cout << "tree is complete?\n";
    _binaryTree_isComplete();

    cout<<"invert tree as follows\n";
    _binaryTree_invert_queue();
    _binaryTree_invert_stack();
    _binaryTree_invert_recursion();

    cout<<"tree's right view as follows\n";
    _binaryTree_rightView();

    cout <<"tree's all path as follows\n";
    _binaryTree_allPaths_recursion();
    _binaryTree_allPaths_stack();

    cout <<"tree's max depth as follows\n";
    _binaryTree_maxDepth_recursion();
    _binaryTree_maxDepth_stack();

    cout <<"tree's min depth as follows\n";
    _binaryTree_minDepth_recursion();
    _binaryTree_minDeth_stack();

    cout <<"tree's path sum as follows\n";
    _binaryTree_pathSum_recursion();
    _binaryTree_pathSum_stack();
    return 0;
}
