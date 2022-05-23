/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 15:04:34
 * @LastEditTime: 2022-05-23 17:07:51
 * @Description: matrix.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\Matrix.cpp
 * @Signature: A boy without dreams
 */
#include <stdlib.h>
#include <stdio.h>
// #include <iostream>
#include "matrix.h"
using namespace myMatrix;
myMatrix::Matrix * myMatrix::createMatrix(size_t rows,size_t cols){
    myMatrix::Matrix * p = nullptr;
    if (rows == 0 || cols == 0){
        fprintf(stderr,"rows or cols is 0\n");
        return nullptr;
    }
    p = (myMatrix::Matrix *)malloc(sizeof(myMatrix::Matrix)); // 分配空间
    if (p == nullptr){
        fprintf(stderr,"malloc failed for a matrix\n");
        return nullptr;
    }
    p->rows = rows;
    p->cols = cols;
    p->data = (float *)malloc(rows * cols * sizeof(float)); // 分配空间
    if (p->data == nullptr){
        fprintf(stderr,"malloc failed for the matrix data\n");
        free(p);
        return nullptr;
    }
    return p;
}
bool releaseMatrix(myMatrix::Matrix * matrix){
    if (matrix == nullptr){
        fprintf(stderr,"matrix is nullptr\n");
        return false;
    }
    if (matrix->data != nullptr){
        free(matrix->data);
        matrix->data = nullptr;
    }
    free(matrix);
    return true;
}
void bad_add_verson_1(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output);
void bad_add_verson_2(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output);
void best_add_version(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output);
bool myMatrix::add(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output,int select){
    // 首先判断传入的指针和指针指向的数据是否为空
    if (lhs == nullptr){
        fprintf(stderr,"File %s, Line %d, Function %s(): The 1st parameter is nullptr.\n",
        __FILE__,__LINE__,__FUNCTION__);
        return false;
    }
    else if (lhs->data == nullptr){
        fprintf(stderr,"%s(): The 1st pparameter has no valid data.\n",__FUNCTION__);
        return false;
    }
    if (rhs == nullptr){
        fprintf(stderr,"File %s, Line %d, Function %s(): The 2nd parameter is nullptr.\n",
        __FILE__,__LINE__,__FUNCTION__);
        return false;
    }
    else if (rhs->data == nullptr){
        fprintf(stderr,"%s(): The 2nd pparameter has no valid data.\n",__FUNCTION__);
        return false;
    }
    // 继续判断传入的矩阵行列是否符合要求
    if (lhs->rows != rhs->rows || lhs->rows != output->rows ||
        lhs->cols != rhs->cols || lhs->cols != output->cols){
            fprintf(stderr,"The matrix rows or cols is not equal.\n");
            fprintf(stderr,"Their sizes are(%zu,%zu),(%zu,%zu) and (%zu,%zu)\n",
                lhs->rows,lhs->cols,
                rhs->rows,rhs->cols,
                output->rows,output->cols);
        return false;
    }
    // 开始计算,下方的示例是1个不太好的示例
    switch (select)
    {
        case 1:
            bad_add_verson_1(lhs,rhs,output);// 不好,运算速度慢耗时
            break;
        case 2:
            bad_add_verson_2(lhs,rhs,output);// 比第1个版本快
            break;
        default:
            best_add_version(lhs,rhs,output);// 最好,运算速度快
            break;
    }
    return true;
}
// 第1个bad的版本
void bad_add_verson_1(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output){
    for (size_t i = 0;i < lhs->rows;i++){
        for (size_t j = 0;j < lhs->cols;j++){
            output->data[i * lhs->cols + j] = 
            lhs->data[i * lhs->cols + j] + 
            rhs->data[i * lhs->cols + j];
        }
    }
}
// 第2个bad的版本
void bad_add_verson_2(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output){
    for(size_t row = 0; row<lhs->rows;++row){
        const float * p1 = lhs->data + row * lhs->cols; // 获取第row行的指针,data指向最开头,row * lhs->cols相当于是step
        const float * p2 = rhs->data + row * rhs->cols;
        float * p3 = output->data + row * output->cols;
        for (size_t col = 0; col<lhs->cols;++col){
            *p3++ = *p1++ + *p2++; // 行指针的运算速度比纯粹的遍历索引要快
        }
    }
}
// 速度最快的版本
void best_add_version(const myMatrix::Matrix * lhs,const myMatrix::Matrix * rhs,myMatrix::Matrix * output){
    size_t length = lhs->rows * lhs->cols; // 获取一维数组的长度
    const float * p1 = lhs->data; // 获取数据指针
    const float * p2 = rhs->data; 
    float * p3 = output->data;
    for (size_t i = 0;i < length;i++){ // 一次for循环,也就是无需看成多行指针,内存是连续的就是一维数组对应数据相乘即可
        // std::cout<<"i = "<<i<<std::endl;
        *p3++ = *p1++ + *p2++; // 连续内存速度最快
    }
}