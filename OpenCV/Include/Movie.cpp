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

	return S_OK;
}

SCENE CMovie::Progress(void)
{
	return SCENE_NONPASS;
}

void CMovie::Render(void)
{
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
