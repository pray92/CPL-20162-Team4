#include "stdafx.h"

using namespace cv;

//전역변수
String face_cascade_name = "haarcascade_frontalface_default.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

vector<Rect>* face_pos; //얼굴 벡터값 저장

						/** 안면, 안구인식 주요 함수 */
void ImageExport()
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
		return;
	};
	if (!eyes_cascade.load(eyes_cascade_name)) {
		printf("--(!)Error loading eye cascade\n");
		return;
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
				return ;
			}


			cvtColor(img, gray, CV_RGB2GRAY);

			//사각 출력 그래픽
			face_pos = new vector<Rect>;
			face_cascade.detectMultiScale(gray, (*face_pos), 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE,
				Size(10, 10));

			/*for (int k = 0; k < (int)(*face_pos).size(); k++) {
			rectangle(img, (*face_pos)[k], Scalar(0, 255, 0), 2);
			}*/

#if 0
			//자른 얼굴 시작점 추출
			newImage = cv::Mat::zeros(cv::Size((*face_pos)[0].width, (*face_pos)[0].height), img.type());

			for (int i = 0; i < (*face_pos)[0].width; i++) {
				for (int j = 0; j < (*face_pos)[0].height; j++) {
					newImage.at<Vec3b>(j, i) = img.at<Vec3b>(face_pos[0].y + j, (*face_pos)[0].x + i);
				}
			}

#endif

			/* --- Cropping facial area with Rect --- */
#if 0
			// Set rectangle position x, y and width, height to cropping
			Rect rect((*face_pos)[0].x, (*face_pos)[0].y, (*face_pos)[0].width, (*face_pos)[0].height);

			// Cropping rectangle facial area with rect()
			newImage = img(rect);
#endif

			/* --- Circular face extraction --- */
#if 1
			newImage = cv::Mat::zeros(cv::Size((*face_pos)[0].width, (*face_pos)[0].height), img.type());

			int face_radius = (int)((*face_pos)[0].width / 2); // Radius of circular facial area
			int d;											// Length between middle of the face & at<Vec3b>(j, i)

			for (int i = 0; i < (*face_pos)[0].width; i++) {
				for (int j = 0; j < (*face_pos)[0].height; j++) {
					d = sqrt(pow((int)((*face_pos)[0].width / 2) - i, 2) + pow((int)((*face_pos)[0].height / 2) - j, 2));

					// Check each point
					if (d > face_radius) {
						// Out of the circle
						newImage.at<Vec3b>(j, i)[0] = 255;
						newImage.at<Vec3b>(j, i)[1] = 255;
						newImage.at<Vec3b>(j, i)[2] = 255;
					}
					else {
						// Point is included in circle
						newImage.at<Vec3b>(j, i) = img.at<Vec3b>((*face_pos)[0].y + j, (*face_pos)[0].x + i);
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

	face_pos->clear();

}
