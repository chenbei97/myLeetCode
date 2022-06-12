/*
 * @Author: chenbei
 * @Date: 2022-04-30 11:34:02
 * @LastEditTime: 2022-04-30 12:44:48
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\simpleShow.hpp
 * @Description: 一个用于简单显示图片的脚本程序
 * @Signature: A boy without dreams
 */
#ifndef _simpleShow_
#define _simpleShow_
#include <string>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
void simpleShow(const Mat& img,const std::string& winName)
{
    namedWindow(winName,WINDOW_FREERATIO);
    imshow(winName,img);
    waitKey(-1);
    destroyWindow(winName);
}
#endif // !_simpleShow_
