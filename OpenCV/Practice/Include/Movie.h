#pragma once
#include "Scene.h"

class CMovie :
	public CScene
{
public:
	virtual HRESULT Initialize(void);
	virtual SCENE Progress(void);
	virtual void Render(void);
	virtual void Release(void);
public:
	CMovie();
	~CMovie();
};

