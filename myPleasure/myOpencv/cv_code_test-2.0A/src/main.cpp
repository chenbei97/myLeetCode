/****************************************************************
 * Test example
 * /******************************
 * 注：除程序中注明不能使用第三方库外，其他操作推荐使用opencv
 * © Yihang.ai
 * Version : 1.6A
 ******************************/
#include "include/bilateral_filter.h"
#include "include/has_overlap.h"
#include "include/point_on_line.h"
#include "include/calc_homography.h"
int main(int argc, char **argv)
{
    
    //// 普通情况测试
    //cout << boolalpha << "(-1,-1) is on y=2x+1 && inline? " << point_on_line(-3, -5, 5, 11, -1, -1) << endl; // 点在直线上且在线段上
    //cout << boolalpha << "(6,13) is on y=2x+1 && inline? " << point_on_line(-3, -5, 5, 11, 6, 13) << endl; // 点在直线不在线段上
    //cout << boolalpha << "(-1,0) is on y=2x+1? " << point_on_line(-3, -5, 5, 11, -1, 0) << endl; // 不在直线上
    //// 平行线测试
    //cout << boolalpha << "(-1,1) is on y=1&& inline? " << point_on_line(-3, 1, 5, 1, -1, 1) << endl;// 点在直线上且在线段上
    //cout << boolalpha << "(-5,1) is on y=1&& inline? " << point_on_line(-3, 1, 5, 1, -5, 1) << endl; // 点在直线不在线段上
    //cout << boolalpha << "(-1,2) is on y=1&& inline? " << point_on_line(-3, 1, 5, 1, -1, 2) << endl; // 点在直线不在线段上
    //// 垂直线测试
    //cout << boolalpha << "(-5,3) is on x=1&& inline? " << point_on_line(-5, 1, -5, 8, -5, 3) << endl;// 点在直线上且在线段上
    //cout << boolalpha << "(-5,9) is on x=1&& inline? " << point_on_line(-5, 1, -5, 8, -5, 9) << endl; // 点在直线不在线段上
    //cout << boolalpha << "(-4,2) is on x=1&& inline? " << point_on_line(-5, 1, -5, 8, -4, 2) << endl; // 点在直线不在线段上

    // Project1
    printf("========= Project1 =============== \n");
    int tri[5][6] = {
        {100, 200, 305, 105, 100, 25},  // triangle in
        {86, 192, 100, 150, 102, 75},
        {200, 260, 160, 100, 201, 300},
        {150, 100, 50, 60, 300, 60},
        {260, 200, 150, 60, 80, 100}
    };
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            printf("Overlap [%d][%d] = %d\n", i, j, has_overlap(tri[i], tri[j]));
        }        
    }
    // Project2   
    printf("\n========= Project2 =============== \n");
    char out_img_name[256]; 
    for (int k = 0; k < 5; k++) // generate 5 filter parameters
    {
        memset(out_img_name, 0, sizeof(out_img_name));
        int sig_c = rand() % 50;
        int sig_s = rand() % 50;
        sprintf(out_img_name, "pro2_out_c%d_s%d.png", sig_c, sig_s);
        bilateral_filter("project2.png",out_img_name,k,sig_c, sig_s); 
    }
   
    //Project3
    printf("\n========= Project3 =============== \n");
    int pts1[4][2] = {
        {20, 45},
        {30, 600},
        {560, 650},
        {550, 30}
    };
    int pts2[4][2] = {
        {10, 15},
        {400, 560},
        {450, 600},
        {560, 20}
    };

    int pts2_in[][2] = {
        {15, 25},
        {35, 67},
        {100, 200},
        {300, 560}
    };
    int pts1_out[4][2];
    calc_homography(pts1, pts2, pts2_in, pts1_out);
    return 0;
}
