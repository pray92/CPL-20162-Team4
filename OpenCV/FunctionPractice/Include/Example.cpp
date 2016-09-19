#include "source.h"
#include "Example.h"

void CExample::FaceDetection()
{
	cvNamedWindow("Face Detection");

	cv::CascadeClassifier face_cascade;
	if (!face_cascade.load("haarcascade_frontalface_alt2.xml"))
	{
		std::cerr << "Fail to load face cascade" << std::endl;
		return;
	}
	cv::CascadeClassifier eye_cascade;
	if (!eye_cascade.load("haarcascade_eye.xml"))
	{
		std::cerr << "Fail to load eye cascade" << std::endl;
		return;
	}

	CvCapture* pCapture = cvCaptureFromCAM(0);
	cv::Mat Frame;

	std::vector<cv::Rect> faces; 
	std::vector<cv::Rect> eyes;
	while (1)
	{
		if (cvWaitKey(10) == 27)
			break;

		Frame = cvQueryFrame(pCapture);
		cv::Mat GrayFrame;

		cv::cvtColor(Frame, GrayFrame, CV_BGR2GRAY);
		cv::equalizeHist(GrayFrame, GrayFrame);

		face_cascade.detectMultiScale(GrayFrame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

		for (size_t i = 0; i < faces.size(); ++i)
		{
			rectangle(Frame, faces[i], cv::Scalar(255, 255, 255));

			cv::Mat faceROI = GrayFrame(faces[i]);
			eye_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
			for (size_t j = 0; j < eyes.size(); ++j)
			{
				cv::Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				cv::circle(Frame, center, radius, cv::Scalar(255, 0, 0), 4, 8, 0);
			}
		}

		cv::imshow("Face Detection", Frame);
		faces.clear();
		eyes.clear();
	}
	cvReleaseCapture(&pCapture);
	cvDestroyAllWindows();
}

void CExample::WebCam()
{
	IplImage* image = 0;
	CvCapture* capture = cvCaptureFromCAM(0);		//0��° ī�޶�κ��� ��Ʈ���� ����
	cvNamedWindow("T9-camera", 0);					//T9-Camera��� �̸��� �����츦 ����
													//0�� ������ ������
	cvResizeWindow("T9-camera", 320, 240);			//T9-Camera��� �̸��� ������ ũ�� ����

	while (1)
	{
		cvGrabFrame(capture);						//ī�޶�κ��� �� �������� ����
		image = cvRetrieveFrame(capture);			//���� ���������κ��� lpIImage �� ������
													//��ȯ�޾� image�� ����
		cvShowImage("T9-camera", image);			//T9-camera �����쿡 image�� ������

		if (cvWaitKey(10) >= 0)						//�ƹ�Ű�� ������ ����
			break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("T9-camera");

}

void CExample::Image()
{
	IplImage *image = cvLoadImage("Title.png");

	cvNamedWindow("Test", 1);
	cvShowImage("Test", image);
	cvWaitKey(0);

	cvReleaseImage(&image);
	cvDestroyWindow("Test");
}

void CExample::Video()
{
	IplImage* frame;

	CvCapture* capture = cvCaptureFromFile("test.avi");		//������ avi, wmv, mp4, 3gp, mkv ��
	//CvCapture* capture = cvCreateFileCapture("test.avi");
	//CvCapture* capture = cvCaptureFromAVI("test.avi");

	cvNamedWindow("Test", 1);								//������ ��� ������ ����

	while (capture)
	{
		frame = cvQueryFrame(capture);						//capture�� ���� ���� �̹�����
															//cvQUeryFrame()���� ������
		cvShowImage("Test", frame);

		if (cvWaitKey(33) == 27)							//cvWaitKey�� �Ķ����
															//�������� �޾ƿ��� �ӵ�(1/1000��)
			break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("Test");
}

CExample::CExample()
{
}


CExample::~CExample()
{
}
