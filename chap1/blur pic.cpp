
#include "stdafx.h"

using namespace cv;


//----------��ͼ�����ģ������-----------
//date:2018.7.29
//author:GZY
//

int main_blur()
{
	Mat srcImage = imread("heibao.jpg");

	namedWindow("blur",3);

	imshow("��ֵ�˲���ԭͼ��", srcImage);

	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	imshow("��ֵ�˲���Ч��ͼ��", dstImage);
	waitKey(0);

	return 0;

}