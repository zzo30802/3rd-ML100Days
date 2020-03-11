#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> //image processing
#include <vector>

using namespace std;
using namespace cv;

int main() {
	//載入檔案
	Mat image1 = imread("E:\\opencv_sample\\images\\lena.jpg");
	Mat logo = imread("E:\\opencv_sample\\images\\opencv-logo.png");

	//編譯器要求使用前須給初始值
	Mat image = image1, opencvlogo;

	//縮小原圖成Size(col, row)
	resize(logo, opencvlogo, Size(80, 64));

	namedWindow("Image 1", WINDOW_AUTOSIZE);

	//定義圖有興去的區域(Region Of Interest, ROI)
	Mat imageROI;

	//指定商標在原圖的位置，Rect(x, y, width(col), height(row))
	imageROI = image(Rect(420, 420, 80, 64));

	imshow("Image 1", opencvlogo);

	//加入商標
	addWeighted(imageROI, 1.0, opencvlogo, 0.3, 0.0, imageROI);

	//顯示結果
	namedWindow("with logo");
	imshow("with logo", image);

	waitKey();
	return 0;

}