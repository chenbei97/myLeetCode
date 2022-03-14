from typing import List
import numpy as np
class linearArrayValidSudokuIteration:
    def isValidSudoku(self,board:List[List[int]]):
        # 初始化都是0个
        rows = np.zeros((9,9)) # 第1个9是表示统计board的9行,第2个9是表示1行9个数字需要统计
        cols = np.zeros((9,9)) # 第1个9统计board的9列,第2个9也是统计9个数字的占位符
        subBoxes = np.zeros((3,3,9)) # 这个9表示统计某个数字出现的占位符,3×3的每个格子依次代表board的9个3×3子宫格
        for i in range(len(board)):
            for j in range(len(board[0])):# 遍历每个board的元素
                # print(board[i][j],end=" ")
                if board[i][j]>0: # 不是空白元素
                    rows[i][board[i][j]-1] += 1 # 出现的数是board[i][j],它的位置还要-1,也就是1在位置0记录,9在位置8记录
                    cols[j][board[i][j]-1] += 1 # cols也是用1行来统计各数字
                    subBoxes[i//3][j//3][board[i][j]-1] += 1 # i/3和j/3是确定处于board的哪个子宫格,注意是除法,第3个维度是这个数的位置上+1
                    # subBoxes的每个格子来记录board的每个子宫格同一数字出现的次数,位置由board[i][j]-1决定
                    # 计算完毕后判断次数是否>1,大于说明重复了
                    if rows[i][board[i][j]-1] > 1 or \
                       cols[j][board[i][j]-1] > 1 or \
                       subBoxes[i//3][j//3][board[i][j]-1] > 1:
                       return False
        return True
        
if __name__ == '__main__':
    # 用0代替空白也可以,因为数独要求是[1,9]的数字
    board = [[5,3,-1,-1,7,-1,-1,-1,-1],
             [6,-1,-1,1,9,5,-1,-1,-1],
             [-1,9,8,-1,-1,-1,-1,6,-1],
             [8,-1,-1,-1,6,-1,-1,-1,3],
             [4,-1,-1,8,-1,3,-1,-1,1],
             [7,-1,-1,-1,2,-1,-1,-1,6],
             [-1,6,-1,-1,-1,-1,2,8,-1],
             [-1,-1,-1,4,1,9,-1,-1,5],
             [-1,-1,-1,-1,8,-1,-1,7,9]]
 
    solution = linearArrayValidSudokuIteration()
    print(True if solution.isValidSudoku(board) else False)