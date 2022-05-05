/*** 
 * @Author: chenbei
 * @Date: 2022-05-05 08:18:14
 * @LastEditTime: 2022-05-05 08:38:25
 * @Description: test for Matx
 * @FilePath: \myLeetCode\myPleasure\myOpencv\basicTypes\source\Matx.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Matx -g Matx.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Matx
*/
int main(int argc,char**argv)
{
    /*
        Matx是一个模板类,Vec继承自这个固定矩阵类为固定向量类
        Matx同样有一些别名,Matx{1,2,..6}{1,2,..6}{f,d}
        数字可以是1-6任意的数字以及f或者d
        但是有的类型例如奇数模板没有别名,例如Matx<float,5,5>,自己实例化即可
        固定矩阵类要注意的是已知大小,例如相机矩阵,一般来说Mat更常用适合未知大小的图像
    */
   // 1、Matx的别名
    Matx12d mx12d;Matx12f mx12f;
    Matx13d mx13d;Matx13f mx13f;
    Matx14d mx14d;Matx14f mx14f;
    // Matx15d mx15d;Matx15f mx15f; // 没有5×5别名
    Matx16d mx16d;Matx16f mx16f;
    Matx21d mx21d;Matx21f mx21f;
    Matx22d mx22d;Matx22f mx22f;
    Matx23d mx23d;Matx23f mx23f;
    Matx31d mx31d;Matx31f mx31f;
    Matx32d mx32d;Matx32f mx32f;
    Matx33d mx33d;Matx33f mx33f;
    Matx34d mx34d;Matx34f mx34f;
    Matx41d mx41d;Matx41f mx41f;
    Matx61d mx61d;Matx61f mx61f;
    Matx66d mx66d;Matx66f mx66f;

    // 2、Matx的默认构造函数、复制构造函数和值构造函数
    Matx<float,2,2> mx22f1; // 默认构造函数
    Matx66d mx66d1; Matx66d mx66d2(mx66d1); // 复制构造函数
    Matx34f mx34f1(1,2,3,4,5,6,7,8,9,10,11,12); // 值构造函数

    // 3、Matx的静态成员函数
    // 3.1、含相同元素的矩阵all(x)
    Matx33f mx33f1 = Matx33f::all(1); // 全1
    // 3.2、全0初始化zeros(x)
    Matx33f mx33f2 = Matx33f::zeros(); // 全0
    // 3.3、全1初始化ones(x)
    Matx<float,5,5> mx55f1 = Matx<float,5,5>::ones(); // 全1
    // 3.4、单位矩阵eye(x)
    Matx33f mx33f3 = Matx33f::eye(); // 单位矩阵
    // 3.5、创建容纳一个矩阵对角线的矩阵diag()
    // Matx31f mx31f1 = Matx33f::diag(); // 这样不行,必须是具体对象的diag()
    Matx33f mx33f4(1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5); // 具体对象
    Matx31f mx31f1 = mx33f4.diag(); // 对角线元素 ,这样可以
    cout<<"mx31f1="<<mx31f1<<endl; // [1.5;5.5;9.5]
    // 3.6、创建均匀分布的矩阵
    Matx33f mx33f5 = Matx33f::randu(0,1); // 均匀分布,min,max
    // 3.7、创建正态分布的矩阵
    Matx33f mx33f6 = Matx33f::randn(0,1); // 正态分布,mean,variance
    // 3.8、成员的访问与赋值可以使用(),不能使用[],不同于Vec或Scalar
    mx33f6(0,1) = 1.2;
    cout<<"mx33f6(0,1)="<<mx33f6(0,1)<<endl; // 1.2
    Matx13f m13f1 = mx33f6.row(1); // 获取第2行,注意是1×3
    cout << "m13f1=" << m13f1 << endl; // [1.3059061, -1.9596839, -1.8992141]
    Matx31f mx31f2 = mx33f6.col(1); // 获取第2列,注意是3×1
    cout << "mx32f1=" << mx31f2 << endl; // [1.2;-1.9596839;-0.74828959]
    // 3.9、矩阵的转置
    Matx33f mx33f7 = mx33f6.t(); // 转置
    // 3.10、矩阵的逆
    Matx33f mx33f8 = mx33f6.inv(); // 逆
    // 3.11、矩阵的内积和外积
    Matx33f mx33f9 = mx33f6.mul(mx33f6); // 内积
    Matx33f mx33f10 = mx33f6.mul(mx33f6.t()); // 外积
    cout << "mx33f9=" << mx33f9 << endl; 
    cout << "mx33f10=" << mx33f10 << endl; 
    // 3.12、点积,可以使用dot()和ddot(),后者精度更高,使用双精度
    double d1 = mx33f6.dot(mx33f6); // 点积
    double d2 = mx33f6.ddot(mx33f6);// 点积
    cout << "d1=" << d1 << endl; // 16.3513
    cout << "d2=" << d2 << endl; // 16.3513
    // 3.13、矩阵更改形状
    Matx<double,1,9> mx33f11 = mx33f6.reshape<1,9>(); // 更改形状,1行9列
    cout << "mx33f11=" << mx33f11 << endl; 
    // 3.14、取逆
    Matx33f mx33f12 = mx33f6.inv(DECOMP_LU); // 逆,指定LU分解方法
    // 3.15、获取(i,j)处的2×2子矩阵,向右和向下延申的
    Matx22f mx22f2 = mx33f6.get_minor<2,2>(1,1); // 获取(1,1)处的2×2子矩阵
    cout << "mx22f2=" << mx22f2 << endl; 
    
    // 4、Matx的成员变量和一些别名
    // 4.1、矩阵的行数和列数
    int rows = mx33f6.rows; // 行数
    int cols = mx33f6.cols; // 列数
    cout << "rows=" << rows << endl; // 3
    cout << "cols=" << cols << endl; // 3
    // 4.2、矩阵的通道数和最短维度数
    int channels = mx33f6.channels; // 通道数
    int shortdim = mx33f6.shortdim; // 最短维度数
    cout << "channels=" << channels << endl; // 9
    cout << "shortdim=" << shortdim << endl; // 3
    // 4.3、矩阵的元素类型可作为类型使用value_type
    float d3 = Matx33f::value_type(4.14); // 元素类型
    // 4.4、返回默认构造类型mat_type()
    Matx<float, 3, 3> construct = Matx33f::mat_type();
    // 4.5、变换操作符,转换类型
    cv::Matx<double, 3, 3> mxd19 = (Matx33d)mx33f6; // float->double
    
    // 5、支持各类算术运算和2个逻辑运算
    // 5.1、矩阵的加法+,+=
    Matx31d mx31d1(3.14,2.71,1.41);
    Matx31d mx31d2(1.0,2.0,3.0);
    Matx31d mx31d3 = mx31d1 + mx31d2; // 加法
    cout << "mx31d3=" << mx31d3 << endl; // [4.14;4.71;4.41]
    mx31d3 += mx31d2; // +=
    cout << "mx31d3=" << mx31d3 << endl; // [5.14;6.71;7.41]
    // 5.2、矩阵的减法,-=,-和取负
    mx31d3 -= mx31d2; // -=
    cout << "mx31d3=" << mx31d3 << endl; // [4.14;4.71;4.41]
    mx31d3 = -mx31d3; // 取负
    cout << "mx31d3=" << mx31d3 << endl; // [-4.14;-4.71;-4.41]
    mx31d3 = mx31d3 + Matx<double,3,1>::all(4); // 加上常数,不支持直接+1个数
    cout << "mx31d3=" << mx31d3 << endl; // [-0.14;-0.71;-0.41]
    // 5.3、矩阵的乘法*,*=,务必满足矩阵的前列后行维度相同
    Matx13d mx13d1  ={1,2,3}; // 列表初始化也是ok的
    Matx33d mx33d1 = mx31d1 * mx13d1; // 矩阵乘法结果是3×3
    cout << "mx33d1=" << mx33d1 << endl; 
    mx33d1 *= 3; // 不同于+,-,支持乘1个系数
    cout << "mx33d1=" << mx33d1 << endl;
    // 5.4、矩阵的除法,/=
    // mx33d1 /= 3; // 除法不支持除1个数
    Matx33d mdiv1 = {10,5,3,6,4,7,1,0,9};
    Matx33d mdiv2 = {1,3,8,7,5,4,10,6,0};
    // A/B = A * inv(B),矩阵除法
    Matx33d mdiv3 = mdiv1 * mdiv2.inv(DECOMP_LU);
    cout<<"mdiv3="<<mdiv3<<endl;
    // 按位的除法
    // Matx33d mdiv4 = mdiv1 / mdiv2; // 现在不予支持

    // 6、不常用的方法solve，用于求解线性方程组
    /*
    求解的方程组实际上就是:
        x+3y+2z=10
        x+y+z=5
        3x-2y+4z=-6
        [x,y,z]=[26/7,26/7,-17/7]
    */
    Matx33f coffs = {1,3,2,1,1,1,3,-2,4};
    Matx31f target = {10,5,-6};
    Matx31f res = coffs.solve(target, DECOMP_LU);
    cout << "res=" << res << endl; // res=[3.7142859;3.7142859;-2.4285715]

    // 还可以指定求解的是2组方程组,2组目标和2组结果,但系数是没变的,故用Matx<float,3,2>表示
    /*
    2组方程组
        x+3y+2z=[10,11.5]
        x+y+z=[5,5]
        3x-2y+4z=[-6,4]
        [x,y,z]=[[26/7,1],[26/7,2.5],[-17/7,1.5]]
    */
    Matx32f targets ={10,11.5,5,5,-6,4}; // 注意顺序
    Matx32f ress = coffs.solve<2>(targets, DECOMP_LU);
    cout << "ress=" << ress << endl; // ress=[3.7142859;3.7142859;-2.4285715]和[1.0,2.5,1.5]
    // 如果忘记了加<2>,也其实不会影响结果
    ress = coffs.solve(targets, DECOMP_LU);
    cout << "ress=" << ress << endl; // ress=[3.7142859;3.7142859;-2.4285715]和[1.0,2.5,1.5]
    return 0;
}