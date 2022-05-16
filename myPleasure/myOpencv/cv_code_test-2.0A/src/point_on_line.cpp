/*** 
 * @Author: chenbei
 * @Date: 2022-05-15 17:38:43
 * @LastEditTime: 2022-05-16 19:26:16
 * @Description: point_on_line.cpp
 * @FilePath: \myLeetCode\myPleasure\myOpencv\cv_code_test-2.0A\src\point_on_line.cpp
 * @Signature: A boy without dreams
 */
#include "../include/point_on_line.h"  // point_on_line
// 1个判断点(x,y)是否在2点(x1,y1),(x2,y2)构成的线段上的辅助函数
bool point_on_line(int x1,int y1,int x2,int y2,int x,int y){
    // 1.首先判断(x,y)是否满足直线方程
    // 2.满足直线方程的情况下,点还要在2点构成的线段上
    int condition = 0; // 非特殊情况
    if (x2 == x1) condition = 1; // 垂直线
    else if (y1 == y2) condition = 2;// 平行线
    switch (condition)
    {
        case 1: // 垂直线
            if (x == x1){ //点在垂线上要求x=x1或x=x2,同时y在[y1,y2]或[y2,y1]之间
                if (y1 < y2){
                    if (y1 <= y && y <= y2){
                        return true;
                    }
                }
                else{
                    if (y2 <= y && y <= y1){
                        return true;
                    }
                }
            }
            break;
        case 2: // 平行线
            if (y == y1){ // 点在平行线上要求y=y1或y=y2,同时x在[x1,x2]或[x2,x1]之间
                if (x1 < x2){
                    if (x1 <= x && x <= x2){
                        return true;
                    }
                }
                else{
                    if (x2 <= x && x <= x1){
                        return true;
                    }
                }
            }
            break;
        default: // 正常情况
            double k = ((double)y2 - (double)y1) / ((double)x2 - (double)x1); // 直线斜率
            double b = (double)y1 - k * (double)x1; // 直线截距
            if (abs((double)y - k * (double)x - b) < 1e-7) { //  判断点是否在直线上
                if (x1 < x2) { // 判断点是否在线段上,判断x或y坐标均可,这里判断x坐标
                    if (x1<=x && x<=x2) { // [x1,x,x2]
                        return true;
                    }
                }
                else {
                    if (x2<=x && x<=x1) { // [x2,x,x1]
                        return true;
                    }
                }
            }
            break;
    }
    return false;
}