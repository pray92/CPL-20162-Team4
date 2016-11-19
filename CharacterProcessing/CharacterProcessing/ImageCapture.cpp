#include "stdafx.h"

void ImageCapture()
{
	IplImage *frame;
	Mat image;
	CvCapture* capture = cvCaptureFromCAM(0);

	cvNamedWindow("Test", 1);

	char file_name[20];
	int pressed_key;
	time_t timer;
	tm *t;

	VideoCapture cap(0);
	if (!cap.isOpened())
		return;

	namedWindow("Test", 1);
	while (true)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("Test", frame);

		pressed_key = cvWaitKey(30);
		if (pressed_key == 27)
			break;
		else if (pressed_key == 'c' || pressed_key == 'C')
		{
			timer = time(NULL);
			t = localtime(&timer);

			String savename = "image\\" + to_string(t->tm_mon + 1) +
				to_string(t->tm_mday) + "_" +
				to_string(t->tm_min) +
				to_string(t->tm_sec) + "saved.jpg";

			imwrite(savename, frame);

			printf("img saved!\n");
		}
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("Test");


}