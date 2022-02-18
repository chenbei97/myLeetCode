from TreeNode import TreeNode
class HbltNode(TreeNode):
    def __init__(self, number = 1 or None,val=0 or None, left=None, right=None):
        super().__init__(val, left, right)
        self.val = val
        self.number = number
        self.left = left
        self.right = right