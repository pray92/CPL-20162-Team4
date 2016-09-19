#include "stdafx.h"
#include "SettingMenu.h"

#include "SystemFunc.h"

HRESULT CSettingMenu::Initialize(void)
{
	if (FAILED(InitDevice(WINMODE_WIN, g_hWnd, WINSIZEX, WINSIZEY)))
	{
		MessageBox(g_hWnd, L"장치 초기화 실패", L"Sysytem Error", MB_OK);
		return E_FAIL;
	}

	MSGBOX(L"Menu Scene");

	return S_OK;
}

SCENE CSettingMenu::Progress(void)
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		ReleaseDevice();
		return SCENE_MOVIE;
	}

	return SCENE_NONPASS;
}

void CSettingMenu::Render(void)
{
}

void CSettingMenu::Release(void)
{
}

CSettingMenu::CSettingMenu()
{
}

CSettingMenu::~CSettingMenu()
{
	Release();
}
