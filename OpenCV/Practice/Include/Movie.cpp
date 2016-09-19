#include "stdafx.h"
#include "Movie.h"

#include "SystemFunc.h"

HRESULT CMovie::Initialize(void)
{
	if (FAILED(InitDevice(WINMODE_WIN, g_hWnd, WINSIZEX, WINSIZEY)))
	{
		MessageBox(g_hWnd, L"장치 초기화 실패", L"Sysytem Error", MB_OK);
		return E_FAIL;
	}

	MSGBOX(L"Movie Scene");

	image = cvLoadImage("t9t9.jpg", 1);

	return S_OK;
}

SCENE CMovie::Progress(void)
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		ReleaseDevice();
		return SCENE_MENU;
	}
	
	return SCENE_NONPASS;
}

void CMovie::Render(void)
{
	cvNamedWindow("T9-viewer", 1);
	cvShowImage("T9-viewer", image);
	cvWaitKey(0);
}

void CMovie::Release(void)
{
}

CMovie::CMovie()
{
}


CMovie::~CMovie()
{
	Release();
}
