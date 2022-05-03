#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Vec -g Vec.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Vec
*/
int main()
{
    /*
        cv::Vec<T,int>是模板,但是很少使用这样的形式,因为这样的形式会把数据类型和数组长度混淆
        
        Vec被称为固定向量类，继承自固定矩阵类Matx
        template<typename _Tp, int cn> class Vec : public Matx<_Tp, cn, 1>
        从上述表达式来看,Vec继承于Matx,而Matx的类型template<typename _Tp, int m, int n> class Matx
        所以其实是Matx的特化版本,让n=1,即Vec的类型为Matx<_Tp,cn,1>
        Matx并非用于大型数组,而是用于小型数组,因为常有2×2和3×3等小型数组用于变化
        Matx的常见使用方式为Matx{1,2,3,4}{1,2,3,4,5}{f,d}列表初始化
        注意固定矩阵类和固定向量类编译期间就已知维度,消除了动态内存分配,效率比较高


        大多数情况下使用的都是Vec的别名typedef
        首先在图像处理中常用的6种数据类型是uchar,int,float,double,short,ushort
        分别用字母b,i,f,d,s,w表示,这里的w是ushort的缩写
        常见的Vec别名且代表的含义如下:
        typedef Vec<uchar, 2> Vec2b;
        typedef Vec<uchar, 3> Vec3b;
        typedef Vec<uchar, 4> Vec4b;

        typedef Vec<short,2> Vec2s;
        typedef Vec<short,3> Vec3s;
        typedef Vec<short,4> Vec4s;

        typedef Vec<ushort, 2> Vec2w;
        typedef Vec<ushort, 3> Vec3w;
        typedef Vec<ushort, 4> Vec4w;

        typedef Vec<int, 2> Vec2i;
        typedef Vec<int, 3> Vec3i;
        typedef Vec<int, 4> Vec4i;
        typedef Vec<int, 6> Vec6i;
        typedef Vec<int, 8> Vec8i;

        typedef Vec<float, 2> Vec2f;
        typedef Vec<float, 3> Vec3f;
        typedef Vec<float, 4> Vec4f;
        typedef Vec<float, 6> Vec6f;

        typedef Vec<double, 2> Vec2d;
        typedef Vec<double, 3> Vec3d;
        typedef Vec<double, 4> Vec4d;
        typedef Vec<double, 6> Vec6d;

        对于2,3,4所有数据类型都有
        对于6只有Vec6f,Vec6d,Vec6w
        对于8只有Vec8i

        Vec的访问方式通过operator[]实现,Scalar继承自Vec<double,4>也是operator[]访问
        这里提一句,Scalar一般是双精度四元素向量的别名,所以直接继承自<double,4>的实例

        其它的Point,Rect,RotateRect等都会在各自的cpp文件介绍,这里不赘述

        官网参考Vec的学习链接：
        https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html#aeb91d64fc995b155a99ded4fb1520295
    */
    // 1、Vec的默认构造函数
    Vec2b v2b;Vec3b v3b;Vec4b v4b; // support 2,3,4 dims
    Vec2w v2w;Vec3w v3w;Vec4w v4w; // support 2,3,4 dims
    Vec2s v2s;Vec3s v3s;Vec4s v4s; // support 2,3,4 dims
    Vec2i v2i;Vec3i v3i;Vec4i v4i; Vec6i v6i;Vec8i v8i; // support 2,3,4,6,8 dims
    Vec2f v2f;Vec3f v3f;Vec4f v4f; Vec6f v6f; // support 2,3,4,6 dims
    Vec2d v2d;Vec3d v3d;Vec4d v4d; Vec6d v6d; // support 2,3,4,6 dims

    // 2、Vec的复制构造函数
    Vec2b cv2b(v2b);Vec3b cv3b(v3b);Vec4b cv4b(v4b); 
    Vec2s cv2s(v2s);Vec3s cv3s(v3s);Vec4s cv4s(v4s);
    Vec2w cv2w(v2w);Vec3w cv3w(v3w);Vec4w cv4w(v4w);
    Vec2i cv2i(v2i);Vec3i cv3i(v3i);Vec4i cv4i(v4i); Vec6i cv6i(v6i);Vec8i cv8i(v8i);
    Vec2f cv2f(v2f);Vec3f cv3f(v3f);Vec4f cv4f(v4f); Vec6f cv6f(v6f);
    Vec2d cv2d(v2d);Vec3d cv3d(v3d);Vec4d cv4d(v4d); Vec6d cv6d(v6d);

    // 3、Vec的值构造函数,使用()括号构造,支持别名支持下的任意维度,()内是构造的元素
    // 例如b类型支持2,3,4维度,则可以使用(uchar,2),(uchar,3),(uchar,4)构造
    Vec2b v2b1('1','2');Vec3b v3b1('1','2','3');Vec4b v4b1('1','2','3','4');
    // 使用[]访问元素
    cout<<"vec2b[0] = "<< v2b1[0]<< " vec2b[1] = "<< v2b1[1]<<endl; // '1' '2'
    // 再如Vec4b的访问方式
    cout<<"vec4b[0] = "<< v4b1[0]<< " vec4b[1] = "<< v4b1[1]<< " vec4b[2] = "
        << v4b1[2]<< " vec4b[3] = "<< v4b1[3]<<endl; // '1' '2' '3' '4'
    // 其它诸如int、float、double等类型也可以使用这种方式
    // 这里给出int8和double6的例子
    Vec8i v8i1(1,2,3,4,5,6,7,8);
    // 可以[]赋值
    v8i1[0] = 10;
    // 遍历Vec的方式,因为没有Mat的size等属性,只能事先按照元素个数计算
    for(int i = 0; i < 8; i++) // 8是提前已知的
        cout<<"v8i1["<<i<<"] = "<< v8i1[i]<<endl; // 10 2 3 4 5 6 7 8
    Vec6d v6d1(1.5,2.7,3.,4.4,5.3,6.9);
    v6d1[2]=3.1415926535;
    for(int i = 0; i < 6; i++)
        cout<<fixed<<setprecision(10)<<"v6d1["<<i<<"] = "<< v6d1[i]<<endl; // 1.5 2.7 3.1415926525 4.4 5.3 6.9
    
    // 4、Vec存在一些静态成员函数,例如all,ones,zeros,randn,randu
    // 但是除了all之外,其他静态成员函数本质来源于Matx,故必须用Matx去接收
    // 不能使用Vec接收,因为没有适当的隐式转换,Matx(_Tp,_Tm,_Tn)->Vec(_Tp,_Tm)
    // static Vec 	all (_Tp alpha)
    Vec<uchar,2> v2b2 = Vec<uchar,2>::all(255); // 全部赋值255
    Vec<int,2> v2i2 = Vec<int,2>::all(255); // 全部赋值255
    Vec<float,2> v2f2 = Vec<float,2>::all(255.); // 全部赋值255.
    Vec<double,2> v2d2 = Vec<double,2>::all(255.); // 全部赋值255.
    // static Vec 	ones ()
    Matx <uchar,2,1> m2b3 = Vec<uchar,2>::ones(); // 全部赋值1,用Matx接收而不能用Vec接收
    Matx <int,2,1> m2i3 = Vec<int,2>::ones(); // 全部赋值1,用Matx接收而不能用Vec接收
    Matx <float,2,1> m2f3 = Vec<float,2>::ones(); // 全部赋值1,用Matx接收而不能用Vec接收
    Matx <double,2,1> m2d3 = Vec<double,2>::ones(); // 全部赋值1,用Matx接收而不能用Vec接收
    // static Vec 	zeros ()
    Matx <uchar,2,1> m2b4 = Vec<uchar,2>::zeros(); // 全部赋值0,用Matx接收而不能用Vec接收
    // static Vec 	randu (_Tp a, _Tp b),用于随机生成一个Vec
    Matx <double,6,1> v2b5 = Vec<double,6>::randu(0,1); // 随机生成一个Vec,元素值在0-255之间
    cout<<"v2b5 = "<< v2b5<<endl; // 重载了<<运算符,所以可以直接输出
    // static Vec 	randn (_Tp a, _Tp b),用于随机生成一个Vec
    // randn和randu的区别在于,randu生成的是均匀分布的随机数,randn生成的是高斯分布的随机数
    Matx<int,8,1> v2i6 = Vec<int,8>::randn(0,255); // 随机生成一个Vec,元素值在0-255之间
    cout<<"v2i6 = "<< v2i6<<endl; // 重载了<<运算符,所以可以直接输出

    // 5、Vec支持算术运算,+,-,*,/,+=,-=,*=,/=
    // 其中Vec和Matx的算术运算只能用于同类型的Vec和Matx
    // 支持多个参数组合
    // (const Vec<_Tp,cn>&,int)、(int,const Vec<_Tp,cn>&)
    // (const Vec<_Tp,cn>&,float)、(float,const Vec<_Tp,cn>&)
    // (const Vec<_Tp,cn>&,double)、(double,const Vec<_Tp,cn>&)
    // (const Vec<_Tp,cn>&,const Vec<_Tp,cn>&)
    // operator*= 也支持上述格式,但是引用参数在第1个,也就是右边3种不支持
    // operator+ 只支持(const Vec<_Tp,cn>&,const Vec<_Tp,cn>&)
    // operator+=稍有区别,第1个不是const(Vec<_Tp,cn>&,const Vec<_Tp,cn>&)
    // operator-和-=类似,多了一个(const Vec<_Tp,cn>&a)单纯取负号的操作
    // operator/和operator/=一样,支持第2参数位int,float,double
    Vec4i v4iop1(1,2,3,4);
    Vec4i v4iop2(5,6,7,8);
    Vec4i v4iop3 = v4iop1 + v4iop2; // 加法
    Vec4i v4iop4 = v4iop1 - v4iop2; // 减法
    Vec4i v4iop5 = v4iop1 * v4iop2; // 乘法,但不是对应元素相乘
    Vec4i v4iop6 = v4iop1 / 4; // 除法,但是不支持直接向量相除
    cout<<"v4iop3 = "<< v4iop3<<endl; // 6 8 10 12
    cout<<"v4iop4 = "<< v4iop4<<endl; // -4 -4 -4 -4
    cout<<"v4iop5 = "<< v4iop5<<endl; // -60 12 30 24
    cout<<"v4iop6 = "<< v4iop6<<endl; // 0 0 1 1 0.75四舍五入为1
    // *=,/*,+=,-=也支持
    v4iop1 *= v4iop2;
    cout<<"v4iop1 = "<< v4iop1<<endl; // -60 12 30 24 
    v4iop1 /= 2; // 不支持直接向量相除,但可以除数字
    cout<<"v4iop1 = "<< v4iop1<<endl; // -30 6 15 12

    // 6、Vec支持逻辑运算==和!=
    cout<<boolalpha<<"v4iop1 == v4iop2 = "<< (v4iop1 == v4iop2)<<endl; // false
    cout<<boolalpha<<"v4iop1 != v4iop2 = "<< (v4iop1 != v4iop2)<<endl; // true

    // 7、Vec的成员函数val,val方法返回的是一个Vec的指针,所以可以直接修改Vec的元素
    int *pv4iop1 = v4iop1.val; // 使用整型指针接收,内部实际上就是m*n二维数据用一个一维数组表示
    pv4iop1[0] = 100; // 修改第一个元素
    cout<<"v4iop1 = "<< v4iop1<<endl; // 100 6 15 12

    // 8、向量的内积运算使用dot,也就是对应元素相乘并累加
    Vec4f v4fop1(1.1,2.2,3.,4.);
    Vec4f v4fop2 (2.,3.,4.,5.);
    float v4fop3 = v4fop1.dot(v4fop2); // 向量的内积
    cout<<"Vec4f::dot = "<< v4fop3<<endl; // 2.2+6.6+12+20=40.79999
    // ddot和dot的区别在于以双精度计算
    cout<<"Vec4f::ddot = " <<v4fop1.ddot(v4fop2)<<endl;// 40.80000

    // 9、成员函数conj用于得到向量的共轭复数
    Vec4f v4fop1_complex = v4fop1.conj(); // 得到向量的共轭复数,除了第1位其它全部取反
    cout<<"v4fop1_complex = "<< v4fop1_complex<<endl; // [1.1000000238, -2.2000000477, -3.0000000000, -4.0000000000]
    
    // 10、可以使用cross计算叉乘,但必须是3维的,其它维度会抛出错误
    /*
    叉乘的计算是这样的,借助线性代数的知识
        A = [a1,a2,a3]
        B = [b1,b2,b3]
        A x B = 
        | i j k |
        |a1 a2 a3|
        |b1 b2 b3|
        = i * |a2 b3 - a3 b2| 
          j * |a3 b1 - a1 b3|
          k * |a1 b2 - a2 b1|
        = [a2b3-a3b2, a3b1-a1b3, a1b2-a2b1]
        参考:https://blog.csdn.net/weixin_31992237/article/details/112309369
    */
    Vec3d v3dcross1 (3.0,4.0,5.0);
    Vec3d v3dcross2 (6.0,7.0,8.0);
    Vec3d v3dcross3 = v3dcross1.cross(v3dcross2); // 叉乘
    cout<<"v3dcross3 = "<< v3dcross3<<endl; // -3.0 6.0 -3.0 = [4*8-5*7, 5*6-3*8, 3*7-4*6]

    // 11、正如上边说的,*,/,*=,/=不是对应元素相乘,而是为了同乘除1个系数
    // 可以使用mul和div方法来实现对应元素相乘除
    Vec4f v4fop1_mul(2.5,3.2,4.1,5.0);
    Vec4f v4fop2_mul(1.5,2.2,3.1,4.0);
    Vec4f v4fop3_mul = v4fop1_mul.mul(v4fop2_mul); // 向量的乘法
    cout<<"v4fop3_mul = "<< v4fop3_mul<<endl; // [3.75, 7.04, 12.71, 20.0]
    Vec4f v4fop1_div(1,3,4,8);
    Vec4f v4fop2_div(2,1,2,4);
    cv::Matx<float, 4, 1> v4fop3_div = v4fop1_div.div(v4fop2_div); // 除法不能使用Vec4f接收了
    cout <<"v4fop3_div = "<<v4fop3_div<<endl; // [0.5;3;2;2],可以看出这是个列向量


    // 12、回到operator操作,除了支持[]以外还有其它类型
    // 12.1、显式和隐式转换类型
    // cv::Vec< _Tp, cn >::operator Vec< T2, cn >()	const,用于转换为另一种数据类型
    Vec2w v2wop1(1,2);
    // 隐式转换为int类型
    Vec<int,2> v2op1 = v2wop1;
    // 显式转为int类型,使用operator Vec<int,2>()
    Vec<int,2> v2op2 = v2wop1.operator Vec<int,2>();
    // 12.2、operator()常用于访问元素,和[]功能一样
    // const _Tp& cv::Vec< _Tp, cn >::operator()(int i)	const
    cout << "v2op1(1) = " << v2op1(1) << endl; // 2
    // ()返回的元素也可以更改,可读可写
    v2op1(1) = 3;
    cout << "v2op1(1) = " << v2op1(1) << endl; // 3

    // 13、除了官网上提到的这些函数以外还有其它的,以Vec4d为例说明
    // 13.1、channels,rows、cols,val,shortdims,注意这些是属性,而不是函数
    cout<<"vec4f<double,4>'s channels = "<<Vec<double,4>::channels<<endl; // 4
    cout <<"vec4f<double,4>'s rows = " <<Vec<double,4>::rows<<endl; // 4
    cout <<"vec4f<double,4>'s cols = " <<Vec<double,4>::cols<<endl; // 1
    cout <<"vec4f<double,4>'s shortdim = " <<Vec<double,4>::shortdim<<endl; // 
    // 13.2、col(),row()必须依赖于实际对象
    Vec4d vec4d_col(1.7,2.5,3.3,4.1);
    // cout <<"vec4f<double,4>'s rows = "<<Vec<double,4>::col(1)<<endl;  x
    cout <<"vec4f<double,4>'s rows = "<<vec4d_col.row(1)<<endl; // [2.5]
    cout <<"vec4f<double,4>'s cols = "<<vec4d_col.col(1)<<endl; // [2.5;3.3;4.1;0]
    // 13.3、eye函数
    cout<<"vec4f::eye() = " <<Vec<double,4>::eye()<<endl;// [1;0;0;0]
    // 13.4、提取对角线diag,不过对于一维向量是没有意义的
    // cout<<"vec4f::diag() = "<<Vec<double,4>::diag()<<endl; // 错误
    Matx33d m33d{1.5,3.3,4.5,6.1,5.9,7.9,4.7,8.8,9.9};
    cout<<"Matx33d's diag() = "<<m33d.diag()<<endl; //[1.5;5.9;9.9]
    // 13.5、通过diag_type可以当成double使用
    cout<<"Vec<double,4>::diag_type = "<<Vec<double,4>::diag_type(1.33)<<endl; // [1.33]
    // 13.6、改变矩阵的形状,reshape,Mat可以,Vec和Matx不知道为啥不行
    Mat m1(220,180,CV_8U);
    cout<<"m1.size() = "<<m1.size()<<endl; // [180 x 220]
    Mat m2 = m1.reshape(0,200);// 第1个参数是调整后的通道数,0表示不变,第二个是行数,0也是不变
    cout<<"m2.size() = "<<m2.size()<<endl;// [198 x 200],列在前行在后
    // 13.7、solve函数,计算线性系统,此函数不会用先这样

    // 13.8、t()转置函数
    Vec<double,4> vd5t(1.5,2.5,3.5);
    cout <<"before t() = "<<vd5t<<endl;//[1.5000000000, 2.5000000000, 3.5000000000, 0.0000000000]
    auto vd5t1 = vd5t.t();
    cout <<"after t() = "<<vd5t1<<endl;// [1.5, 2.5, 3.5, 0]
    Matx23d m23d;
    cout<<"m23d's col and row = "<<m23d.cols<<"  "<<m23d.rows<<endl; //3,2
    Matx32d m32d = m23d.t();// 转置
    cout<<"m23d's col and row = "<<m32d.cols<<"  "<<m32d.rows<<endl; //2,3
    // 13.9、获取数据类型,Vec<double,4>::value_type当成double使用
    cout<<"Vec<double,4>::value_type = "<<Vec<double,4>::value_type(1.5)<<endl;//1.5
    
    // 13.10、inv函数,必须是方阵
    Matx22d m22d_inv(1,2,3,4);
    auto m22dinv = m22d_inv.inv();
    cout<<"m22dinv = "<<m22dinv<<endl;//[-2,1;1.5,-0.5]
    return 0;
}