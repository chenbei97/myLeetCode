/*** 
 * @Author: chenbei
 * @Date: 2022-05-15 17:45:31
 * @LastEditTime: 2022-05-16 19:25:08
 * @Description: has_overlap.cpp 
 * @FilePath: \myLeetCode\myPleasure\myOpencv\cv_code_test-2.0A\src\has_overlap.cpp
 * @Signature: A boy without dreams
 */
#include "../include/point_on_line.h"
#include "../include/has_overlap.h"
/**
 * Project1: 计算两三角形是否有交集
 * 要求： 
 *  1） 计算给定两个三角形是否有交集
 *  2） 输出以bool结果给出
 *  3） 计算过程不可直接使用第三方库
 *  4） 除计算过程外，图像读取、显示、输出可使用第三方库
 *  5） 求取过程思路可在注释中说明
 * 注： 两个三角形仅有一边重合，或者仅有一个顶点重合或顶点落在边上，视为有交集情况
 * 输入： 三角形描述 [x1, y1, x2, y2, x3, y3]
 *       分别表示三角形三个顶点的坐标
 * 输出： 计算所有三角形是否有交集
 * */
bool has_overlap(int triangle1[6], int triangle2[6])
{
    // 1.事先计算出2个三角形,3条边的斜率和长度
    // 为了方便,事先使用[x1, y1, x2, y2, x3, y3]表示出2个三角形的顶点坐标
    // 下标1,表示第几个三角形，下标2,表示第几个点
    int x11 = triangle1[0],y11 = triangle1[1],
        x12 = triangle1[2],y12 = triangle1[3],
        x13 = triangle1[4],y13 = triangle1[5];
    int x21 = triangle2[0],y21 = triangle2[1],
        x22 = triangle2[2],y22 = triangle2[3],
        x23 = triangle2[4],y23 = triangle2[5];
    
    // 判断第2个三角形的第1个顶点在第1个三角形3条边的情况
    bool point21_on_line11 = point_on_line(x11,y11,x12,y12,x21,y21);
    bool point21_on_line12 = point_on_line(x12,y12,x13,y13,x21,y21);
    bool point21_on_line13 = point_on_line(x13,y13,x11,y11,x21,y21);

    // 判断第2个三角形的第2个顶点在第1个三角形3条边的情况
    bool point22_on_line11 = point_on_line(x11,y11,x12,y12,x22,y22);
    bool point22_on_line12 = point_on_line(x12,y12,x13,y13,x22,y22);
    bool point22_on_line13 = point_on_line(x13,y13,x11,y11,x22,y22);

    // 判断第2个三角形的第3个顶点在第1个三角形3条边的情况
    bool point23_on_line11 = point_on_line(x11,y11,x12,y12,x23,y23);
    bool point23_on_line12 = point_on_line(x12,y12,x13,y13,x23,y23);
    bool point23_on_line13 = point_on_line(x13,y13,x11,y11,x23,y23);

    // cout << "point21_on_line11: " << point21_on_line11 << " point21_on_line12: " << point21_on_line12 << " point21_on_line13: " << point21_on_line13 << endl;
    // cout << "point22_on_line11: " << point22_on_line11 << " point22_on_line12: " << point22_on_line12 << " point22_on_line13: " << point22_on_line13 << endl;
    // cout << "point23_on_line11: " << point23_on_line11 << " point23_on_line12: " << point23_on_line12 << " point23_on_line13: " << point23_on_line13 << endl;

    int sum = point21_on_line11 + point21_on_line12 + point21_on_line13 +
              point22_on_line11 + point22_on_line12 + point22_on_line13 +
              point23_on_line11 + point23_on_line12 + point23_on_line13;

    /*
      1、如果2个三角形重合,意味着顶点必定都在相邻2条边上而不在对向边,每个顶点有2个true和1个false,故sum=6
         /\
        /  \
       / _ _\
      2.如果是1条边重合,且2个三角形不是互相包含(第1个图),则有个顶点不在边上,另外2个顶点各自在2条边上,各有2个true,sum=4
        如果是包含关系(第3个图,第2个图不是对的),如果第2个三角形是小三角形则是2+0+2=4,是大三角形则是2+2+0=4
               _ _ _                                  
             /\    / it's ok         /\              /|\
            /  \  /            bad! /__\            / | \  it's ok
           /_ _ \/                 /    \          /   \ \
                                  /_ _ _ \        /      \\
                                                 /_ _ _ _ _\
      3. 如果只是1个顶点重合,或者顶点在1条边上,sum=2 或者 sum=1
        |\  /|              |\
        | \/ |              | \
        | /\ |              | /_ _ _ 
        |/  \|              |/\     /
                               \   /
                                \ /
     */
    if (sum == 1 || sum == 2 || sum == 4) return true;
    return false;
}