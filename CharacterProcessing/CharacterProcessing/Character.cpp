#include "stdafx.h"

cv::Mat img;
cv::Mat img2;
cv::Mat newImage;
cv::Mat height;

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

void MakeCharacter()
{
	cv::namedWindow("image");
	img2 = cv::imread("Character\\turtle.png");

	cv::setMouseCallback("image", on_mouse);

	cv::imshow("image", img2);

	////height = cv::imread("images\\height.bmp");
	height = cv::imread("height\\height.bmp");

	while (1) {
		char ch = cv::waitKey(0);
		if (ch == 27)
			break;
	}

	////DIR *dir = opendir("\images");
	DIR *dir = opendir("\export");
	struct dirent *ent;
	if (dir) {
		int i = 0;
		while ((ent = readdir(dir)) != NULL) {
			if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
				continue;
			}
			////char name[100] = "images\\";
			char name[100] = "export\\";
			strcat(name, ent->d_name);

			cv::Mat gMatChangeImage;

			img2.copyTo(gMatChangeImage);
			//cv::imshow("name", gMatChangeImage);

			img = cv::imread(name);

			cv::resize(img, img, cv::Size(width, hei), 0, 0, CV_INTER_NN);
			cv::resize(height, height, cv::Size(width, hei), 0, 0, CV_INTER_NN);

			//cv::imshow("aa", img);

			int m = 0;
			int k = 0;

			int face_radius = (int)(width / 2); // Radius of circular facial area
			int height_avg;
			int d;

			for (int i = lupoint_x; i < rdpoint_x; i++, m++) {
				k = 0;
				for (int j = lupoint_y; j < rdpoint_y; j++, k++) {
					d = sqrt(pow((int)(width / 2) - (i - lupoint_x), 2) + pow((int)(hei / 2) - (j - lupoint_y), 2));
					if (d < face_radius) {
						height_avg = (height.at<cv::Vec3b>(k, m)[0] + height.at<cv::Vec3b>(k, m)[1] + height.at<cv::Vec3b>(k, m)[2]) / 3.f;
						gMatChangeImage.at<cv::Vec3b>(j, i)[0] = img2.at<cv::Vec3b>(j, i)[0] * (1.0f - height_avg / 255.f) + img.at<cv::Vec3b>(k, m)[0] * height_avg / 255.f;
						gMatChangeImage.at<cv::Vec3b>(j, i)[1] = img2.at<cv::Vec3b>(j, i)[1] * (1.0f - height_avg / 255.f) + img.at<cv::Vec3b>(k, m)[1] * height_avg / 255.f;
						gMatChangeImage.at<cv::Vec3b>(j, i)[2] = img2.at<cv::Vec3b>(j, i)[2] * (1.0f - height_avg / 255.f) + img.at<cv::Vec3b>(k, m)[2] * height_avg / 255.f;
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
