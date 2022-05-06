#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace dnn;
using namespace std;

class YOLO
{
public:
	YOLO(string modelpath, float confThreshold, float nmsThreshold, float objThreshold);
	Mat detect(Mat& frame);
private:
	const float mean[3] = { 0.485, 0.456, 0.406 };
	const float std[3] = { 0.229, 0.224, 0.225 };
	const float anchors[3][6] = { {3,9,5,11,4,20}, {7,18,6,39,12,31},{19,50,38,81,68,157} };
	const float stride[3] = { 8.0, 16.0, 32.0 };
	const string classesFile = "bdd100k.names";
	const int inpWidth = 640;
	const int inpHeight = 640;
	float confThreshold;
	float nmsThreshold;
	float objThreshold;
	const bool keep_ratio = true;
	vector<string> classes;
	Net net;
	Mat resize_image(Mat srcimg, int* newh, int* neww, int* top, int* left);
	void normalize(Mat& srcimg);
	void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame);
};
