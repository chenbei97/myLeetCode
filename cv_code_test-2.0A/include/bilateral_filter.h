#ifndef __BILATERAL_FILTER_H__
#define __BILATERAL_FILTER_H__
#include <opencv2/opencv.hpp>
using namespace cv;
void bilateral_filter(const char* in_img_name, const char* out_img_name, 
                      const int ker_radius, const float sigma_color, const float sigma_space);
#endif // !__BILATERAL_FILTER_H__