#include "stdafx.h"

using namespace cv;
using namespace std;

//-----------------�ڴ�����ӻ�����-------------------
//create file date:2018.8.11
//author:GZY
//


int nAlphaValueSlider;          //��������ֵ
const int nMaxAlphaValue = 100; //͸�������ֵ

//alpha,beta���������ںϣ�y = alpha * x1 + beta * x2 + gamma 
double dAlphaValue;
double dBetaValue;
const String winName = "�������Ĵ���&�ı�ͼ��͸����";

Mat src1, src2,dst;

void on_Trackbar(int, void*);//��Ӧ�������Ļص�������������ʽ������ func-name(int,void*) 
							 

int main_create_trackbar(int argc,char** argv)
{
	src1 = imread("arc.jpg");
	if (!src1.data) {
		cout << " src1.jpg ͼƬ����ʧ�ܣ�\n";
		return false;
	}
	src2 = imread("arc.jpg");
	if (!src2.data) {
		cout << " src2.jpg ͼƬ����ʧ�ܣ�\n";
		return false;
	}

	
	char trackbarName[50];

	sprintf_s(trackbarName, "����%d", nMaxAlphaValue);

	namedWindow(winName, WINDOW_NORMAL);
	createTrackbar(trackbarName, winName, &nAlphaValueSlider, nMaxAlphaValue,on_Trackbar ,trackbarName);

	
	on_Trackbar(nAlphaValueSlider,trackbarName);

	waitKey(0);

	return 0;

}


//�ı�ͼƬ������
void on_Trackbar(int,void* trackbarName)
{
	dAlphaValue = (double)nAlphaValueSlider / nMaxAlphaValue;
	//dBetaValue = 1.0 - dAlphaValue;
	

	cout << "����ֵΪ��" << nAlphaValueSlider << "\n";
	int n  = getTrackbarPos((char*)(trackbarName), winName);
	cout << "ͨ�� getTracbarPos() ��õ�����ֵ : " << n << endl;

	//ͨ������ָ������������
	/*for (int i = 0; i < src1.rows; i++) {
		Vec3b *srcRowPixel = src1.ptr<Vec3b>(i);
		Vec3b *dstRowPixel = src2.ptr<Vec3b>(i);
		for (int j = 0; j < src1.cols; j++) {
			//λ����(i,j)�������ع���3��ͨ��
			for (int c = 0; c < src1.channels(); c++) {
				dstRowPixel[j][c] = (srcRowPixel[j][c] * dAlphaValue);
			
		}
	}*/

	//ͨ������������������
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