/*
 * @Author: chenbei
 * @Date: 2022-04-30 09:46:30
 * @LastEditTime: 2022-04-30 09:50:40
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\commandLine.cpp
 * @Description: by command line to run the program
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\commandLine -g commandLine.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/commandLine ../images/anime.png
*/
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
int main(int argc,char**argv)
{
    Mat img = imread(argv[1],-1);
    if (img.empty()) return -1;
    namedWindow("eg",cv::WINDOW_AUTOSIZE);
    imshow("eg",img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
