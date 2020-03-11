#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

double alpha; // 對比控制
int beta;	  // 亮度控制

int main(int argc, char** argv) {
	Mat image = imread("E:\\opencv_sample\\images\\lena.jpg");

	//為了不影響原圖所以建立一個大小與原圖相同的矩陣，內容補0。
	// 建立並初始化一個新矩陣，零矩陣、資料結構和image一樣。
	Mat new_image;
	new_image = Mat::zeros(image.size(), image.type());

	// Initialize values (Basic Linear Transform)
	cout << "基本線性轉換" << endl;
	cout << "------------" << endl;
	cout << "* 輸入alpha值[1.0 - 3.0]: "; cin >> alpha;
	cout << "* 輸入 beta值[  0 - 100]: "; cin >> beta;

	// 轉換公式 new_image(i,j) = alpha*image(i,j) + beta
	// 以下公式等於 cv::Mat::convertTo(OutputArray, int, alpha, beta)
	//https://blog.csdn.net/iracer/article/details/49204147
	//markers.convertTo(tmp,CV_8U,255,255); 
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				// 針對像素的每個色頻做轉換
				new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}

	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	imshow("Original Image", image);
	imshow("New Image", new_image);

	waitKey();
	return 0;
}