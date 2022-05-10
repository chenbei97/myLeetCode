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
    Mat src8uc3 = imread(argv[1]);
    Mat src8uc1;
    cvtColor(src8uc3, src8uc1, COLOR_BGR2GRAY);
   
    // 1、基于模板函数at<T>遍历
    Mat dst32fc3_at(src8uc3.size(), CV_32FC3);
    cout << "src8uc3.type()=" << src8uc3.type() << endl; // 16表示CV_8UC3
    double minVal = 0.0;
    double maxVal = 0.0;
    minMaxLoc(src8uc3, &minVal, &maxVal);
    // 从最大值和最小值知道图像是uchar类型
    cout << "minVal = " << minVal << " , maxVal = " << maxVal << endl; // minVal = 0.0 , maxVal = 255.0
    // 现在开始遍历3通道图像
    // 使用getTickCount()获取时间戳,并计时
    double start = getTickCount();
    for (int i = 0; i < src8uc3.rows; i++)
    {
        for (int j = 0; j < src8uc3.cols; j++)
        {
            //for (int k = 0; k < src.channels(); k++)
            //{
            //    dst32fc3_at.at<Vec3f>(i, j)[k] =src.at<Vec3b>(i, j)[k] / 255.0;
            //}
            // 也可以不再遍历通道数,因为通道数已知为3
            dst32fc3_at.at<Vec3f>(i, j)[0] = src8uc3.at<Vec3b>(i, j)[0] / 255.0;
            dst32fc3_at.at<Vec3f>(i, j)[1] = src8uc3.at<Vec3b>(i, j)[1] / 255.0;
            dst32fc3_at.at<Vec3f>(i, j)[2] = src8uc3.at<Vec3b>(i, j)[2] / 255.0;
        }
    }
    double end = getTickCount();
    // cost time 3 channels by at  = 528.956 ms & 682.543 ms，可以看出三层for循环还是慢一些,最好选择直接赋值的
    cout << "cost time 3 channels by at = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst32fc3_at, "dst32fc3_at");
    // 1.2、单通道
    Mat dst32fc1_at(src8uc3.size(), CV_32FC1);
    cout << "src8uc1.type()=" << src8uc1.type() << endl; // 0表示CV_8UC1
    start = getTickCount();
    for (int i = 0; i < src8uc1.rows; i++)
    {
        for (int j = 0; j < src8uc1.cols; j++)
        {
            dst32fc1_at.at<float>(i, j) = src8uc1.at<uchar>(i, j) / 255.0;
        }
    }
    end = getTickCount();
    // cost time 1 channel by at = 167.489 ms
    cout << "cost time 1 channel by at = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst32fc1_at, "dst32fc1_at");

    // 2、基于智能指针遍历
    // 2.1、三通道
    Mat dst32fc3_ptr(src8uc3.size(), CV_32FC3);
    // 使用getTickCount()获取时间戳,并计时
    start = getTickCount();
    for (int i = 0; i < src8uc3.rows; i++)
    {
        Vec3b* ptr = src8uc3.ptr<Vec3b>(i); // 指向i行的指针
        for (int j = 0; j < src8uc3.cols; j++)
        {
            // 第i行访问第j列的0,1,2通道
            dst32fc3_ptr.at<Vec3f>(i, j)[0] = ptr[j][0] / 255.0;
            dst32fc3_ptr.at<Vec3f>(i, j)[1] = ptr[j][1] / 255.0;
            dst32fc3_ptr.at<Vec3f>(i, j)[2] = ptr[j][2] / 255.0;
        }
    }
    end = getTickCount();
    // cost time 3 channels by ptr = 371.747 ms
    cout << "cost time 3 channels by ptr = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst32fc3_ptr, "dst32fc3_ptr");

    // 2.2、单通道
    Mat dst32fc1_ptr(src8uc1.size(), CV_32FC1);
    start = getTickCount();
    for (int i = 0; i <src8uc1.rows; i++)
    {
        uchar* ptr = src8uc1.ptr<uchar>(i); // 基于行指针的遍历法
        for (int j = 0; j < src8uc1.cols; j++)
        {
            dst32fc1_ptr.at<float>(i, j) = ptr[j] / 255.0;
        }
    }
    end = getTickCount();
    // cost time 1 channel by ptr = 78.2221 ms
    cout << "cost time 1 channel by ptr = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst32fc1_ptr, "dst32fc1_ptr");


    // 3、基于迭代器的遍历
    // 3.1、三通道
    Mat dst32fc3_iter(src8uc3.size(), CV_32FC3);
    start = getTickCount();
    MatIterator_<Vec3b> it8uc3 = src8uc3.begin<Vec3b>();
    MatIterator_<Vec3b> it_end8uc3 = src8uc3.end<Vec3b>();
    for (; it8uc3 != it_end8uc3; ++it8uc3)
    {
        // 迭代器的pos()函数用于获取当前迭代器所指向的位置(行,列)
        dst32fc3_iter.at<Vec3f>(it8uc3.pos())[0] = (*it8uc3)[0] / 255.0;
        dst32fc3_iter.at<Vec3f>(it8uc3.pos())[1] = (*it8uc3)[1] / 255.0;
        dst32fc3_iter.at<Vec3f>(it8uc3.pos())[2] = (*it8uc3)[2] / 255.0;
    }
    end = getTickCount();
    // cost time 3 channels by iter = 1015.7 ms
    cout << "cost time 3 channels by iter = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst32fc3_iter, "dst32fc3_iter");
    // 3.2、单通道
    Mat dst32fc1_iter(src8uc1.size(), CV_32FC1);
    start = getTickCount();
    MatIterator_<uchar> it8uc1 = src8uc1.begin<uchar>();
    MatIterator_<uchar> it_end8uc1 = src8uc1.end<uchar>();
    for (; it8uc1 != it_end8uc1; ++it8uc1)
    {
        dst32fc1_iter.at<float>(it8uc1.pos()) = (*it8uc1) / 255.0;
    }
    end = getTickCount();
    // cost time 1 channel by iter = 282.237 ms
    cout << "cost time 1 channel by iter = " << (end - start) / getTickFrequency() * 1000 << " ms" << endl;
    //simpleShow(dst32fc1_iter, "dst32fc1_iter");

    /*
        总结：
        三通道：at = 528.956&682.543 ms ptr = 371.747 ms iter = 1015.7 ms
        单通道：at = 167.489 ms ptr = 78.2221 ms iter = 282.237 ms
        结论：
        无论是单通道还是三通道，智能指针ptr<模板函数at<迭代器MatIterator_
    */
    return 0;
}