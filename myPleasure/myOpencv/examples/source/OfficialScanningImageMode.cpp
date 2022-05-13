#include <iostream>
#include <iterator>
#include "simpleShow.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\OfficialScanningImageMode -g OfficialScanningImageMode.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/OfficialScanningImageMode ../images/lena.jpg
*/
Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    // 要求图像是CV_8U类型的,单或者三通道
    // 使用行数据指针遍历
    CV_Assert(I.depth() == CV_8U);
    int channels = I.channels(); // 获取图像通道数
    int nRows = I.rows; // 获取图像行数
    int nCols = I.cols * channels; // 获取图像列数,这里因为内存分布是逐个维度的所有通道平铺
    if (I.isContinuous()) // 如果图像是连续的
    {
        nCols *= nRows; // 那么就可以把所有行依次在后堆叠
        nRows = 1; // 也就是1行,channels*cols列
    }
    int i,j;
    uchar* p; // 指向行数据的指针
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i); // 获取行数据的指针
        for ( j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]]; // 将每个像素点的值转换为新的值
        }
    }
    return I;
}
void scanImageBydata(Mat& I, const uchar* const table){
    // 要求图像是CV_8UC1类型的,单通道
    CV_Assert(I.depth() == CV_8UC1);
    int nRows = I.rows; // 获取图像行数
    int nCols = I.cols ; // 获取图像列数
    uchar* p = I.data; // 获取图像数据的指针,逐个指向图像的每个像素点
    for( unsigned int i = 0; i < nCols*nRows; ++i)
    {
        // cout<<"*p = "<<(int)*p<<" "; // 值不会超过255,而table恰好是256个元素,所以不会越界
        *p++ = table[*p]; // 指向像素点的指针++,指向下一个像素点,*恰好也是索引
    }
    // cout<<endl;
}
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    switch(channels)
    {
        case 1: // 单通道
            {
                MatIterator_<uchar> it, end;
                for( it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
                    *it = table[*it]; // 将每个像素点的值转换为新的值
                break;
            }
        case 3:
            {
                MatIterator_<Vec3b> it, end;
                for( it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
                {
                    // 迭代器解引用后是Vec3b类型,所以[0],[1],[2]访问不同的通道
                    // cout <<"(*it)[0] = " << (int)(*it)[0] << " (*it)[1] = " << (int)(*it)[1] << " (*it)[2] = " << (int)(*it)[2] << endl;
                    (*it)[0] = table[(*it)[0]];
                    (*it)[1] = table[(*it)[1]];
                    (*it)[2] = table[(*it)[2]];
                }
            }
    }
    return I;
}
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
    // 带引用返回的动态地址计算
    /*
        该方法不建议用于遍历图像,它被用来获取或修改图像中的随机元素
        它的基本用法是指定要访问的项的行号和列号,需要手动指定在自动查找时使用的类型
        对于以下源代码的灰度图像(使用cv::Mat::at<T>()函数)，可以观察到这一点
        使用at<uchar>(i,j)或者at<Vec3b>(i,j)访问图像中的某个像素点

        at函数接受您的输入类型和坐标，并计算查询项的地址，然后返回对它的引用
        当你得到这个值时，它可能是一个常数，而当你设置这个值时，它可能是一个非常数
        仅作为调试模式下的安全步骤，需要检查输入坐标是否有效且确实存在
        如果不是这样的话，你会在标准错误输出流中得到一条很好的输出消息

        如果需要使用此方法对图像进行多次查找，则为每次访问输入类型和at关键字可能会很麻烦且耗时
        为了解决这个问题，OpenCV有一个cv::Mat_数据类型,这与Mat相同
        但在定义时，您需要通过查看数据矩阵的内容来指定数据类型，但作为回报，您可以使用运算符()快速访问像素点
    */
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    switch(channels)
    {
        case 1:
            {
                for( int i = 0; i < I.rows; ++i)
                    for( int j = 0; j < I.cols; ++j )
                        I.at<uchar>(i,j) = table[I.at<uchar>(i,j)]; // 获取指定位置的像素点的值
                break;
            }
        case 3:
            {
            Mat_<Vec3b> _I = I; // 显式转换为Mat_<Vec3b>类型,可以借助Mat_提高效率
            for( int i = 0; i < I.rows; ++i)
                for( int j = 0; j < I.cols; ++j )
                {
                    _I(i,j)[0] = table[_I(i,j)[0]]; // 获取指定位置的像素点的值
                    _I(i,j)[1] = table[_I(i,j)[1]];
                    _I(i,j)[2] = table[_I(i,j)[2]];
                }
            I = _I; // 赋值回去
            break;
            }
    }
    return I;
}

