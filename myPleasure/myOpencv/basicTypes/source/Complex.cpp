#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Complex -g Complex.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Complex
*/
int main(int argc,char**argv)
{
    /*
        和STL的complex<>不一样但是兼容,最大区别是成员获取
        STL通过实部和虚部的成员函数real()和imag()获取
        OpenCV通过成员访问获取,即re和im
    */
    // 默认、复制和值构造函数
    Complexf c1; // 默认构造函数,Complex c1是不允许的
    Complex c2(c1); // 复制构造
    Complex c3(1.1,2.2);//值构造
    Complexd c4(c3); // 复制构造
    // 成员访问
    cout<<"c3: "<<c3<<endl; // [1.1, 2.2]
    cout<<"c3.re: "<<c3.re<<endl; // 1.1
    cout<<"c3.im: "<<c3.im<<endl; // 2.2
    // 复共轭
    Complex c5 = c3.conj(); // [1.1, -2.2]
    cout<<"c5: "<<c5<<endl;

    return 0;
}