#include "stdafx.h"
#include "SettingMenu.h"

#include "Character.h"

#include "TextureMgr.h"
#include "ObjMgr.h"

#include "SystemFunc.h"

HRESULT CSettingMenu::Initialize(void)
{
	if (FAILED(InitDevice(WINMODE_WIN, g_hWnd, WINSIZEX, WINSIZEY)))
	{
		MessageBox(g_hWnd, L"장치 초기화 실패", L"Sysytem Error", MB_OK);
		return E_FAIL;
	}
	for (auto i = 0; i < 3; ++i)
	{
		shared_ptr<CCharacter> character(new CCharacter(i));
		GET_SINGLE(CObjMgr)->InsertObject(character);
	}

	return S_OK;
}

SCENE CSettingMenu::Progress(void)
{
	return GET_SINGLE(CObjMgr)->Progress();
}

void CSettingMenu::Render(void)
{
	Render_Begin();
	GET_SINGLE(CObjMgr)->Render();
	Render_End();
}

void CSettingMenu::Release(void)
{
	SAFE_DELETE_SINGLE(CTextureMgr);
	SAFE_DELETE_SINGLE(CObjMgr);
}

CSettingMenu::CSettingMenu()
{
}

CSettingMenu::~CSettingMenu()
{
	Release();
}