int main(int argc,char**argv)
{
    // 使用官方提供的几种方法扫描图像
    // https://docs.opencv.org/4.x/db/da5/tutorial_how_to_scan_images.html
    /*
        Times passed in seconds: 0.445 ms  三通道 行指针法
        Times passed in seconds: 0.1581 ms 单通道 data指针法
        Times passed in seconds: 1.9845 ms 三通道 迭代器法
        Times passed in seconds: 1.8508 ms 三通道 at<T>(i,j)法
        Times passed in seconds: 0.2193 ms 三通道,LUT法
    */
    Mat src = imread(argv[1]);
    //simpleShow(src, "src");
    Mat gray;
    cvtColor(src,gray,COLOR_BGR2GRAY);
    uchar table[256]; // 创建一个256长度的数组
    int divideWith = 16; // 目的是将像素点的值分成16等份,这样像素点只有256/16=16个可能值
    // 像素相当于更加的均匀分布
    for (int i = 0; i < 256; ++i)
       table[i] = (uchar)(divideWith * (i/divideWith));
    // 输出table
    // ostream_iterator<int> out(cout, " ");
    // copy(table, table + 256, out);
    // cout << endl;

    // table作为参数传入函数
    double t = (double)getTickCount();
    Mat dst = ScanImageAndReduceC(src, table);
    t = ((double)getTickCount() - t)/getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms"<<endl;
    //simpleShow(dst,"dst");

    // 如果是灰度图像,还可以通过data指针获取
    t = (double)getTickCount();
    scanImageBydata(gray, table);
    t = ((double)getTickCount() - t)/getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms"<<endl;
    //simpleShow(gray,"gray");
    
    // 迭代器是最安全的方式,但是效率比较低
    t = (double)getTickCount();
    ScanImageAndReduceIterator(src, table);
    t = ((double)getTickCount() - t)/getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms"<<endl;

    // 上面使用行数据指针/data指针/迭代器遍历,如果需要改变像素值可以使用at<uchar>(i,j)或者at<Vec3b>(i,j)
    // 不过单单是遍历图像不要使用这种方式
    t = (double)getTickCount();
    ScanImageAndReduceRandomAccess(src, table);
    t = ((double)getTickCount() - t)/getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms"<<endl;

    // 使用cv::LUT函数也是可以的
    /*
        这是一种在图像中实现查找表修改的额外方法.在图像处理中，通常需要将所有给定的图像值修改为其他值
        OpenCV提供了修改图像值的功能，无需写入图像的扫描逻辑
        我们使用核心模块的cv:：LUT()函数。首先，我们构建一个Mat类型的查找表
    */
    Mat lookUpTable(1, 256, CV_8U); // 创建一个1行256列的8位矩阵
    uchar* p = lookUpTable.ptr(); // 获取指针
    for( int i = 0; i < 256; ++i)
        p[i] = table[i];
    t = (double)getTickCount();
    Mat dst_new;
    cv::LUT(src, lookUpTable, dst_new);
    t = ((double)getTickCount() - t)/getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms"<<endl;
    return 0;
}