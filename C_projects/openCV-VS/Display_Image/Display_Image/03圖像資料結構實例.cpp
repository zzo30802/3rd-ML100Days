#include <opencv2/core/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int, char**) {
	// 用建構子建立資料
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << "" << M << endl;

	// 用create函數建立資料
	/*
	CV_8UC1: 單通道陣列，8bit無符號整數
	CV_8UC2: 2通道，8bit無符號整數
	CV_8UC3: 3通道，8bit無符號整數
	CV_8UC4: 4通道，8bit無符號整數
	CV_8UC(n): n通道，8bit無符號整數(n可以從1~512)*/
	M.create(2, 1, CV_8UC(3));
	cout << "M = " << endl << "" << M << endl;

	// 建立多維矩陣
	int sz[3] = { 2,2,2 };
	Mat L(3, sz, CV_8UC(1), Scalar::all(0));
	// 無法用<<運算子輸出

	// 用MATLAB風格的眼建立資料
	Mat E = Mat::eye(3, 3, CV_64F);
	cout << "E = " << endl << "" << E << endl;
	/*
	CV_8U：8-bit unsigned integers ( 0~255 )
	CV_8S：8-bit signed integers ( -128~127 )
	CV_16U：16-bit unsigned integers ( 0~65535 )大小相當於short
	CV_16S：16-bit signed integers ( -32768~32767 )大小相當於short
	CV_32S：32-bit signed integers ( -2147483648~2147483647 )大小相當於long
	CV_32F：32-bit ﬂoating-point numbers
	CV_64F：64-bit ﬂoating-point numbers
	*/
	/*Mat_<uchar>對應CV_8U
	Mat_<char>對應CV_8S
	Mat_<short>對應CV_16S
	Mat_<int>對應CV_32S
	Mat_<float>對應CV_32F
	Mat_<double>對應CV_64F
	*/

	// 資料都是1
	Mat O = Mat::zeros(2, 2, CV_32F);
	cout << "O = " << endl << O << endl << endl;

	// 資料都是0
	Mat z = Mat::zeros(0, 0, CV_8UC1);
	cout << "z = " << endl << z << endl << endl;

	// 建立3x3雙精確度矩陣，值由<<輸入
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C = " << endl << C << endl << endl;

	// 複製第一列資料
	Mat RowClone = C.row(1).clone();
	cout << "RowClone = " << endl << RowClone << endl << endl;

	// 以亂數值填入矩陣內
	//randu(dst, low ,high)    low:include  high:exclude
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(256));
	cout << "R (default) = " << endl << R << endl << endl;

	// 圖像中二維的點
	Point2f P(5, 1);
	cout << "Point(2D) : " << P << endl << endl;

	// 圖像中三維的點
	Point3f P3f(2, 6, 7);
	cout << "Point(3D) : " << P3f << endl << endl;

	vector<float> v;
	v.push_back((float)CV_PI);
	v.push_back(2);
	v.push_back(3.01f);

	cout << "浮點向量矩陣 = " << endl << Mat(v) << endl << endl;

	vector<Point2f> vPoints(5);
	for (size_t i = 0; i < vPoints.size(); ++i)
		vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));

	cout << "二維圖點向量 : " << endl << vPoints << endl;

	return 0;

}