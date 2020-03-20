#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
	//程式啟動時會直接輸入
	argv[1] = "E:\\3rd-ML100Days\\C_projects\\openCV-VS\\resource\\dog.jpg";

	Mat image;

	// 輸入圖檔
	image = imread(argv[1], IMREAD_COLOR);

	// 檢查讀檔是否成功
	if (!image.data) {
		cout << "無法開啟或找不到圖檔" << endl;
		return -1;
	}

	// 建立顯示圖檔視窗
	namedWindow("原圖", WINDOW_NORMAL);
	namedWindow("下雪圖", WINDOW_NORMAL);

	imshow("原圖", image);

	// 雪點數
	int i = 600;
	for (int k = 0; k < i; k++) {
		// rand() is the MFC random number generator
		// try qrand() with Qt
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		if (image.channels() == 1) {// gray-level image
			image.at<uchar>(j, i) = 255;
			if (i < (int)image.cols)
				image.at<uchar>(j + 1, i) = 255;
			if (j < (int)image.rows)
				image.at<uchar>(j, i + 1) = 255;
			if ((i < (int)image.cols) && j < (int)image.rows)
				image.at<uchar>(j + 1, i + 1) = 255;
		}
		else if (image.channels() == 3) {// color image
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
			if (i < (int)image.cols - 1) {
				image.at<cv::Vec3b>(j, i + 1)[0] = 255;
				image.at<cv::Vec3b>(j, i + 1)[1] = 255;
				image.at<cv::Vec3b>(j, i + 1)[2] = 255;
			}
			if (j < (int)image.rows - 1) {
				image.at<cv::Vec3b>(j + 1, i)[0] = 255;
				image.at<cv::Vec3b>(j + 1, i)[1] = 255;
				image.at<cv::Vec3b>(j + 0, i)[2] = 255;
			}
			if ((i < (int)image.cols - 1) && (j < (int)image.rows - 1)) {
				image.at<cv::Vec3b>(j + 1, i + 1)[0] = 255;
				image.at<cv::Vec3b>(j + 1, i + 1)[1] = 255;
				image.at<cv::Vec3b>(j + 0, i + 1)[2] = 255;
			}
		}
	}
	//在視窗內顯示圖檔
	imshow("下雪圖", image);

	//視窗等待按鍵
	waitKey(0);
	return 0;
}