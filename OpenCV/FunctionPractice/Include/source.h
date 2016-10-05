#pragma once
#include <cv.h>										//���� ó���� ���� header
#include <highgui.h>								//ī�޶�� ������ �Է¹ްų�
													//�̹����� �о���̰� ȭ�鿡 �����ֱ� ���� header
#ifndef _DEBUG
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif
#include<stdio.h>
#include<crtdbg.h>
#include<cxcore.h>

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

#include<vector>

#define DECLARE_SINGLETON(type) public:		\
	static type** GetInstance()				\
	{										\
		static type* pInstance = new type;	\
		if(pInstance == NULL)				\
			pInstance = new type;			\
		return &pInstance;					\
	}										\
	static void DestroyInstance()			\
	{										\
		type** ppInstance = GetInstance();	\
		if(*ppInstance != NULL)				\
		{									\
			delete *ppInstance;				\
			*ppInstance = NULL;				\
		}									\
	}

#define GET_SINGLE(type) (*type::GetInstance())
#define SAFE_DELETE_SINGLE(type) {(*type::GetInstance())->DestroyInstance(); }
#define SAFE_DELETE(pointer) if(pointer){ delete pointer; pointer= NULL;}

#include "Example.h"