'''
Author: chenbei
Date: 2022-02-17 15:01:48
LastEditTime: 2022-03-15 11:22:41
Description: HbltNode.py
FilePath: \myLeetCode\binaryTree\HbltNode.py
A boy without dreams
'''
from TreeNode import TreeNode
class HbltNode(TreeNode):
    def __init__(self, number = 1 or None,val=0 or None, left=None, right=None):
        super().__init__(val, left, right)
        self.val = val
        self.number = number
        self.left = left
        self.right = right