#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <time.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "dirent.h"
#include <stdlib.h>

#include <math.h>

using namespace std;
using namespace cv;

//전역변수
String face_cascade_name = "haarcascade_frontalface_default.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

vector<Rect> face_pos; //얼굴 벡터값 저장



/** 안면, 안구인식 주요 함수 */
int main(int argc, const char** argv)
{
	CvCapture* capture;
	
	//전역변수로 미설정시 에러
	//Mat frame;
	Mat newImage; //추출 이미지
	Mat img; //사진파일 이미지
	Mat gray; //흑백 변환

	//-- load cascade
	if (!face_cascade.load(face_cascade_name)) {
		printf("--(!)Error loading face cascade\n");
		return -1;
	};
	if (!eyes_cascade.load(eyes_cascade_name)) {
		printf("--(!)Error loading eye cascade\n");
		return -1;
	};

	


	//파일명 읽어오기
	DIR *dir = opendir("\image");
	struct dirent *ent;
	if (dir) {
		int i = 0;
		while ((ent = readdir(dir)) != NULL) {
			if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
				continue;
			}

			cout << (ent->d_name) << "추출중..." << endl;

			char name[100] = "\image\\";

			strcat(name, ent->d_name);

			img = imread(name);

			if (img.data == NULL) {
				cout << "couldn't open image" << endl;
				return -1;
			}


			cvtColor(img, gray, CV_RGB2GRAY);

			//사각 출력 그래픽

			face_cascade.detectMultiScale(gray, face_pos, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE,
				Size(10, 10));

			/*for (int k = 0; k < (int)face_pos.size(); k++) {
			rectangle(img, face_pos[k], Scalar(0, 255, 0), 2);
			}*/

#if 0
			//자른 얼굴 시작점 추출
			newImage = cv::Mat::zeros(cv::Size(face_pos[0].width, face_pos[0].height), img.type());

			for (int i = 0; i < face_pos[0].width; i++) {
				for (int j = 0; j < face_pos[0].height; j++) {
					newImage.at<Vec3b>(j, i) = img.at<Vec3b>(face_pos[0].y + j, face_pos[0].x + i);
				}
			}
			
#endif

			/* --- Cropping facial area with Rect --- */
#if 0
			// Set rectangle position x, y and width, height to cropping
			Rect rect(face_pos[0].x, face_pos[0].y, face_pos[0].width, face_pos[0].height); 

			// Cropping rectangle facial area with rect()
			newImage = img(rect); 
#endif

			/* --- Circular face extraction --- */
#if 1
			newImage = cv::Mat::zeros(cv::Size(face_pos[0].width, face_pos[0].height), img.type());

			int face_radius = (int)(face_pos[0].width / 2); // Radius of circular facial area
			int d;											// Length between middle of the face & at<Vec3b>(j, i)

			for (int i = 0; i < face_pos[0].width; i++) {
				for (int j = 0; j < face_pos[0].height; j++) {
					d = sqrt(pow((int)(face_pos[0].width / 2) - i, 2) + pow((int)(face_pos[0].height / 2) - j, 2));

					// Check each point
					if(d > face_radius)	{
						// Out of the circle
						newImage.at<Vec3b>(j, i) = (0, 0, 0);
					}
					else {
						// Point is included in circle
						newImage.at<Vec3b>(j, i) = img.at<Vec3b>(face_pos[0].y + j, face_pos[0].x + i);
					}
				}
			}
#endif

			String savename = "export\\" + to_string(i) + "saved.jpg";

			//현재 파일 위치에 저장
			imwrite(savename, newImage);
			i++;

		}//while
	}
	else {
		cout << "Error opening directory" << endl;
	}

	////원형(타원) 출력 그래픽 -- 미구현
	///*
	//for (size_t i = 0; i < face_pos.size(); i++) {
	//	Point center(face_pos[i].x + face_pos[i].width*0.5, face_pos[i].y +
	//		face_pos[i].height*0.5);
	//	ellipse(img, center, Size(face_pos[i].width*0.5, face_pos[i].height*0.5), 0,
	//		0, 360, Scalar(255, 0, 255), 4, 8, 0);

	//	Mat faceROI = gray(face_pos[i]);
	//	vector<Rect> eyes;

	//	//각각 얼굴 안구 인식
	//	eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 |
	//		CV_HAAR_SCALE_IMAGE, Size(30, 30));

	//	for (size_t j = 0; j < eyes.size(); j++)
	//	{
	//		Point center(face_pos[i].x + eyes[j].x + eyes[j].width*0.5, face_pos[i].y
	//			+ eyes[j].y + eyes[j].height*0.5);
	//		int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
	//		circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
	//	}
	//}
	//*/



	return 0;


}
