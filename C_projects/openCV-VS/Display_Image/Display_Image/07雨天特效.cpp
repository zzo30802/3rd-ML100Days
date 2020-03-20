#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main() {
	Mat image1, image2, image3;
	image1 = imread("E:\\opencv_sample\\images\\lake.jpg");
	if (!image1.data)
		return -1;
	image2 = imread("E:\\opencv_sample\\images\\fur.jpg");
	if (!image2.data)
		return -2;
	
	// 以image2影像大小調整image1影像大小
	//resize(輸入array, 輸出array, fxfy/size()大小)
	resize(image2, image3, image1.size());

	// 顯示原圖
	namedWindow("Image 1");
	imshow("Image 1", image1);

	namedWindow("Image 3");
	imshow("Image 3", image3);

	//雨天特效圖
	Mat result;
	image3 = image3 * 0.3;
	image1 = image1 * 0.9;
	add(image1, image3, result);
	
	namedWindow("result");
	imshow("result", result);
	
	waitKey();
	return 0;
}