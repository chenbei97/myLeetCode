本文件夹主要是用来测试opencv的基础类型
例如cv::Vec,cv::Point,cv::Scalar等
最后还会重点说明cv::Mat

cd myPleasure\\myOpencv\\basicTypes\\source

#include <iostream>
#include "..\..\examples\source\simpleShow.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/ximgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\m -g m.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/m ../images/m.png
*/
int main(int argc,char**argv)
{
    Mat src = imread(argv[1], IMREAD_GRAYSCALE);
    return 0;
}