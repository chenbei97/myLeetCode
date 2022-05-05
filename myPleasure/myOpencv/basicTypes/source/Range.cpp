#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Range -g Range.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Range
*/
int main(int argc,char**argv)
{
    /*
        Range类是一个区间，它是一个类，它需要指定一个起始值和一个结束值，前闭后开
        它的实例包含两个方法，分别是empty和size
        empty方法返回一个bool值，表示该区间是否为空
        size方法返回一个int值，表示该区间的大小
    */
    // Range可以单独使用
    Range range1(1,10);
    cout<<boolalpha<<"range1.empty()="<<range1.empty()<<endl; // false
    cout<<"range1.size()="<<range1.size()<<endl;// 9
    cout<<"range1.start="<<range1.start<<endl;// 1
    cout<<"range1.end="<<range1.end<<endl; // 10
    // all函数是一个静态函数，它返回一个Range对象，表示一个区间，起始值为0，结束值为-1
    Range range2 = Range::all();
    cout<<"range2.start="<<range2.start<<endl;// 未定义
    cout<<"range2.end="<<range2.end<<endl;// 未定义
    cout<<"range2.size()="<<range2.size()<<endl;// -1
    cout<<"range2.empty()="<<range2.empty()<<endl;// false
    // 一般作为Mat类的选择区间参数去使用
    // 例如先读取一个图像
    Mat src = imread("../../examples/images/lena.jpg");
    if (src.empty())
    {
        cout<<"failed to load image"<<endl;
        return -1;
    }else cout << "load image successful" << endl;
    cout<<"src.size="<<src.size()<<endl;// Size(220,220)
    // 获取src100行到150行的区间
    Mat src_chunck1 = src(Range(100,150),Range::all()); // 行只要100行到150行,列全部
    cout<<"src_chunck1.size="<<src_chunck1.size()<<endl;// Size(220,50)
    // 获取src50-80列的区间
    Range col_range(50,80);
    Mat src_chunck2 = src(Range::all(),col_range); // 行全部,列只要50列到80列
    cout<<"src_chunck2.size="<<src_chunck2.size()<<endl;// Size(30,220)
    return 0;
}