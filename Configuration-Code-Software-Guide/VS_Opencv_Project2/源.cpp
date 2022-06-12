//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <string>
//#include	<vector>
//using namespace std;
//using namespace cv;
//int main() {
    //Mat img = imread("C:/Users/chenb/Desktop/Configuration-Code-Software-Guide/opencv_mingw32-make install.png");
    //namedWindow("img", WINDOW_AUTOSIZE);
    //imshow("img", img);
    //cout << "here\n";
    //waitKey(0);
    //destroyAllWindows();
//}
#include <iostream>
#include <iterator>
#include "simpleShow.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat& ScanImageAndReduceC(Mat & I, const uchar* const table)
{
    // Ҫ��ͼ����CV_8U���͵�,��������ͨ��
    // ʹ��������ָ�����
    CV_Assert(I.depth() == CV_8U);
    int channels = I.channels(); // ��ȡͼ��ͨ����
    int nRows = I.rows; // ��ȡͼ������
    int nCols = I.cols * channels; // ��ȡͼ������,������Ϊ�ڴ�ֲ������ά�ȵ�����ͨ��ƽ��
    if (I.isContinuous()) // ���ͼ����������
    {
        nCols *= nRows; // ��ô�Ϳ��԰������������ں�ѵ�
        nRows = 1; // Ҳ����1��,channels*cols��
    }
    int i, j;
    uchar* p; // ָ�������ݵ�ָ��
    for (i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i); // ��ȡ�����ݵ�ָ��
        for (j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]]; // ��ÿ�����ص��ֵת��Ϊ�µ�ֵ
        }
    }
    return I;
}
void scanImageBydata(Mat & I, const uchar* const table) {
    // Ҫ��ͼ����CV_8UC1���͵�,��ͨ��
    CV_Assert(I.depth() == CV_8UC1);
    int nRows = I.rows; // ��ȡͼ������
    int nCols = I.cols; // ��ȡͼ������
    uchar* p = I.data; // ��ȡͼ�����ݵ�ָ��,���ָ��ͼ���ÿ�����ص�
    for (unsigned int i = 0; i < nCols * nRows; ++i)
    {
        // cout<<"*p = "<<(int)*p<<" "; // ֵ���ᳬ��255,��tableǡ����256��Ԫ��,���Բ���Խ��
        *p++ = table[*p]; // ָ�����ص��ָ��++,ָ����һ�����ص�,*ǡ��Ҳ������
    }
    // cout<<endl;
}
Mat& ScanImageAndReduceIterator(Mat & I, const uchar* const table)
{
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    switch (channels)
    {
    case 1: // ��ͨ��
    {
        MatIterator_<uchar> it, end;
        for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
            *it = table[*it]; // ��ÿ�����ص��ֵת��Ϊ�µ�ֵ
        break;
    }
    case 3:
    {
        MatIterator_<Vec3b> it, end;
        for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
        {
            // �����������ú���Vec3b����,����[0],[1],[2]���ʲ�ͬ��ͨ��
            // cout <<"(*it)[0] = " << (int)(*it)[0] << " (*it)[1] = " << (int)(*it)[1] << " (*it)[2] = " << (int)(*it)[2] << endl;
            (*it)[0] = table[(*it)[0]];
            (*it)[1] = table[(*it)[1]];
            (*it)[2] = table[(*it)[2]];
        }
    }
    }
    return I;
}
Mat& ScanImageAndReduceRandomAccess(Mat & I, const uchar* const table)
{
    // �����÷��صĶ�̬��ַ����
    /*
        �÷������������ڱ���ͼ��,����������ȡ���޸�ͼ���е����Ԫ��
        ���Ļ����÷���ָ��Ҫ���ʵ�����кź��к�,��Ҫ�ֶ�ָ�����Զ�����ʱʹ�õ�����
        ��������Դ����ĻҶ�ͼ��(ʹ��cv::Mat::at<T>()����)�����Թ۲쵽��һ��
        ʹ��at<uchar>(i,j)����at<Vec3b>(i,j)����ͼ���е�ĳ�����ص�

        at�������������������ͺ����꣬�������ѯ��ĵ�ַ��Ȼ�󷵻ض���������
        ����õ����ֵʱ����������һ���������������������ֵʱ����������һ���ǳ���
        ����Ϊ����ģʽ�µİ�ȫ���裬��Ҫ������������Ƿ���Ч��ȷʵ����
        ������������Ļ�������ڱ�׼����������еõ�һ���ܺõ������Ϣ

        �����Ҫʹ�ô˷�����ͼ����ж�β��ң���Ϊÿ�η����������ͺ�at�ؼ��ֿ��ܻ���鷳�Һ�ʱ
        Ϊ�˽��������⣬OpenCV��һ��cv::Mat_��������,����Mat��ͬ
        ���ڶ���ʱ������Ҫͨ���鿴���ݾ����������ָ���������ͣ�����Ϊ�ر���������ʹ�������()���ٷ������ص�
    */
    CV_Assert(I.depth() == CV_8U);
    const int channels = I.channels();
    switch (channels)
    {
    case 1:
    {
        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j)
                I.at<uchar>(i, j) = table[I.at<uchar>(i, j)]; // ��ȡָ��λ�õ����ص��ֵ
        break;
    }
    case 3:
    {
        Mat_<Vec3b> _I = I; // ��ʽת��ΪMat_<Vec3b>����,���Խ���Mat_���Ч��
        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j)
            {
                _I(i, j)[0] = table[_I(i, j)[0]]; // ��ȡָ��λ�õ����ص��ֵ
                _I(i, j)[1] = table[_I(i, j)[1]];
                _I(i, j)[2] = table[_I(i, j)[2]];
            }
        I = _I; // ��ֵ��ȥ
        break;
    }
    }
    return I;
}

