/*
 * @Author: chenbei
 * @Date: 2022-04-30 10:12:40
 * @LastEditTime: 2022-04-30 11:19:27
 * @FilePath: \myLeetCode\myPleasure\myOpencv\examples\source\createTrackbar.cpp
 * @Description: test for createTrackbar
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\createTrackbar -g createTrackbar.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/createTrackbar ../images/myBabyOnBed.mp4
*/
// 滑动条是一个很有用的功能,借助回调函数实现,但是需要一些全局变量
VideoCapture cap; // 全局的视频捕获对象
int slider_position = 0; // 用于存储滑动条的位置
int run = 1; 
/* 当为正数时表示停止前要播放多少张图片
为负数表示处于连续视频播放模式
特别的为1表示进入单步模式
单步模式的意思是程序只读取一张图片
在下面的程序中如果R键被按下,则会连续播放
空格键被按下,进入单步模式,每次只读取一张图片
*/
int dontset = 0; 
/* 用户点击滑动条跳转到视频某个位置后run=1就会进入单步模式,也就是程序会暂停在某个帧,这是回调函数重设置该变量为0导致run=1的原因
但是希望滑动条也要继续跟随视频前进,所以希望不要进入单步模式,默认0表示为单步模式,为1表示连续模式
可以用此变量防止调整进度条位置时触发单步模式*/

// 回调函数
void onTrackBarSlide(int pos, void *){ // 滑动条回调函数固定的参数类型int,void*
    // set,get可以设置和获取视频捕获对象的很多变量,比如帧率,视频大小等
    cap.set(CAP_PROP_POS_FRAMES, pos); // 设置视频捕获对象的位置,pos是滑动条实时的位置
    if (dontset == 0) { // 该变量为0时说明是单步模式
        run = 1;  // 也就是用户触发滑动条事件时会进入单步
    }
    dontset = 0; // 将dontset重置为0,就是每次点击滑动条就回调该变量为0,然后进入单步模式
}
int main(int argc,char**argv)
{
    // Mat src = imread(("../images/m.jpg"), IMREAD_GRAYSCALE);
    namedWindow("src", WINDOW_AUTOSIZE);
    cap.open(argv[1]); // 打开视频文件
    if (!cap.isOpened()) { // 如果没有打开成功
        cout << "open failed" << endl;
        return -1;
    }
    // 获取视频的总帧数、帧率、视频的宽、高
    int total_frames = cap.get(CAP_PROP_FRAME_COUNT);
    double fps = cap.get(CAP_PROP_FPS);
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "total_frames: " << total_frames 
        <<" fps: " << fps 
        << " width: " << width 
        << " height: " << height << endl;
    
    // 创建滑动条
    createTrackbar("position",  // 滑动条要求的参数依次是滑动条名字
                    "src",  // 滑动条要求的窗口名字
                    &slider_position, // 滑动条要求的滑动条位置,全局变量
                    total_frames, // 滑动条要求的滑动条最大位置
                    onTrackBarSlide);// 滑动条要求的回调函数
    
    // 存储帧的结构
    Mat frame;

    // 循环播放视频
    while (1) {
        if (run != 0) { // 如果帧没有播放完成
            cap >> frame; // 读取一帧
            if (frame.empty()) { // 如果读取失败
                cout << "read failed" << endl;
                break;
            }
            int current_pos = (int)cap.get(CAP_PROP_POS_FRAMES); // 获取当前位置
            dontset = 1; // 将dontset设置为1,表示用户点击滑动条后不要进入单步模式
            setTrackbarPos("position", "src", current_pos); // 设置滑动条位置,给出要显示的滑动条名字和窗口名字
            imshow("src", frame); // 显示帧
            waitKey(10); // 等待10ms,至少1ms,不然连续播放模式速度太快会卡住
            run -= 1; // 表示播放完成一帧,run减1
        }  
        char c = (char)waitKey(10); // 等待10ms
        if (c == 27) { // 如果按下ESC键
            break;
        }
        else if (c == ' ') { // 如果按下空格键
            run = 1; // 进入单步模式,重置为1是因为每次按下空格if语句内就会减1变成0会导致不能在播放,所以要重置为1
            cout<< "now is single step mode " << slider_position+1<< endl;// 按下键就知道处于哪一帧
        }
        else if(c == 'r'){ // 连续播放模式,只要是负数就可以,这样run总是自减直到读取帧失败为止
            // 但是只需要按一次r键就可以了,如果想转单步那就按空格键
            run = -2; // <0时认为是连续播放模式,因为run是不等于0就可以执行播放而不是<0
            cout<< "now is run mode " << slider_position+1<< endl; // 按下键就知道处于哪一帧
        }
        else if (c == 'b'){ // 按下键盘b视频会重头播放
            cap.set(CAP_PROP_POS_FRAMES, 0); // 设置当前位置为0
            slider_position = 0; // 滑动条位置为0
            cout<< "now is back to the beginning " << slider_position+1<< endl; // 从头开始
        } 
    }
    destroyAllWindows();
    return 0;
}
