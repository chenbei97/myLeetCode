/*
 * @Author: chenbei
 * @Date: 2022-04-30 11:30:30
 * @LastEditTime: 2022-04-30 13:03:28
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\GaussianBlur.cpp
 * @Description: test for GaussianBlur
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "simpleShow.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\GaussianBlur -g GaussianBlur.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/GaussianBlur ../images/lena.jpg
只能运行中值滤波和双边滤波 
../output/GaussianBlur ../images/cat.jpg
只能运行中值滤波和双边滤波
../output/GaussianBlur ../images/shi_jing_shan_ice.jpg 
只能运行中值滤波和双边滤波
不知道啥原因,先这样跳过去,2022/4/30/13.01
与图像尺寸无关,与滤波器尺寸无关,也和是否使用cv::限定无关,也许头文件包含路径是否错误无关
和单通道还是三通道无关，和是否需要事先convertTo()无关
这些原因都排除了,后边其他原因等以后再看吧
*/
int main(int argc,char**argv)
{
    // Mat src = imread(("../images/m.jpg"));
    Mat src = imread(argv[1]); // ,ImreadModes::IMREAD_GRAYSCALE
    if(src.empty())
    {
        cout<<"can not open "<<argv[1]<<endl;
        return -1;
    }
    else
    {
        cout<<"open "<<argv[1]<<endl;
    }
    // 先将src原地转为8-bit unsigned char型
    src.convertTo(src,CV_8UC1);
    cout<<"src.size() = "<<src.size()<<endl;
    // 打印图片的数据类型和通道数
    cout<<"src.type() = "<<src.type()<<endl; // 0表示CV_8UC1,1表示CV_8SC1,16表示CV_8UC3等
    cout<<"src.channels() = "<<src.channels()<<endl; // 3
    // 打印图片的尺寸
    cout<<"src.cols = "<<src.cols<<endl;
    cout<<"src.rows = "<<src.rows<<endl;
    // 打印图片的深度
    cout<<"src.depth() = "<<src.depth()<<endl; // 8
    simpleShow(src,"src");
    
    // Mat dst = Mat::zeros(src.size(),src.type()); // 创建一个空白图片
    Mat dst1 = Mat(src.rows,src.cols,src.type()); // 创建一个空白图片
    cout<<"dst.size() = "<<dst1.size()<<endl;
    cout<<"dst.type() = "<<dst1.type()<<endl;
    cout<<"dst.channels() = "<<dst1.channels()<<endl;

    // 高斯滤波
    // 参数：目标图像,输出图像,卷积核大小,X和Y方向的sigma值以及边界类型
    // cv::GaussianBlur(src,dst1,Size(5,5),150,150,BORDER_DEFAULT); // 卷积核大小不要超过5,否则很慢
    // simpleShow(dst1,"gaussianBlur");

    // 使用blur函数也可以
    // cv::blur(src,dst1,Size(5,5),Point(-1,-1),BORDER_DEFAULT);
    // simpleShow(dst1,"blur");

    Mat dst2; // 滤波后不一定是原图的大小和类型,不要设定为原图的类型和大小
    // medianBlur中值滤波
    medianBlur(src,dst2,11);
    simpleShow(dst2,"medianBlur");

    // 双边滤波
    bilateralFilter(src,dst2,11,100,100,BORDER_DEFAULT);// 输入输出相同也可但是这里不行
    simpleShow(dst2,"bilateralFilter");
    return 0;
}