// test4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

//-----------------------对图像进行腐蚀处理-----------------------
//date:2018.7.26
//author:GZY
//
int main_erode()
{
	Mat srcImage = imread("zhu.jpg");
	namedWindow("zhu");
	imshow("before erode", srcImage);
	Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	imshow("after erode", dstImage);
	waitKey(60000);

    return 0;
}

