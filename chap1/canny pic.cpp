#include "stdafx.h"

using namespace cv;
using namespace std;
//-----------------canny 边缘检测-------------------
//date:2018.7.29
//author:GZY
//

int main_canny()
{
	Mat srcImage = imread("heibao.jpg");
	Mat dstImage, edge, grayImage;
	char flag;

	namedWindow("canny");
	imshow("【原始图】Canny 边缘检测", srcImage);

	//创建于源图像同类型，同大小的图像
	dstImage.create(srcImage.size(), srcImage.type());

	//将原图转换为灰度图像
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//使用3x3内核降噪
	blur(grayImage, edge, Size(3, 3));
	

	//运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	imshow("【效果图】 Canny 边缘检测", edge);

	cout << "请输入 g 以查看原图像的灰度图: ";
	cin >> flag;
	if (flag == 'g') {
		cout << "gray:\n" << grayImage.rowRange(1, 20).colRange(1, 20) << endl;
		imshow("【灰度图】", grayImage);
	}

	waitKey(0);

	return 0;

}