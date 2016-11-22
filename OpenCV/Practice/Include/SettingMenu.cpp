#include "stdafx.h"
#include "SettingMenu.h"

#include "Character.h"
#include "Background.h"

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

	_finddatai64_t c_file;
	intptr_t hFile;
	char* path = "./CharacterImage/*.png";
	int iCnt = 0;
	hFile = _findfirsti64(path, &c_file);
	if(hFile == -1)
		MessageBox(g_hWnd, L"캐릭터들이 없습니다.", L"Sysytem Error", MB_OK);
	else 
	{
		++iCnt;
		while (_findnexti64(hFile, &c_file) == 0)
			++iCnt;
		_findclose(hFile);
	}

	for (auto i = 0; i < iCnt; ++i)
	{
		shared_ptr<CObj> character(new CCharacter(i));
		GET_SINGLE(CObjMgr)->InsertObject(character);
	}

	for (auto i = 0; i < 3; ++i)
	{
		shared_ptr<CObj> background(new CBackground(i));
		GET_SINGLE(CObjMgr)->InsertObject(background);
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
