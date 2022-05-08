#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\DataType -g DataType.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/DataType.exe
*/
template<typename _Tp> class DataType {
    typedef _Tp value_type;
    typedef value_type working_type;
    typedef value_type channel_type;
    typedef value_type vec_type;

    enum { 
        generic_type = 1, 
        depth = -1,
        channels = 1,
        fmt = 0,
        type = CV_MAKETYPE(depth, channels)
    };
};
int main(int argc,char**argv)
{
    /*
        Opencv中传递特定数据类型的概念时会创建一个cv::DataType类型的对象
        该对象包含了数据类型的各种信息，包括其名称、其大小、其类型等
        DataType类型的对象可以通过cv::DataType::allTypes()函数获取
        它本身是一个模板,传递的实际对象是这个模板的特化
        这是一个在C++中称为trait的概念
        DataType的定义如下：
        template<typename _Tp> class DataType {
            typedef _Tp value_type;
            typedef value_type working_type;
            typedef value_type channel_type;
            typedef value_type vec_type;

            enum { 
                generic_type = 1, 
                depth = -1,
                channels = 1,
                fmt = 0,
                type = CV_MAKETYPE(depth, channels)
            };
        };
        首先DataType<>是一个模板,它希望被一个_Tp类型特化,内含4个typedef声明和1个enum声明
        typedef声明可以让我们在程序中使用DataType<>::value_type来访问value_type
        也就是在编译的时候就已经知道了value_type的类型

        首先看一个基于float类型的特化例子
        template<> class DataType<float> {
            typedef float value_type;
            typedef value_type working_type;
            typedef value_type channel_type;
            typedef value_type vec_type;

            enum { 
                generic_type = 0,
                depth = DataDepth<channel_type>::value,
                channels = 1,
                fmt = DataDepth<channel_type>::fmt,
                type = CV_MAKETYPE(depth, channels)
            };
        };
        这里value_type是float,working_type是float,channel_type是float,vec_type是float
        要说明的是value_type表示值类型,working_type表示工作类型,channel_type表示通道类型,vec_type表示向量类型
        枚举值中generic_type定义的是否是一个通用类型,depth定义的是通道类型的深度,channels定义的是通道数量
        fmt定义的是通道类型的格式,type定义的是通道类型的类型
        其中depth和fmt都要基于channel_type来计算,知道通道类型才知道深度和格式
        对于float来说,它首先是个通用类型,深度是32位,通道数量是1,格式是浮点数
        所以generic_type是0,depth是32,channels是1,fmt是CV_32F,type是CV_MAKETYPE(32,1)
        所以type被解析成CV_32FC1

        DataType<>更重要的功能是与更复杂的结构进行交互,例如与传入数据类型无关的方式实现算法
        这里再举一个例子,即Rect_<_Tp>的例子
        template<typename _Tp> class DataType<Rect_<_Tp> > {
            public:
                typedef Rect_<_Tp> value_type;
                typedef Rect_<typename DataType<_Tp>::working_type> working_type;
                typedef _Tp channel_type;
                typedef Vec<channel_type, channels> vec_type;

            enum{
                generic_type = 0,
                depth = DataDepth<channel_type>::value,
                channels = 4,
                fmt = ((channels-1)<<8) + DataDepth<channel_type>::fmt,
                type = CV_MAKETYPE(depth, channels)
            };
        };
        首先要注意cv::Rect并没有出现,它其实是一个模板的别名也就是cv::Rect_<>
        这个模板可以被特化为cv::DataType<Rect>或者cv::DataType<Rect_<_Tp> >如cv::DataType<Rect_<float> >
        本例中的特化形式是cv::DataType<Rect>,考虑到所有的元素是整型,即Rect.x,Rect.y,Rect.width,Rect.height
        故这个例子中所有_TP都解析为int
        value_type表示Rect_<_Tp>的值类型,也就是Rect<int>
        working_type被定义为typename DataType<_Tp>的工作类型即int,可以告诉cv::DataType<>由什么类型数据组成,这里是Rect_<int>,也是Rect<int>
        channel_type表示通道类型,这里是int
        vec_type表示向量类型,这里是Vec<int,4>
        至于运行时常量,也就是枚举类型
        generic_type是0,depth是CV_32S,channels是4(因为有4个数)
        fmt解析为0x3069,因为i是0x69,type是CV_MAKETYPE(32,4),解析为CV_32SC4
    */
    return 0;
}