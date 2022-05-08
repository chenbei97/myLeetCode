#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\InputArray -g InputArray.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/InputArray
*/
void myAffineTransform(InputArray _src, OutputArray _dst, InputArray _m)
{
    // m是变换矩阵
    Mat src = _src.getMat(), m = _m.getMat(); // 获取真正的数据
    // Size定义的宽度和高度,所以先列后行,这里要求是3行4列的矩阵
    CV_Assert(src.type() == CV_32FC3 && m.type() == CV_32F && m.size() == Size(4, 3)); // 限定src的类型和m的类型
    _dst.create(src.size(), src.type()); // 使用create创建内存
    Mat dst = _dst.getMat(); // 获取真正的数据,是个引用

    //cout << "m.at<float>(0, 0) = " << m.at<float>(0, 0) << "  m.at<float>(0, 1) = " << m.at<float>(0, 1)
    //    << "  m.at<float>(0, 2) = " << m.at<float>(0, 2) << "  m.at<float>(0, 3) = " << m.at<float>(0, 3) << endl;
    //  -1.60309e-09 ,0.158135 ,-0.700928,-0.428596

    for (int i = 0; i < src.rows; i++) // 遍历src的行
        for (int j = 0; j < src.cols; j++) // 遍历src的列
        {
            // Point2f pt = src.at<Point2f>(i, j); // 获取src的点可以使用at方法,如果是双通道使用Point2f获取
            // 如果是3通道使用不能使用Vec3f(i,j,k)
            // 变换矩阵第1行
            float pt1 = src.at<Vec3f>(i, j)[0];
            float pt2 = src.at<Vec3f>(i, j)[1];
            float pt3 = src.at<Vec3f>(i, j)[2];
            dst.at<Vec3f>(i, j)[0] = m.at<float>(0, 0) *pt1 + m.at<float>(0, 1) * pt1 + m.at<float>(0, 2) * pt1 + m.at<float>(0, 3);
            dst.at<Vec3f>(i, j)[1] = m.at<float>(1, 0) * pt2 + m.at<float>(1, 1) * pt2 + m.at<float>(1, 2) * pt2 + m.at<float>(1, 3);
            dst.at<Vec3f>(i, j)[2] = m.at<float>(2, 0) * pt3 + m.at<float>(2, 1) * pt3 + m.at<float>(2, 2) * pt3 + m.at<float>(2, 3);
        }
}
int main(int argc,char**argv)
{
    /*
        许多函数需要传递数组并返回数组，所以有一个统一数据类型InputArray和OutputArray
        它们支持cv::Scalar、cv::Matx、cv::Vec以及cv::Mat、cv::SparseMat甚至std::vector类型的数据
        为了防止接口变的复杂,所以提供了两个类型：InputArray和OutputArray,可以表示上述的任何一个类型

        InputArray一般是只读的,OutputArray是可读写的
        与cv::InputArray对应的特殊函数是cv::noArray()或者cv::Mat()可以作为空参数
        当然不需要输出时也可以使用cv::noArray()或者cv::Mat()

        OutputArray是InputArray的派生类,它的构造函数是cv::OutputArray(cv::Mat& m)
        OutputArray：：getMat（）之前一定要调用_OutputArray：：create（）为矩阵分配空间
        可以用OutputArray：：needed（）来检测输出的矩阵是否需要被计算。有时候传进去的参不是空就不需要计算
        OutputArrayOfArrays、InputOutputArray、InputOutputArrayOfArrays都是OutputArray的别名而已
    */
 // 创建1个3行4列的的变换矩阵,数据类型为CV_32F,且基于高斯随机初始化
    Mat m = Mat::zeros(3, 4, CV_32F); // Mat直接指定rows,cols就是行和列
    randn(m, 0, 1);
    // 输出变换矩阵
    cout << "m = " << m << endl;
    /*
    m = [-1.6030948e-09, 0.15813506, -0.70092797, -0.42859599;
             1.2387421, -0.27800822, -0.64839876, 0.30516329;
             0.51501459, -1.1450437, 0.76984555, -0.04643121]
    */

    // 创建一个CV_32FC3的随机矩阵,100行,120列,基于均匀初始化
    Mat src = Mat::zeros(100, 120, CV_32FC3);
    randu(src, Scalar::all(0), Scalar::all(1));

    // 遍历矩阵src
    // for( int i = 0; i < src.rows; i++ ){
    //     for( int j = 0; j < src.cols; j++ ){
    //         cout << "src[" << i << "][" << j << "] = " << src.at<Point2f>(i, j) << endl;
    //     }
    // }

    
    cout << "src's type() = " << src.type() << endl;
    cout << "m's type() = " << m.type() << endl; 
    cout << "m's size() = " << m.size() << endl;
    cout << "CV_32FC3 = " << CV_32FC3 << endl;
    cout << "CV_32F = " << CV_32F << endl;

    // 创建一个CV_32FC3的空矩阵
    Mat dst(src.size(),src.type());
    // Mat dst;
    // // 调用函数
    myAffineTransform(src, dst, m);

    namedWindow("src", WINDOW_FREERATIO);
    namedWindow("dst", WINDOW_FREERATIO);
    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);
    destroyAllWindows();
    return 0;
}