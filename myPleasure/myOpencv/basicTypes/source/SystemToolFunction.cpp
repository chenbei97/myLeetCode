#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
#include <opencv2/core/cvstd.hpp>
using namespace cv;
using namespace std;
/*
g++ -o ..\output\SystemToolFunction -g SystemToolFunction.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/SystemToolFunction
*/
int main(int argc,char**argv)
{
    /*
        opencv存在一些常见的系统工具函数，如下：
        1、cv::alignPtr() 对齐指针到给定字节数       
            函数原型:template<T> T* alignPtr(T* ptr,int n = sizeof(T))
            参数说明: ptr:指针，n:对齐字节数
            返回值:对齐后的指针,依据公式计算对齐指针=>(T*)(((size_t)ptr + n - 1) & -n)
        2、cv::alignSize() 将缓冲区大小和给定字节数对齐
            函数原型:size_t alignSize(size_t sz,int n = sizeof(size_t))
            参数说明: sz:缓冲区大小，n:对齐字节数
            返回值:对齐后的缓冲区大小,依据公式计算对齐缓冲区大小=>(sz + n - 1) & -n
        3、cv::allocate() 分配一个C风格的数组对象
            函数原型:template<T> T* allocate(size_t n)
            参数说明: n:数组大小
            返回值:数组指针,和数组形式的new相似,分配了n个T类型的对象C风格数组
        4、cv::deallocate() 释放一个C风格的数组对象
            函数原型:template<T> void deallocate(T* ptr,size_t n)
            参数说明: ptr:数组指针，n:数组大小
            返回值:无,释放了n个T类型的对象C风格数组,和数组形式的delete相似
        5、cvCeil()：对浮点数向上取整得到整型
            函数原型:int cvCeil(float x)
            参数说明: x:单精度浮点数
            返回值:向上取整得到的整型,如果输入超出32位整型表示范围则返回未定义
        6、cvFloor()：向下取整
            函数原型:int cvFloor(float x)
            参数说明: x:单精度浮点数
            返回值:向下取整得到的整型,如果输入超出32位整型表示范围则返回未定义
        7、cvRound()：四舍五入
            函数原型:int cvRound(double x)
            参数说明: x:双精度浮点数
            返回值:四舍五入得到的整型,如果输入超出32位整型表示范围则返回未定义
        8、CV_Assert()：断言是一个宏，用来检查输入参数是否合法，如果不合法则抛出异常
        9、CV_Error():从cv::Exception固定字符串抛出异常的宏
        10、CV_Error_():从cv::Exception格式化字符串抛出异常的宏
        11、cv::error(): 指示错误并抛出异常
            函数原型:void error(const Exception& ex)
            参数说明: ex:异常对象
            返回值:无,这个函数一般是CV_Error或CV_Error_的辅助函数,而很少直接使用此函数
        12、cv::fastAtan2():向量的二维角度计算
            函数原型:float fastAtan2(float y,float x)
            参数说明: y:y轴坐标，x:x轴坐标
            返回值:向量的二维角度,结果以0.0~360.0的角度表示,包含0.0但不包含360.0
        13、cv::fastFree():快速释放内存缓存区
            函数原型:void fastFree(void* ptr)
            参数说明: ptr:内存缓存区指针
            返回值:无,常由fastMalloc()函数使用
        14、cv::fastMalloc():快速分配对齐的内存缓存区
            函数原型:void* fastMalloc(size_t size)
            参数说明: size:内存缓存区大小
            返回值:内存缓存区指针,如果分配失败则返回nullptr,和malloc相似但是做了缓存区内存大小对齐执行速度更快
        15、cv::format()：格式化字符串
            函数原型:String format(const char* fmt,...)
            参数说明: fmt:格式化字符串,后面跟着的参数用来格式化字符串
            返回值:格式化后的字符串,本质上和标准库的sprintf相同,但不需要获得字符缓冲区,而是构建STL字符串返回
        16、cv::getCPUTickCount():获取CPU时钟计数
            函数原型:int64 getCPUTickCount(void)
            参数说明: 无
            返回值:CPU时钟计数,计算时间间隔此函数最好不要使用,改用cv::getTickCount()
        17、cv::getTickCount():获取系统时钟计数
            函数原型:int64 getTickCount(void)
            参数说明: 无
            返回值:系统时钟计数,这个返回的计数时间可以通过时钟频率cv::getTickFrequency()计算
        18、cv::getTickFrequency():获取系统时钟频率
            函数原型:double getTickFrequency(void)
            参数说明: 无
            返回值:系统时钟频率,单位Hz,可以调用2次cv::getTickCount()函数得到计数差再除以这个频率得到时间间隔
        19、cv::getNumThreads():获取线程数
            函数原型:int getNumThreads(void)
            参数说明: 无
            返回值:线程数
        20、cv::getThreadNum():获取当前线程编号
            函数原型:int getThreadNum(void)
            参数说明: 无
            返回值:当前线程编号,前提是opencv添加了opeenmp支持
        21、cv::setThreadNum():设置当前线程编号
            函数原型:void setThreadNum(int nthreads)
            参数说明: nthreads:线程编号
            返回值:无,当添加了opencvmp后,此函数可以设定opencv在并行的openmp区域使用的线程数
        22、cubeRoot()：立方根
            函数原型:float cubeRoot(float val)
            参数说明: val:要计算立方根的数
            返回值:立方根
        23、cvIsInf():判断是否为无穷大
            函数原型:bool cvIsInf(double val)
            参数说明: val:要判断的数
            返回值:true:是无穷大,false:不是无穷大
        24、cvIsNaN():判断是否为一个数
            函数原型:bool cvIsNaN(double val)
            参数说明: val:要判断的数
            返回值:true:是一个数,false:不是一个数
        25、cv::getOptimalDFTSize():获取传递给DFT的数组的最佳尺寸
            函数原型:int getOptimalDFTSize(int n)
            参数说明: n:要计算的数组大小
            返回值:传递给DFT的数组的最佳尺寸,一般输入是图片的实际大小并返回应该传递给cv::dtf()数组的大小
            当图像的尺寸是2、3、5的整数倍时计算速度最快
        26、cv::setUseOptimized():设置是否使用OpenCV优化
            函数原型:void setUseOptimized(bool onoff)
            参数说明: onoff:true:使用优化,false:不使用优化
            返回值:无
        27、cv::useOptimized():指示代码优化的启用
            函数原型:bool useOptimized(void)
            参数说明: 无
            返回值:true:当前在使用优化,false:当前没有使用优化
    */

    // 对于上述的系统工具函数只测试部分常用的函数
    double t1 = cv::getTickCount();

    // 1、测试cvCeil(),cvFloor(),cvRound()函数
    float a1 = 1.4f; double a2 = 1.4;
    float b1 = 1.5f; double b2 = 1.5;
    float c1 = 1.6f; double c2 = 1.6;
    cout<<"cvCeil(1.4f)="<<cvCeil(a1)<<" cvCeil(1.4)="<<cvCeil(a2)<<endl; // 2,2
    cout<<"cvCeil(1.5f)="<<cvCeil(b1)<<" cvCeil(1.5)="<<cvCeil(b2)<<endl; // 2,2
    cout<<"cvCeil(1.6f)="<<cvCeil(c1)<<" cvCeil(1.6)="<<cvCeil(c2)<<endl; // 2,2
    cout<<"cvFloor(1.4f)="<<cvFloor(a1)<<" cvFloor(1.4)="<<cvFloor(a2)<<endl; // 1,1
    cout<<"cvFloor(1.5f)="<<cvFloor(b1)<<" cvFloor(1.5)="<<cvFloor(b2)<<endl; // 1,1
    cout<<"cvFloor(1.6f)="<<cvFloor(c1)<<" cvFloor(1.6)="<<cvFloor(c2)<<endl; // 1,1
    cout<<"cvRound(1.4f)="<<cvRound(a1)<<" cvRound(1.4)="<<cvRound(a2)<<endl; // 2,2
    cout<<"cvRound(1.5f)="<<cvRound(b1)<<" cvRound(1.5)="<<cvRound(b2)<<endl; // 2,2
    cout<<"cvRound(1.6f)="<<cvRound(c1)<<" cvRound(1.6)="<<cvRound(c2)<<endl; // 2,2
    // 从下边的测试可以知道,opencv的四舍五入是从0.4开始的,>=0.4 => 1,<0.4 => 0
    float d1 = 1.39f; double d2 = 1.39;
    cout<<"cvRound(1.39f)="<<cvRound(d1)<<" cvRound(1.39)="<<cvRound(d2)<<endl; // 1,1
    
    // 2、测试cv::fastAtan2()函数
    int x1 = 3; int y1 = 4;
    cout<<"cv::fastAtan2(4,3)=arctan(4/3)="<<cv::fastAtan2(y1,x1)<<endl; // 53°

    // 3、测试cv::format()函数
    const char* s1 = "Hello, %s";
    string fmt = cv::format(s1,"World");
    cout<<"fmt="<<fmt<<endl; // Hello, World

    // 4、测试cubeRoot()函数,必须传递float或double类型的参数
    cout<<"cubeRoot(27.)="<<cv::cubeRoot(27.)<<endl; // 3.0

    // 5、测试cvIsInf()和cvIsNaN()函数
    float e1 = 1.0f/0.0f;
    cout<<boolalpha<<"cvIsInf(1.0f/0.0f)="<<cvIsInf(e1)<<endl; // true
    cout<<boolalpha<<"cvIsNaN(1.0f/0.0f)="<<cvIsNaN(e1)<<endl; // false

    // 6、测试断言CV_Assert()函数
    CV_Assert(5*3 == 15); // 如果条件不成立,则抛出异常

    // 7、测试cv::getTickCount()函数并转换到ms
    double t2 = cv::getTickCount();
    // 计算时间差,单位为ms
    double time = (t2-t1)/cv::getTickFrequency()*1000;
    cout<<"time="<<time<<"ms"<<endl; // time=20.8558ms
    return 0;
}