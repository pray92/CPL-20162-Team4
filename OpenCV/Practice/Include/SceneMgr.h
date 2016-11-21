#pragma once
#include "SystemFunc.h"

class CScene;
class CSceneMgr
{
	DECLARE_SINGLETON(CSceneMgr)
private:
	CScene*		m_pScene;
public:
	HRESULT Initialize(SCENE _eScene);
	void Progress(void);
	void Render(void);
	void Release(void);
private:
	CSceneMgr();
public:
	~CSceneMgr();
};

