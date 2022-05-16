#ifndef __CALC_HOMOGRAPHY_H__
#define __CALC_HOMOGRAPHY_H__
#include <opencv2/opencv.hpp>
using namespace cv;
void calc_homography(int pts1[4][2], int pts2[4][2], 
 int pts_in[][2], int pts_out[][2]);
#endif // !__CALC_HOMOGRAPHY_H__