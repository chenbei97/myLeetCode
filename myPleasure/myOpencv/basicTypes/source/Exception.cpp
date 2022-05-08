#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp> // include exceptions
#include <opencv2/core/base.hpp> // include enum codes
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Exception -g Exception.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Exception
*/
int main(int argc,char**argv)
{
    /*
        https://docs.opencv.org/4.x/d1/dee/classcv_1_1Exception.html#a95c2117604b1d51c17e5ccd540f448b9
        opencv的异常处理类继承自STL的异常处理类，仅仅是命名空间不同
        cv::Exception是一个类，它的父类是std::exception
        所以继承了virtual const char* cv::Exception::what()const throw()函数
        并定义了自己的输出印象函数
        void cv::Exception::formatMessage	()	

        cv::Exception的成员有code、err、func、file和line
        cv::Exception::Exception(int _code,const String & _err,const String & _func,const String & _file,int _line )	
        分别表示数字错误码、对应表示异常错误的字符串、错误发生的函数名、错误发生的文件和错误发生所在行数
        err、func、file都是const string&类型，可以直接输出
        枚举类型定义在#include <opencv2/core/base.hpp>的命名空间ERROR中

        有几个内置宏用于自己生成异常处理类，这些宏的名字是CV_Error,CV_Error_,CV_Assert,CV_Assert_
        CV_Error是一个内置宏，它的参数是一个错误码和一个错误信息，即#define CV_Error(code,msg) cv::error( code, msg, CV_Func, __FILE__, __LINE__ )
        #define CV_Error_(code,args,cv::error(code, cv::format args, CV_Func, __FILE__, __LINE__)		   
        
        而CV_ERROR_可以允许使用类似printf格式字符串的参数代替固定的描述
        其宏原型为CV_Error_(errorcode,printf_fmt_str,[printf-args]..),其中使用格式控制需要使用()括起来
        
        CV_Assert是一个内置宏，它的参数是一个布尔表达式，如果表达式为false，则抛出异常
        #define CV_Assert(expr)do { if(!!(expr)) ; else cv::error( cv::Error::StsAssert, #expr, CV_Func, __FILE__, __LINE__ ); } while(0)

        CV_DbgAssert(expr)也是一个内置宏，它的参数是一个布尔表达式，如果表达式为false，则抛出异常
        但是这个宏要求只能在debug模式下使用,CV_Assert可以在release模式下使用
        
    */
    // CV_Error的例子,枚举类型定义在#include <opencv2/core/base.hpp>
    // CV_Error(Error::StsOutOfRange, "The value is out of range");
    // 也可以使用cv::error,但是后面的3个参数不能省略
    // cv::error(Error::StsOutOfRange, "The value is out of range", CV_Func, __FILE__, __LINE__);
    // CV_Error_的例子,使用printf字符串控制需要用小括号括起来
    Point badPt = Point(1,2);
    int badValue = -1;
    // CV_Error_(Error::StsOutOfRange,("the value at (%d, %d)=%g is out of range", badPt.x, badPt.y, badValue));

    // CV_Assert的例子
    CV_Assert(badValue != 0); // it's ok
    return 0;
}