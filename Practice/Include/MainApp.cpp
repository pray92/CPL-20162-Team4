#include "stdafx.h"
#include "MainApp.h"

#include "SystemFunc.h"
#include "SceneMgr.h"

HRESULT CMainApp::Initialize()
{

	GET_SINGLE(CSceneMgr)->Initialize(SCENE_MENU);

	return S_OK;
}

void CMainApp::Progress(void)
{
	GET_SINGLE(CSceneMgr)->Progress();
}

void CMainApp::Render(void)
{
	GET_SINGLE(CSceneMgr)->Render();
}

void CMainApp::Release(void)
{
	System_Release();
	SAFE_DELETE_SINGLE(CSceneMgr);
}

CMainApp::CMainApp()
{
}


CMainApp::~CMainApp()
{
	Release();
}
