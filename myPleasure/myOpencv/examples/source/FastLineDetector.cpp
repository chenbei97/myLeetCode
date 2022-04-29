/*
 * @Author: chenbei
 * @Date: 2022-04-29 21:44:51
 * @LastEditTime: 2022-04-29 22:41:27
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\FastLineDetector.cpp
 * @Description: test for FastLineDetector
 * @Signature: A boy without dreams
 */
/*
g++ -o ../output/FastLineDetector -g FastLineDetector.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/FastLineDetector
*/
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/ximgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/ximgproc/fast_line_detector.hpp>
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;
using namespace cv::ximgproc;
int main()
{
    // 本文件因为undefined reference to 
    // `cv::ximgproc::createFastLineDetector(int, float, double, double, int, bool)'
    // 所以没有编译通过执行,但是代码没有问题
    // 参考:https://docs.opencv.org/4.x/d1/d9e/fld_lines_8cpp-example.html
    Mat src = imread(("../images/FastLineDetector.jpg"), IMREAD_GRAYSCALE);
    if (src.empty())
    {
        cout << "could not load image..." << endl;
        return -1;
    }
    else cout << "image loaded..." << endl;
    int length_threshold = 10; // 短于10个像素的线段被忽略
    int distance_threshold = 1.41421356f; // 线段之间的最小间距
    double canny_th1 = 50.0; // canny算子的阈值1
    double canny_th2 = 50.0; // canny算子的阈值2
    int canny_aperture_size = 3; // canny中sobel运算符的孔径大小
    bool do_merge = false; // 是否合并相邻的线段
    // 创建一个FastLineDetector对象
    Ptr<FastLineDetector> fld = createFastLineDetector
                    (length_threshold, 
                    distance_threshold,
                    canny_th1,
                    canny_th2,
                    canny_aperture_size,
                    do_merge);
    vector<Vec4f> lines;
    // 调用FastLineDetector对象的detect函数
    fld->detect(src, lines);
    // 将结果显示在图像上
    for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4f l = lines[i];
        line(src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
    }
    imshow("src", src);
    waitKey(0);
    return 0;
}
