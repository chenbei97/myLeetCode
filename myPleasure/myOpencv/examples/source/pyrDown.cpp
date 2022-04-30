/*
 * @Author: chenbei
 * @Date: 2022-04-30 16:40:04
 * @LastEditTime: 2022-04-30 16:41:51
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\pyrDown.cpp
 * @Description: test for pyrDown
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "simpleShow.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/ximgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\pyrDown -g pyrDown.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/pyrDown ../images/lena.jpg
*/
int main(int argc,char**argv)
{
    // 用于降采样,这里是高度和宽度都降低一半
    // Mat src = imread(("../images/m.jpg"), IMREAD_GRAYSCALE);
    Mat src = imread(argv[1]);
    if (src.empty())
    {
        cout << "could not load image..." << endl;
        return -1;
    }
    Mat dst;
    pyrDown(src, dst);
    simpleShow(src,"src");
    simpleShow(dst,"dst");
    return 0;
}