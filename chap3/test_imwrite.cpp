
#include "stdafx.h"
#include <vector>

using namespace std;
using namespace cv;

//-----------------使用imwrite生成图像-------------------
//create file date:2018.8.9
//author:GZY
//


void createAlphaMat(Mat &mat);
void createMat1(Mat &mat);
void addPic(Mat &up, Mat &bottom);// 简单的将两幅图片叠加在一起

int main_test_imwrite()
{
	//创建带Alpha通道的Mat
	/*Mat mat(480, 640, CV_8UC4);
	Mat mat1(720, 720, CV_8UC3);
	createAlphaMat(mat);
	createMat1(mat1);

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(4);

	try {
		imwrite("Alpha.png", mat, compression_params);
		fprintf(stdout, "PNG图片文件的数据保存完毕~\n可在工程目录下查看由imwrite函数生成的图片\n");
		imshow("生成的PNG图---Alpha图", mat);

		imwrite("mat1.png", mat, compression_params);
		fprintf(stdout, "彩色方块形图片mat1.png保存完毕~\n可在工程目录下查看由imwrite函数生成的图片\n");
		imshow("生成的PNG图---彩色方块图", mat1);
		waitKey(0);

	}
	catch (runtime_error& e) {
		fprintf(stdout, "图像转换成PNG格式发生错误：%s\n", e.what());
		return 1;
	}*/

	Mat up = imread("dota_logo.png");
	Mat bottom = imread("Alpha.png");

	addPic(up, bottom);

	
    return 0;
}


void createAlphaMat(Mat &mat)
{
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			Vec4b &rgba = mat.at<Vec4b>(i, j);
			rgba[0] = UCHAR_MAX;
			rgba[1] = saturate_cast<uchar>((float (mat.cols - j)) / ((float)mat.cols) * UCHAR_MAX);
			rgba[0] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.rows) * UCHAR_MAX);
			rgba[0] = saturate_cast<uchar>(.5 * (rgba[1] + rgba[2]));

		}
	}
}

void createMat1(Mat &mat)
{
	for (int i = 0; i < mat.rows; i++) {
		for (int j = 0; j < mat.cols; j++) {
			Vec3b pixel;
			pixel[0] = i % 256;
			pixel[1] = j % 256;
			pixel[2] = 0;
			mat.at<Vec3b>(i, j) = pixel;

		}
	}
}

void addPic(Mat &up, Mat &bottom)
{
	Mat roi;
	roi = bottom(Rect(bottom.cols/2, bottom.rows/2, up.cols, up.rows));

	addWeighted(roi, 0, up, 0.3, 0.0, roi);

	namedWindow("叠加后的图", WINDOW_NORMAL);
	imshow("叠加后的图", bottom);
	waitKey(0);//防止照片一闪而过
}