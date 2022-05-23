/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 15:31:50
 * @LastEditTime: 2022-05-23 17:05:48
 * @Description: test_matrix.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\test_matrix.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode\\yushiqi
g++ -o test_matrix test_matrix.cpp matrix.cpp
./test_matrix
*/
#include "matrix.h"
#include <random>
#include <iostream>
#include <chrono>
#define START_T std::chrono::steady_clock::now()
#define END_T std::chrono::steady_clock::now()
#define PRINT_TIME   std::cout << (std::chrono::duration<float>(END_T - START_T).count()) * 1000.0f \
            << " ms" << std::endl;
using namespace myMatrix;
int main(){
    const int rows = 20000; // 2万
    std::default_random_engine generator(100); // 随机种子
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    
    // 使用matrix随机生成2个二维矩阵
    Matrix * m1 = createMatrix(rows,rows);
    Matrix * m2 = createMatrix(rows,rows);
    START_T;
    for(int i = 0 ; i < rows * rows ; ++i){// 对m1,m2的data进行随机赋值
        m1->data[i] = distribution(generator);
        m2->data[i] = distribution(generator);
    }
    END_T;
    printf("createMatrix cost time: "); // 0 ms
    PRINT_TIME;
    // 对m1,m2进行矩阵乘法, 结果存储在m3中
    Matrix * m3 = createMatrix(rows,rows);
    // 输入数字来确定使用何种算法计算矩阵乘法
    int select;
    std::cout<<"please input the number to select the algorithm(0,1,2):"<<std::endl;
    std::cin>>select;
    switch(select){
        case 0:
            START_T;
            add(m1,m2,m3,select);
            END_T;
            printf("best verson => add cost time: ");
            PRINT_TIME;
            break;
        case 1:
            START_T;
            add(m1,m2,m3,select);
            END_T;
            printf("bad version 1 => cost time: ");
            PRINT_TIME;
            break;
        case 2:
            START_T;
            add(m1,m2,m3,select);
            END_T;
            printf("bad version 2 => cost time: ");
            PRINT_TIME;
            break;
        default:
            std::cout<<"input error!"<<std::endl;
            break;
    }
    std::cout<<"m1.data[rows*rows-1] = "<<m1->data[rows*rows-1] // 0 ms
    <<" m2.data[rows*rows-1] = "<<m2->data[rows*rows-1] // 0.0001ms
    <<" m3.data[rows*rows-1] = "<<m3->data[rows*rows-1]<<std::endl; // 0.0001ms
    return 0;
}