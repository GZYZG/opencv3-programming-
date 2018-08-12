#include "stdafx.h"

using namespace cv;

//-----------------��ȡ����ͷ-------------------
//date:2018.8.3
//author:GZY
//

int main_read_camera()
{
	VideoCapture capture(0);//������ͷ��ȡ
	Mat edge;
	Mat frame;

	while (1) {

		capture >> frame;

		//��ԭͼת��Ϊ�Ҷ�ͼ
		cvtColor(frame, edge, CV_BGR2GRAY);

		//����
		blur(edge, edge, Size(10, 10));

		//��Ե��Ⲣ��ʾ
		Canny(edge, edge, 0, 30, 3);

		imshow("read camera canny", edge);
		imshow("read camera", frame);
		if (waitKey(30) >= 0) {
			break;
		}
	}

	capture.release();

	return 0;
}