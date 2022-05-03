#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Scalar -g Scalar.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Scalar
*/
int main(int argc,char**argv)
{
    /*
        Scalar是四维双精度向量的快速表示，继承于固定向量模板实例Vec4d
        继承了所有的向量代数操作、成员访问函数等,具体可以看Vec.cpp的部分
        这里只介绍一些简单的操作
    */
    // 构造函数,默认+复制+值构造
    Scalar s1; // 默认构造函数
    Scalar s2(s1); // 复制构造
    Scalar s3(1,2,3,4);//值构造
    Scalar s4(1,-1); // 复制构造
    cout<<"s3: "<<s3<<endl; // [1, 2, 3, 4]
    cout<<"s4: "<<s4<<endl; // [1, -1, 0, 0]
    // 元素相乘
    double scale = 2.5;
    Scalar mul = s4.mul(s4,scale); // [2.5, 2.5, 0, 0]
    cout<<"mul: "<<mul<<endl;
    // 四元数共轭
    Scalar conj = mul.conj(); // [2.5, -2.5, -0, -0]
    cout<<"conj: "<<conj<<endl;
    // 四元数真值测试
    cout<<boolalpha<<"mul.isReal(): "<<mul.isReal()<<endl;//false

    // 其他操作均在Vec.cpp已有体现,不再赘述
    return 0;
}