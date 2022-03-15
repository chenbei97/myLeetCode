'''
Author: chenbei
Date: 2022-03-07 09:22:51
LastEditTime: 2022-03-15 11:07:42
Description: design an iterator of binarySearchTree by recursion
FilePath: \myLeetCode\binaryTree\binaryTreeInOrderSearchIterator_Recursion.py
A boy without dreams
'''
from TreeNode import TreeNode
class binaryTreeInOrderSearchIteratorRecursion:
    def __init__(self,root) -> None:
        self.arr = []
        self.__inOrder(root)
        self.idx = 0
    def __inOrder(self,root:TreeNode):
        if not root:return
        self.__inOrder(root.left)
        self.arr.append(root.val)
        self.__inOrder(root.right)
    def next(self)->int:
        next = self.arr[self.idx]
        self.idx += 1
        return next
    def hasNext(self)->bool:
        return self.idx<len(self.arr)
if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(4)
    root.right = TreeNode(5)
    root.right.right = TreeNode(7)
    iterator = binaryTreeInOrderSearchIteratorRecursion(root)
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(True if iterator.hasNext() else False)
