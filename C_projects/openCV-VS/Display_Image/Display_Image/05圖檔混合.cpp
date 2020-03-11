#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(void) {
	double alpha = 1, beta, input;
	Mat src1, src2, dst;

	// 讓使用者輸入alpha值
	cout << "簡易線性攪合(Linear Blender)" << endl;
	cout << "-----------------" << endl;
	cout << "* 輸入 0 到 1 的alpha值 : ";
	cin >> input;

	//確認alpha值於0~1之間
	if (alpha >= 0 && alpha <= 1) //alpha在進入區域變數前要先初始化
		alpha = input;

	// 讀取兩個大小與類型相同的圖檔
	src1 = imread("E:\\opencv_sample\\images\\LinuxLogo.jpg");
	src2 = imread("E:\\opencv_sample\\images\\WindowsLogo.jpg");
	
	if (!src1.data) {
		cout << "讀取src1錯誤" << endl; return -1;
	};
	if (!src2.data) {
		cout << "讀取src1錯誤" << endl; return -1;
	};

	namedWindow("Linear Blend", 1);

	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);

	waitKey(0);
	return 0;
}