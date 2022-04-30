/*
 * @Author: chenbei
 * @Date: 2022-04-30 09:53:48
 * @LastEditTime: 2022-04-30 10:08:05
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\showVideo.cpp
 * @Description: test for imgproc
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\showVideo -g showVideo.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/showVideo ../images/myBabyOnBed.mp4
*/
int main(int argc,char**argv)
{
    namedWindow("eg",WINDOW_AUTOSIZE);
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    cap.open(string(argv[1])); // 视频文件地址
    Mat frame; // 帧
    while(1)
    {
        cap >> frame; // 每一帧被frame接收
        if (frame.empty()) // 没有这个会一直等待读取就会报错
            break;
        imshow("eg",frame);// 视频就是一帧一帧的显示
        if(waitKey(30) >= 0) break; // 等待30ms，如果按下esc键，则退出
    }

    return 0;
}
