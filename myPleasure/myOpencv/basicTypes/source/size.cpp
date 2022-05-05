/*** 
 * @Author: chenbei
 * @Date: 2022-05-05 08:18:14
 * @LastEditTime: 2022-05-05 08:40:17
 * @Description: test for size
 * @FilePath: \myLeetCode\myPleasure\myOpencv\basicTypes\source\size.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Size -g Size.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Size
*/
int main(int argc,char**argv)
{
    /*
        Size和Point类似,可以互相转换
        只是Point的属性为x,y,而Size的属性为width,height
        另外Point可以转换为固定向量类但是Size类不支持
    */
    // 默认、复制和值构造函数
    Size s1; // 默认构造函数
    Size2i s2(s1); // 复制构造,Size2i等价于Size
    Size2f s3(1.1,2.2);//值构造
    // 成员访问
    cout<<"s3: "<<s3<<endl; // [1.1, 2.2]
    cout<<"s3.width: "<<s3.width<<endl; // 1.1
    cout<<"s3.height: "<<s3.height<<endl; // 2.2
    // 计算面积
    double area = s3.area(); // 2.42
    cout<<"area: "<<area<<endl;
    // 计算宽高比
    double ratio = s3.width/s3.height; // 1.1/2.2 = 0.5
    cout<<"ratio: "<<ratio<<endl;
    cout<<"ratio:"<<s3.aspectRatio()<<endl; // 0.5

    return 0;
}