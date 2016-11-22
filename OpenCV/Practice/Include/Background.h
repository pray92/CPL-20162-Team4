#pragma once
#include "Obj.h"
class CBackground :
	public CObj
{
private:
	static bool m_bTextCalled;
private:
	RECT m_rcFrame;
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
public:
	CBackground(); 
	CBackground(int _iID);
	~CBackground();
};

