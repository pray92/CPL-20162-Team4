#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>

#include<new>

using namespace std;

#include "opencv2\opencv.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "dirent.h"

cv::Mat img;
cv::Mat img2;
cv::Mat newImage;

int point[4][2];
int point_count = 0;
int lupoint_x;
int lupoint_y;

int rdpoint_x;
int rdpoint_y;

int width;
int hei;

void on_mouse(int event, int x, int y, int flag, void*params) {
	if (event == CV_EVENT_LBUTTONDOWN) {
		if (point_count < 4) {
			point[point_count][0] = x;
			point[point_count++][1] = y;
		}

		if (point_count == 4) {
			point_count++;

			lupoint_x = point[0][0];
			lupoint_y = point[2][1];

			rdpoint_x = point[1][0];
			rdpoint_y = point[3][1];

			width = rdpoint_x - lupoint_x;
			hei = rdpoint_y - lupoint_y;
		}
	}
}


int main(void) {

	//cv::namedWindow("image");
	img2 = cv::imread("Character\\turtle.png");

	cv::Mat gray;

	cv::cvtColor(img2, gray, cv::COLOR_BGR2GRAY);

	std::vector<cv::Vec3f> circles;

	GaussianBlur(gray, gray, cv::Size(7, 7), 3, 3);

	cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, 10);

	/*cv::setMouseCallback("image", on_mouse);

	cv::imshow("image", img2);

	while (1) {
		char ch = cv::waitKey(0);
		if (ch == 27)
			break;
	}*/

	DIR *dir = opendir("\images");
	struct dirent *ent;
	if (dir) {
		int i = 0;
		while ((ent = readdir(dir)) != NULL) {
			if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
				continue;
			}
			char name[100] = "images\\";
			strcat(name, ent->d_name);

			cv::Mat gMatChangeImage;

			img2.copyTo(gMatChangeImage);
			//cv::imshow("name", gMatChangeImage);

			img = cv::imread(name);

			for (size_t e = 0; e < circles.size(); e++) {

				int face_radius = cvRound(circles[e][2]); // Radius of circular facial area

				lupoint_x = cvRound(circles[e][0]) - face_radius;
				lupoint_y = cvRound(circles[e][1]) - face_radius;
				rdpoint_x = lupoint_x + 2 * face_radius;
				rdpoint_y = lupoint_y + 2 * face_radius;

				cv::resize(img, img, cv::Size(2 * face_radius, 2 * face_radius), 0, 0, CV_INTER_NN);

				//cv::imshow("aa", img);

				int m = 0;
				int k = 0;

				
				int d;

				for (int i = lupoint_x; i < rdpoint_x; i++, m++) {
					k = 0;
					for (int j = lupoint_y; j < rdpoint_y; j++, k++) {
						d = sqrt(pow((int)(face_radius) - (i - lupoint_x), 2) + pow((int)(face_radius / 2) - (j - lupoint_y), 2));
						if (d < face_radius) {
							gMatChangeImage.at<cv::Vec3b>(j, i)[0] = img2.at<cv::Vec3b>(j, i)[0] * (1.0f - (face_radius - d) * 0.01f) + img.at<cv::Vec3b>(k, m)[0] * (face_radius - d) * 0.01f;
							gMatChangeImage.at<cv::Vec3b>(j, i)[1] = img2.at<cv::Vec3b>(j, i)[1] * (1.0f - (face_radius - d) * 0.01f) + img.at<cv::Vec3b>(k, m)[1] * (face_radius - d) * 0.01f;
							gMatChangeImage.at<cv::Vec3b>(j, i)[2] = img2.at<cv::Vec3b>(j, i)[2] * (1.0f - (face_radius - d) * 0.01f) + img.at<cv::Vec3b>(k, m)[2] * (face_radius - d) * 0.01f;
						}
					}
				}
			}
			char filename[100] = "CharacterImage\\";
			strcat(filename, ent->d_name);
			cv::imwrite(filename, gMatChangeImage);
		}
	}
	cv::waitKey(0);
	cv::destroyAllWindows();
}
