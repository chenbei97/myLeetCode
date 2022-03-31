/*** 
 * @Author: chenbei
 * @Date: 2022-03-31 10:40:31
 * @LastEditTime: 2022-03-31 16:28:15
 * @Description: linearArraySpiralMatrix_Iteraton.h
 * @FilePath: \myLeetCode\linearArray\linearArraySpiralMatrix_Iteraton.h
 * @A boy without dreams
 */
#ifndef linearArraySpiralMatrixIteraton_
#define linearArraySpiralMatrixIteraton_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class linearArraySpiralMatrixIteraton{
    public:
        vector<int> spiralMatrix(vector<vector<int>>&nums){
            // 思路是从外边一圈到次一圈直到最后1圈(只有1个数)
            // 关键就是获取每个圈的4个顶点坐标
            // 因为每圈遍历总是符合这样的遍历过程
            // [top,left]->[top,right]-> // top行
            // ->[top+1,right]->[bottom,right]-> // right列
            // ->[bottom,right-1]->[bottom,left]-> // bottom行
            // ->[bottom-1,left]->[top,left] // left列
            // 进入下一圈时也就是还没回到[top,left]要及时让top+1,left+1,right-1和bottom-1
            vector<int> ans;
            int rows = nums.size();//行数
            int cols = nums[0].size();//列数
            int top=0,bottom=rows-1,left=0,right=cols-1;//最外圈的位置
            while (top<=bottom && left<=right){ //相等时也要执行,此时只有1个数
                for(int col=left;col<=right;++col)
                    ans.push_back(nums[top][col]);//遍历top行
                for(int row=top+1;row<=bottom;++row)
                    ans.push_back(nums[row][right]);//遍历right列
                if (left<right && top<bottom){// 这个判断条件是用于防止不对称矩阵时(rows≠cols)多添加元素
                    for (int col=right-1;col>=left;--col) // 遍历bottom行
                        ans.push_back(nums[bottom][col]);
                    for(int row=bottom-1;row>top;--row)// 遍历left列
                        ans.push_back(nums[row][left]); // 注意回到[top,left]不要重复添加,故是row>top而不是≥  
                }
                ++top;--bottom;
                ++left;--right;
            }
            return ans;
        }
};
void _linearArray_spiralMatrix_iteraton(){
    linearArraySpiralMatrixIteraton solution;
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto ans = solution.spiralMatrix(nums);
    ostream_iterator<int> os(cout," ");
    // [1,2,3,4,8,12,11,10,9,5,6,7]
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!linearArraySpiralMatrixIteraton_