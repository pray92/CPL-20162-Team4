#pragma once
#include "Scene.h"

class CCharacter;
class CSettingMenu :
	public CScene
{
private:
	DWORD		m_dwTime;
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
public:
	CSettingMenu();
	~CSettingMenu();
};

