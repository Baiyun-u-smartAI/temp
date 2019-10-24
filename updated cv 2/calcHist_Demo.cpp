#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include "OpenCV_example.hpp"
using namespace std;
using namespace cv;

int run832()
{
	Mat src, dst;

	///加载图形文件
	src = imread("1.jpg", 1);
	if (!src.data)
		return -1;

	///分开图的三个色屏( B, G and R )
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	///设置bins
	int histSize = 256;

	///设置颜色范为值 ( B,G,R )
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;

	///计算色阶分布图(histograms):
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist,
		1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist,
		1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist,
		1, &histSize, &histRange, uniform, accumulate);

	//Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	///Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows,
		NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows,
		NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows,
		NORM_MINMAX, -1, Mat());

	///Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1),
			hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1),
			hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1),
			hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	///显示结果
	namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);

	waitKey(0);

	return 0;

}
int(*run_calcHist_Demo)()=run832;