#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Mat -g Mat.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Mat
*/
int main(int argc,char**argv)
{
    /*
        Mat可以用于存储任意维度的稠密数组,稠密表示该数组的所有部分都可以有一个值0存储
        稀疏矩阵的存储方式是不同的,其实存储数据的只是一维数组
        但是索引稀疏矩阵的某个元素时会按照一定的规则获取一维数组上的数,降低内存占用
        这里不讲SparseMat的使用,大部分操作和Mat没有区别

        所有的矩阵都包含的属性：
            flag：矩阵元素的类型
            dims：矩阵的维度
            rows：矩阵的行数
            cols：矩阵的列数
            data：指示数据真正存储位置的指针
            refcount：指示该矩阵的引用计数，类似于cv::Ptr<>的引用计数器，该成员可智能管理内存区域

        数据实体data的结构被step[]所描述，对于常见的二维数组公式为：
        &(mtx i,j) = mtx.data + i*mtx.step[0] + j*mtx.step[1]
        其中，mtx.step[0]是行步长，mtx.step[1]是列步长，mtx.step[i]是第i维度步长

        Mat也不要求数据必须是简单基元，元素可以是一个简单的数字也可以是多个数字
        队医多个数字的元素就称为多通道数组，实际上n维数组和n-1维的多维数组有着相似结构
        例如一个数组可能会被声明为二维三通道32位浮点型的数组，那么此时数组的元素是大小为12子节的32位浮点数
        在内存中，数组的行可能不是按顺序存储，由于数据对齐原因每行之间存在很小的间隔
        n维单通道数组和(n-1)维多通道数组区别就是，这种填充始终出现于每一行的末尾

        完整的Mat构造函数如下，其中常用的1-5,非常用6-10：
        常用构造函数：
        1、Mat：默认构造函数
        2、Mat(rows,cols,type)：指定行数、列数和类型的构造函数,二维数组
        3、Mat(rows,cols,type,const Scalar&s)：指定行数、列数、类型和初始值的构造函数,二维数组
        4、Mat(Size sz,type)：Size指定宽度和高度对于列和行,二维数组
        5、Mat(Size sz,type,const Scalar&s)：Size指定宽度和高度，Scalar指定填充值,二维数组
        非常用的构造函数：
        6、Mat(rows,cols,type,void*data,size_t step=AUTO_STEP)：指定行数、列数、类型和数据的构造函数,二维数组
        7、Mat(Size sz,type,void*data,size_t step=AUTO_STEP)：Size指定宽度和高度，data指定数据，step指定步长,二维数组
        8、Mat(int dims,const int*size,int type)：dims指定维度，size指定每一维的大小，type指定类型,多维数组
        9、Mat(int dims,const int*size,int type,const Scalar&s)：dims指定维度，size指定每一维的大小，type指定类型，s指定填充值,多维数组
        10、Mat(int dims,const int*size,int type,void*data,size_t*step)：dims指定维度，size指定每一维的大小，type指定类型，data指定数据，step指定步长,多维数组

        其中，Scalar允许指定某个类型,让初始化的所有数据都是这个值
        也可以提供一个执行数据块的指针,对于Mat来说只是创建了一个指向已存在数据的头,不会发生数据复制
        data成员会被设置位data参数指向的区域

        Mat也存在复制构造方法：
        常用的复制构造函数：
        1、Mat(const Mat&m)：复制一个Mat对象
        2、Mat(const Mat&m,const Range&rowRange,const Range&colRange)：复制一个Mat对象的一部分,从指定的行列构造
        3、Mat(const Mat&m,const Rect&roi)：复制一个Mat对象的一部分,从指定的矩形构造
        不常用的复制构造函数：
        4、Mat(const Mat&m,const Range*ranges)：复制一个Mat对象的一部分,从指定的行列范围构造,服务于n维数组
        5、Mat(const MatExpr&expr)：复制一个MatExpr对象,从其他矩阵的线性代数表述生成新矩阵

        Mat还存在一组模板构造函数，即依据模板创建Mat的实例
        允许使用Vec、Matx以及STL的vector来创建
        1、Mat(const Vec<T,n>&vec,bool copyData=true)：从一个Vec模板创建一个Mat对象,n为维度,T为类型
        2、Mat(const Matx<T,m,n>&matx,bool copyData=true)：从一个Matx模板创建一个Mat对象,m为行数,n为列数,T为类型
        3、Mat(const vector<T>&vec,bool copyData=true)：从一个vector模板创建一个Mat对象,T为类型

        Mat存在一些静态方法,诸如ones、zeros、eye等,它们可以直接调用,在Vec.cpp展示过它们的用法,Mat类似
        1、Mat::ones(rows,cols,type)：创建一个全1的矩阵
        2、Mat::zeros(rows,cols,type)：创建一个全0的矩阵
        3、Mat::eye(rows,cols,type)：创建一个单位矩阵(对角线为1,其他为0)

        Mat的访问方式主要是2种,一种是基于模板函数at<T>(),另一种是基于迭代器访问
        如果是一维的,T就是常见内置类型,如uchar、float、double等
        如果是二维的,T常常使用Point2f类型,即img.at<Point2f>(i,j)表示第i行第j列的点
        如果是三维的,T常常使用Vec3f类型,但是也只有i,j,第三个维度使用[]访问,即img.at<Vec3f>(i,j)[k]表示第i行第j列的点的第k个维度

    */
    // 1、常用构造函数测试
    Mat m1; // 1、Mat
    Mat m2(3,3,CV_8UC3); // 2、Mat(int rows,int cols,int type)
    Mat m3(3,3,CV_8UC3,Scalar(0,0,255)); // 3、Mat(int rows,int cols,int type,Scalar s)
    Mat m4(3,3,CV_8UC1,Scalar(0)); // 4、Mat(int rows,int cols,int type,Scalar s)
    Mat m5(Size(3,3),CV_8UC3); // 5、Mat(Size size,int type)
    Mat m6(Size(3,3),CV_8UC1,Scalar::all(0)); // 6、Mat(Size size,int type,Scalar s)
    // 2、常用复制构造函数
    Mat m7(m1); // 1、Mat(const Mat&m)
    Mat m8(m2,Range(0,1),Range(0,1)); // 2、Mat(const Mat&m,const Range&rowRange,const Range&colRange)
    Mat m9(m2,Rect(0,0,1,1)); // 3、Mat(const Mat&m,const Rect&roi)
    // 3、模板构造函数
    Mat m10(Vec<uchar,3>(110, 99, 121)); // 1、Mat(const Vec<T,n>&vec,bool copyData=true)
    Mat m11(Matx<float,3,3>(1, 2, 3, 4, 5, 6, 7, 8, 9)); // 2、Mat(const Matx<T,m,n>&matx,bool copyData=true)
    Mat m12(vector<uchar>{0,0,255}); // 3、Mat(const vector<T>&vec,bool copyData=true)
    
     // 4、访问方式
    // 4.1、基于模板函数at<T>()
    // 4.1.1、单通道
    // 4.1.1.1、一维数组: at<uchar>(i)
    uchar u1 = m10.at<uchar>(0); //  n
    uchar u2 = m10.at<uchar>(1); //  c
    uchar u3 = m10.at<uchar>(2); // y
    cout << "uchar u1 = " << u1 << " uchar u2 = " << u2 << " uchar u3 = " << u3 << endl;
    // m10.at<Point2i>(0,0) = Point2i(1, 2); // 不允许
    // m10.at<Vec2i>(0,0) = Vec2i(1, 2); // 不允许
    
    // 4.1.1.2、二维数组: at<uchar>(i,j)
    Mat m13(Size(3, 2), CV_8UC1);
    cout << "m13.channels() = " << m13.channels() << endl; // 是单通道的
    m13.at<uchar>(0, 0) = 10; m13.at<uchar>(0, 1) = 11; m13.at<uchar>(0, 2) = 12;
    m13.at<uchar>(1, 0) = 13; m13.at<uchar>(1, 1) = 14; m13.at<uchar>(1, 2) = 15;
    cout << "m13 = \n" << m13 << endl;// [ 10, 11, 12;  13, 14, 15]
   // m13.at<Point2i>(0, 0) = Point2i(1, 2); // uchar不允许
   //  m13.at<Vec2i>(0, 0) = Vec2i(1, 2); // uchar不允许
   
   // 单通道浮点数的二维数组虽然可以使用point2f访问但是会漏或多一些东西
    // 这是因为内存访问按照指定大小跨越,一对sizeof(float)逐个的被Point2f捕获
    Mat  m13_(Size(3, 2), CV_32FC1);
    m13_.at<float>(0, 0) = 10.; m13_.at<float>(0, 1) = 11; m13_.at<float>(0, 2) = 12.;
    m13_.at<float>(1, 0) = 13.; m13_.at<float>(1, 1) = 14; m13_.at<float>(1, 2) = 15.;
    cout << "m13_ = \n" << m13_ << endl;// [ 10, 11, 12;  13, 14, 15]
    cout << "m13_(0,0) = " << m13_.at<Point2f>(0, 0)  // float允许
        << " m13_(0,1) = " << m13_.at<Point2f>(0, 1) << endl; // m13_(0,0) = [10, 11] m13_(0,1) = [12, 13]
    cout << "m13_(1,0) = " << m13_.at<Point2f>(1, 0) 
        << " m13_(1,1) = " << m13_.at<Point2f>(1, 1) << endl; // m13_(1,0) = [13, 14] m13_(1,1) = [15, -4.31602e+08] 多了1个
    m13_.at<Point2f>(0, 0) = Point2f(1, 2); // float允许
    cout << "m13_ = \n" << m13_ << endl;//[1, 2, 12 ;13, 14, 15]

   // m11是Matx初始化的二维数组,和m13_类似,使用Point2f会漏东西
    cout << "m11.channels() = " << m11.channels() << endl; // 1,是单通道的
    Point2f p1 = m11.at<Point2f>(0, 0); cout << "point2f p1 = " << p1 << "\n"; // [1, 2]
    Point2f p2 = m11.at<Point2f>(0, 1); cout << "point2f p2 = " << p2 << "\n"; // [3, 4]
    Point2f p3 = m11.at<Point2f>(1, 0); cout << "point2f p3 = " << p3 << "\n"; // [4, 5]
    Point2f p4 = m11.at<Point2f>(1, 1); cout << "point2f p4 = " << p4 << "\n"; // [6, 7],8和9漏了
    cout << "m11 = \n" << m11 << endl;//[1, 2, 3;4,5,6;7,8,9]

    // 4.1.1.3、三维数组(很少使用,需要借助不常用的构造函数构建高维数组(dims≥3)): at<uchar>(i,j,k)
    int sz14[] = { 2,3,4 };
    const int* psz14 = sz14;
    float data14[2*3*4] = {};
    for (int i = 0; i < 2 * 3 * 4; ++i) data14[i] = (i +1)/ 24.0;
    Mat m14(3, psz14, CV_32FC1,data14); // dims=3, 2×3×4
    cout << "m14(0,0,0) = "<<m14.at<float>(0, 0, 0) 
            << " m14(0,0,1) = " << m14.at<float>(0, 0, 1)
            << " m14(0,0,2) = " << m14.at<float>(0, 0, 2)
            << " m14(0,0,3) = " << m14.at<float>(0, 0, 3)<< endl;
    cout << "m14(0,1,0) = " << m14.at<float>(0, 1, 0)
        << " m14(0,1,1) = " << m14.at<float>(0, 1, 1)
        << " m14(0,1,2) = " << m14.at<float>(0, 1, 2)
        << " m14(0,1,3) = " << m14.at<float>(0, 1, 3) << endl;
    cout << "m14(0,2,0) = " << m14.at<float>(0, 2, 0)
        << " m14(0,2,1) = " << m14.at<float>(0, 2, 1)
        << " m14(0,2,2) = " << m14.at<float>(0, 2, 2)
        << " m14(0,2,3) = " << m14.at<float>(0, 2, 3) << endl;
    cout << "m14(1,0,0) = " << m14.at<float>(1, 0, 0)
        << " m14(1,0,1) = " << m14.at<float>(1, 0, 1)
        << " m14(1,0,2) = " << m14.at<float>(1, 0, 2)
        << " m14(1,0,3) = " << m14.at<float>(1, 0, 3) << endl;
    cout << "m14(1,1,0) = " << m14.at<float>(1, 1, 0)
        << " m14(1,1,1) = " << m14.at<float>(1, 1, 1)
        << " m14(1,1,2) = " << m14.at<float>(1, 1, 2)
        << " m14(1,1,3) = " << m14.at<float>(1, 1, 3) << endl;
    cout << "m14(1,2,0) = " << m14.at<float>(1, 2, 0)
        << " m14(1,2,1) = " << m14.at<float>(1, 2, 1)
        << " m14(1,2,2) = " << m14.at<float>(1, 2, 2)
        << " m14(1,2,3) = " << m14.at<float>(1, 2, 3) << endl;
    
    // 4.1.2、双通道
    // 4.1.2.1、一维数组且双通道(不存在)
    Mat m15(1, 3, CV_32FC2); // 即使这样也是二维数组,向量初始化模板就是m10,默认是单通道初始化的
    cout << "m10.channels() = " << m10.channels() << endl; // channels = 1

    // 4.1.2.2、二维数组视为双通道
    Mat m16(Size(3, 2), CV_8UC2); // 2行3列
    // 使用uchar赋值只能覆盖第1通道
    m16.at<uchar>(0, 0) = 1; m16.at<uchar>(0, 1) = 2; m16.at<uchar>(0, 2) = 3;
    m16.at<uchar>(1, 0) = 4; m16.at<uchar>(1, 1) = 5; m16.at<uchar>(1, 2) = 6;
    cout << "m16 = \n" << m16 << endl; // 其实只是把第1个通道赋值了,第2个通道没有赋值
    // [1,   2,   3, 205, 205, 205;4,   5,   6, 205, 205, 205]
    // m16.at<Point2i>(0, 0) = Point2i(1, 2);  // 这种方式是不允许的,同理Vec2i

    Mat m16_(2, 3, CV_32FC2);
    m16_.at<float>(0, 0) = 1; m16_.at<float>(0, 1) = 2; m16_.at<float>(0, 2) = 3;
    m16_.at<float>(1, 0) = 4; m16_.at<float>(1, 1) = 5; m16_.at<float>(1, 2) = 6;
    cout << "m16_ = \n" << m16_ << endl; // 浮点数同理,只覆盖第1通道
    // 浮点数允许使用Point2f赋值,且可以对第2通道赋值
    m16_.at<Point2f>(0, 1) = Point2f(-1.0, -2.0); m16_.at<Point2f>(0, 1) = Point2f(-3.0, -4.0); m16_.at<Point2f>(0, 2) = Point2f(10.0, 11.0);
    m16_.at<Point2f>(1, 0) = Point2f(-5.0, -6.0); m16_.at<Point2f>(1, 1) = Point2f(-7.0, -8.0); m16_.at<Point2f>(1, 2) = Point2f(15.0, 16.0);
    cout << "m16_ = \n" << m16_ << endl; // [1, 2, -3, -4, 10, 11;-5, -6, -7, -8, 15, 16]
    
    // 4.1.2.3、三维数组视为双通道
    return 0;
}