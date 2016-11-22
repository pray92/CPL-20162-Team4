#pragma once
#include "source.h"

class CExample
{
	DECLARE_SINGLETON(CExample);
private:
	std::vector<cv::Rect>* faces;
	std::vector<cv::Rect>* eyes;
public:
	void FaceDetection();
	void WebCam();
	void Image();
	void Video();
public:
	CExample();
	~CExample();
};

