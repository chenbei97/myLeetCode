#ifndef __POINT_ON_LINE_H__
#define __POINT_ON_LINE_H__
#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
// 1个判断点(x,y)是否在2点(x1,y1),(x2,y2)构成的线段上的辅助函数
bool point_on_line(int x1,int y1,int x2,int y2,int x,int y);
#endif // !__POINT_ON_LINE_H__