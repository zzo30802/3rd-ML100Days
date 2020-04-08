// 專門將image用於全域變數

#pragma once
#ifndef IMAGE_H
#define IMAGE_H
#include <opencv2/core/core.hpp>
using namespace cv;
class image_grobal
{
public:
	static Mat image;
};
#endif // !IMAGE_H
