#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Point -g Point.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Point
*/
int main(int argc,char**argv)
{
    /*
        Point存在一些别名,可以拓展到更多的类型
        常见的就是二维点坐标和三维点坐标Point2i,Point3f
    */
   // 1、常见的别名
    Point2i pi1(1,2);Point2f pf1(1.1,2.2);Point2d pd1(1.1,2.2);Point2l pl1(1,2);
    Point3i pi2(1,2,3);Point3f pf2(1.1,2.2,3.3);Point3d pd2(1.1,2.2,3.3);
    
    // 2、默认构造、复制构造和值构造
    Point2i pi3;//默认构造
    Point2i pi4(pi3);//复制构造
    Point2i pi5(1,2);//值构造

    // 3、可转换类型,例如Size,Rect,Vec3f等
    Size s1 = pi5; // 隐式转换
    Size s2 = (Size)pi5; // 显示转换
    cout<<"s1.width="<<s1.width<<endl; // 1
    cout<<"s2.height="<<s2.height<<endl; // 2
    cout<<"s2.area="<<s2.area()<<endl; // 2
    cout<<"s2.empty="<<s2.empty()<<endl; // 0
    cout<<"s2.aspectRatio="<<s2.aspectRatio()<<endl; // width/height=0.5
    Rect r1 = Rect(Point(1,2),Size(3,4)); // 一种构造函数
    Rect r2 = Rect(1,2,3,4); // 另一种构造函数
    Vec3f v1 = (Vec3f)Point3f(1.1,2.2,3.3); // 显示转换

    // 4、成员访问
    cout<<"pi5.x="<<pi5.x<<endl; // 1
    cout<<"pi5.y="<<pi5.y<<endl; // 2

    // 5、点乘和双精度点乘
    cout<<"pi5.dot(pi5)="<<pi5.dot(pi5)<<endl; // 5
    cout<<"pi5.ddot(pi5)="<<pi5.ddot(pi5)<<endl; // 5

    // 6、叉乘
    cout<<"pi5.cross(pi5)="<<pi5.cross(pi5)<<endl; // 0

    // 7、判断点是否在矩形r内
    cout<<"pi5.inside(r1)="<<pi5.inside(r1)<<endl; // 1

    return 0;
}