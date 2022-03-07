from TreeNode import TreeNode
class binaryTreeInOrderSearchIteratorStack:
    def __init__(self,root) -> None:
        self.arr = []
        self.__inOrder(root)
        self.idx = 0
    def __inOrder(self,root:TreeNode):
        stk = []
        while root or len(stk)!=0:
            if root :
                stk.append(root)
                root = root.left
            else :
                root = stk[-1]
                stk.pop()
                self.arr.append(root.val)
                root = root.right
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
    iterator = binaryTreeInOrderSearchIteratorStack(root)
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(True if iterator.hasNext() else False)
