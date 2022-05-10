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

        Mat的访问方式主要是3种,一种是基于模板函数at<T>(),一种是基于智能指针ptr，另一种是基于迭代器访问
        借助模板函数at<T>()访问:
        对于单通道的一维数组使用at<T>(i),二维数组使用at<T>(i,j),三维数组使用at<T>(i,j,k)
        对于双通道的一维数组不存在,二维数组对于uchar类型不能使用Point2i,float类型可以使用Point2f(i,j)/Vec2f(i,j)访问
            如果单独使用uchar或者float只能访问到第1通道,第2通道必须借助Point2f(i,j)/Vec2f(i,j)[k]访问
            三维数组,无法借助Vec或Point访问,也不能借助单独的float或uchar访问,只能借助step访问
        对于三通道的一维数组不存在,三维数组不常用忽略,二维数组最常用,基于Vec3f/Vec3b访问
        借助智能指针访问:
        只针对单通道和三通道的二维图像进行说明,如果是三通道uchar*p或者Vec3f *p可以获取某行指向第一个通道的指针
            如果是单通道,这两个指针实际就是指向了1个元素的指针
        借助迭代器访问:
        需要使用MatIterator类型的迭代器,可以使用begin()和end()方法获取迭代器,迭代器可以使用++和--进行前后移动
            对于单通道直接按照一行行打印元素,对于三通道每次打印的是一个Vec3f,即(i,j)位置的连续3个通道元素
        三种方式，ptr是最快的，迭代器是最慢的，无论是单通道还是三通道

        Mat还可以通过块访问,例如col(int)和row(int)可以返回该行或该列的data指针,改变指针内容就可以改变原有数据
        不过col()和row()只适用于二维数组
        与col,row密切相关的是rowRange()和colRange()方法,可以返回一个Mat对象,该对象包含了一行或一列的数据
        colRange(col1,col2),rowRange(row1,row2)
        相关的类是Range,rowRange(Range(x0,x1)),colRange(Range(x0,x1)),借助Range类型的对象可以获取某一行或某一列的数据
        Range类其实也能实现rowRange()和colRange()的功能,注意左闭右开,即m(Range(x1,x2),Range(y1,y2)),这里不赘述见Range.cpp
        还可以使用Rect获取一个矩形区域的Mat对象,m(Rect(x,y,w,h))会获取(x,y)到(x+2-1,y+h-1)的矩形区域,注意左闭右开
        diag()：返回对角线元素的Mat对象,如果是0就是主对角线,如果是整数就是相对主对角线向上的偏移对角线,反之向下偏移

        Mat的常用运算方法，支持矩阵之间的加减法和矩阵与元素之间的加减法，支持取负
        支持按元素相乘除mul、/，矩阵乘法 *，求逆inv、转置t()、
        按元素比较，返回0-255的uchar矩阵，就是掩码
        矩阵之间或矩阵和元素之间按位进行逻辑操作
        矩阵之间或矩阵和元素之间按元素选择最大值和最小值，以及按元素取绝对值
        1、矩阵之间的加减法： m0 = m1 + m2; m0 = m1 - m2;
        2、矩阵与元素之间的加减法： m0 = m1 + 2; m0 = m1 - 2;
        3、矩阵与元素之间的乘法： m0 = m1 * 2; m0 = m1 / 2;
        4、矩阵和矩阵按元素相乘除： m0 = m1 * m2; m0 = m1 / m2;
        5、矩阵取负： m0 = -m1;
        6、矩阵转置zi： m0 = m1.t();
        7、矩阵求逆： m0 = m1.inv(DECOMP_LU); // DECOMP_LU表示使用LU分解法,还可以使用DECOMP_SVD和DECOMP_CHOLESKY
            LU分解法必须是非奇异矩阵,SKY解法适用于矩阵半正定,此时大型矩阵运算速度很快,SVD解法可用于奇异矩阵求出伪逆
        8、矩阵按元素比较： m0 = m1 > m2; m0 = m1 < m2; m0 = m1 == m2; m0 = m1 != m2;
        9、矩阵与矩阵之间的按位运算： m0 = m1 & m2; m0 = m1 | m2; m0 = m1 ^ m2;
        10、矩阵与元素之间的按位运算： m0 = m1 & 2; m0 = m1 | 2; m0 = m1 ^ 2;
        11、矩阵与矩阵之间的按元素选择最大值和最小值： m0 = max(m1,m2); m0 = min(m1,m2);
        12、矩阵与元素之间的按元素选择最大值和最小值： m0 = max(m1,2); m0 = min(m1,2);
        13、矩阵与矩阵之间的按元素取绝对值： m0 = abs(m1);
        14、矩阵的叉乘： m0 = m1.cross(m2); 只适用于3x1和1x3的矩阵
        15、矩阵的点积： m0 = m1.dot(m2); 
        16、其它诸如cv::sum(),cv::norm(),cv::mean()可以分别求和、范数、均值等

        Mat具备饱和转换操作，即saturate_cast()函数，可以将其他类型的Mat转换为指定类型的Mat
        可以自动检测是否上溢出或者下溢，如果是，则进行饱和转换，该函数具有返回值，与要转换的类型一致

        Mat更多的函数成员，这里并不一一测试：
        1、m1 = m0.clone()：从m0完全复制给m1,该操作将复制所有的数据元素
        2、m0.copyTo(m1)：将m0中的数据元素复制给m1,等同于clone()
        3、m0.convertTo(m1,type,scale=1,offset=0)：将m0转换为m1,type为转换的类型,scale为缩放因子,offset为偏移量
        4、m0.assignTo(m1,type)：只在内部使用,集成在convertTo
        5、m0.setTo(value,mask)：将m0中的所有数据元素设置为value,如果有mask,则针对mask中的数据元素设置为value
        6、m0.reshape(cn,rows)：将m0转换为cn列，rows行的矩阵,可以为0表示不做更改
        7、m0.push_back(m1)：将m1添加到m0的末尾,m1是个?×n的数组
        8、m0.pop_back(n)：从m×n的矩阵移除行,默认是1
        9、m0.locateROI(size,offset)：返回m0的ROI区域，size为m0的大小，offset为Point偏移量,以(宽,高)=(列,行)给出
        10、m0.adjustROI(up,down,left,right)：通过4个值来调整ROI范围,也就是类似截图操作,负数表示截掉多少行多少列,方向取决于参数
        11、m0.total()：计算数组序列的元素数目,不包括通道
        12、m0.isContinuous()：如果m0的行之间没有空隙将返回true,说明是连续的内存
        13、m0.elemSize()：返回m0的位长度，例如三通道浮点矩阵返回12,因为每个通道float占据4字节
        14、m0.elemSize1()：返回m0最基本元素的位长度,三通道浮点矩阵返回12,因为float是4字节
        15、m0.type()：返回元素类型如CV_32FC3对应的整数枚举值
        16、m0.depth()：返回通道中元素类型如CV_32F
        17、m0.channels()：通道数
        18、m0.size()：返回矩阵的(宽,高)=(行,列)
        19、m0.empty()：矩阵是否存在元素,等价于m0.total==0 & m0.data=nullptr
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
    int sz14[] = { 2,3,4 }; // 高、宽、长 = 2，3，4
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
    cout<<"m16_(0,1)[0]"<<m16_.at<Vec2f>(0,1)[0] <<endl;
    /*
        [1, 2, -3, -4, 10, 11;
        -5, -6, -7, -8, 15, 16]
        从下方Vec2f的访问可以知道,数据的排列是第一通道然后第二通道,再第一、二通道交替
        即(0,0)的第1通道是1,(0,0)的第2通道是2..
    */ 
    // 使用Vec2f来访问,[]访问不同的通道
    cout << "m16_(0,1)[0] = " << m16_.at<Vec2f>(0, 1)[0] << endl; // m16_(0,1)[0] = -3
    cout << "m16_(0,1)[1] = " << m16_.at<Vec2f>(0, 1)[1] << endl;// m16_(0,1)[1] = -4
    cout << "m16_(1,2)[1] = " << m16_.at<Vec2f>(1, 2)[1] << endl;// m16_(1,2)[1] =16

    // 4.1.2.3、三维数组视为双通道(很少用)
    float data17[2 * 3 * 4 * 2] = {}; // 必须分配2个通道的数据也就是48个否则后边访问时部分数据不存在
    for (int i = 0; i < 48; ++i) data17[i] = (i + 1) / 48.0;
    Mat m17(3, psz14, CV_32FC2, data17);
   cout << "m17.dims = " << m17.dims << " m17.channels() = " << m17.channels() << endl;
   // cout<<"m17.size = " << m17.size() << endl; // 不能运行
    // cout << m17.at<Point2f>(0, 0) << endl; // Assertion failed (dims <= 2) 不允许
    // cout << m17.at<Vec2f>(0, 0) << endl; // Assertion failed (dims <= 2) 不允许
    // cout << m17.at<float>(0, 0 , 0) << endl; // elemSize() == sizeof(_Tp) 不允许
    // cout << m17.at<Vec3f>(0, 0)[0] << endl; // Assertion failed (dims <= 2) 不允许
    // 高维图像借助step取值和赋值,
    for (int i = 0; i < sz14[0]; ++i) {
        for (int j = 0; j < sz14[1]; ++j) {
            for (int k = 0; k < sz14[2]; ++k) {
                int id = m17.step[0] * i + m17.step[1] * j + m17.step[2] * k ; // 内存块标记
                // cout << "id = " << id << endl;
                float* p = (float*)(m17.data + id); 
                cout << "m17(" << i << "," << j << "," << k<<") = " <<*p<< endl;
            }
        }
    }

    // 4.1.3、三通道
    // 4.1.3.1、一维数组的三通道也是不存在的
    // 4.1.3.2、二维数组的三通道(最常见)
    Mat m18(3, 2, CV_32FC3);
    // 常见的使用Vec3f访问遍历
    for (int i = 0; i < m18.rows; ++i) {
        for (int j = 0; j < m18.cols; ++j) {
            Vec3f& v = m18.at<Vec3f>(i, j);
            v[0] = i + 3.0;
            v[1] = j + 6.0;
            v[2] = (float)(i + 1) * (j + 1);
        }
    }
    cout << "m18 : \n" << m18 << endl;
    /*
        [3, 6, 1, 3, 7, 2;
         4, 6, 2, 4, 7, 4;
         5, 6, 3, 5, 7, 6]
    */
    // 可以使用Point2f访问,访问的其实是相邻2个通道
    cout << m18.at<Point2f>(0, 0) << endl; //3×2有3个通道,每列都是一个通道[3,6]
    cout << m18.at<Point2f>(2, 2) << endl; // [7, 6],这其实是第2行的第3个连续通道
    // 显然Point2f割裂了相同通道的访问这样并不好,使用Vec3f是最好的,代表3个通道
    cout << m18.at<Vec3f>(0, 0) << endl;// [3, 6, 1] 位置(0,0)连续的3个通道
     // 4.1.3.2、三维数组的三通道,这里忽略,很少用

    // 4.2、基于ptr访问,这里只给出单通道二维和三通道二维的访问方式,其它的情况比较少见
    // 4.2.1、单通道二维
    Mat m19 = Mat::eye(3, 3, CV_32FC1);
    for (int i = 0; i < m19.rows; ++i) {
        for (int j = 0; j < m19.cols; ++j) {
            float* p = m19.ptr<float>(i, j); // 单通道返回指向元素(i,j)的指针
            cout << *p << " ";
        }
        cout << endl;
    }
    // 4.2.2、三通道二维
    Mat m20 = Mat::eye(3, 3, CV_32FC3);
    cout << "m20 : \n" << m20 << endl;
    for (int i = 0; i < m20.rows; ++i) {
        Vec3f* p = m20.ptr<Vec3f>(i); //三通道返回指向元素(i,j)的连续3通道的指针
        for (int j = 0; j < m20.cols; ++j) {
                p[j][0] = (float)i + 3.0 + (float)j;
                p[j][1] = ((float)i + 1.0) * 2.0 - (float)j;
                p[j][2] = ((float)j - 1.0) * 2.0 + (float)i;
        }
    }
    cout << "m20 : \n" << m20 << endl;
    /*
        [3, 2, -2, 4, 1, 0, 5, 0, 2;
         4, 4, -1, 5, 3, 1, 6, 2, 3;
         5, 6, 0, 6, 5, 2, 7, 4, 4]
    */

    //4.3、基于迭代器访问
    // 4.3.1、单通道二维
    MatIterator_ <float> it = m19.begin<float>();
    MatIterator_ <float> itend = m19.end<float>();
    for (; it != itend; ++it) {
        cout << *it << " "; // 1 0 0 0 1 0 0 0 1
    } // 按照先行后列的顺序打印元素
    cout << endl;
    // 4.3.2、三通道二维
    MatIterator_ <Vec3f> it2 = m20.begin<Vec3f>();
    MatIterator_ <Vec3f> it2end = m20.end<Vec3f>();
    for (; it2 != it2end; ++it2) {
        cout << *it2 << " "; // [3, 2, -2] [4, 1, 0] [5, 0, 2] [4, 4, -1] [5, 3, 1] [6, 2, 3] [5, 6, 0] [6, 5, 2] [7, 4, 4]
    } // 按照每个点连续的3个通道打印
    cout << endl;
    // 一个使用迭代器访问三维三通道数组,找到最长的向量的例子,也就是x^2+y^2+z^2最大的向量
    // 不仅是某个通道中最长的向量,还是所有通道中最长的向量
    int sz_iter[] = {4,4,4};
    Mat m21(3,sz_iter,CV_32FC3); // 3维,3通道,4行4列高度4
    randu(m21,-1.0f,1.0f); // 填充随机数
    MatConstIterator_<Vec3f> it3 = m21.begin<Vec3f>(); // 可以使用const迭代器
    MatConstIterator it4 = m21.begin<Vec3f>(); // 也可以使用const迭代器
    // MatConstIterator和MatConstIterator_是两种不同的迭代器,两者的区别是
    // MatConstIterator继承自MatConstIterator_,没有模板参数
    float max_m21 = 0.0f;
    while (it3 != m21.end<Vec3f>()) {
        float len = (*it3)[0] * (*it3)[0] + (*it3)[1] * (*it3)[1] + (*it3)[2] * (*it3)[2];
        if (max_m21 < len) {
            max_m21 = len;
        }
        it3++;
    }
    cout << "max_m21 : " << max_m21 << endl; //  1.41017
    // 使用MatConstIterator也是可以的,但是含义不同
    max_m21 = 0.0f;
    while (it4 != m21.end<Vec3f>()) {
        float len = sqrt((*it4)[0] * (*it4)[0] + (*it4)[1] * (*it4)[1] + (*it4)[2] * (*it4)[2]);
        if (max_m21 < len) {
            max_m21 = len;
        }
        it4++;
    }
    cout << "max_m21 : " << max_m21 << endl; // 380.576

    // Mat基于块的访问方式
    // 使用row和col方法访问块,以m20为例
    // 访问m20的第2行和第1列
    Mat m20_row1 = m20.row(1); // 返回一个行向量
    auto m20_col0 = m20.col(0); // 返回一个列向量
    /*
         [3, 2, -2, 4, 1, 0, 5, 0, 2;
         4, 4, -1, 5, 3, 1, 6, 2, 3;
         5, 6, 0, 6, 5, 2, 7, 4, 4]
    */
    // 比较可以知道row,col会把所有通道的数都取出来
    cout << "m20_row1 : \n" << m20_row1 << endl; // [4, 4, -1, 5, 3, 1, 6, 2, 3]
    cout << "m20_col0 : \n" << m20_col0 << endl; // [3, 2, -2;4, 4, -1;5, 6, 0]
    // 也可以访问某个范围的行或列,如1-2行,0-1列,但是注意左闭右开
    Mat m20_row1_2 = m20.rowRange(1,3); // 返回2个行向量
    Mat m20_col0_1 = m20.colRange(0,2); // 返回2个列向量
    cout << "m20_row1_2 : \n" << m20_row1_2 << endl; // [4, 4, -1, 5, 3, 1, 6, 2, 3;5, 6, 0, 6, 5, 2, 7, 4, 4]
    cout << "m20_col0_1 : \n" << m20_col0_1 << endl; // [3, 2, -2, 4, 1, 0; 4, 4, -1, 5, 3, 1;5, 6, 0, 6, 5, 2]

    // Mat的一些算术操作，只测试个别操作
    Mat m22 = cv::abs(m20_col0_1);
    cout << "m22 = " << m22 << endl;
    Mat m23 = m20_col0_1 * 2;
    Mat m24 = m20_col0_1.mul(2);
    Mat m25 = m20_col0_1.mul(m20_col0_1);
    Mat m26 = m20_col0_1 / m20_col0_1;
    Mat m27 = m20_col0_1 / 2;
    Mat m28 = Mat(3, 3, CV_32FC1);
    m28.at<float>(0, 0) = 1.0f; m28.at<float>(0, 1) = 2.0f; m28.at<float>(0, 2) = 3.0f;
    m28.at<float>(1, 0) = 1.0f; m28.at<float>(1, 1) = 0.0f; m28.at<float>(1, 2) = -1.0f;
    m28.at<float>(2, 0) = 0.0f; m28.at<float>(2, 1) = 1.0f; m28.at<float>(2, 2) = 1.0f;
    Mat m28_inv = m28.inv();
    cout << "m23 = " << m23 << endl;
    cout << "m24 = " << m24 << endl;
    cout << "m25 = " << m25 << endl;
    cout << "m26 = " << m26 << endl;
    cout << "m27 = " << m27 << endl;
    cout << "m28 = " << m28 << endl;
    cout << "m28_inv = " << m28_inv << endl;

    // Mat的饱和转换测试
    Matx<uchar,2,2> m29 = Matx<uchar, 2, 2>{ 10,12,23,44 };
    uchar& m29_ref_0_0 = m29(0, 0); uchar& m29_ref_0_1 = m29(0, 1);
    uchar& m29_ref_1_0 = m29(1, 0); uchar& m29_ref_1_1 = m29(1, 1);
    m29_ref_0_0 = saturate_cast<uchar>((m29_ref_0_0 - 128) * 2 + 128);
    m29_ref_0_1 = saturate_cast<uchar>((m29_ref_0_1 - 128) * 2 + 128);
    m29_ref_1_0 = saturate_cast<uchar>((m29_ref_1_0 - 128) * 2 + 128);
    m29_ref_1_1 = saturate_cast<uchar>((m29_ref_1_1 - 128) * 2 + 128);
    cout << "m29 = " << m29 << endl; // 全部变成0

    // push_back和pop_back操作
    Mat m30 = Mat::ones(3, 5, CV_8UC1);
    m30.pop_back(1);
    cout << "m30.size() = " << m30.size() << endl; // [5 x 2],表示删除行
    m30.push_back(Mat::ones(13, 5, CV_8UC1));
    cout << "m30.size() = " << m30.size() << endl; // [5 x 15],表示添加列相同的多行

    // 测试locateROI函数,m31是m30的[1,2]行,[3,4]列,使用Range的方式代替rowRange,colRange获取m30的块区域
    Mat m31 = m30(Range(7,10), Range(3,5));
    Size sz_m32; Point2i ofs_m32;
    m31.locateROI(sz_m32, ofs_m32);
    cout << "sz_m32 = " << sz_m32 << endl; // [5 x 15]
    cout << "ofs_m32 = " << ofs_m32 << endl; // [3, 7],偏置的意思是偏离了m30的起点3列,7行,因为宽3高7

    // 测试adjustROI函数,指定(up,down,left,right)=(-5,-5,-1,-1)
    // 含义是从顶行向下减去5行,底层向上减去5行,左右也向中心删除边界行
    m30.at<uchar>(6, 3) = 18;
    cout << "m30 :\n" << m30 << endl;
    Mat m32 = m30.adjustROI(-5, -5, -1, -1); // m32.size() = [3 x 5]
    cout << "m32.size() = " << m32.size() << endl;
    cout << "m32 :\n" << m32 << endl;
    /*
         可以看出确实是截图,且改变了m32也会改变m30
            m30 :
        [  1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,  18,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1;
           1,   1,   1,   1,   1]
        m32 :
        [  1,   1,   1;
           1,   1,  18;
           1,   1,   1;
           1,   1,   1;
           1,   1,   1]
    */
    cout << boolalpha <<" m32.isContinuous() = "<< m32.isContinuous() << endl; // false
    cout << "m32.elemSize() = " << m32.elemSize() << endl; // 1
    cout << "m32.elemSize1() = " << m32.elemSize1() << endl; // 1

    return 0;
}