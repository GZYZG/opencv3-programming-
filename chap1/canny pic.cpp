#include "stdafx.h"

using namespace cv;
using namespace std;
//-----------------canny ��Ե���-------------------
//date:2018.7.29
//author:GZY
//

int main_canny()
{
	Mat srcImage = imread("heibao.jpg");
	Mat dstImage, edge, grayImage;
	char flag;

	namedWindow("canny");
	imshow("��ԭʼͼ��Canny ��Ե���", srcImage);

	//������Դͼ��ͬ���ͣ�ͬ��С��ͼ��
	dstImage.create(srcImage.size(), srcImage.type());

	//��ԭͼת��Ϊ�Ҷ�ͼ��
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//ʹ��3x3�ں˽���
	blur(grayImage, edge, Size(3, 3));
	

	//����Canny����
	Canny(edge, edge, 3, 9, 3);

	imshow("��Ч��ͼ�� Canny ��Ե���", edge);

	cout << "������ g �Բ鿴ԭͼ��ĻҶ�ͼ: ";
	cin >> flag;
	if (flag == 'g') {
		cout << "gray:\n" << grayImage.rowRange(1, 20).colRange(1, 20) << endl;
		imshow("���Ҷ�ͼ��", grayImage);
	}

	waitKey(0);

	return 0;

}