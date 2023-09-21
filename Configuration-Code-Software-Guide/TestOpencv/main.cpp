#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <QDir>
#include <QDebug>
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    auto dir = QDir::current();
    dir.cdUp();
    auto path = dir.path()+"/myBaby.jpg";
    qDebug()<<path;
    cout<<"hello opencv"<<endl;
    cv::Mat src = cv::imread(path.toStdString().c_str(),IMREAD_GRAYSCALE);
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
    return 0;
}

