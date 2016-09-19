#pragma once
#include "source.h"

class CExample
{
	DECLARE_SINGLETON(CExample);
public:
	void FaceDetection();
	void WebCam();
	void Image();
	void Video();
public:
	CExample();
	~CExample();
};

