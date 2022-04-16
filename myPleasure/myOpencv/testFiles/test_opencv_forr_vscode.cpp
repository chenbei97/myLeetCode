/*** 
 * @Author: chenbei
 * @Date: 2022-04-15 09:35:37
 * @LastEditTime: 2022-04-15 10:30:19
 * @Description: opencv 
 * @FilePath: \myLeetCode\myPleasure\myOpencv\main.cpp
 * @Signature: A boy without dreams
 */
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
using namespace std;
using namespace cv;
int main(){
    cv::Mat src = cv::imread("./myBaby.jpg",IMREAD_GRAYSCALE);
    if (!src.empty())
    {
        std::cout << "src.depth()=" << src.depth() << std::endl;
        cv::namedWindow("input", WINDOW_FREERATIO);//可调的自由比例
        cv::imshow("input", src);
        cv::waitKey(0);
        cv::destroyAllWindows();
    }
    else
        printf("could not load image...");
}
