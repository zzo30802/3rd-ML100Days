#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
    argv[1] = "E:\\3rd-ML100Days\\C_projects\\openCV\\resource\\dog.jpg";
    //Mat是openCV新訂的資料型態，就像傳統的資料型態int、float、String。Mat代表圖像，而圖像都是二維陣列，所以OpenCV定義處理圖像的矩陣類別(Matrix)
    Mat image;

    //載入圖檔
    image = imread(argv[1], IMREAD_COLOR);

    //檢查讀檔是否成功
    if (!image.data) {
        cout << "無法開啟或找不到圖檔" << std::endl;
        return -1;
    }

    //建立顯示圖檔視窗
    namedWindow("Display window", WINDOW_NORMAL);

    // CV_WINDOW_FREERATIO 與 CV_WINDOW_KEEPRATIO
    // CV_GUI_NORMAL 與 CV_GUI_EXPANDED

    // 視窗內顯示圖檔
    imshow("Display window", image);

    //視窗等待按鍵
    waitKey(0);

    return 0;
}