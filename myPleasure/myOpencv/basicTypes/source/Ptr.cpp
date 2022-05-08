#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Ptr -g Ptr.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Ptr ../images/1.jpg
*/
int main(int argc,char**argv)
{
    /*
        Ptr是opencv的一个智能指针类型，与STL的shared_ptr类似
        它是一个引用计数器，可以让指针指向的对象被多个指针指向
        如果指针指向的对象被删除，则指针也会被删除
        是一种资源管理类，可以自动释放资源
        
        Ptr是一个模板类，用法也是需要指定类型，然后绑定一个指针
        makePtr是一个模板函数，用来创建一个指针
        cv::Ptr<T> makePtr(T* ptr)
        使用make_shared可以创建一个指针
        cv::Ptr<T> make_shared(T* ptr)
        
        Ptr有一些与引用计数相关的附加函数，addref和release,可以增加和减少引用计数
        但是这些函数是比较危险的函数,如果自行管理引用计数可以使用addref和release
        还有一个empty函数,用来判断指针是否指向一个已经被释放的对象，因为release调用后可能对象已被销毁但指针仍存在
        empty还可以确定智能指针对象内部对象指针是否处于其他原因成为nullptr
        例如可能给智能指针赋值时使用了一个返回nullptr的函数,如加载图像cvLoadImage和打开文件fopen

        Ptr还需要了解的成员是delete_obj，这是引用计数为0自动被调用的函数
        其函数原型:
        template<>inline void cv::Ptr<IplImage>::delete_obj(){
            cvReleaseImage(&obj); // opencv2.1版本的函数
        }
        可以自动释放从cvLoadImage和fopen函数返回的图像指针
    */
    Mat src = imread(argv[1], IMREAD_GRAYSCALE);
    // 创建一个智能指针
    Ptr<Mat> p = make_shared<Mat>(src); // 自动管理释放资源,Create an object that is owned by a shared_ptr.
    // 使用makePtr也可以
    Ptr<Mat> p1 = makePtr<Mat>(src); // 使用makePtr也可以
    // 判断指针是否指向一个已经被释放的对象
    if(p->empty())
        cout << "empty" << endl;
    else 
        cout << "not empty" << endl;
    // 增加引用计数
    Mat src1 = src;
    p->addref();
    if(p->empty())
        cout << "empty" << endl;
    else 
        cout << "not empty" << endl;
    // 减少引用计数,释放指针
    p.release();
    //此时p已经被销毁,不能再使用p
    // if(p->empty())
    //     cout << "empty" << endl;
    // else 
    //     cout << "not empty" << endl;
    
    // 旧式使用cvLoadImage和fopen函数返回的指针,不过现在4.3.1的版本已经不支持了
    // IplImage* img1 = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    // IplImage* img1 = fopen(argv[1], "rb");
    return 0;
}