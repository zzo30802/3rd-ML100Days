#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#define w 400  // 定義程式中所有的w = 400

using namespace std;
using namespace cv;

// 函式宣告
void MyEllipse(Mat img, double angle);
void MyFilledCircle(Mat img, Point center); //Point center; 建立一個2D點物件 center.x=10; center.y=8; 初始化x,y座標值
void MyPolygon(Mat img);
void MyLine(Mat img, Point start, Point end);

int main() {
	// 視窗名稱
	char atom_window[] = "Drawing 1: Atom";
	char rook_window[] = "Drawing 2: Rook";

	// 建立空的黑圖
	Mat atom_image = Mat::zeros(w, w, CV_8UC3);
	Mat rook_image = Mat::zeros(w, w, CV_8UC3);

	// atom
	// 畫橢圓
	MyEllipse(atom_image, 90);
	MyEllipse(atom_image, 0);
	MyEllipse(atom_image, 45);
	MyEllipse(atom_image, -45);
	MyFilledCircle(atom_image, Point(w / 2, w / 2));

	// rook
	// 畫凸面多邊形
	MyPolygon(rook_image);
	// 畫長方形
	rectangle(rook_image,
		Point(0, 7 * w / 8),
		Point(w, w),
		Scalar(0, 255, 255),
		-1,
		8);
	// 繪直線
	MyLine(rook_image, Point(0, 15 * w / 16), Point(w, 15 * w / 16));
	MyLine(rook_image, Point(w / 4, 7 * w / 8), Point(w / 4, w));
	MyLine(rook_image, Point(w / 2, 7 * w / 8), Point(w / 2, w));
	MyLine(rook_image, Point(3 * w / 4, 7 * w / 8), Point(3 * w / 4, w));
	
	// 顯示視窗
	imshow(atom_window, atom_image);
	// 移動到視窗指定位置
	moveWindow(atom_window, w, 200);

	imshow(rook_window, rook_image);
	moveWindow(rook_window, w, 200);

	waitKey(0);

	return(0);
}

// 橢圓
void MyEllipse(Mat img, double angle) {
	int thickness = 2;
	int lineType = 8;

	ellipse(img,
		Point(w / 2, w / 2),
		Size(w / 4, w / 16),
		angle,
		0,
		360,
		Scalar(255, 0, 0),
		thickness,
		lineType);
	}

// 繪圓
void MyFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		w / 32,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}

// 繪凸面多邊型
void MyPolygon(Mat img)
{
	int lineType = 8;

	/** 先建立點 */
	Point rook_points[1][20];
	rook_points[0][0] = Point(w / 4, 7 * w / 8);
	rook_points[0][1] = Point(3 * w / 4, 7 * w / 8);
	rook_points[0][2] = Point(3 * w / 4, 13 * w / 16);
	rook_points[0][3] = Point(11 * w / 16, 13 * w / 16);
	rook_points[0][4] = Point(19 * w / 32, 3 * w / 8);
	rook_points[0][5] = Point(3 * w / 4, 3 * w / 8);
	rook_points[0][6] = Point(3 * w / 4, w / 8);
	rook_points[0][7] = Point(26 * w / 40, w / 8);
	rook_points[0][8] = Point(26 * w / 40, w / 4);
	rook_points[0][9] = Point(22 * w / 40, w / 4);
	rook_points[0][10] = Point(22 * w / 40, w / 8);
	rook_points[0][11] = Point(18 * w / 40, w / 8);
	rook_points[0][12] = Point(18 * w / 40, w / 4);
	rook_points[0][13] = Point(14 * w / 40, w / 4);
	rook_points[0][14] = Point(14 * w / 40, w / 8);
	rook_points[0][15] = Point(w / 4, w / 8);
	rook_points[0][16] = Point(w / 4, 3 * w / 8);
	rook_points[0][17] = Point(13 * w / 32, 3 * w / 8);
	rook_points[0][18] = Point(5 * w / 16, 13 * w / 16);
	rook_points[0][19] = Point(w / 4, 13 * w / 16);

	const Point* ppt[1] = { rook_points[0] };
	int npt[] = { 20 };

	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
}

// 繪直線
void MyLine(Mat img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		Scalar(0, 0, 0),
		thickness,
		lineType);
}