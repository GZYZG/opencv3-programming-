
#include "stdafx.h"

using namespace cv;


//----------对图像进行模糊处理-----------
//date:2018.7.29
//author:GZY
//

int main_blur()
{
	Mat srcImage = imread("heibao.jpg");

	namedWindow("blur",3);

	imshow("均值滤波【原图】", srcImage);

	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	imshow("均值滤波【效果图】", dstImage);
	waitKey(0);

	return 0;

}