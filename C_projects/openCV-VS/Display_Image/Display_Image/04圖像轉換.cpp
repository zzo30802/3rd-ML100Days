#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2\imgproc.hpp> //cvtColor
using namespace std;
using namespace cv;
int main(int argc, char* argv) {
	// 圖檔
	const char* imageName = "E:\\3rd-ML100Days\\C_projects\\openCV-VS\\resource\\dog.jpg";
	
	// 讀取圖檔
	Mat image = imread(imageName, 1); // 1 = IMREAD_COLOR

	// 圖檔從RGB轉灰階
	Mat gray_image;
	cvtColor(image, gray_image, cv::COLOR_RGB2GRAY);

	// 顯示圖檔視窗大小
	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("Gray image", WINDOW_AUTOSIZE);

	// 顯示原先圖樣
	imshow(imageName, image);
	
	// 顯示灰階圖樣
	imshow("Gray image", gray_image);
	
	
	waitKey(0);
	return 0;
}