int main(int argc, char** argv)
{
    // ʹ�ùٷ��ṩ�ļ��ַ���ɨ��ͼ��
    // https://docs.opencv.org/4.x/db/da5/tutorial_how_to_scan_images.html
    /*
        Times passed in seconds: 0.445 ms  ��ͨ�� ��ָ�뷨
        Times passed in seconds: 0.1581 ms ��ͨ�� dataָ�뷨
        Times passed in seconds: 1.9845 ms ��ͨ�� ��������
        Times passed in seconds: 1.8508 ms ��ͨ�� at<T>(i,j)��
        Times passed in seconds: 0.2193 ms ��ͨ��,LUT��
    */
    Mat src = imread("cat.jpg");
    //simpleShow(src, "src");
    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    uchar table[256]; // ����һ��256���ȵ�����
    int divideWith = 16; // Ŀ���ǽ����ص��ֵ�ֳ�16�ȷ�,�������ص�ֻ��256/16=16������ֵ
    // �����൱�ڸ��ӵľ��ȷֲ�
    for (int i = 0; i < 256; ++i)
        table[i] = (uchar)(divideWith * (i / divideWith));
    // ���table
    // ostream_iterator<int> out(cout, " ");
    // copy(table, table + 256, out);
    // cout << endl;

    // table��Ϊ�������뺯��
    double t = (double)getTickCount();
    Mat dst = ScanImageAndReduceC(src, table);
    t = ((double)getTickCount() - t) / getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms" << endl;
    //simpleShow(dst,"dst");

    // ����ǻҶ�ͼ��,������ͨ��dataָ���ȡ
    t = (double)getTickCount();
    scanImageBydata(gray, table);
    t = ((double)getTickCount() - t) / getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms" << endl;
    //simpleShow(gray,"gray");

    // ���������ȫ�ķ�ʽ,����Ч�ʱȽϵ�
    t = (double)getTickCount();
    ScanImageAndReduceIterator(src, table);
    t = ((double)getTickCount() - t) / getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms" << endl;

    // ����ʹ��������ָ��/dataָ��/����������,�����Ҫ�ı�����ֵ����ʹ��at<uchar>(i,j)����at<Vec3b>(i,j)
    // ���������Ǳ���ͼ��Ҫʹ�����ַ�ʽ
    t = (double)getTickCount();
    ScanImageAndReduceRandomAccess(src, table);
    t = ((double)getTickCount() - t) / getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms" << endl;

    // ʹ��cv::LUT����Ҳ�ǿ��Ե�
    /*
        ����һ����ͼ����ʵ�ֲ��ұ��޸ĵĶ��ⷽ��.��ͼ�����У�ͨ����Ҫ�����и�����ͼ��ֵ�޸�Ϊ����ֵ
        OpenCV�ṩ���޸�ͼ��ֵ�Ĺ��ܣ�����д��ͼ���ɨ���߼�
        ����ʹ�ú���ģ���cv:��LUT()���������ȣ����ǹ���һ��Mat���͵Ĳ��ұ�
    */
    Mat lookUpTable(1, 256, CV_8U); // ����һ��1��256�е�8λ����
    uchar* p = lookUpTable.ptr(); // ��ȡָ��
    for (int i = 0; i < 256; ++i)
        p[i] = table[i];
    t = (double)getTickCount();
    Mat dst_new;
    cv::LUT(src, lookUpTable, dst_new);
    t = ((double)getTickCount() - t) / getTickFrequency() * 1000;
    cout << "Times passed in seconds: " << t << " ms" << endl;
    return 0;
}