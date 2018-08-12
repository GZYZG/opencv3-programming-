#include "stdafx.h"

using namespace cv;

//-----------------¶ÁÈ¡ÉãÏñÍ·-------------------
//date:2018.8.3
//author:GZY
//

int main_read_camera()
{
	VideoCapture capture(0);//´ÓÉãÏñÍ·¶ÁÈ¡
	Mat edge;
	Mat frame;

	while (1) {

		capture >> frame;

		//½«Ô­Í¼×ª»»Îª»Ò¶ÈÍ¼
		cvtColor(frame, edge, CV_BGR2GRAY);

		//½µÔë
		blur(edge, edge, Size(10, 10));

		//±ßÔµ¼ì²â²¢ÏÔÊ¾
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