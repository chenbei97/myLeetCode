#include "YOLO.h"
int main()
{
	YOLO yolo_model("./yolop.onnx", 0.25, 0.45, 0.5);
	string imgpath = "./images/1.jpg";
	Mat srcimg = imread(imgpath);
	if (srcimg.empty()) {
		cout << "load image failed" << endl;
	}
	Mat outimg = yolo_model.detect(srcimg);

	static const string kWinName = "Deep learning object detection in OpenCV";
	namedWindow(kWinName, WINDOW_NORMAL);
	imshow(kWinName, outimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}