#include "stdafx.h"
#include "Practice.h"
#include "SceneMgr.h"

#include "Define.h"
#include "SystemFunc.h"

#include "Movie.h"
#include "SettingMenu.h"

HRESULT CSceneMgr::Initialize(SCENE _eScene)
{
	SAFE_DELETE(m_pScene);

	switch (_eScene)
	{
	case SCENE_MENU:
		m_pScene = new CSettingMenu;
		break;
	case SCENE_MOVIE:
		m_pScene = new CMovie;
		break;
	}

	if (FAILED(m_pScene->Initialize()))
	{
		SAFE_DELETE(m_pScene);
		return E_FAIL;
	}

	return S_OK;
}

void CSceneMgr::Progress()
{
	switch (m_pScene->Progress())
	{
	case SCENE_MENU:
		Initialize(SCENE_MENU);
		break;
	case SCENE_MOVIE:
		Initialize(SCENE_MOVIE);
		break;
	default:
		m_pScene->Progress();
	}
}

void CSceneMgr::Render(void)
{
	m_pScene->Render();
}

void CSceneMgr::Release(void)
{
	SAFE_DELETE(m_pScene);
}

CSceneMgr::CSceneMgr()
	:m_pScene(NULL)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}
