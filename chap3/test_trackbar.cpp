#include "stdafx.h"

using namespace cv;
using namespace std;

//-----------------在窗口添加滑动条-------------------
//create file date:2018.8.11
//author:GZY
//


int nAlphaValueSlider;          //滑动条的值
const int nMaxAlphaValue = 100; //透明度最大值

//alpha,beta用于线性融合，y = alpha * x1 + beta * x2 + gamma 
double dAlphaValue;
double dBetaValue;
const String winName = "滑动条的创建&改变图像透明度";

Mat src1, src2,dst;

void on_Trackbar(int, void*);//响应滑动条的回调函数，函数格式必须是 func-name(int,void*) 
							 

int main_create_trackbar(int argc,char** argv)
{
	src1 = imread("arc.jpg");
	if (!src1.data) {
		cout << " src1.jpg 图片加载失败！\n";
		return false;
	}
	src2 = imread("arc.jpg");
	if (!src2.data) {
		cout << " src2.jpg 图片加载失败！\n";
		return false;
	}

	
	char trackbarName[50];

	sprintf_s(trackbarName, "亮度%d", nMaxAlphaValue);

	namedWindow(winName, WINDOW_NORMAL);
	createTrackbar(trackbarName, winName, &nAlphaValueSlider, nMaxAlphaValue,on_Trackbar ,trackbarName);

	
	on_Trackbar(nAlphaValueSlider,trackbarName);

	waitKey(0);

	return 0;

}


//改变图片的亮度
void on_Trackbar(int,void* trackbarName)
{
	dAlphaValue = (double)nAlphaValueSlider / nMaxAlphaValue;
	//dBetaValue = 1.0 - dAlphaValue;
	

	cout << "亮度值为：" << nAlphaValueSlider << "\n";
	int n  = getTrackbarPos((char*)(trackbarName), winName);
	cout << "通过 getTracbarPos() 获得的亮度值 : " << n << endl;

	//通过数据指针来操作像素
	/*for (int i = 0; i < src1.rows; i++) {
		Vec3b *srcRowPixel = src1.ptr<Vec3b>(i);
		Vec3b *dstRowPixel = src2.ptr<Vec3b>(i);
		for (int j = 0; j < src1.cols; j++) {
			//位置在(i,j)处的像素共有3个通道
			for (int c = 0; c < src1.channels(); c++) {
				dstRowPixel[j][c] = (srcRowPixel[j][c] * dAlphaValue);
			
		}
	}*/

	//通过迭代器来操作像素
	MatIterator_<Vec3b> srcIt, srcEnd,dstIt,dstEnd;
	dstIt = src2.begin<Vec3b>();
	dstEnd = src2.end<Vec3b>();
	srcIt = src1.begin<Vec3b>();
	srcEnd = src1.end<Vec3b>();

	for ( ; dstIt != dstEnd && srcIt != srcEnd; dstIt++,srcIt++) {
		for (int c = 0; c < src1.channels(); c++) {
			(*dstIt)[c] = (*srcIt)[c] * dAlphaValue;
		}
	}
	//addWeighted(src1, dAlphaValue, src2, dBetaValue, 0.0, dst);

	imshow(winName, src2);
}