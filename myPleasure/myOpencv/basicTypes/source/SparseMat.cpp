#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\SparseMat -g SparseMat.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/SparseMat
*/
int main(int argc,char**argv)
{
    /*
        Mat存储数据按照C风格的可以按照索引得到数据元素，SparseMat使用哈希表存储非0元素,适用于非0元素很少的矩阵
        SparseMat最大的区别就是访问元素的机制不同，可以使用4种方法访问
        即SparseMat::ptr()、SparseMat::ref<>()、SparseMat::value<>()和SparseMat::find<>()函数
        1、ptr方法,存在一些变体
            1.1、uchar* SparseMat::ptr(int i, bool createMissing,size_t * hashcal = 0); // 用于一维数组访问的
            参数：
                i：表示请求元素的索引
                createMissing：表示是否创建缺失元素，如果这个元素不存在于数组中，则创建一个缺失元素
                hashcal：表示哈希值，如果不需要计算哈希值，可以将其设置为0
            返回值：
                返回请求元素的指针
            1.2、uchar* SparseMat::ptr(int i, int j, bool createMissing,size_t * hashcal = 0); // 用于二维数组访问的
            1.3、uchar* SparseMat::ptr(int i, int j, int k, bool createMissing,size_t * hashcal = 0); // 用于三维数组访问的
            1.4、uchar* SparseMat::ptr(const int * idx, bool createMissing,size_t * hashcal = 0);
                参数：
                    idx：表示请求元素的索引数组,用于访问更多维的数组
                    createMissing：表示是否创建缺失元素，如果这个元素不存在于数组中，则创建一个缺失元素
                    hashcal：表示哈希值，如果不需要计算哈希值，可以将其设置为0
                返回值：
                    返回请求元素的指针
        2、ref<>()方法,返回一个指向数组中特定元素的引用,类似于ptr,也可以接受1,2,3个索引或者一个索引数组
            但ref是个模板函数,必须指定对象类型,默认CV_32F,也就是ref<>()使用的是CV_32F类型
            2.1、template<typename _Tp> _Tp& ref<_TP>(int i ,size_t * hashcal = 0 ); // 用于一维数组访问的
            2.2、template<typename _Tp> _Tp& ref<_TP>(int i ,int j,size_t * hashcal = 0 ); // 用于二维数组访问的
            2.3、template<typename _Tp> _Tp& ref<_TP>(int i ,int j,int k,size_t * hashcal = 0 ); // 用于三维数组访问的
            2.4、template<typename _Tp> _Tp& ref<_TP>(const int * idx,size_t * hashcal = 0 );// 用于多维数组访问的
        3、value<>()方法和ref<>()类似,但是返回的是值而非引用,也就是只读的
            多了2个变体,也就是基于SparseMat::Node*的变体
            3.1、template<typename _Tp> _Tp<> value<_TP>(int i ,size_t * hashcal = 0 ); // 用于一维数组访问的
            3.2、template<typename _Tp> _Tp value<_TP>(int i ,int j,size_t * hashcal = 0 ); // 用于二维数组访问的
            3.3、template<typename _Tp> _Tp value<_TP>(int i ,int j,int k,size_t * hashcal = 0 ); // 用于三维数组访问的
            3.4、template<typename _Tp> _Tp value<_TP>(const int * idx,size_t * hashcal = 0 );// 用于多维数组访问的
            3.5、template<typename _Tp> _Tp& value<_TP>(Node*n) ; // 使用Node*访问
            3.6、template<typename _Tp> const _Tp& value<_TP>(const Node*n) ; // 使用const Node*访问
        4、find<>(),返回指向元素的指针,但是基于模板实现不同于ptr
            find返回的是只读const指针,很多时候和ptr还是不能转换的
            4.1、const _Tp* find<_TP>(int i ,size_t * hashcal = 0 ) const; // 用于一维数组访问的
            4.2、const _Tp* find<_TP>(int i ,int j,size_t * hashcal = 0 ) const; // 用于二维数组访问的
            4.3、const _Tp* find<_TP>(int i ,int j,int k,size_t * hashcal = 0 ) const; // 用于三维数组访问的
            4.4、const _Tp* find<_TP>(const int * idx,size_t * hashcal = 0 ) const; // 用于多维数组访问的
    */
    return 0;
}