#include <iostream>
#include "simpleShow.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\TraverseMat -g TraverseMat.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/TraverseMat ../images/shi_jing_shan_ice.jpg
*/
int main(int argc,char**argv)
{
    /*
        遍历数组的3种方式,模板函数at<T>、智能指针ptr以及迭代器
        参考链接：https://blog.csdn.net/m0_37833142/article/details/105940111
    */
    Mat src = imread(argv[1]);
    Mat dst(src.size(),CV_32FC3);
    // 1、基于模板函数at<T>遍历
    // 1.1、三通道
    cout<<"src.type()="<<src.type()<<endl; // 16表示CV_8UC3
    double minVal = 0.0;
    double maxVal = 0.0;
    minMaxLoc(src, &minVal, &maxVal);
    // 从最大值和最小值知道图像是uchar类型
    cout << "minVal = "<<minVal << " , maxVal = " << maxVal << endl; // minVal = 0.0 , maxVal = 255.0
    // 现在开始遍历3通道图像
    // 使用getTickCount()获取时间戳,并计时
    double start = getTickCount();
    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            //for (int k = 0; k < src.channels(); k++)
            //{
            //    dst.at<Vec3f>(i, j)[k] =src.at<Vec3b>(i, j)[k] / 255.0;
            //}
            // 也可以不再遍历通道数,因为通道数已知为3
            dst.at<Vec3f>(i, j)[0] = src.at<Vec3b>(i, j)[0] / 255.0;
            dst.at<Vec3f>(i, j)[1] = src.at<Vec3b>(i, j)[1] / 255.0;
            dst.at<Vec3f>(i, j)[2] = src.at<Vec3b>(i, j)[2] / 255.0;
        }
    }
    double end = getTickCount();
    // cost time 3 channels by at<T> = 609.204 ms
    cout << "cost time 3 channels by at<T> = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst, "dst");
    // 1.2、单通道
    Mat src_gray;
    Mat dst_gray(src.size(),CV_32FC1);
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    cout << "src_gray.type()=" << src_gray.type() << endl; // 0表示CV_8UC1
    // 遍历单通道图像
    start = getTickCount();
    for (int i = 0; i < src_gray.rows; i++)
    {
        for (int j = 0; j < src_gray.cols; j++)
        {
            dst_gray.at<float>(i, j) = src_gray.at<uchar>(i, j) / 255.0;
        }
    }
    end = getTickCount();
    // cost time 1 channel by at<T> = 167.489 ms
    cout << "cost time 1 channel by at<T> = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst_gray, "dst_gray");

    // 2、基于智能指针遍历
    // 2.1、三通道
    Mat src_ptr(src.size(),CV_32FC3);
    // 使用getTickCount()获取时间戳,并计时
    start = getTickCount();
    for (int i = 0; i < src.rows; i++)
    {
        Vec3b *ptr = src.ptr<Vec3b>(i); // 基于行指针的遍历法
        for (int j = 0; j < src.cols; j++)
        {
            // 基于行指针的遍历法无需再第三层遍历
            src_ptr.at<Vec3f>(i, j)[0] = ptr[j][0] / 255.0;
            src_ptr.at<Vec3f>(i, j)[1] = ptr[j][1] / 255.0;
            src_ptr.at<Vec3f>(i, j)[2] = ptr[j][2] / 255.0;
        }
    }
    end = getTickCount();
    // cost time 3 channels by ptr = 609.204 ms
    cout << "cost time 3 channels by ptr = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(src_ptr, "src_ptr");

    // 2.2、单通道
    Mat src_gray_ptr;
    Mat dst_gray_ptr(src.size(),CV_32FC1);
    cvtColor(src, src_gray_ptr, COLOR_BGR2GRAY);
    // 遍历单通道图像
    start = getTickCount();
    for (int i = 0; i < src_gray_ptr.rows; i++)
    {
        uchar *ptr = src_gray_ptr.ptr<uchar>(i); // 基于行指针的遍历法
        for (int j = 0; j < src_gray_ptr.cols; j++)
        {
            dst_gray_ptr.at<float>(i, j) = ptr[j] / 255.0;
        }
    }
    end = getTickCount();
    // cost time 1 channel by ptr = 78.2221 ms
    cout << "cost time 1 channel by ptr = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst_gray_ptr, "dst_gray_ptr");


    // 3、基于迭代器的遍历
    // 3.1、三通道

    return 0;
}