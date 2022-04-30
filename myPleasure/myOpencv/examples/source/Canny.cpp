/*
 * @Author: chenbei
 * @Date: 2022-04-30 16:43:36
 * @LastEditTime: 2022-04-30 16:45:43
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\Canny.cpp
 * @Description: test for Canny
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
g++ -o ..\output\Canny -g Canny.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Canny ../images/lena.jpg
*/
int main(int argc,char**argv)
{
    // Mat src = imread(("../images/m.jpg"), IMREAD_GRAYSCALE);
    Mat src = imread(argv[1]);
    if (src.empty())
    {
        cout << "could not load image..." << endl;
        return -1;
    }
    Mat grey;
    cvtColor(src, grey, COLOR_BGR2GRAY);
    Mat dst;
    Canny(grey, dst, 50, 200, 3); // 参数依次是:目标对象,输出,高阈值,低阈值,Sobel运算符的孔径大小
    simpleShow(src,"src");
    simpleShow(dst,"dst");
    return 0;
}
