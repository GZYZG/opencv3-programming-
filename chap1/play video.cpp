#include "stdafx.h"

using namespace cv;

//-----------------播放视频-------------------
//date:2018.8.2
//author:GZY
//

int main_play_video()
{
	VideoCapture capture("C:\\Users\\GZY\\Desktop\\Imagine Dragons - Demons.mp4");//读取视频
	Mat frame;

	while (1) {
		
		capture >> frame;

		imshow("play video", frame);
		waitKey(30) >= 0;
	}

	capture.release();

	return 0;
}