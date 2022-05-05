/*** 
 * @Author: chenbei
 * @Date: 2022-05-05 08:18:14
 * @LastEditTime: 2022-05-05 08:39:18
 * @Description: test for cv::Rect
 * @FilePath: \myLeetCode\myPleasure\myOpencv\basicTypes\source\Rect.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\Rect -g Rect.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/Rect
*/
int main(int argc,char**argv)
{
    /*
        矩形类包含了Point和Size，因为矩形可以通过一个点和宽高来构造
    */
   // 默认和复制构造以及值构造
    Rect r1; // 默认构造函数
    Rect r2(r1); // 复制构造
    Rect r3(1,2,3,4);//值构造
    cout<<"r3: "<<r3<<endl; // [3 x 4 from (1, 2)]
    // 通过Point和Size构造
    Rect r4(Point(1,2),Size(3,4));
    // 计算面积
    cout<<"r4 area: "<<r4.area()<<endl; // 12
    // 由2个对角点构造
    Rect r5(Point(1,2),Point(5,6));
    // 计算面积
    cout<<"r5 area: "<<r5.area()<<endl; // 16

    // 成员访问
    cout<<"r5.x="<<r5.x<<" r5.y="<<r5.y<<" r5.width="<<r5.width
        <<" r5.height="<<r5.height<<endl; // 1 2 4 4
    
    // 判断(3,3)是否在矩形内
    cout<<boolalpha<<"r5 contains (3,3): "<<r5.contains(Point(3,3))<<endl; // true

    // 提取矩形的左上角和右下角点
    Point pt1 = r5.tl(); // (1,2)
    Point pt2 = r5.br(); // (5,6)
    cout<<"r5 tl: "<<pt1<<" r5 br: "<<pt2<<endl; // (1,2) (5,6)

    // 可以计算2个矩形的交集
    Rect r6(1,2,3,4);
    Rect r7(2,3,4,5);
    Rect r8 = r6 & r7;
    cout<<"r8: "<<r8<<endl; // [2 x 2 from (2, 3)]
    r6 &= r7; // 这样做也可以
    cout<<"r6: "<<r6<<endl; // [2 x 2 from (2, 3)]
    
    // 2个矩形并集,但是保证是最小面积矩形的情况下
    Rect r9 = r6 | r7;
    cout<<"r9: "<<r9<<endl; // [4 x 5 from (2, 3)]

    // 平移矩形x个数量
    Rect r9x = r9 + Point(5,4); // 向右平移5个单位,向下平移4个单位
    cout<<"r9x: "<<r9x<<endl; // [4 x 5 from (7, 7)]

    // 扩大矩形的大小
    Rect r9s = r9 + Size(5,4); // 向右扩大5个单位,向下扩大4个单位
    cout<<"r9s: "<<r9s<<endl; // [9 x 9 from (2, 3)]

    // 比较2个矩形是否相等
    Rect r10(1,2,3,4);
    Rect r11(1,2,3,4);
    cout<<boolalpha<<"r10==r11: "<<(r10==r11)<<endl; // true
    // 比较2个矩形是否不等
    cout<<boolalpha<<"r10!=r11: "<<(r10!=r11)<<endl; // false

    // RotatedRect类和Rect类似,只是增加了一个额外的参数,用来表示旋转角度
    // Rect原地在左上角,而RotatedRect在中心
    // 是少数没有使用模板的接口类
    // RotatedRect类支持默认、复制、值的Point,Size,theta的构造
    RotatedRect rr1;// 默认构造
    RotatedRect rr2(rr1);// 复制构造
    RotatedRect rr3(Point(1,2),Size(3,4),45);// Point,Size,theta的构造

    // 提取旋转矩形的中心点、Size和旋转角度
    Point pt3 = rr3.center;
    cout<<"rr3 center: "<<pt3<<endl; // (1,2)
    Size sz3 = rr3.size;
    cout<<"rr3 size: "<<sz3<<endl; // (3,4)
    double theta3 = rr3.angle;
    cout<<"rr3 theta: "<<theta3<<endl; // 45

    // 返回4个角的列表
    Point2f pts[4]; // Point2f的数组
    rr3.points(pts); // 存储4个角点
    cout<<"rr3 points: "<<pts[0]<<" "<<pts[1]<<" "<<pts[2]
        <<" "<<pts[3]<<endl; 
    // [-1.47487, 2.35355] [1.35355, -0.474874] [3.47487, 1.64645] [0.646446, 4.47487]

    // 返回边界矩形
    Rect rr4 = rr3.boundingRect();
    cout<<"rr4: "<<rr4<<endl; // [7 x 7 from (-2, -1)]
    Rect rr5 = rr3.boundingRect2f(); // 返回边界矩形,但是返回的是float类型的矩形
    cout<<"rr5: "<<rr5<<endl; // [5 x 5 from (-1, 0)]

    return 0;
}