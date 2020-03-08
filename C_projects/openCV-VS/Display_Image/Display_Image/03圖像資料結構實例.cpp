#include <opencv2/core/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int, char**) {
	//用建構子建立資料
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << "" << M << endl;

	//用create函數建立資料
}