#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>
using namespace cv;
using namespace std;
/*
g++ -o ..\output\TermCriteria -g TermCriteria.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452
../output/TermCriteria
*/
int main(int argc,char**argv)
{
    /*
        很多算法需要一个终止条件确定何时退出，常常是迭代次数COUNT或者某种形式的误差参数EPS
        这些条件可以被封装传入Opencv的算法函数里，也就是TermCriteria类
        TermCriteria类有3个成员，分别是type，maxCount和epsilon
        这3个成员的值可以是任意的，但是type的值必须是下面的枚举值之一
        TermCriteria::COUNT：迭代次数
        TermCriteria::EPS：误差 
        TermCriteria::MAX_ITER：迭代次数，其中MAX_ITER是COUNT的同义词
        如果两个条件都想设置，可以在type使用或运算，即type=TermCriteria::COUNT|TermCriteria::EPS
    */
   // 一个简单的例子使用TermCriteria类作为算法的传入值
    TermCriteria termcrit(TermCriteria::COUNT|TermCriteria::EPS,20,0.03);

    // K均值聚类的例子
    const int MAX_CLUSTERS = 5; // 5聚类
    Scalar colorTab[] = 
    {
        Scalar(0, 0, 255),
        Scalar(0,255,0),
        Scalar(255,100,100),
        Scalar(255,0,255),
        Scalar(0,255,255) // 使用不同的颜色表示
    };
    Mat img(500, 500, CV_8UC3); // 创建一个500*500的彩色图像
    RNG rng(12345); // 随机数种子
    
    int k, clusterCount = rng.uniform(2, MAX_CLUSTERS+1); // [2,6)的范围随机数,2,3,4,5
    int i, sampleCount = rng.uniform(1, 1001); // 样本数量[0,1000]
    cout << "clusterCount = " << clusterCount << endl; // 4
    cout << "sampleCount = " << sampleCount << endl; // 664
    
    Mat points(sampleCount, 1, CV_32FC2), labels; // 2通道32位浮点数,sampleCount行2列,因为点有2个坐标
    // labels是k均值聚类的输出，每个点的类别
    cout <<"points.size() = " << points.size() << endl; // [1,664]
    clusterCount = MIN(clusterCount, sampleCount); // 聚类数量不能大于样本数量
    std::vector<Point2f> centers; // 存储点的集合centers,用于kmeans的输出
    
    /* 从多重高斯分布生成随机样本 */
    for( k = 0; k < clusterCount; k++ ) // 每个聚类生成一堆点 k=0,1,2,3
    {
        Point center; // 点
        center.x = rng.uniform(0, img.cols); // 随机,但是坐标不超过图像的宽度
        center.y = rng.uniform(0, img.rows); // 随机,但是坐标不超过图像的高度
        cout << "center.x = " << center.x << " center.y = " << center.y << endl; 
        // center.x = 483 center.y = 131
        // center.x = 189 center.y = 482
        // center.x = 263 center.y = 386
        // center.x = 123 center.y = 271
        // rowRange用于获取矩阵的一个块
        Mat pointChunk = points.rowRange(k*sampleCount/clusterCount,  //startrow,开始行=k*664/4
                                         // endrow,结束行,如果聚类数量为1,则为664,如果聚类数量为k>1,则为(k+1)*664/4
                                         k == clusterCount - 1 ? sampleCount :(k+1)*sampleCount/clusterCount); // 分块
        cout<<"pointChunk.size() = " << pointChunk.size() << endl; // [1,166] 664/166=4,其实就是分成了4段
         // pointChunk其实是points一部分的一个引用,填充了这个引用,points其实也是被填充了
         // fill的参数含义依次是：输出图像、分布类型(高斯还是均匀分布)
         // 2个参数a,b，如果是高斯分布，则为均值和标准差,如果是均匀分布，则为a,b上下界
         // saturateRange用于控制输出的值的上下限
        rng.fill(pointChunk, RNG::NORMAL, Scalar(center.x, center.y), Scalar(img.cols*0.05, img.rows*0.05)); // 填充点
    }
    
    randShuffle(points, 1, &rng); // 打乱点的顺序
    // points判断是否为空
    cout << "points.empty() = " << points.empty() << endl; // 0
    // points的size
    cout << "points.size() = " << points.size() << endl; // [1,664]
    // 输出points
    // cout << "points = " << points << endl; // [1,664]
    double compactness = kmeans(points, clusterCount, labels,  // 664个点分成4个簇,
        TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0),  //终止条件迭代次数10,误差1.0
           3,KMEANS_PP_CENTERS, centers); // 指定使用不同初始标签执行算法的次数,3次,centers是输出的中心点
    cout << "Compactness: " << compactness << endl; // 输出聚类的紧密程度=801575

    // 打印出所有的中心点,4×2
    cout << "centers = " << centers << endl; // [480.43631, 131.26483;263.0054, 389.98752;124.43169, 271.78226;187.88651, 484.75717]
    // 打印出所有点的类别labels,[1,664]
    cout<<"labels.size() = " << labels.size() << endl; // [1,664]
    // cout<<"labels = "<<labels<<endl;

    img = Scalar::all(0); // 用于画点的空白图像,赋好初值
    for( i = 0; i < sampleCount; i++ ) // 把所有的样本点在图像上画出来
    {
        int clusterIdx = labels.at<int>(i); // 获取点的簇索引,也就是点分类后的类别
        // cout<<"clusterIdx = " << clusterIdx << endl; // ∈[0,1,2,3]
        Point2i ipt = points.at<Point2f>(i); // 获取与i对应的点,隐式转换为int型
        // cout<<"ipt = " << ipt << endl; // 观察发现有些点越界,如ipt = [183, 507]
        
        // 所以使用circle函数时事先对点进行一个判断,不要超过图像的边界
        // 参数为:输出对象、点的坐标、半径、颜色、线宽以及线类型
        // opencv中x代表图像的宽度,y代表图像的高度,对应就是列和行
        if( ipt.x >= 0 && ipt.x < img.cols && ipt.y >= 0 && ipt.y < img.rows )
            circle(img, ipt, 1, colorTab[clusterIdx],FILLED,LINE_AA); // 画点
    }
    for (i = 0; i < (int)centers.size(); ++i) // 画聚类中心
    {
        Point2f c = centers[i]; // 获取聚类中心
        circle( img, c, 40, colorTab[i], 1, LINE_AA );// 画聚类中心
    }
    
    imshow("clusters", img);// 显示图像
    waitKey(0);
    destroyAllWindows();
    return 0;
}