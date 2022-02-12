from typing import Optional
from typing import List
from queue import Queue
from queue import Empty
from TreeNode import TreeNode
class binaryTreeIsSymmetric_Array:
    def levelOrderTraversalWithNone(self,height,root: Optional[TreeNode] ) -> List[List[int]]:
        ans = []
        q = Queue()
        q.put_nowait(root)
        while not q.empty() : # root最终会更新到队列为空为止
            try:
                root = q.get_nowait()  # 队首元素出列(首次是根)
            except Empty:
                break
            ans.append(root.val if root else None)
            # print(ans)
            q.put_nowait(root.left if root else None) # 左节点入列
            q.put_nowait(root.right if root else None) # 右节点入列
            if len(ans) == pow(2,height)-1:
                break
        return ans
    def isSymmetric(self,height,root: Optional[TreeNode]) -> bool:
        treeArray = self.levelOrderTraversalWithNone(height,root) # 层次遍历得到元素
        treeArray.insert(0,"head") # 插入1个元素是为了下标从1开始计算 此时列表为偶数2^height个
        if len(treeArray[1:]) % 2:  # 是奇数才可能对称
            for i in range(height):
                j1 = pow(2, i)
                j2 = pow(2, i + 1) - 1
                print(j1,j2)
                while j1 <= j2: # 小区间[2^i,2^(i+1)-1]对称进行比较,前索引小于等于后索引说明没比完继续比
                    if (treeArray[j1] and treeArray[j2]):  # 均不为空继续判断值是不是相等
                        if (treeArray[j1] != treeArray[j2]):
                            return False
                        else:
                            j1 += 1 # 均不为空且值相等继续比较下一组
                            j2 -= 1
                    else:  # 可能有1个不为空也可能全为空
                        if (treeArray[j1] or treeArray[j2]):  # 有1个为空另一个不为空
                            return False
                        else:  # 均为空
                            j1 += 1 # 均为空也继续下一组
                            j2 -= 1
        else:
            return False
        return True
if __name__ == '__main__':
    s = binaryTreeIsSymmetric_Array()
    # 8,9,14,15是对称的,为了验证None是否能够检查
    # 这4个节点修改为None
    n15 = TreeNode(10)
    n14 = TreeNode(8)
    n13 = TreeNode(8)
    n12 = TreeNode(10)
    n11 = TreeNode(10)
    n10 = TreeNode(8)
    n9 = TreeNode(8)
    n8 = TreeNode(10)
    n7 = TreeNode(4,n14,n15)
    n6 = TreeNode(6,n12,n13)
    n5 = TreeNode(6,n10,n11)
    n4 = TreeNode(4,n8,n9)
    n3 = TreeNode(None,n6,n7)
    n2 = TreeNode(None,n4,n5)
    root = TreeNode(1,n2,n3)
    print(s.levelOrderTraversalWithNone(4,root))
    print(s.isSymmetric(4,root))