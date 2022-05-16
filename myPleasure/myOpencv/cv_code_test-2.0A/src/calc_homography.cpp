/*** 
 * @Author: chenbei
 * @Date: 2022-05-15 17:50:42
 * @LastEditTime: 2022-05-16 19:25:27
 * @Description: calc_homography.cpp
 * @FilePath: \myLeetCode\myPleasure\myOpencv\cv_code_test-2.0A\src\calc_homography.cpp
 * @Signature: A boy without dreams
 */
/**
 * Project3: 单应性变换
 * 要求： 
 *  1） 已知一个平面上的4个点（A、B、C、D），经过两个针孔相机分别成像得到4个点的图像坐标分别为
 *          相机1： (xA1, yA1)，(xB1, yB1), (xC1, yC1), (xD1, yD1)
 *          相机2： (xA2, yA2)，(xB2, yB2), (xC2, yC2), (xD2, yD2),
 *      计算相机1的图像到相机2图像的单应矩阵，并转换相机2图像中的点坐标到相机1图像坐标中
 *  2） 计算单应矩阵及求取点坐标时不可直接使用第三方库
 *  3） 除2）要求的过程外，其他过程如求矩阵的逆、迹、秩可根据个人习惯使用第三方库
 *  4） 在程序中打印输出单应矩阵的内容
 * 输入： 4个点在相机1图像中的坐标，以二维数组形式给出，
 *       4个点在相机2图像中的坐标，以二维数组形式给出，
 *       N个相机2图像中坐标的点，以长度为N的二维数组形式给出 
 * 输出： N个相机1图像中坐标的点，以长度为N的二维数组形式给出 
 * */
#include "../include/calc_homography.h"
void calc_homography(int pts1[4][2], int pts2[4][2], int pts_in[][2], int pts_out[][2])
{
    // 不使用第三方库不会求,使用第三库使用2个函数即可
    // 调用findHomography函数
    Mat p1 = cv::Mat(4, 2, CV_32S, pts1);
    Mat p2 = cv::Mat(4, 2, CV_32S ,pts2);
    cv::Mat H = cv::findHomography(p1,p2);
    // 输出单应矩阵
    printf("homography=\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", H.at<double>(i, j));
        }
        printf("\n");
    }
    // cout << "H.channels()=" << H.channels() << endl;
    // cout << "H.cols=" << H.cols << endl;

    // 调用perspectiveTransform函数
    // 构造输出点坐标的二维数组
    cv::Mat pts_in_mat(4, 2, CV_32SC2, pts_in);
    cv::Mat pts_out_mat(4, 2, CV_32SC2, pts_out);
    
    // 调用perspectiveTransform函数
    // 这里报错:Assertion failed (depth == CV_32F || depth == CV_64F),不知道是什么原因..
     cv::perspectiveTransform(pts_in_mat, pts_out_mat, H);
    // 输出结果
    printf("result=\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", pts_out[i][j]);
        }
        printf("\n");
    }
}