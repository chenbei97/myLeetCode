/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 15:00:35
 * @LastEditTime: 2022-05-23 16:45:06
 * @Description: matrix.h
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\matrix.h
 * @Signature: A boy without dreams
 */
#ifndef _MATRIX_H
#define _MATRIX_H
#include <stdbool.h>
#include <cstddef>
namespace myMatrix{
typedef struct Matrix_{
    size_t rows;
    size_t cols;
    float * data; // 一维数据内存连续效率较高
} Matrix; 
// 定义几个全局函数
Matrix * createMatrix(size_t rows,size_t cols);
bool releaseMatrix(Matrix * matrix);
bool add(const Matrix * lhs,const Matrix * rhs,Matrix * output,int select = 0);
}
#endif