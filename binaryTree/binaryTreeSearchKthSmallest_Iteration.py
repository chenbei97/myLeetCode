from TreeNode import TreeNode
class binaryTreeSearchKthSmallestIteration:
    def __init__(self,root) -> None:
        self.subNodeNum = {} # 字典存储,键是node的地址,值是它和它的子节点数量
        self.root = root
        self._count_node_num(root) # 把self.subNodeNum初始化,所有节点都计算了数目
    def kthSmallest(self,k: int) -> int:
        node = self.root
        while node:
            subNum = self._get_node_num(node.left) # 计算的是node.left的节点数
            if subNum+1< k: #  subNum加上node有n+1个节点,比k小,只能从右子树找
                node = node.right 
                k = k-subNum-1 # node+node的左子树共subNum+1个节点,在右子树寻找时应该找以它为根节点第k-subNum-1小的元素
            elif subNum == k-1 : # 说明第k小就是节点node.left
                return node.val
            else: node = node.left # 子节点数大于k-1,算上node＞k,说明第k小在左子树
    def _count_node_num(self,node:TreeNode)->int: # 计算节点node的子节点数量
        if not node: # 空节点返回0
            return 0
        self.subNodeNum[node] = self._count_node_num(node.left)+\
            self._count_node_num(node.right)+1 # node也算1个节点
        return self.subNodeNum[node]
    def _get_node_num(self,node:TreeNode)->int: #获取指定节点node的子节点数量
        return self.subNodeNum[node] if node else 0
    def printNodeNum(self):
        for key,value in self.subNodeNum.items():
            print(f"key = {key.val} num = {value}",end=" => ")
        print()

if __name__ == '__main__':
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    solution = binaryTreeSearchKthSmallestIteration(root)
    solution.printNodeNum()
    print("iteration: the smallest k element is ",solution.kthSmallest(5))