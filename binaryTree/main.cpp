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

<<<<<<< HEAD
    cout <<"levelOrder as follows\n";
    _binaryTree_levelOrder_queue();

    cout <<"binaryTree is symmetric as follows\n";
    _binaryTree_is_symmetric_recursion();
    _binaryTree_isSymmetric_array(); // 暂时无法解决层次遍历有nullptr打印-1的机制
=======
    _binaryTree_is_symmetric();
>>>>>>> 298375c1307d333d7c3c2d275d23d645be929bf1
    return 0;
}